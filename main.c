#include <stdio.h>
#include <stdlib.h>

void printmatrix (int **A, int **B, int row, int col);
int max (int **A, int row, int maxe);
int transposition (int **B, int row, int col, int **T);
int multiply (int **A, int **B, int row, int col, int **C);
int sort (int **A, int row, int col, int sortA);
int summ (int **A, int **B, int row, int col, int sumA, int sumB);

// T=transponated, C=multiplied

int main()
{
    int choice_fill, choice_task;
    int row;
    int col;
    int maxe, sortA, sumA, sumB;

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

    int **A=NULL;
    A=(int**) malloc(row * sizeof(int));
    for(int i=0;i<row;i++)
    {
        A[i]=(int*) malloc(row * sizeof(int));
    }

    int **B=NULL;
    B=(int**) malloc(col * sizeof(int));
    int **C=NULL;
    C=(int**) malloc(col * sizeof(int));
    int **T=NULL;
    T=(int**) malloc(row * sizeof(int));

    for(int i=0;i<col;i++)
    {
        B[i]=(int*) malloc(row*sizeof(int));
        C[i]=(int*) malloc(row*sizeof(int));
        T[i]=(int*) malloc(row*sizeof(int));
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
                A[i][j]= rand()%97;
            }
        }
        for (int i=0;i<row;i++)
        {
            for (int j=0;j<col;j++)
            {
                B[i][j]= rand()%97;
            }
        }
    }
    else
    {
        for (int i=0;i<row;i++)
        {
            for (int j=0;j<row;j++)
            {
                A[i][j]= i+j;
            }
        }
        for (int i=0;i<row;i++)
        {
            for (int j=0;j<col;j++)
            {
                B[i][j]= i+j;
            }
        }
    }
    system("cls");
    printmatrix (A, B, row, col);

    printf(" What do you want to do with this(-ese) matrix(-es)?");
    printf("\n 1: Search for the MAX of A");
    printf("\n 2: Transponate B");
    printf("\n 3: Multiply the A by B");
    printf("\n 4: Sort A in ascending (entire matrix or a certain row)");
    printf("\n 5: Sum of the rows of A and columns of B\n\t");
    do
    {
        scanf (" %d", &choice_task);
    }while (choice_task!=1 && choice_task!=2 && choice_task!=3 && choice_task!=4 && choice_task!=5);

   switch (choice_task){
    case 1:
        max (A, row, maxe);
        break;

    case 2:
        transposition (B, row, col, T);
        break;

    case 3:
        multiply (A, B, row, col, C);
        break;

    case 4:
        sort (A, row, col, sortA);
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
                    printf("%d ", A[i][j]);
                }
            printf("\n");
        }
    printf("\n");
    for(int i=0; i<row; i++)
        {
            for(int j=0;j<col;j++)
                {
                    printf("%d ", B[i][j]);
                }
            printf("\n");
        }
    printf("\n");
}

int max (int **A, int row, int maxe)
{
    maxe=0;
    for(int i=0;i<row;i++)
        {
            for(int j=0;j<row;j++)
            {
                if (A[i][j] > maxe)
                    {
                        maxe = A[i][j];
                    }
            }
        }
    printf(" MAX value of A: MAX = %d\n", maxe);
}

int transposition (int **B, int row, int col, int **T)
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
            {
                T[j][i] = B[i][j];
            }
    }
    printf("\nTransponated B = \n");
  for (int i=0; i<row; i++)
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
   for(int i=0;i<col;i++)
        {
            for(int j=0;j<row;j++)
                {
                    C[i][j]=0;
                    for(int k=0;k<col;k++)
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

int sort (int **A, int row, int col, int sortA)
{
    int choice_sort;
    int row_sort;
    printf("\n Choose how to sort the matrix");
    printf("\n 1: the entire matrix\t2: a row\n\t");
    do
        {
            scanf("%d", &choice_sort);
        }
    while(choice_sort !=1 && choice_sort !=2);
    if (choice_sort == 1)
    {
        for(int k=0; k<row*col; ++k)
        {
            for(int i=0; i<row; ++i)
            {
                for(int j=0; j<col; ++j)
                {
                    if(j!=col-1)
                    {
                        if(A[i][j+1] < A[i][j])
                        {
                            int sortA = A[i][j+1];
                            A[i][j+1] = A[i][j];
                            A[i][j] = sortA;
                        }
                    }

                }
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
    if(choice_sort == 2)
        {
            printf("\n Which row would you like to sort?\n");
            scanf("%d",&row_sort);
            for(int k=0;k<row;k++)
                {
                    for(int j=0;j<row-k;j++)
                    {
                        if(A[row_sort][j]>A[row_sort][j+1])
                            {
                                sortA = A[row_sort][j];
                                A[row_sort][j] = A[row_sort][j+1];
                                A[row_sort][j+1] = sortA;
                            }
                    }
                }

            for(int j=0;j<row;j++)
                {
                    printf("%d ",A[row_sort][j]);
                }
        }
}

int summ (int **A, int **B, int row, int col, int sumA, int sumB)
{
    for(int i=0;i<row;i++)
        {
            int sumA=0;
            for(int j=0;j<row;j++)
                {
                    sumA = sumA + A[i][j];
                }
            printf("\n Sum of a line %d of A = %d",i,sumA);
        }
    printf("\n");
    for(int j=0;j<col;j++)
    {
        int sumB=0;
        for(int i=0;i<row;i++)
            {
                sumB = sumB + B[i][j];
            }
        printf("\n Sum of a column %d of B = %d",j,sumB);
    }
}
