#include <stdio.h>
int main()
{
    int Array_1[2][2];
    int Array_2[2][2];
    int subtract[2][2];
    int i;
    int j;
    
    printf("Enter value of 1st matric  : \n");
    for (i=0; i<2; i++)
    {
        for (j=0; j<2; j++)
        {
            scanf("%d",& Array_1[i][j]);
        }
    }
    
    printf("Enter value of 2nd matric  : \n");
    for (i=0; i<2; i++)
    {
        for (j=0; j<2; j++)
        {
            scanf("%d",& Array_2[i][j]);
        }
    }
    printf("The Subtract  of two matric : \n");
    for (i=0; i<2; i++)
    {
        for (j=0; j<2; j++)
        {
            subtract[i][j]=Array_1[i][j]-Array_2[i][j];
            printf("%d\t",subtract[i][j]);
        }
        printf("\n");
        
    }
    return 0;
}

