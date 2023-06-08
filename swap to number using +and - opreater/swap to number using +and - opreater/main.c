#include <stdio.h>
int main()
{
    printf("Enter first number : ");
    int first_number;
    scanf("%d",&first_number);
    printf("Enter second number : ");
    int Second_number;
    scanf("%d",&Second_number);
    
    
    printf("Befour swaping First_number :%d \n",first_number);
    printf("Befour swaping Second_number :%d \n",Second_number);
    
    first_number=first_number-Second_number;
    Second_number=Second_number+first_number;
    first_number=Second_number-first_number;
    
    printf("After swaping First_number :%d \n",first_number);
    printf("After swaping Second_number :%d \n",Second_number);
    
    return 0;
}
