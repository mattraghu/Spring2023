# Lab 8 : Building Makemore

## Introduction

For this lab, I decided to take it as an oppertunity to learn something new. I always wanted to learn how to make complex neural networks, and I thought this would be a good oppertunity to do so.

Andrej Karpathy is the (now former) director of AI at **Tesla**. He has a youtube channel where he teaches about neural networks and machine learning. I previously watched his video on [The spelled-out intro to neural networks and backpropagation: building micrograd](https://www.youtube.com/watch?v=VMj-3S1tku0&t=4s), and I decided to continue learning by creating a neural network based on his video: [The spelled-out intro to language modeling: building makemore](https://www.youtube.com/watch?v=PaCmpygFfXo)

For this project, I'm provided with a list of names (see **index.txt**) and I'm supposed to create a neural network that can generate new names based on the names in the list.

# Basic Bigram Model

## Introduction

Essentially a bigram will predict the next letter based on the previous letter. Its a very simple model, but its a good starting point for learning how to make neural networks.

## Explanation

---

We begin by loading the dataset and creating a tokenizer to convert the names into a list of numbers.

```python
#Load up names.txt
words = open('names.txt', 'r').read().split('\n')

chars = sorted(list(set(''.join(words))))

#Add "." to the beggining of the list (This will be used to indicate the start/end of a name)
chars = ['.'] + chars

#Tokenize the text- This will be used to convert the text to numbers
char_to_idx = {ch:i for i,ch in enumerate(chars)}
idx_to_char = {i:ch for i,ch in enumerate(chars)}
```

Indexing char_to_idx will give us the index of the character in the list, and indexing idx_to_char will give us the character at the index.

---

Now I create a tensor with the frequencies of every bigram in the dataset. This will be used to calculate the probability of a letter occuring after another letter.

```python
#Create a tensor of the bigram frequencies
freq_tensor = torch.zeros(len(chars), len(chars))

for w in words[:]:
    chs = ['.'] + list(w) + ['.']
    #We want to get chars 1,2 then 2,3 then 3,4 ...
    for ch1, ch2 in zip(chs, chs[1:]):
        # print(ch1, ch2)
        # b = (ch1, ch2)
        #Convert to numbers
        b = (char_to_idx[ch1], char_to_idx[ch2])

        freq_tensor[b[0], b[1]] += 1

```

Ex. if the only word in the data set was "bob", then the tensor would look like this:

|     | .   | b   | o   |
| --- | --- | --- | --- | --- |
| .   | 0   | 1   | 0   |
| b   | 0   | 0   | 1   |
| o   | 0   | 0   | 0   | A   |

---

I then create a graph (just to visualize the data) of the bigram frequencies.

```python
# Get list of letters and their frequencies
letters = sorted(list(set(chars)))
freqs = freq_tensor.numpy()

# Create heatmap
fig = go.Figure(data=go.Heatmap(
                   z=freqs,
                   x=letters,
                   y=letters,
                   colorscale='Greens',
                   zmin=0,
                   zmax=np.max(freqs),
                   hovertemplate='Frequency: %{z}<extra></extra>'))
fig.update_layout(
    title='Bigram Frequency',
    xaxis_title='Second Letter',
    yaxis_title='First Letter',
    width=600,
    height=600,
)
fig.show()

```

![Bigram Frequency](./Media/BigramFrequencies.png)

---

Now if we're given a letter, we can index the tensor to get the frequencies of the letters that come after it. We can then normalize the frequencies to get the probability of each letter occuring after the given letter.

Then we just need to sample from the probability distribution to get the next letter.

```python
g = torch.Generator().manual_seed(2147483647)

for i in range(20):
    ix = 0
    out = []
    while True:
        #Get the probabilities of the next letter based on the previous letter
        p = freq_tensor[ix]
        #Normalize the probabilities
        p = p / p.sum()
        #Generate a random letter based on the probabilities in p and a first letter
        ix = torch.multinomial(p, 1, replacement=True, generator=g).item()
        #Get the letter
        out.append(idx_to_char[ix])
        if idx_to_char[ix] == '.':
            break

    print(''.join(out[:-1]))

```

Output:

```
cexze
momasurailezitynn
konimittain
llayn
ka
da
staiyaubrtthrigotai
moliellavo
ke
teda
ka
emimmsade
enkaviyny
ftlspihinivenvorhlasu
dsor
br
jol
pen
aisan
ja
```

Note: As Kapathy says, the Bigram model is really terrible because it only has the context of a single letter without any notion of what came before it. Though this is much more "namelike" than if we didn't use the model.

For example if I were to change the p to a uniform distribution (all letters have the same probability of occuring with the following line:

```python
        #Test- Create a uniform distribution
        p = torch.ones(len(chars)) / len(chars)
```

Then the output would be:

```
loufqqtlyvpodqutigkysohlvohycqucacflvjjapklabqlveaamvlx
zcexvgxhfykobe
eitrrrlxhiordgopzdsy
ttnzpkumzqjjqtubeybwdzetvozddkmsvkzfzfvqxmnafpjfnamhokcdcpgvludiclojbghjoyyauaufnwwvdltswcr
awocteegebavdjlcebdfnnvkobilvxjbagvoyhbpsizsbdsoiwepwglormndgcmpmjjzrty
pdynuklhljxktriqqkrrk
spqphdoproqfiwagujj
fgkx
yuypfdgzscvkbrluyxbvzfyt
ffijvobtdkduqwcrdpcboitmxottbfqamaaofmql
cypbheriuglgfzetifjfgvyieqqnvaipbiniugz
wttvevvsuewbpsibkusrnkcwjihumtlngwdlzq
ydfovsrxixeheimvwrtfkornkolzcqwyxhhinirxnirwipciqxhakfxxjpipctdibhxobavkkibdihtflynv
ztuhexiyeciwjerkyfylkbbphdyoquptttnwfxydspkyqmcqafcxgjzmzjyoljwinirlupxijtlwidoavegjelswcomthaphnsbydjttbjlaxdrcaplxamiahcyyrmbioliogpkkwzdufbifxdzkhokwzcymqdcbzlkvbulzdawfmya
xhgupough
lob
yyihftbpqh
p
kzywhlmrarfsfhizsqeyygabjkinpbkgqshpuwsckmabxbbhhjmvywcnzenyigpnovlfakvfyyjyyohdixqiaszgjouevgklrpcykwrgepkdwfohrm
mqxjeciawzdcslpm
```

Which is much less "namelike" than the output from the bigram model.

### Loss Function

Goal is to minimize the loss function.

We calculate loss by taking the negative log of the probability of the correct letter.

I create first create a prob_tensor that give the probability of each letter occuring after a given letter instead of the frequency.

```python
    #Create a prob_tensor with the probabilities so we dont have to keep calculating them
    prob_tensor = freq_tensor / freq_tensor.sum(dim=1, keepdim=True)
```

- Now if we go and look at a random word from the dataset, we can what our model _thinks_ the probability of each letter pair is.

- In an ideal model, the probability would be close to 1.
- For example, if the only word was "Bob" and we were looking at the probability of "o" occuring after "b", then the probability would be close to 1.
- If our model was not trained and it was not close to one then we would know that our model is not very good.

To create our loss function we will start by taking the log of the probability of the correct letter.

We take the log because of the following mathematical property:

$$log(a*b) = log(a) + log(b)$$

This property allows us to add the log of the probabilities instead of multiplying them.

The log function is plotted below:
![Log Function](./Media/logx.png)

As you can see, the log function appraoches negative infinity as x approaches 0 and approaches 0 as x approaches 1.

We take the negative log because of tradition (higher loss is bad, lower loss is good).

The code for this is shown below:

```python
log_likelihood = 0
n = 0
for w in words[:]:
    chs = ['.'] + list(w) + ['.']
    #We want to get chars 1,2 then 2,3 then 3,4 ...
    for ch1, ch2 in zip(chs, chs[1:]):
        # print(ch1, ch2)
        # b = (ch1, ch2)
        #Convert to numbers
        b = (char_to_idx[ch1], char_to_idx[ch2])

        prob = prob_tensor[b[0], b[1]]
        log_prob = torch.log(prob)

        log_likelihood += log_prob
        n += 1

        # print(f'{ch1} -> {ch2}: {prob:.4f} {log_prob:.4f}')

        freq_tensor[b[0], b[1]] += 1

log_likelihood /= -n
print(f'Log Likelihood: {log_likelihood:.4f}')
```

### Neural Network

Essentially, a neural network is a function that takes in some input and produces some output.

![Neural Network](./Media/nn.png)

- The neural network is made up of layers.
- Each layer is made up of neurons.
- Each neuron takes in some input and by applying some function to the input, produces some output.
- That function is made up of weights and biases and takes the following form:
  - $$y = f(\sum_{i=1}^{n} w_i x_i + b)$$
  - Where:
    - $y$ is the output
    - $f$ is the activation function
    - $w_i$ is the weight of the $i^{th}$ input
    - $x_i$ is the $i^{th}$ input
    - $b$ is the bias
    - $n$ is the number of inputs
- The goal of training a neural network is to find the weights and biases that minimize the loss function.

For our code, I start defining the inputs and targets for our neural network.

```python
xs, ys = [], [] #xs are the inputs and ys are the targets

for w in words[:1]:
    chs = ['.'] + list(w) + ['.']
    #We want to get chars 1,2 then 2,3 then 3,4 ...
    for ch1, ch2 in zip(chs, chs[1:]):
        # print(ch1, ch2)
        # b = (ch1, ch2)
        #Convert to numbers
        b = (char_to_idx[ch1], char_to_idx[ch2])

        xs.append(b[0])
        ys.append(b[1])

xs = torch.tensor(xs)
ys = torch.tensor(ys)
```

Then I encode the inputs by using one hot encoding.

```python
x_enc = F.one_hot(xs, num_classes=len(chars)).float()
plt.imshow(x_enc)

#Convert the x axis to letters
plt.xticks(range(len(chars)), labels=chars)
plt.show()
```

This creates a tensor that has a 1 in the column of the letter and 0's everywhere else shown below:

![One Hot Encoding](./Media/xs.png)
This particular tensor is for the name, "Bob"

As mentioned before, you can calculate the output for a single neuron by multiplying the inputs by the weights and adding the bias.

We can achieve a similar result by multiplying the inputs by a matrix of weights and adding a vector of biases.

Say I have this matrix of inputs with a vocabulary size of 3 **(.,b,o)** and a batch size of 3:

$$
x =
\begin{bmatrix}
    1 & 0 & 0 \\
    0 & 1 & 0 \\
    0 & 0 & 1 \\

\end{bmatrix}
$$

This would be the one hot encoding of the word ".bo"

And I have this matrix of weights with a vocabulary size of 3 **(.,b,o)** by 1

$$
w =
\begin{bmatrix}
    1 \\
    2 \\
    3 \\
\end{bmatrix}


$$

Then I can calculate the output by multiplying the inputs by the weights:

$$
xw =
\begin{bmatrix}
    1 & 0 & 0 \\
    0 & 1 & 0 \\
    0 & 0 & 1 \\
\end{bmatrix}
\begin{bmatrix}
    1 \\
    2 \\
    3 \\
\end{bmatrix}
=
\begin{bmatrix}
    1 \\
    2 \\
    3 \\
\end{bmatrix}
$$

The calculation for each output index is shown below:

$$
xw[0] = x[0][0]w[0] + x[0][1]w[1] + x[0][2]w[2] = 1*1 + 0*2 + 0*3 = 1
$$

$$
xw[1] = x[1][0]w[0] + x[1][1]w[1] + x[1][2]w[2] = 0*1 + 1*2 + 0*3 = 2
$$

$$
xw[2] = x[2][0]w[0] + x[2][1]w[1] + x[2][2]w[2] = 0*1 + 0*2 + 1*3 = 3
$$

As you can see, each letter produces an output equal to the sum of weights multiplied onto it. In this case, the only weight that will effect the output is the weight at the index of the letter. This is because the input is one hot encoded (all other values are 0).

A method called the **softmax** function is used to convert the outputs into probabilities.

The softmax function is defined as:

$$
\sigma(z)_j = \frac{e^{z_j}}{\sum_{k=1}^{K} e^{z_k}}
$$

Where:

- $z$ is the input
- $j$ is the index of the output
- $K$ is the number of outputs

In otherwords, I exponentiate each output and divide it by the sum of all the exponentiated outputs.

The output above is kinda misleading cause it only features the output as if there was only one possible letter to follow "., b, and o" but in reality, there are 3 possible letters to follow each of those letters. So let's add more neurons for each letter.

$$

xw =
\begin{bmatrix}
    1 & 0 & 0 \\
    0 & 1 & 0 \\
    0 & 0 & 1 \\
\end{bmatrix}
\begin{bmatrix}
    1 & 4 & 7 \\
    2 & 5 & 8 \\
    3 & 6 & 9 \\
\end{bmatrix}
=
\begin{bmatrix}
1 & 4 & 7 \\
2 & 5 & 8 \\
3 & 6 & 9 \\
\end{bmatrix} \
$$

The output for the example above is shown below:

$$

\sigma(xw) =
\begin{bmatrix}
\frac{e^1}{e^1 + e^4 + e^7} & \frac{e^4}{e^1 + e^4 + e^7} & \frac{e^7}{e^1 + e^4 + e^7} \\
\frac{e^2}{e^2 + e^5 + e^8} & \frac{e^5}{e^2 + e^5 + e^8} & \frac{e^8}{e^2 + e^5 + e^8} \\
\frac{e^3}{e^3 + e^6 + e^9} & \frac{e^6}{e^3 + e^6 + e^9} & \frac{e^9}{e^3 + e^6 + e^9} \\
\end{bmatrix}
$$

The sum of the outputs for each character in the word is 1 indicating that the output is the probability of a letter being the next letter in the word.

Like for the first letter "B" the probability of "O" being the next letters is $\frac{e^4}{e^1 + e^4 + e^7} = 0.0473$ according to this neural network. Because our dataset is only "Bob" for this example we would expect the probability of "O" being the next letter to be 0.5, as the only other option is "." and so we want to tweak the parameters of the neural network so that the probability of "O" being the next letter is 0.5.
