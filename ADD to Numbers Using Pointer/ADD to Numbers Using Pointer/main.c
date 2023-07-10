#include <stdio.h>

void addNumbers(int *a, int *b, int *result) {
    *result = *a + *b;
}

int main() {
    int num1, num2, sum;
    
    printf("Enter first number: ");
    scanf("%d", &num1);
    
    printf("Enter second number: ");
    scanf("%d", &num2);
    
    addNumbers(&num1, &num2, &sum);
    
    printf("The Sum is : %d\n", sum);
    
    return 0;
}
