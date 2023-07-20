```python
torch.manual_seed(1337)
B,T,C = 1,3,4 # batch size, sequence length, embedding size
x = [[[1,2,3,4],[5,6,7,8],[9,10,11,12]]]
x = torch.tensor(x, dtype=torch.float32)

wei_0 = torch.tril(torch.ones(T, T))
wei_0[wei_0==0] = float('-inf')
wei_0[wei_0==1] = 0
wei = F.softmax(wei_0, dim=1)

out = torch.matmul(wei, x)
```

Given a **B,T,C** of 1,3,4.

In other words, a **batch size** of 1, a 3 **length sequence**, and a **vocabulary size** of 4.

We generate an arbitrary x given as:

$$
x = \begin{bmatrix}
     \begin{bmatrix}
       1 & 2 & 3 & 4 \\
       5 & 6 & 7 & 8 \\
       9 & 10 & 11 & 12 \\
     \end{bmatrix}
     \end{bmatrix}


$$

The wei for this example is generated as:

$$
\text{wei} = \begin{bmatrix}
1 & 0 & 0 \\
0.5 & 0.5 & 0 \\
0.33 & 0.33 & 0.33
\end{bmatrix}
$$

Thus, the output matrix is calculated with:

$$
\begin{align*}
\text{output}[0, 0, 0] &= \text{wei}[0, 0] \times \text{x}[0, 0] + \text{wei}[0, 1] \times \text{x}[1, 0] + \text{wei}[0, 2] \times \text{x}[2, 0] \\
                       &= 1.0000 \times 1 + 0.0000 \times 5 + 0.0000 \times 9 \\
                       &= 1.0000 \\
\end{align*}
$$

$$
\text{output} = \begin{bmatrix}
                 \begin{bmatrix}
                   1.0000 & 2.0000 & 3.0000 & 4.0000 \\
                   3.0000 & 4.0000 & 5.0000 & 6.0000 \\
                   5.0000 & 6.0000 & 7.0000 & 8.0000 \\
                 \end{bmatrix}
               \end{bmatrix}
$$

Instead of just using fixed normalized weights in wei, we want the network to be able to learn the weights.

The softmax will still be used to normalize the weights and increase the importance of the greater weights.

```python
torch.manual_seed(1337)
B,T,C = 1,3,4 # batch size, sequence length, embedding size
# x = torch.randn(B,T,C)
x = [[[1,2,3,4],[5,6,7,8],[9,10,11,12]]]
x = torch.tensor(x, dtype=torch.float32)

# model definition
head_size = 16
key = nn.Linear(C, head_size, bias=False)
query = nn.Linear(C, head_size, bias=False)
value = nn.Linear(C, head_size, bias=False)

k = key(x) #B,T,head_size
q = query(x) #B,T,head_size
v = value(x) #B,T,head_size


tril = torch.tril(torch.ones(T, T))
wei = torch.matmul(q, k.transpose(-2,-1)) / (head_size ** 0.5) # B,T,T
wei = wei.masked_fill(tril == 0, float('-inf')) #Make the future weights -inf because they should not be used
wei = F.softmax(wei_0, dim=1) # Normalize and increase the importance of the greater weights

out = torch.matmul(wei, v) #B,T,head_size
```

In this case we expand the channel size to a head size to get a better representation of the data.

Before the wei is normalized, we want to make the variance of the weights to be 1 so that the softmax will not be too extreme (one hot ish)

Thus we divide the weights by the square root of the head size.

We can now create a Head class to convert x (B,T,C) into a (B,T,head_size) representation where values in the last channel give an understanding of what the next character should be based on the previous characters.
