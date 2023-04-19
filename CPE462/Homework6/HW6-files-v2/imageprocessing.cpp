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

    // Perform histogram equalization using OpenCV
    Mat output_image;
    equalizeHist(input_image, output_image);

    // Display output image in a window using OpenCV
    namedWindow("Output Image", WINDOW_NORMAL);
    imshow("Output Image", output_image);
    waitKey(0);

    // Write output image to file using OpenCV
    imwrite(argv[2], output_image);

    return 0;
}
