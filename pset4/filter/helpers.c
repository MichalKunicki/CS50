#include "helpers.h"
#include <math.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int a = 0; a < height; a++)
    {
        for (int b = 0; b < width; b++)
        {
            RGBTRIPLE pixel = image[a][b];
            int average = round((pixel.rgbtRed + pixel.rgbtBlue + pixel.rgbtGreen) / 3.0);
            image[a][b].rgbtRed = image[a][b].rgbtBlue = image[a][b].rgbtGreen = average;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed;
    int sepiaGreen;
    int sepiaBlue;

    for (int a = 0; a < height; a++)
    {
        for (int b = 0; b < width; b++)
        {
            RGBTRIPLE pixel = image[a][b];

            sepiaRed = round(0.393 * pixel.rgbtRed + 0.769 * pixel.rgbtGreen + 0.189 * pixel.rgbtBlue);
            sepiaGreen = round(0.349 * pixel.rgbtRed + 0.686 * pixel.rgbtGreen + 0.168 * pixel.rgbtBlue);
            sepiaBlue = round(0.272 * pixel.rgbtRed + 0.534 * pixel.rgbtGreen + 0.131 * pixel.rgbtBlue);

            image[a][b].rgbtRed = sepiaRed > 255 ? 255 : sepiaRed;
            image[a][b].rgbtGreen = sepiaGreen > 255 ? 255 : sepiaGreen;
            image[a][b].rgbtBlue = sepiaBlue > 255 ? 255 : sepiaBlue;
       }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int a = 0; a < height; a++)
    {
        int currentPos = 0;
        for (int b = width -1; b >= 0; b--, currentPos++)
        {
            temp[a][currentPos] = image[a][b];
        }

    }

    for (int a = 0; a < height; a++)
    {
        for (int b = 0; b < width; b++)
        {
            image[a][b] = temp[a][b];
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE newImage[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            newImage[i][j] = image[i][j];
        }
    }

    for (int i = 0, red, green, blue, counter; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            red = green = blue = counter = 0;
            // add the center pixel
            if (i >= 0 && j >= 0)
            {
                red += newImage[i][j].rgbtRed;
                green += newImage[i][j].rgbtGreen;
                blue += newImage[i][j].rgbtBlue;
                counter++;
            }
            // add below pixel
            if (i >= 0 && j - 1 >= 0)
            {
                red += newImage[i][j-1].rgbtRed;
                green += newImage[i][j-1].rgbtGreen;
                blue += newImage[i][j-1].rgbtBlue;
                counter++;
            }
            // add right pixel
            if ((i >= 0 && j + 1 >= 0) && (i >= 0 && j + 1 < width))
            {
                red += newImage[i][j+1].rgbtRed;
                green += newImage[i][j+1].rgbtGreen;
                blue += newImage[i][j+1].rgbtBlue;
                counter++;
            }
            // add left pixel
            if (i - 1 >= 0 && j >= 0)
            {
                red += newImage[i-1][j].rgbtRed;
                green += newImage[i-1][j].rgbtGreen;
                blue += newImage[i-1][j].rgbtBlue;
                counter++;
            }
            // add left below pixel
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                red += newImage[i-1][j-1].rgbtRed;
                green += newImage[i-1][j-1].rgbtGreen;
                blue += newImage[i-1][j-1].rgbtBlue;
                counter++;
            }
            // add left upper pixel
            if ((i - 1 >= 0 && j + 1 >= 0) && (i - 1 >= 0 && j + 1 < width))
            {
                red += newImage[i-1][j+1].rgbtRed;
                green += newImage[i-1][j+1].rgbtGreen;
                blue += newImage[i-1][j+1].rgbtBlue;
                counter++;
            }
            // add upper pixel
            if ((i + 1 >= 0 && j >= 0) && (i + 1 < height && j >= 0))
            {
                red += newImage[i+1][j].rgbtRed;
                green += newImage[i+1][j].rgbtGreen;
                blue += newImage[i+1][j].rgbtBlue;
                counter++;
            }
            // add below right pixel
            if ((i + 1 >= 0 && j - 1 >= 0) && (i + 1 < height && j - 1 >= 0))
            {
                red += newImage[i+1][j-1].rgbtRed;
                green += newImage[i+1][j-1].rgbtGreen;
                blue += newImage[i+1][j-1].rgbtBlue;
                counter++;
            }
            // add upper right pixel
            if ((i + 1 >= 0 && j + 1 >= 0) && (i + 1 < height && j + 1 < width))
            {
                red += newImage[i+1][j+1].rgbtRed;
                green += newImage[i+1][j+1].rgbtGreen;
                blue += newImage[i+1][j+1].rgbtBlue;
                counter++;
            }

            image[i][j].rgbtRed = round(red / (counter * 1.0));
            image[i][j].rgbtGreen = round(green / (counter * 1.0));
            image[i][j].rgbtBlue = round(blue / (counter * 1.0));
        }
    }
    return;
}
