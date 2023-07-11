#include <stdio.h>

  void multiplymatrices(int n,int matric_1[][n],int matric_2[][n],int result[][n])
    {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                result[i][j]=0;
                for (int k=0; k<n; k++) {
                    result[i][j]+= matric_1[i][k]*matric_2[k][j];
                }
            }
        }
    }
void displaymatric(int n,int matric[][n])
{
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("%d   ",matric[i][j]);
        }
        printf("\n");
    }
}

int main()
{

    printf("Enter the size of the matric : ");
    int numner;
    scanf("%d",&numner);
    int n = 0;
    int matric_1[n][n],matric_2[n][n],result[n][n];
    printf("Enter the first matric elements : ");
    for (int i=0; i<numner; i++) {
        for (int j=0; j<numner; j++) {
            scanf("%d",&matric_1[i][j]);
        }
    }
    printf("Enter the second matric elements : ");
    for (int i=0; i<numner; i++) {
        for (int j=0; j<numner; j++) {
            scanf("%d",&matric_2[i][j]);
        }
    }
    multiplymatrices(numner, matric_1, matric_2, result);
    printf("result matric after multiply : ");
    displaymatric(numner, result);
    
}
