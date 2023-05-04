# Homework 8

## 8.3:

In a JPEG image coder, after the DCT, quantization and zig-zag scanning, all the AC coefficients are coded through a run-length coding. This run-length coding is defined as pairs of (zero-run, amplitude), where the amplitude is a non-zero coefficient and the zero- run is the number of zeros prior to this non-zero coefficient. At a certain point when there is no more non-zero coefficient in the block, a symbol EOB (end-of-block) is coded.

The image is loaded in and the first 8x8 block is replicated into x1 with:

```matlab
fid=fopen('images/lenna.256','r');
x=fread(fid,[256,256],'uchar');
fclose(fid);
x1=x(1:8,1:8);
```

x1 looks like this:

$$
\begin{bmatrix}
137 & 137 & 138 & 133 & 129 & 131 & 131 & 131\\
136 & 136 & 133 & 133 & 133 & 133 & 130 & 132\\
133 & 133 & 134 & 133 & 130 & 130 & 130 & 130\\
136 & 136 & 134 & 130 & 130 & 122 & 130 & 130\\
138 & 138 & 136 & 134 & 133 & 132 & 132 & 131\\
134 & 134 & 132 & 133 & 131 & 131 & 131 & 131\\
134 & 134 & 130 & 128 & 132 & 130 & 128 & 130\\
132 & 132 & 130 & 125 & 128 & 130 & 130 & 128\\
\end{bmatrix}
$$

### DCT

The DCT is computed with:

```matlab
y1=dct2(x1);
```

y1 looks like this:

$$
\begin{bmatrix}
1055.75 & 14.85 & 5.66 & -1.02 & -1.25 & -1.55 & -0.72 & 1.14\\
7.20 & 3.17 & -1.01 & -3.76 & 0.36 & 1.97 & 0.86 & -0.95\\
-3.13 & -2.37 & 0.57 & 2.64 & -2.67 & -1.15 & 2.88 & -1.19\\
7.26 & 1.24 & -0.73 & 0.04 & 0.05 & 0.38 & 0.67 & -1.81\\
0.25 & 3.66 & 2.96 & -1.97 & -2.25 & 1.30 & -0.69 & 2.59\\
-4.28 & 2.04 & 1.66 & -2.69 & 1.01 & -0.10 & -1.04 & 2.18\\
-1.68 & -1.64 & -1.12 & -1.72 & -1.87 & 3.10 & 0.93 & -0.96\\
3.06 & -0.01 & -1.83 & 1.09 & -1.27 & 0.00 & 1.90 & -1.10\\
\end{bmatrix}
$$

### Quantization

The Q-Matrix is defined as:

$$

Q =
\begin{bmatrix}
16 & 11 & 10 & 16 & 24 & 40 & 51 & 61 \\
12 & 12 & 14 & 19 & 26 & 58 & 60 & 55 \\
14 & 13 & 16 & 24 & 40 & 57 & 69 & 56 \\
14 & 17 & 22 & 29 & 51 & 87 & 80 & 62 \\
18 & 22 & 37 & 56 & 68 & 109 & 103 & 77 \\
24 & 35 & 55 & 64 & 81 & 104 & 113 & 92 \\
49 & 64 & 78 & 87 & 103 & 121 & 120 & 101 \\
72 & 92 & 95 & 98 & 112 & 100 & 103 & 99 \\
\end{bmatrix}


$$

The quantization is then computed with:

```matlab
Q = [16 11 10 16 24 40 51 61;     12 12 14 19 26 58 60 55;     14 13 16 24 40 57 69 56;     14 17 22 29 51 87 80 62;     18 22 37 56 68 109 103 77;     24 35 55 64 81 104 113 92;     49 64 78 87 103 121 120 101;     72 92 95 98 112 100 103 99];
quant_dct_x1 = round(y1 ./ Q);
```

quant_dct_x1 looks like this:

$$
\begin{bmatrix}
66 & 1 & 1 & 0 & 0 & 0 & 0 & 0 \\
1 & 0 & 0 & 0 & 0 & 0 & 0 & 0 \\
0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 \\
1 & 0 & 0 & 0 & 0 & 0 & 0 & 0 \\
0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 \\
0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 \\
0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 \\
0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 \\
\end{bmatrix}
$$

### 0.1\*Q

The 0.1\*Q matrix is defined as:

$$
\begin{bmatrix}
1.6 & 1.1 & 1.0 & 1.6 & 2.4 & 4.0 & 5.1 & 6.1 \\
1.2 & 1.2 & 1.4 & 1.9 & 2.6 & 5.8 & 6.0 & 5.5 \\
1.4 & 1.3 & 1.6 & 2.4 & 4.0 & 5.7 & 6.9 & 5.6 \\
1.4 & 1.7 & 2.2 & 2.9 & 5.1 & 8.7 & 8.0 & 6.2 \\
1.8 & 2.2 & 3.7 & 5.6 & 6.8 & 10.9 & 10.3 & 7.7 \\
2.4 & 3.5 & 5.5 & 6.4 & 8.1 & 10.4 & 11.3 & 9.2 \\
4.9 & 6.4 & 7.8 & 8.7 & 10.3 & 12.1 & 12.0 & 10.1 \\
7.2 & 9.2 & 9.5 & 9.8 & 11.2 & 10.0 & 10.3 & 9.9 \\
\end{bmatrix}
$$

The 0.1\*Q is then computed with:

```matlab
Q_01 = 0.1*Q;
quant_dct_x1_01 = round(y1 ./ Q_01);
```

quant_dct_x1_01 looks like this:

$$
\begin{bmatrix}
660 & 14 & 6 & -1 & -1 & 0 & 0 & 0 \\
6 & 3 & -1 & -2 & 0 & 0 & 0 & 0 \\
-2 & -2 & 0 & 1 & -1 & 0 & 0 & 0 \\
5 & 1 & 0 & 0 & 0 & 0 & 0 & 0 \\
0 & 2 & 1 & 0 & 0 & 0 & 0 & 0 \\
-2 & 1 & 0 & 0 & 0 & 0 & 0 & 0 \\
0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 \\
0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 \\
\end{bmatrix}
$$
