
#include<stdio.h>
#include<limits.h>
int N;
void PrintOptimalParens(int s[][N], int i, int j);
void MatrixChainOrder(int p[])
{
	int n = N - 1;
	int m[n+1][n+1], s[n+1][n+1];
	int i, l, j, k, q;
	for(i=1;i<=n;i++)
	m[i][i] = 0;

	for(l=2;l<=n;l++)
	{
		for(i=1;i<=n-l+1;i++)
		{
			j = i+l-1;
			m[i][j] = INT_MAX;
			for(k=i;k<j;k++)
			{
				q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				if(q<m[i][j])
				{
					m[i][j] = q;
					s[i][j] = k;
				}//if
			}//k loop
		}//i loop
	}//l loop
	printf("Minimum number of scalar multiplications: %d\n", m[1][n]);
	PrintOptimalParens(s, 1, n);
}
void PrintOptimalParens(int s[][N], int i, int j)
{
	if(i==j)
	printf("A%d ", i);
	else
	{
		printf("(");
		PrintOptimalParens(s, i, s[i][j]);
		PrintOptimalParens(s, s[i][j]+1, j);
		printf(")");
	}//else
}

int main()
{
	int i;
	printf("Enter number of dimensions: ");
	scanf("%d", &N);
	int p[N];
	printf("Enter dimensions:\n");
	for(i=0;i<N;i++)
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
Minimum number of scalar multiplications: 15125
((A1 (A2 A3 ))((A4 A5 )A6 ))
--------------------------------
Process exited after 11.37 seconds with return value 0
Press any key to continue . . .
*/
