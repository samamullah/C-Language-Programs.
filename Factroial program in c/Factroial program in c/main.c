#include <stdio.h>

int main() {
    int number;
    unsigned long long factorial = 1;
    
    printf("Enter a non-negative integer: ");
    scanf("%d", &number);
    
    // Check for negative input number 
    if (number < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        // Calculate the factorial number
        for (int i = 1; i <= number; i++) {
            factorial *= i;
        }
        
        printf("Factorial of %d is %llu\n", number, factorial);
    }
    
    return 0;
}

