#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
int fileisaJPEG(unsigned char bytes[]);

int main(int argc, char *argv[])
{

    // Check for invalid usage
    if (argc != 2)
    {
        printf("Usage: ./recover [forensic image name]\n");
        return 1;
    }

    // Open input file
    FILE *input = fopen(argv[1], "r");

    if (input == NULL)
    {
        printf ("Could not open file\n");
        return 1;
    }

    FILE *output;
    char filename[8];
    int jpegCount = 0;
    unsigned char bytes[512];
    int jpgFound = 0;

    while (fread(bytes, 512, 1, input) != 0)
    {

        //Use checker function on the files
        if (fileisaJPEG(bytes) == 1)
        {
            if (jpgFound == 1)
            {
                fclose(output);
            }
            else
            {
                jpgFound = 1;
            }
            //Add a name to the file
            sprintf(filename, "%03d.jpg", jpegCount);

            output = fopen(filename, "a");

            jpegCount++;
        }
        if (jpgFound == 1)
        {
            //Write to the file
            fwrite(&bytes, 512, 1, output);
        }
    }
    //Close everything
    fclose(output);
    fclose(input);
}

//Function checking if a file is JPG
int fileisaJPEG(unsigned char bytes[])
{
    if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff && (bytes[3] & 0xf0) == 0xe0)
    {
        return 1;
    }
    return 0;
}
