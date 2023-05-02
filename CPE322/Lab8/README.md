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
