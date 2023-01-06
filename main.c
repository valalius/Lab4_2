#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printmatrix (int **A, int **B, int row, int col);
int maxmin (int **A, int row, int max, int min);
int transposition (int **B, int row, int col, int **T);
int multiply (int **A, int **B, int row, int col, int **C);
int sort (int **A, int row);
int summ (int **A, int **B, int row, int col, int sumA, int sumB);

// T=transponated, C=multiplied

int main()
{
    int choice_fill, choice_task;
    int row;
    int col;
    int max, min, sortA, sumA, sumB;
    srand(time(NULL));

    printf(" A is square, B is rectangular");
    printf("\n Enter the desired number of rows and columns in A and rows in B\n\t ");
    scanf (" %d", &row);
    printf("\n Enter the desired number of columns in B\n\t ");
    scanf (" %d", &col);
    printf("\n Choose how to fill the matrix");
    printf("\n 1: manually\t2: randomly \t3: mathematically\n\t");
    while (choice_fill!=1 && choice_fill!=2 && choice_fill!=3)
    {
        scanf (" %d", &choice_fill);
    }

    int **A = (int **)malloc(sizeof(int *)* row);
    for (int i=0; i<row; i++)
    {
        A[i]=(int *)malloc(sizeof(int)*row);
    }
    int **B = (int **)malloc(sizeof(int *)* row);
    for (int i=0; i<row; i++)
    {
        B[i]=(int *)malloc(sizeof(int)*col);
    }
    int **C = (int **)malloc(sizeof(int *)* row);
    for (int i=0; i<row; i++)
    {
        C[i]=(int *)malloc(sizeof(int)*col);
    }
    int **T = (int **)malloc(sizeof(int *)* col);
    for (int i=0; i<col; i++)
    {
        T[i]=(int *)malloc(sizeof(int)*row);
    }

    if (choice_fill==1)
    {
        for(int i=0; i<row; i++)
            {
                for(int j=0;j<row;j++)
                    {
                        printf("Enter value for A[%d][%d]: ", i, j);
                        scanf("%d", &A[i][j]);
                    }
            }
        for(int i=0; i<row; i++)
            {
                for(int j=0;j<col;j++)
                    {
                        printf("Enter value for B[%d][%d]: ", i, j);
                        scanf("%d", &A[i][j]);
                    }
            }
    }
    else if (choice_fill==2)
    {
        for (int i=0;i<row;i++)
        {
            for (int j=0;j<row;j++)
            {
                A[i][j]= rand()%27;
            }
        }
        for (int i=0;i<row;i++)
        {
            for (int j=0;j<col;j++)
            {
                B[i][j]= rand()%27;
            }
        }
    }
    else
    {
        for (int i=0;i<row;i++)
        {
            for (int j=0;j<row;j++)
            {
                A[i][j]= 2+i-j;
            }
        }
        for (int i=0;i<row;i++)
        {
            for (int j=0;j<col;j++)
            {
                B[i][j]= 2+i-j;
            }
        }
    }
    system("cls");
    printmatrix (A, B, row, col);

    printf(" What do you want to do with this(-ese) matrix(-es)?");
    printf("\n 1: Search for the MAX and MIN of A");
    printf("\n 2: Transponate B");
    printf("\n 3: Multiply the A by B");
    printf("\n 4: Sort A in ascending");
    printf("\n 5: Sum of the rows of A and columns of B\n\t");
    do
    {
        scanf (" %d", &choice_task);
    }while (choice_task!=1 && choice_task!=2 && choice_task!=3 && choice_task!=4 && choice_task!=5);

   switch (choice_task){
    case 1:
        maxmin (A, row, max, min);
        break;

    case 2:
        transposition (B, row, col, T);
        break;

    case 3:
        multiply (A, B, row, col, C);
        break;

    case 4:
        sort (A, row);
        break;

    case 5:
        summ (A, B, row, col, sumA, sumB);
        break;
    }
for (int i=0;i<row;i++)
    {
        free(A[i]);
    }
    free(A);
    for(int i=0;i<col;i++)
    {
        free(B[i]);
        free(C[i]);
        free(T[i]);
    }
    free(B);
    free(C);
    free(T);
    return 0;
}

void printmatrix (int **A, int **B, int row, int col)
{
    for(int i=0; i<row; i++)
        {
            for(int j=0;j<row;j++)
                {
                    printf("%3d ", A[i][j]);
                }
            printf("\n");
        }
    printf("\n");
    for(int i=0; i<row; i++)
        {
            for(int j=0;j<col;j++)
                {
                    printf("%3d ", B[i][j]);
                }
            printf("\n");
        }
    printf("\n");
}

int maxmin (int **A, int row, int max, int min)
{
    max=A[0][0];
    min=A[0][0];
    for(int i=0;i<row;i++)
        {
            for(int j=0;j<row;j++)
            {
                if (A[i][j] > max)
                    {
                        max = A[i][j];
                    }
            }
        }
    for(int i=0;i<row;i++)
        {
            for(int j=0;j<row;j++)
            {
                if (A[i][j] < min)
                    {
                        min = A[i][j];
                    }
            }
        }
    printf(" MAX value of A: MAX = %d\n", max);
    printf(" MIN value of A: MIN = %d\n", min);
}

int transposition (int **B, int row, int col, int **T)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            {
                T[j][i] = B[i][j];
            }
    }
    printf("\nTransponated B = \n");
  for (int i=0; i<col; i++)
        {
            for (int j=0; j<row; j++)
                {
                    printf("%d ", T[i][j]);
                }
            printf("\n");
        }
}

int multiply (int **A, int **B, int row, int col, int **C)
{

   for (int i=0;i<row;i++)
        {
            for (int j=0;j<col;j++)
            {
                C[i][j]= 0;
            }
        }
   for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                for (int k=0; k<row; k++)
                {
                    C[i][j]+=A[i][k]*B[k][j];
                }
            }
        }
    printf("\n A*B = \n");
    for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
                {
                    printf("%d\t",C[i][j]);
                }
            printf("\n");
        }
}

int sort (int **A, int row)
{
        for (int i=0; i<row; i++)
        {
            for (int j=0; j<row; j++)
            {
            int mini = A[i][j];

            int x = i;
            int y = j;

            int w = j;

            for (int k = i; k < row; k++)
                {
                    for (w; w < row; w++)
                    {
                        if (A[k][w] < mini)
                        {
                          mini = A[k][w];
                          x = k;
                          y = w;
                        }
                    }
                w = 0;
                }
            int temp = A[i][j];
            A[i][j] = A[x][y];
            A[x][y] = temp;
            }
        }
    printf("\n Sorted A = \n");
    for (int i=0;i<row;i++)
        {
            for (int j=0;j<row;j++)
                {
                    printf("%d ", A[i][j]);
                }
            printf("\n");
        }

}

int summ (int **A, int **B, int row, int col, int sumA, int sumB)
{

    for(int i=0;i<row;i++)
        {
            sumA=0;
            for(int j=0;j<row;j++)
                {
                    sumA += A[i][j];
                }
            printf("\n Sum of a row %d of A = %d",i+1,sumA);
        }
    printf("\n");

    for(int j=0;j<col;j++)
    {
        sumB=0;
        for(int i=0;i<row;i++)
            {
                sumB += B[i][j];
            }
        printf("\n Sum of a column %d of B = %d",j+1,sumB);
    }
    printf("\n");
}
