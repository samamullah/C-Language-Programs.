#include <stdio.h>

int* sumNumbers(int Number_1, int Number_2) {
    int sum = Number_1 + Number_2;
    int* pointer = &sum;
    return pointer;
}

int main() {
    int num1, num2;
    
    printf("Enter the first number: ");
    scanf("%d", &num1);
    
    printf("Enter the second number: ");
    scanf("%d", &num2);
    
    int* sumPtr = sumNumbers(num1, num2);
    
    printf("Sum: %d\n", *sumPtr);
    
    return 0;
}

