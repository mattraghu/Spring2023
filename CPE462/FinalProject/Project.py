import numpy as np
from PIL import Image, ImageTk
import cv2
import tkinter as tk
from tkinter import filedialog
output_file = 'output'



def blur_image_cv2(image, ksize=5, sigma=1.0):
    # Apply Gaussian blur to the input image using cv2.GaussianBlur()
    blurred_image = cv2.GaussianBlur(image, (ksize, ksize), sigma)
    
    # Return the blurred image
    return blurred_image

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

# Function to apply a given kernel to an image
def apply_kernel(image, kernel):
    print(image.shape)
    # Get the dimensions of the input image
    height, width = image.shape
    
    # Determine the size of the kernel
    ksize = kernel.shape[0]
    
    # Calculate the padding size (half of the kernel size)
    pad_size = ksize // 2
    
    # Pad the input image with zeros around the border
    padded_image = np.pad(image, ((pad_size, pad_size), (pad_size, pad_size)), mode='constant')
    
    # Create an empty array to store the output image
    output = np.zeros_like(image)
    
    # Loop through the input image, applying the kernel at each pixel
    for i in range(height):
        for j in range(width):
            # Multiply the kernel with the corresponding region in the padded image, and sum the result
            output[i, j] = np.sum(padded_image[i:i+ksize, j:j+ksize] * kernel) # This is the same as convolving the kernel with the image. 
            
    
    # Return the output image
    return output

# Function to blur an image using a Gaussian kernel
def blur_image(image, ksize=5, sigma=1.0):
    # Create the Gaussian kernel with the given size and standard deviation
    kernel = create_gaussian_kernel(ksize, sigma)

    
    # Apply the kernel to the input image
    blurred_image = apply_kernel(image, kernel)
    
    # Return the blurred image
    return blurred_image

def apply_noise(image, noise_level):
    # Get the dimensions of the input image
    height, width = image.shape

    # Generate uniform random variables
    u = np.random.uniform(size=(height, width)) 
    #Transform the uniform variables into normal variables using the inverse transform method
    noise = np.sqrt(-2 * np.log(u)) * np.cos(2 * np.pi * u)
    # Scale the noise to the specified noise level
    noise *= noise_level

    # # Generate additive white noise with the specified noise level
    # noise = np.random.normal(0, noise_level, size=(height, width))
    
    # Add the noise to the input image
    noisy_image = image + noise
    
    # Clip the pixel values to ensure they are within the valid range of 0-255
    noisy_image = np.clip(noisy_image, 0, 255)
    
    # Convert the noisy image to an unsigned 8-bit integer
    noisy_image = noisy_image.astype(np.uint8)
    
    # Return the noisy image
    return noisy_image



def add_speckle_noise(image, mean=0.0, variance=0.01):
    # Compute the noise multiplier as a log-normal random variable
    # with the given mean and variance
    noise_multiplier = np.exp(np.random.normal(mean, np.sqrt(variance), size=image.shape))

    # Multiply the input image by the noise multiplier to obtain the
    # speckle-noisy image
    speckle_noisy_image = image * noise_multiplier

    # Clip the pixel values to the valid range [0, 255]
    speckle_noisy_image = np.clip(speckle_noisy_image, 0, 255)

    # Convert the speckle-noisy image to uint8 data type
    speckle_noisy_image = speckle_noisy_image.astype(np.uint8)

    return speckle_noisy_image


options = [
    {
        "name" : "Gaussian Blur",
        "function" : blur_image,
        "parameters" : ["ksize", "sigma"]
    },
    {
        "name" : "Gaussian Noise",
        "function" : apply_noise,
        "parameters" : ["noise_level"]
    },
    {
        "name" : "Speckle Noise",
        "function" : add_speckle_noise,
        "parameters" : ["mean", "variance"]
    }
]
class ImageProcessorApp(tk.Tk):
    def __init__(self):
        super().__init__()

        self.title("Image Processor App")

        # Create the input image frame
        input_frame = tk.Frame(self)
        input_frame.pack(side=tk.LEFT, padx=10, pady=10, anchor='n')

        # Create the input image label
        self.input_label = tk.Label(input_frame, text="Input Image")
        self.input_label.pack(pady=5)

        # Create the load image button
        load_image_button = tk.Button(input_frame, text="Load Image", command=self.load_input_image)
        load_image_button.pack(pady=5)

        # Create the input image canvas
        self.input_canvas = tk.Canvas(input_frame, width=256, height=256)
        self.input_canvas.pack()

        # Create the output image frame
        output_frame = tk.Frame(self)
        output_frame.pack(side=tk.LEFT, padx=10, pady=10, anchor='n')

        # Create the output image label
        self.output_label = tk.Label(output_frame, text="Output Image")
        self.output_label.pack(pady=5)

        # Add an empty label with the same pady value as the "Load Image" button
        tk.Label(output_frame, text="").pack(pady=8)


        # Create the output image canvas
        self.output_canvas = tk.Canvas(output_frame, width=256, height=256)
        self.output_canvas.pack()

        # Create the options frame
        options_frame = tk.Frame(self)
        options_frame.pack(side=tk.LEFT, padx=10, pady=10)

        # Create the options label
        options_label = tk.Label(options_frame, text="Options")
        options_label.pack()

        # Create the options menu
        self.options_var = tk.StringVar()
        # self.options_var.set(options[0]["name"])
        self.options_menu = tk.OptionMenu(options_frame, self.options_var, * [option["name"] for option in options], command=self.update_parameters)
        self.options_menu.pack(pady=5)



        # Create the parameters frame
        self.parameters_frame = tk.Frame(options_frame)
        self.parameters_frame.pack()

        
        # Create the process button
        process_button = tk.Button(self, text="Process", command=self.process_image)
        process_button.pack(pady=10)

        # Set the minimum size of the window
        self.minsize(800, 400)

        # Initialize the input and output images
        self.input_image = None
        self.output_image = None

    def create_parameter_entries(self, parameter_names):
        # Create the parameters labels and entry fields
        self.parameter_entries = {}
        for parameter_name in parameter_names:
            parameter_label = tk.Label(self.parameters_frame, text=parameter_name.capitalize())
            parameter_label.pack(pady=5)
            parameter_entry = tk.Entry(self.parameters_frame)
            parameter_entry.pack()
            self.parameter_entries[parameter_name] = parameter_entry

    def update_parameters(self, selected_option_name):

        print("Selected option: ", selected_option_name)
        # Find the selected option in the options list
        selected_option = next((option for option in options if option["name"] == selected_option_name), None)

        if selected_option:
            # Remove the existing parameter entries
            for child in self.parameters_frame.winfo_children():
                child.destroy()

            # Create the new parameter entries based on the selected option
            self.create_parameter_entries(selected_option["parameters"])
        else:
            print("Selected option not found in options list")

        

    def load_input_image(self):
        # Ask the user to select an image file
        file_path = filedialog.askopenfilename()

        if file_path:
            # Load the image using PIL and convert it to grayscale
            pil_image = Image.open(file_path).convert("L")

            # Convert the PIL image to a NumPy array
            np_image = np.array(pil_image)

            # Store the NumPy array as the input image
            self.input_image = np_image

            # Resize the input image to fit in the input canvas
            resized_image = pil_image.resize((256, 256), Image.ANTIALIAS)

            # Convert the resized image to a PhotoImage object and display it in the input canvas
            self.input_photo_image = ImageTk.PhotoImage(resized_image)
            self.input_canvas.create_image(0, 0, anchor=tk.NW, image=self.input_photo_image)
            
    def process_image(self):
        # Get the selected option
        selected_option_name = self.options_var.get()

        # Find the selected option in the options list
        selected_option = next((option for option in options if option["name"] == selected_option_name), None)

        if selected_option:
            # Get the parameter values from the entry fields
            parameter_values = {}
            for parameter_name in selected_option["parameters"]:
                parameter_entry = self.parameter_entries[parameter_name]
                parameter_value = parameter_entry.get()

                # Try to convert the parameter value to a float
                try:
                    parameter_value = float(parameter_value)
                except ValueError:
                    # If the parameter value cannot be converted to a float, set it to zero
                    parameter_value = 0.0

                parameter_values[parameter_name] = parameter_value

            # Apply the selected option to the input image
            output_image = selected_option["function"](self.input_image, **parameter_values)

            # Store the output image
            self.output_image = output_image

            # Convert the output image to a PIL image
            output_pil_image = Image.fromarray(output_image)

            # Resize the output image to fit in the output canvas
            resized_image = output_pil_image.resize((256, 256), Image.ANTIALIAS)

            # Convert the resized image to a PhotoImage object and display it in the output canvas
            self.output_photo_image = ImageTk.PhotoImage(resized_image)
            self.output_canvas.create_image(0, 0, anchor=tk.NW, image=self.output_photo_image)
        else:
            print("Selected option not found in options list")



# Create an instance of the ImageProcessorApp class
app = ImageProcessorApp()

# Start the GUI event loop
app.mainloop()

