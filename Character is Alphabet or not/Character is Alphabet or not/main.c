#include <stdio.h>
int main()
{
    
    printf("Enter a Alphabet : ");
    char Alphabet;
    scanf("%c",&Alphabet);
    
    if (Alphabet>='A' || Alphabet<='Z' || Alphabet>='a' || Alphabet<='z')
    {
        printf("%c is Alphabet",Alphabet);
        
    }
    else
    {
        printf("%c is not Alphabet",Alphabet);
    }
    
    return 0;
    
}
