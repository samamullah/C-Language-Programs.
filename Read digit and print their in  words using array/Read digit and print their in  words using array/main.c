#include <stdio.h>
int main()
{
    char *digits[]={"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int number;
    printf("Enter a digit : ");
    scanf("%d",&number);
    if (number>=0 && number<=9) {
        printf("In words :%s  ",digits[number]);
    }
    else
    {
        printf("Invalid input plese try again a digit between 0 to 9 ");
    }
    return 0;
}
    




