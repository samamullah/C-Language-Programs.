#include <stdio.h>
int main()
{
    printf("Enter first Number : ");
    int First_number;
    scanf("%d",&First_number);
    printf("Enter second number : ");
    int second_number;
    scanf("%d",&second_number);
    if (First_number>second_number)
    {
        printf("First number is greater than second number ");
    }
    else
    {
        printf("Second number is greater then first number ");
    }
    return 0;
}
