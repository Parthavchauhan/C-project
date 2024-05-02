#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include<string.h>
#include <stdlib.h>
int binaryTodecimal(int num);
void decimalTobinary(int size, int binary[size], int orignal_num1);
void decimalTooctal(int size, int octal[size], int orignal_num2);
void binaryTohexadecimal(int num4, int decimal, int temp, int size, char answer[size + 1]);
int octalTodecimal(int num5);
void hexadecimalTodecimal(char hexadecimal[100], int size, int hexadecimal_orig[size]);
int main()
{
    system("color E0");   //E for light yellow and 0 black of font;
    printf("\n\n\t\t\t***Welcome to Base Converter Calculator***\n\n");
    int select;
    // Project of c!
    
    while (1)
    {
        label1:

        printf("-> Enter the Number to select the base conversion\n\n");
        printf("1.) Decimal to Binary\t\t2.) Binary to decimal\t\t3.)Decimal to Octal\n");
        printf("4.) Binary to Hexadecimal\t5.) Octal to Decimal\t\t6.)Hexadecimal to Binary\n");
        printf("\t\t\t\t7.)Exit\n\n");

        printf("-->Enter Your Choice: ");
        scanf("%d", &select);

        if (select >= 1 && select <= 6)
        {
            break; // Breaking the While Loop;
        }
        else if (select == 7)
        {
            printf("\n\t\t\t***Thank's for using our calculator***\n");
            return 0;
        }
        else
        {
            printf("\n\t\t\tInvalid Input.\n\n");
        }
    }

    int num1, num2, num3, num4, num5, num6, ans1, ans2, ans3, ans4, ans5, ans6;

    if (select == 1)
    {
        // int num1;
        system("cls");
        printf("Enter the decimal number: ");
        scanf("%d", &num1);
        int origanl_num1 = num1;
        int size = 0;
        while (num1 != 0)
        {
            num1 = num1 / 2;
            size++;
        }
        int binary[size];

        decimalTobinary(size, binary, origanl_num1);

        printf("--------------\n");
        printf("[%d] to binary = ", origanl_num1);
        for (int i = size - 1; i >= 0; i--)
        {
            printf("%d", binary[i]);
        }
        printf("\n--------------\n");
        printf("\n\n");

        goto label1;
    }
    else if (select == 2)
    {
        num2;
        system("cls");
        printf("Enter the Binary number: ");
        scanf("%d", &num2);
        ans2 = binaryTodecimal(num2);
        printf("----------------------\n");
        printf("[%d] to Decimal = %d\n", num2, ans2);
        printf("----------------------\n\n");
        goto label1;
    }
    else if (select == 3)
    {
        int num3;
        system("cls");
        printf("Enter the Decimal Number: ");
        scanf("%d", &num3);
        int orignal_num2 = num3;
        int size = 0;
        while (num3 != 0)
        {
            num3 = num3 / 8;
            size++;
        }
        int octal[size];
        decimalTooctal(size, octal, orignal_num2);
        printf("--------------\n");
        printf("[%d] to octal is = ", orignal_num2);
        for (int i = size - 1; i >= 0; i--)
        {
            printf("%d", octal[i]);
        }
        printf("\n--------------\n");
        goto label1;
    }
    else if (select == 4)
    {
        num4;
        system("cls");
        printf("Enter the binary number: ");
        scanf("%d", &num4);

        int decimal = binaryTodecimal(num4);
        int temp = decimal;
        int orignal_num4 = decimal;

        int size = 0;
        while (orignal_num4 != 0)
        {
            orignal_num4 = orignal_num4 / 16;
            size++;
        }

        char answer[size + 1];

        binaryTohexadecimal(num4, decimal, temp, size, answer);
        printf("--------------\n");
        printf("[%d] to Hexadecimal is = ", num4);
        for (int i = size - 1; i >= 0; i--)
        {
            printf("%c", answer[i]);
        }
        printf("\n--------------\n");

        goto label1;
    }
    else if (select == 5)
    {
        num5;
        system("cls");
        printf("Enter the Octal number: ");
        scanf("%d", &num5);

        int temp = num5;
        ans4 = octalTodecimal(num5);
        printf("--------------\n");
        printf("[%d] to decimal is = %d", temp, ans4);
        printf("\n--------------\n");

        goto label1;
    }
    else if (select == 6)
    {
        char hexadecimal[100];
        system("cls");
        printf("Enter the hexadecimal number: ");
        scanf("%s", hexadecimal);

        int i = 0, size = 0;
        while (hexadecimal[i] != '\0')
        {
            size++;
            i++;
        }

        int hexadecimal_orig[size];

        hexadecimalTodecimal(hexadecimal, size, hexadecimal_orig);

        goto label1;
    }

    return 0;
}

int binaryTodecimal(int num)
{
    // Binary to Decimal;
    int digit;

    int temp1 = num;
    // ------------------------------------------->(Checking that input is correct or not!)
    while (num != 0)
    {
        digit = num % 10;
        num = num / 10;
        if (digit < 0 || digit > 1)
        {
            printf("Invalid input..Please Try Again!\n");
            return 0;
        }
    }

    digit = 0;
    // ------------------------------------------->(Done)

    // ------------------------------------------->(Converting Binary to Deciml\n);
    int i = 0, sum = 0;
    while (temp1 != 0)
    {
        digit = temp1 % 10;
        temp1 = temp1 / 10;

        sum = sum + (digit * pow(2, i));
        i++;
    }

    return sum;

    // ------------------------------------------>(Done\n);
}

// Converting Decimal to Binary
void decimalTobinary(int size, int binary[size], int orignal_num1)
{
    int i = 0;
    while (orignal_num1 != 0)
    {
        binary[i] = orignal_num1 % 2;
        orignal_num1 = orignal_num1 / 2;
        i++;
    }
}

// Converting Decimal to octal
void decimalTooctal(int size, int octal[size], int orignal_num2)
{
    int i = 0;
    while (orignal_num2 != 0)
    {
        octal[i] = orignal_num2 % 8;
        orignal_num2 = orignal_num2 / 8;
        i++;
    }
}

// Converting binary to hexadecimal;
void binaryTohexadecimal(int num4, int decimal, int temp, int size, char answer[size + 1])
{
    int i = 0, digit;
    while (temp != 0)
    {
        digit = temp % 16;
        if (digit == 10)
        {
            answer[i] = 'A';
        }
        else if (digit == 11)
        {
            answer[i] = 'B';
        }
        else if (digit == 12)
        {
            answer[i] = 'C';
        }
        else if (digit == 13)
        {
            answer[i] = 'D';
        }
        else if (digit == 14)
        {
            answer[i] = 'E';
        }
        else if (digit == 15)
        {
            answer[i] = 'F';
        }
        else
        {
            answer[i] = '0' + digit;
        }
        temp = temp / 16;
        i++;
    }

    answer[size] = '\0';
}

// Converting Octal to decimal;
int octalTodecimal(int num5)
{
    int sum = 0, i = 0;
    while (num5 != 0)
    {
        int digit = num5 % 10;
        sum = sum + (digit * pow(8, i));
        num5 = num5 / 10;
        i++;
    }

    return sum;
}

// Converting hexadecimal to binary;
void hexadecimalTodecimal(char hexadecimal[100], int size, int hexadecimal_orig[size])
{
    char toprint[100];
    strcpy(toprint,hexadecimal);
    int j = 0;
    while (hexadecimal[j] != '\0')
    {
        int digit = hexadecimal[j];
        if (digit == 'A')
        {
            hexadecimal_orig[j] = 10;
        }
        else if (digit == 'B')
        {
            hexadecimal_orig[j] = 11;
        }
        else if (digit == 'C')
        {
            hexadecimal_orig[j] = 12;
        }
        else if (digit == 'D')
        {
            hexadecimal_orig[j] = 13;
        }
        else if (digit == 'E')
        {
            hexadecimal_orig[j] = 14;
        }
        else if (digit == 'F')
        {
            hexadecimal_orig[j] = 15;
        }
        else
        {
            hexadecimal_orig[j] = digit - '0';
        }
        j++;
    }

    int sum = 0, k = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        sum = sum + (hexadecimal_orig[i] * pow(16, k)); // Now we have sum od decimal and now we will create the decimal to binary !
        k++;
    }

    int binary_size = 0;
    int orignal_num6 = sum;

    while (sum != 0)
    {
        sum = sum / 2;
        binary_size++; // Calculating the size of binary number which we have to create;
    }

    int padding = binary_size % 4; // Calculate the padding to add zero in front that how many zeros will be added;

    int size_of_binary = binary_size + padding;

    int binary[size_of_binary];

    for (int i = 0; i < padding; i++)
    {
        binary[i] = 0; // Aading zero's at the position of padding;
    }

    // Converting into binary;
    for (int i = size_of_binary; i >= padding; i--)
    {
        int check = orignal_num6 % 2;
        binary[i] = check; // Hence converted into binary;
        orignal_num6 = orignal_num6 / 2;
    }

    printf("--------------\n");
    printf("[%s] to Hexadecimal is = ", toprint);
    for (int i = 0; i < size_of_binary; i++)
    {
        printf("%d", binary[i]);
    }
    printf("\n--------------\n");
}
