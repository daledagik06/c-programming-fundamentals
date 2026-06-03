#include <stdio.h>

int main()
{
    int matrix[10][10];
    int row, col, i, j;
    int sum = 0;

    printf("Enter number of rows: ");
    scanf("%d", &row);

    printf("Enter number of columns: ");
    scanf("%d", &col);

    if(row != col)
    {
        printf("\nMain diagonal is only for square matrix.\n");
        return 0;
    }

    printf("\nInput array elements:\n");

    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    for(i = 0; i < row; i++)
    {
        sum = sum + matrix[i][i];
    }
    
    printf("\n");
    for (i=0; i<row; i++)
        {
            for (j=0; j<col; j++) {
                if (i==j)
                    printf("%d + ", matrix[i][j]);
            }
        }
     printf("= %d\n", sum);
     
     for (i=0; i<row; i++) {
             for (j=0; j<col; j++) {
                 printf("%d ", matrix[i][j]);
             }
             printf("\n");
         }
    
    printf("\nSum of main diagonal elements = %d\n", sum);

    return 0;
}