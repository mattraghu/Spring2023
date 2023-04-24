# Image Enchancement Algorithms

## Gaussian Blur

### Description

#### Mathematical Description

Gaussian blur is a simple and effective image enhancement algorithm. It is a linear filter that is used to blur an image. It is a convolution of the image with a Gaussian function. The Gaussian function is a bell-shaped curve that is used to model the distribution of a variable. The Gaussian function is defined as:

$$G(x,y) = \frac{1}{2\pi\sigma^2}e^{-\frac{x^2+y^2}{2\sigma^2}}$$

where $\sigma$ is the standard deviation of the Gaussian function.

The $$\frac{1}{2\pi\sigma^2}$$ term is a normalization factor that ensures that the Gaussian function integrates to 1.

#### Creating the Gaussian Kernel

In code, this can be represented as

```python
# Function to create a Gaussian kernel given the kernel size and standard deviation (sigma)
def create_gaussian_kernel(ksize, sigma):
    # Create a 1D array of coordinates centered at zero
    ax = np.arange(-ksize // 2 + 1., ksize // 2 + 1.)

    # Create a 2D meshgrid from the 1D array
    xx, yy = np.meshgrid(ax, ax)

    # Compute the Gaussian kernel using the meshgrid
    kernel = np.exp(-(xx**2 + yy**2) / (2. * sigma**2))

    # Normalize the kernel so that it sums to 1
    return kernel / kernel.sum()
```

Note: the normalization factor is applied when we divide the kernel by the sum of the kernel. This ensures that the kernel integrates to 1.

Say we had a 3x3 kernel,
xx,yy would be

$$xx = \begin{bmatrix} -1 & 0 & 1 \\ -1 & 0 & 1 \\ -1 & 0 & 1 \end{bmatrix}$$

$$yy = \begin{bmatrix} -1 & -1 & -1 \\ 0 & 0 & 0 \\ 1 & 1 & 1 \end{bmatrix}$$

$$G = \begin{bmatrix} e^{-\frac{(-1)^2+(-1)^2}{2\sigma^2}} & e^{-\frac{(0)^2+(-1)^2}{2\sigma^2}} & e^{-\frac{(1)^2+(-1)^2}{2\sigma^2}} \\ e^{-\frac{(-1)^2+(0)^2}{2\sigma^2}} & e^{-\frac{(0)^2+(0)^2}{2\sigma^2}} & e^{-\frac{(1)^2+(0)^2}{2\sigma^2}} \\ e^{-\frac{(-1)^2+(1)^2}{2\sigma^2}} & e^{-\frac{(0)^2+(1)^2}{2\sigma^2}} & e^{-\frac{(1)^2+(1)^2}{2\sigma^2}} \end{bmatrix}$$

The Gaussian Kernel would then be normalized by dividing by the sum of the kernel in the following line:

```python
return kernel / kernel.sum()
```

#### Convolution

We know that to apply a Gaussian Blur we have to convolve the image with the Gaussian kernel.

A 1D convolution is defined as:

$$x[n] * h[n] = \sum_{k=-\infty}^{\infty}x[k]h[n-k]$$

This can be extended to 2D convolution by applying the 1D convolution to each row and column of the image.

$$x[n,m] * h[n,m] = \sum_{j=-\infty}^{\infty}\sum_{i=-\infty}^{\infty}x[j,i]h[n-j,m-i]$$

In code this is shown as:

```python
# Loop through the input image, applying the kernel at each pixel
for i in range(height):
    for j in range(width):
        # Multiply the kernel with the corresponding region in the padded image, and sum the result
        output[i, j] = np.sum(padded_image[i:i+ksize, j:j+ksize] * kernel) # This is the same as convolving the kernel with the image.
```

#### Padding

Before we apply the convolution, we also have to pad the image with zeros. The problem is that when we apply the convolution without the padding, the kernel will go out of bounds of the image when applied to the edges of the image. This will result in the output image being smaller than the input image. To avoid this, we pad the image with zeros with a border size equal to half the kernel size. This ensures that the output image is the same size as the input image.

```python
# Calculate the padding size (half of the kernel size)
pad_size = ksize // 2

# Pad the input image with zeros around the border
padded_image = np.pad(image, ((pad_size, pad_size), (pad_size, pad_size)), mode='constant')
```

#### Results

We testing the algorithm by giving it an input image (shown below) and applying the Gaussian Blur algorithm with a kernel size of 91 and a standard deviation of 10. The results are shown below.

##### Input Image

![Input Image](Media/MINIRAT.jpeg)

##### Output Image

![Output Image](Media/output.jpg)

We also tested it with the OpenCV Gaussian Blur function with the following output:

![OpenCV Output Image](Media/cv2_blurred_image.jpg)

#### Comments

We were able to effectively implement the Gaussian Blur algorithm. The results are very similar to the OpenCV Gaussian Blur function. The only difference is that the OpenCV function is much faster than our implementation. This is because the OpenCV function is written in C++ and is optimized for speed. Our implementation is written in Python and is not optimized for speed.

Because of the large image and kernel size, the algorithm took **41.6s** to execute vs the OpenCV function which took **0.9s** to execute.

Additionally, the output images do not have color. This is because we only apply this algorithm to the luminance channel of the image. If we applied it to all three channels, the output image would be in color.

## Additive White Gaussian Noise

### Description

#### Mathematical Description

Additive White Gaussian Noise (AWGN) is a type of noise that is added to an image. It is a random signal with a Gaussian distribution.

The Gaussian distribution is defined as:

$$f(x) = \frac{1}{\sigma\sqrt{2\pi}}e^{-\frac{(x-\mu)^2}{2\sigma^2}}$$

where $\mu$ is the mean of the distribution and $\sigma$ is the standard deviation of the distribution.

A set of random variables with a Gaussian distribution can be generated by generating a set of uniformly distributed random variables and applying the following transformation:

$$x = \sqrt{-2\ln(u)}\cos(2\pi v)$$

where $u$ and $v$ are uniformly distributed random variables.

In code this can be represented as:

```python
# Get the dimensions of the input image
height, width = image.shape

# Generate uniform random variables
u = np.random.uniform(size=(height, width))
#Transform the uniform variables into normal variables using the inverse transform method
noise = np.sqrt(-2 * np.log(u)) * np.cos(2 * np.pi * u)
# Scale the noise to the specified noise level
noise *= noise_level
```

The noise is then added to the original image to generate the noisy image.

```python
# Add the noise to the input image
noisy_image = image + noise

# Clip the pixel values to ensure they are within the valid range of 0-255
noisy_image = np.clip(noisy_image, 0, 255)
```

#### Results

We tested the algorithm by giving it an input image (shown below) and applying the AWGN algorithm with a noise level of 200. The results are shown below.

##### Input Image

![Input Image](Media/MINIRAT.jpeg)

##### Output Image

![Output Image](Media/output_noisy.jpg)

### Comments

The algorithm was able to effectively add AWGN to the input image. At worse, for this 2419 × 1814 image the algorithm took **0.2s** to execute on its worst trial.

## Speckle Noise

### Description

Speckle noise is similar to AWGN. It is a random signal with a Gaussian distribution. However, the variance of the distribution is not constant. Instead, it is proportional to the intensity of the image.

To achieve this we will generate a log-normal distribution of random variables and multiply it by the input image.:

```python
noise_multiplier = np.exp(np.random.normal(mean, np.sqrt(variance), size=image.shape))

# Multiply the input image by the noise multiplier to obtain the
# speckle-noisy image
speckle_noisy_image = image * noise_multiplier
```

The multiplication of the noise multiplier ensures that the variance of the speckle noise is proportional to the intensity of the image.

#### Results

We tested the algorithm by giving it an input image (shown below) and applying the Speckle Noise algorithm with a mean of .5 and a variance of 1. The results are shown below.

##### Input Image

![Input Image](Media/MINIRAT.jpeg)

##### Output Image

![Output Image](Media/output_speckle_noisy.jpg)

### Comments

For the 2419 × 1814 image, the algorithm took less than **0.1s** to execute. The algorithm was able to effectively add speckle noise to the input image.
