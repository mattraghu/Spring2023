# Makemore - Part 3

## Introduction

This will follow the [Building makemore Part 3: Activations & Gradients, BatchNorm](https://www.youtube.com/watch?v=P6sfmUTpUmc) lecture on youtube by the (former) director of AI at Tesla, Andrej Karpathy.

This continues the makemore labs from labs 8/9.

## Optimization

### Uniform Output Probabilities

Remember that we calculated the logits using:

```python
logits = h @ W2 + b2 #len(X_train) x len(chars)
```

We then used the softmax function to convert the logits to probabilities:

```python
counts = torch.exp(logits)
probs = counts / counts.sum(dim=1, keepdim=True)
```

- We orginially initilize the weights and biases to be random values.
- This means that the output probabilities are also random. We want the output probabilities to be uniform.
- We can do this by initilizing the weights and biases of the output layer to be close to zero.

```python
W2 = torch.randn(hidden_size, len(chars), generator=g)*0.01
b2 = torch.randn(len(chars), generator=g)*0
```

### Dead Neurons

For our network we use the tanh activation function to squash the output of the hidden layer to be between -1 and 1.

$$ tanh(x) = \frac{e^x - e^{-x}}{e^x + e^{-x}} $$

The derivative of the tanh function is:

$$ \frac{d}{dx}tanh(x) = 1 - tanh^2(x) $$

- We observe that when tanh(x) is close to 1 or -1, the derivative is close to 0.
- This means that the gradient is close to 0.
- This is a problem because the gradient is used to update the weights and biases. If the gradient is close to 0, then the weights and biases will not be updated.
- Any parameter behind this neuron will multiply by 0, essentially stopping the backpropagation.

Previously we initilized the weights and biases of the hidden layer to be random values.

```python
W1 = torch.randn(emb_dim*block_size, hidden_size, generator=g)
b1 = torch.randn(hidden_size, generator=g)
```

Plotting the distribution of the hidden layer output, we see that many of the values are close to 1 or -1.

![PreOp HiddenLayer](./Media/PreOp_h.png)

We can fix this by initilizing the weights and biases of the hidden layer to be close to zero.

```python
W1 = torch.randn(emb_dim*block_size, hidden_size, generator=g) * 0.1
b1 = torch.randn(hidden_size, generator=g) * .01
```

Plotting the distribution of the hidden layer output, we see that the values are more spread out.

![PostOp HiddenLayer](./Media/PostOp_h.png)

### Calculating the initial scale with Kaiming

Assume we have an output layer with 1000 examples and 200 neurons.

```python
x = torch.randn(1000,10)
w = torch.randn(10,200)
y = x @ w
```

Randn initializes with a gaussian distribution with mean 0 and variance 1.

Printing the mean and stddev of x and y give the following output:

```
x mean: 0.0 std: 1.0
y mean: -0.01 std: 3.13
```

- The goal is to have the mean and stddev of y to be the same as x.
- This is so that the gradient is not too large or too small.

How do we scale w so that the mean and stddev of y is the same as x?

```python
x = torch.randn(1000,10)
w = torch.randn(10,200) / 10**0.5
y = x @ w
```

Printing the mean and stddev of x and y give the following output:

```
x mean: -0.01 std: 1.0
y mean: 0.0 std: 1.0
```

By dividing w by the square root of the number of inputs, we can scale the output to have the same mean and stddev as the input.
