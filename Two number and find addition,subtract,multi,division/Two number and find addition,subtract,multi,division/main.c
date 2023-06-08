#include <stdio.h>
int main()
{
    printf("Enter first number : ");
    int first_number;
    scanf("%d",&first_number);
    printf("Enter second number : ");
    int Second_number;
    scanf("%d",&Second_number);
    
    // for addition.
    int addition;
    addition=first_number+Second_number;
    printf("The sum of two number is %d \n",addition);
    
    // for subtraction.
    int subtraction;
    subtraction=first_number-Second_number;
    printf("The subtract of two number is %d \n",subtraction);
    
    // for division.
    int division;
    division=first_number/Second_number;
    printf("The division of two number is %d \n ",division);
    
    // for multiplication.
    int multi;
    multi=first_number*Second_number;
    printf("The multiplication of two number is %d \n",multi);
    
    return 0;
}
