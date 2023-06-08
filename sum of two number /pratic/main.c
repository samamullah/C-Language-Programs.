#include <stdio.h>
int main()
{
    printf("Enter first number : "); // first we are print a first number.
    int Number_one;
    scanf("%d",&Number_one);    // user enter a number.
    printf("Enter second number : "); // we are print a second number .
    int Number_two;
    scanf("%d",&Number_two);  // user enter a second number.
    int Sum;
    Sum =Number_one+Number_two; // sum of tow number.
    
    printf("first number %d and second number %d = sum of two number =%d",Number_one,Number_two,Sum);
    return 0;
}
