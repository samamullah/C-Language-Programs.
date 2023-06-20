#include <stdio.h>

int calculateSum(int n) {
    if (n == 0)
        return 0;
    
    return n + calculateSum(n - 1);
}

int main() {
    int n, sum;
    
    printf("Enter the value of n: ");
    scanf("%d", &n);
    
    sum = calculateSum(n);
    
    printf("The sum of numbers from 1 to %d is: %d\n", n, sum);
    
    return 0;
}

