#include <stdio.h>

int main() {
    char character;
    
    printf("Enter a character: ");
    scanf("%c", &character);
    
    // Type-cast the character to an integer to get its ASCII value
    int asciiValue = (int)character;
    
    printf("ASCII value of '%c' is %d\n", character, asciiValue);
    
    return 0;
}

