#include <stdio.h>

// Function to calculate the GPA
float calculateGPA(int totalCredits, int* credits, int* grades) {
    float totalGradePoints = 0;
    float totalCreditsEarned = 0;
    
    for (int i = 0; i < totalCredits; i++) {
        totalGradePoints += credits[i] * grades[i];
        totalCreditsEarned += credits[i];
    }
    
    return totalGradePoints / totalCreditsEarned;
}

int main() {
    int totalCredits;
    printf("Enter the total number of courses: ");
    scanf("%d", &totalCredits);
    
    int credits[totalCredits];
    int grades[totalCredits];
    
    // Input the credits and grades for each course
    for (int i = 0; i < totalCredits; i++) {
        printf("Enter credits for course %d: ", i + 1);
        scanf("%d", &credits[i]);
        printf("Enter grade for course %d (0-100): ", i + 1);
        scanf("%d", &grades[i]);
    }
    
    float gpa = calculateGPA(totalCredits, credits, grades);
    printf("Your GPA is: %.2f\n", gpa);
    
    return 0;
}

