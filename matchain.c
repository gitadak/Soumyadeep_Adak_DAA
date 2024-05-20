#include<stdio.h>
#include<limits.h>

int N;

void PrintOptimalParens(int s[][N], int i, int j);

void MatrixChainOrder(int p[])
{
    int n = N - 1;
    int m[n+1][n+1], s[n+1][n+1];
    int i, l, j, k, q;

    // Initialize the diagonal of m to 0
    for(i=1; i<=n; i++)
        m[i][i] = 0;

    // Compute the matrix chain order
    for(l=2; l<=n; l++)
    {
        for(i=1; i<=n-l+1; i++)
        {
            j = i+l-1;
            m[i][j] = INT_MAX;
            for(k=i; k<j; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                    printf("m[%d][%d] = %d split at k = %d\n", i, j, q, k);
                }
            }
        }
    }

    printf("Minimum number of scalar multiplications: %d\n", m[1][n]);
    PrintOptimalParens(s, 1, n);
}

void PrintOptimalParens(int s[][N], int i, int j)
{
    if(i == j)
        printf(" A%d ", i);
    else
    {
        printf("(");
        PrintOptimalParens(s, i, s[i][j]);
        PrintOptimalParens(s, s[i][j]+1, j);
        printf(")");
    }
}

int main()
{
    int i;
    printf("Enter number of dimensions: ");
    scanf("%d", &N);
    int p[N];
    printf("Enter dimensions:\n");
    for(i=0; i<N; i++)
        scanf("%d", &p[i]);
    MatrixChainOrder(p);
    return 0;
}

/*
Output:
------
Enter number of dimensions: 7
Enter dimensions:
30
35
15
5
10
20
25
m[1][2] = 15750 split at k = 1
m[2][3] = 2625 split at k = 2
m[3][4] = 750 split at k = 3
m[4][5] = 1000 split at k = 4
m[5][6] = 5000 split at k = 5
m[1][3] = 7875 split at k = 1
m[2][4] = 6000 split at k = 2
m[2][4] = 4375 split at k = 3
m[3][5] = 2500 split at k = 3
m[4][6] = 6250 split at k = 4
m[4][6] = 3500 split at k = 5
m[1][4] = 14875 split at k = 1
m[1][4] = 9375 split at k = 3
m[2][5] = 13000 split at k = 2
m[2][5] = 7125 split at k = 3
m[3][6] = 5375 split at k = 3
m[1][5] = 28125 split at k = 1
m[1][5] = 27250 split at k = 2
m[1][5] = 11875 split at k = 3
m[2][6] = 18500 split at k = 2
m[2][6] = 10500 split at k = 3
m[1][6] = 36750 split at k = 1
m[1][6] = 32375 split at k = 2
m[1][6] = 15125 split at k = 3
Minimum number of scalar multiplications: 15125
(( A1 ( A2  A3 ))(( A4  A5 ) A6 ))
*/
