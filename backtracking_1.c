//Backtracking//
#include <stdio.h>
#include <stdlib.h>
int is_safe(int **board,int r,int col,int n)
 {
     int i,j;
    for (i=0;i<r;i++)
        {
        if (board[i][col])
            {
            return 0;
           }

    for (i=r,j=col;i>=0&&j>=0;i--,j--)
        {
        if (board[i][j])
            {
            return 0;
        }
    }
    for (i=r,j=col;i>=0&&j<n; i--,j++)
        {
            {
            return 0;
        }
    }

    return 1;
}
 }

int solve(int **board,int r,int n)
{
    int i,j;
    if (r==n)
        {
        for (i=0;i<n;i++)
            {
            for (j=0;j<n;j++)
             {
                printf("%d ",board[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        return 1;
    }

    int count = 0;
    for (i=0;i<n;i++)
        {
        if (is_safe(board, r, i, n))
        {
            board[r][i] = 1;
            count += solve(board, r + 1, n);
            board[r][i] = 0;
        }
        }

return count;
}

int main()
{
    int n,i;
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    int **board = (int **)malloc(n *sizeof(int *));
    for (i=0;i<n;i++)
        {
        board[i]=(int *)calloc(n,sizeof(int));
    }

    int soln = solve(board, 0, n);
    printf("Total number of soln: %d\n", soln);
    for (i = 0; i < n; i++)
        {
        free(board[i]);
    }
    free(board);

    return 0;
}

