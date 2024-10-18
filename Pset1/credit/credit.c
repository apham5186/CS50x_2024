#include <cs50.h>
#include <stdio.h>

int findLength(long number);
bool ccIsValid(int ccLength, long number);
int main(void)
{
    // prompts user for a credit card number
    long number = get_long("Number: ");
    int ccLength = findLength(number);
    bool valid = ccIsValid(ccLength, number);
    // AMEX card validation
    if(valid && ccLength == 15)
    {
        for (int i  = 2; i < ccLength; i++)
        {
            number = number / 10;
        }
        if(number == 34 || number == 37)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    // Visa card validation
    else if(valid && ccLength == 13)
    {
        for (int i  = 1; i < ccLength; i++)
        {
            number = number / 10;
        }
        if(number == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    // Visa and Mastercard validation
     else if(valid && ccLength == 16)
    {
        long numberTemp = number;
        for (int i  = 1; i < ccLength; i++)
        {
            number = number / 10;
        }
        if(number == 4)
        {
            printf("VISA\n");
        }
        else if (number == 5)
        {
            for (int i = 2; i < ccLength; i++)
            {
                numberTemp = numberTemp / 10;
            }
               if (numberTemp == 51 || numberTemp == 52 || numberTemp == 53 || numberTemp == 54 || numberTemp == 55)
                {
                    printf("MASTERCARD\n");
                }
                else
                {
                    printf("INVALID\n");
                }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    //Card number is INVALID
    else
    {
        printf("INVALID\n");
    }
}

// Returns True if cc number is valid otherwise False.
bool ccIsValid(int ccLength, long number)
{
    int sum1 = 0;
    int sum2 = 0;
    for (int i  = 1; i <= ccLength; i++)
    {
        if(i % 2 != 0)
        {
            sum1 = sum1 + (number % 10);
            number = number / 10;
        }
        else
        {
            int multi = 2 * (number % 10);
            while (multi != 0)
            {
                sum2 = sum2 + (multi % 10);
                multi = multi / 10;
            }
            number = number / 10;
        }
    }
    int total = sum1 + sum2;
    if(total % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Function that finds the length of the credit card number.
int findLength(long number)
{
    int ccLength = 0;
    while (number != 0)
    {
    number = number / 10;
    ccLength++;
    }
    return ccLength;
}
