```python
import torch
import torch.nn as nn
import torch.nn.functional as F

torch.manual_seed(1337)
B, T, C = 1, 3, 4  # batch size, sequence length, vocab size
x = torch.randn(B, T, C)

# model definition
head_size = 16
key = nn.Linear(C, head_size, bias=False)
query = nn.Linear(C, head_size, bias=False)

wei_0 = torch.tril(torch.ones(T, T))
wei_0[wei_0 == 0] = float('-inf')
wei_0[wei_0 == 1] = 0
wei = F.softmax(wei_0, dim=1)

print(wei.shape)
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
