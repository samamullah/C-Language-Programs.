#include <stdio.h>
#include <string.h>
int stringlength(char * string)
{
    int length_of_string =0;
    while (string[length_of_string] !='\0')
           {
               length_of_string++;
    }
           return length_of_string;
}
int main()
{
    char string[50];
    printf("Enetr a string : ");
    scanf("%s",string);
    int length = stringlength(string);
    printf("Lenght of string :%d\n ",length);
    return 0;
}


