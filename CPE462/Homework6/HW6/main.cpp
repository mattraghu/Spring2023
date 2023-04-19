#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        cout << "Usage: imageprocessing input_file output_file" << endl;
        return -1;
    }

    // Read input image using OpenCV
    Mat input_image = imread(argv[1], IMREAD_GRAYSCALE);
    if (input_image.empty())
    {
        cout << "Error: Can't read input image!" << endl;
        return -1;
    }

    // // Apply thresholding operator using OpenCV
    // Mat output_image;
    // threshold(input_image, output_image, 128, 255, THRESH_BINARY);

    // // Perform histogram equalization using OpenCV
    // Mat output_image;
    // equalizeHist(input_image, output_image);

    // Define 3x3 mask
    Mat kernel = (Mat_<float>(3, 3) << -1, -1, -1, -1, 9, -1, -1, -1, -1);

    // Apply mask to input image using OpenCV
    Mat output_image;
    filter2D(input_image, output_image, -1, kernel);

    // Display output image in a window using OpenCV
    namedWindow("Output Image", WINDOW_NORMAL);
    imshow("Output Image", output_image);
    waitKey(0);

    // Write output image to file using OpenCV
    imwrite(argv[2], output_image);

    // Also write the grayscale original image to another file
    imwrite("original.jpeg", input_image);

    return 0;
}
