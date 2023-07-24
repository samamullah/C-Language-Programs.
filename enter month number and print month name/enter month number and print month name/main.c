#include <stdio.h>
int main()
{
    printf("Enter month number 1-12 : ");
    int month;
    scanf("%d",&month);
    
    if (month<1 || month>12)
    {
        printf("The month number is invalid! ");
        
    }
    else
    {
        switch (month) {
            case 1:
                printf("january");
                break;
            case 2:
                printf("febrary");
                break;
            case 3:
                printf("march");
                break;
            case 4:
                printf("Aprial");
                break;
            case 5:
                printf("may");
                break;
            case 6:
                printf("june");
                break;
            case 7:
                printf("july");
                break;
            case 8:
                printf("Augest");
                break;
            case 9:
                printf("september");
                break;
            case 10:
                printf("October");
                break;
            case 11:
                printf("nowember");
                break;
            case 12:
                printf("december");
                break;
                
            default:
                break;
        }
    }
}
