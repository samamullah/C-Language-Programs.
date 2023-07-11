#include <stdio.h>

int main() {
    const char *months[] = {
        "Invalid Month",
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    
    int month_Number;
    
    printf("Enter a month number (1-12): ");
    scanf("%d", &month_Number);
    
    if (month_Number >= 1 && month_Number <= 12) {
        printf("Month Name is : %s\n", months[month_Number]);
    } else {
        printf("Invalid  the month number!\n");
    }
    
    return 0;
}

