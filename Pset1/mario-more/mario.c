#include <cs50.h>
#include <stdio.h>
void pyramid(int height);

int main(void)
{
  // Ask user for Height Value won't proceed untill value is between 1 and 8
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    pyramid(height);
}

// Function that takes height value and prints the blocks into a pyramid format
void pyramid(int height)
{
    for (int row = 0; row < height; row++)
    {
        for (int space = 0; space < height - row - 1; space++)
        {
            printf(" ");
        }
        for (int column = 0; column <= row; column++)
        {
            printf("#");
        }
        printf("  ");
        for (int column = 0; column <= row; column++)
        {
            printf("#");
        }
        printf("\n");
    }
}
