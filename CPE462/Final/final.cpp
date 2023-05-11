#include <stdio.h>

int main()
{
    int x[6][6] = {
        {0, 0, 1, 1, 1, 0},
        {0, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 0},
        {1, 1, 1, 1, 0, 0}};

    int g_1[2][2] = {
        {0, 1},
        {-1, 0}};
    int g_2[2][2] = {
        {0, -1},
        {1, 0}};

    int x_width = 6;
    int x_height = 6;
    int g_width = 2;
    int g_height = 2;

    int result[x_height][x_width];

    // Flip g twice
    int g_flipped[g_height][g_width];
    for (int i = 0; i < g_height; i++)
    {
        for (int j = 0; j < g_width; j++)
        {
            g_flipped[i][j] = g_1[g_height - 1 - i][g_width - 1 - j];
        }
    }

    // Slide g across x to calculate the convolution
    for (int i = 0; i < x_height; i++)
    {
        for (int j = 0; j < x_width; j++)
        {
            int sum = 0;
            for (int k = 0; k < g_height; k++)
            {
                for (int l = 0; l < g_width; l++)
                {
                    int x_val = i + k - (g_height - 1);
                    int y_val = j + l - (g_width - 1);
                    if (x_val >= 0 && x_val < x_height && y_val >= 0 && y_val < x_width)
                    {
                        sum += x[x_val][y_val] * g_flipped[k][l];
                    }
                }
            }
            result[i][j] = sum;
        }
    }

    // Print the result of the convolution
    printf("Result of Convolution:\n");
    for (int i = 0; i < x_height; i++)
    {
        for (int j = 0; j < x_width; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
