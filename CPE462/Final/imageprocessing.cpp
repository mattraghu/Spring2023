/**********************************************************************************
 * imageproc.c
 * Usage: imageproc in_file_name out_file_name width height
 **********************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *in, *out;
	int j, k, width, height;
	int **image_in, **image_out;

	if (argc < 5)
	{
		printf("ERROR: Insufficient parameters!\n");
		return 1;
	}

	width = atoi(argv[3]);
	height = atoi(argv[4]);

	image_in = (int **)calloc(height, sizeof(int *));
	if (!image_in)
	{
		printf("Error: Can't allocate memory!\n");
		return 1;
	}

	image_out = (int **)calloc(height, sizeof(int *));
	if (!image_out)
	{
		printf("Error: Can't allocate memory!\n");
		return 1;
	}

	for (j = 0; j < height; j++)
	{
		image_in[j] = (int *)calloc(width, sizeof(int));
		if (!image_in[j])
		{
			printf("Error: Can't allocate memory!\n");
			return 1;
		}

		image_out[j] = (int *)calloc(width, sizeof(int));
		if (!image_out[j])
		{
			printf("Error: Can't allocate memory!\n");
			return 1;
		}
	}

	if (!(in = fopen(argv[1], "rb")))
	{
		printf("ERROR: Can't open in_file!\n");
		return 1;
	}

	if (!(out = fopen(argv[2], "wb")))
	{
		printf("ERROR: Can't open out_file!\n");
		return 1;
	}

	for (j = 0; j < height; j++)
	{
		for (k = 0; k < width; k++)
		{
			if ((image_in[j][k] = getc(in)) == EOF)
			{
				printf("ERROR: Can't read from in_file!\n");
				return 1;
			}
		}
	}

	if (fclose(in) == EOF)
	{
		printf("ERROR: Can't close in_file!\n");
		return 1;
	}

	/********************************************************************/
	/* Image Processing begins                                          */
	/********************************************************************/

	int foreground_sum = 0;
	int foreground_count = 0;
	int background_sum = 0;
	int background_count = 0;
	int threshold = 128;
	int new_threshold;
	int epsilon = 1;

	while (1)
	{
		// Reset the foreground and background variables
		foreground_sum = 0;
		foreground_count = 0;
		background_sum = 0;
		background_count = 0;

		// Compute the mean gray values of the foreground and background classes
		for (j = 0; j < height; j++)
		{
			for (k = 0; k < width; k++)
			{
				if (image_in[j][k] > threshold)
				{
					foreground_sum += image_in[j][k];
					foreground_count++;
				}
				else
				{
					background_sum += image_in[j][k];
					background_count++;
				}
			}
		}

		// Compute a new threshold value
		foreground_sum /= foreground_count;
		background_sum /= background_count;
		new_threshold = (foreground_sum + background_sum) / 2;

		// Check if the difference between the old and new threshold values is less than epsilon
		if (abs(new_threshold - threshold) < epsilon)
		{
			break;
		}

		threshold = new_threshold;
	}

	printf("Final threshold: %d\n", threshold);

	// Threshold the image based on the final threshold value
	for (j = 0; j < height; j++)
	{
		for (k = 0; k < width; k++)
		{
			if (image_in[j][k] > threshold)
			{
				image_out[j][k] = 255;
			}
			else
			{
				image_out[j][k] = 0;
			}
		}
	}

	/********************************************************************/

	/* save image_out into out_file in RAW format */
	for (j = 0; j < height; j++)
	{
		for (k = 0; k < width; k++)
		{
			if (putc(image_out[j][k], out) == EOF)
			{
				printf("ERROR: Can't write to out_file!\n");
				return 1;
			}
		}
	}

	if (fclose(out) == EOF)
	{
		printf("ERROR: Can't close out_file!\n");
		return 1;
	}

	for (j = 0; j < height; j++)
	{
		free(image_in[j]);
		free(image_out[j]);
	}
	free(image_in);
	free(image_out);

	return 0;
}
