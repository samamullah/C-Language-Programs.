#include <stdio.h>
int main()
{
    
    printf("Enter a Character :  ");
    char Character;
    scanf("%c",&Character);
    
    if (Character=='A' || Character=='E' ||Character=='I' ||Character=='O' ||Character=='U' ||Character=='a' ||Character=='e' ||Character=='i' ||Character=='o' ||Character=='u' )
    {
        printf("The character is vowal ");
    }
    else
    {
        printf("The character is Consant ");
    }
    return 0;
}
    
