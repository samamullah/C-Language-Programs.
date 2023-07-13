#include <stdio.h>
void swap_number(int *First_Number,int *Second_Number)
{
   int temp = *First_Number;
    *First_Number= *Second_Number;
    *Second_Number=temp;
}
int main()
{
    printf("Enetr first Number : ");
    int first_number;
    scanf("%d",&first_number);
    
    printf("Enetr second Number : ");
    int second_number;
    scanf("%d",&second_number);
    
    printf("After Swaping the first Number:%d and second number :%d",first_number,second_number);
    
    swap_number(&first_number,&second_number);
    
    printf("befour Swaping the first Number:%d and second number :%d",first_number,second_number);
    
    return 0;
}
