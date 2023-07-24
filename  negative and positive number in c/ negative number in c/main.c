#include <stdio.h>
int main()
{
    printf("Enter a number Positive / Negative :  ");
    int Number;
    scanf("%d",&Number);
    
    if (Number>0)
    {
        printf("The number is positive : %d",Number);
    }
    else if(Number<0)
    {
        printf("The number is Negative : %d",Number);
    }
    else
    {
        printf("The number is ZER0 ");
    }
    return 0;
    }

