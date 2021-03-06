#include<stdio.h>
#include<math.h>
#define EPS 1e-6
#define SIZE 50
double matrix[SIZE+3][2*SIZE+3];
int findRow(int N, int r)
{
    int j = r;
    while(j<=N)
    {
        if (!(fabs(matrix[j][r])<EPS)) return j;
        ++j;
    }
    return -1;
}
void swap(int N, int r1, int r2)
{
    if (r1==r2) return;
    double temp;
    int j;
    for (j=1; j<=2*N; ++j)
    {
        temp = matrix[r1][j];
        matrix[r1][j] = matrix[r2][j];
        matrix[r2][j] = temp;
    }
}
void printMatrix(int N)
{
    int i,j;
    for (i=1; i<=N; ++i)
    {
        for (j=1; j<=2*N; ++j) printf("%.3lf ", matrix[i][j]);
        puts("");
    }
    puts("");
}
bool GaussianElimination(int N)
{
    int i,j,k;
    for (i=1; i<=N; ++i)
    {
        j = findRow(N,i);
        if (j==-1) return false;
        swap(N,i,j);
        for (j=2*N; j>=i; --j) matrix[i][j] /= matrix[i][i];
        for (j=i+1; j<=N; ++j)
        {
            for (k=2*N; k>=i; --k) matrix[j][k] -= matrix[j][i] * matrix[i][k];
        }
    }
    for (i=N; i>=1; --i)
    {
        for (j=i-1; j>=1; --j)
        {
            for (k=2*N; k>=i; --k) matrix[j][k] -= matrix[j][i] * matrix[i][k];
        }
    }
    return true;
}
void printInverse(int N)
{
    int i,j;
    puts("");
    for (i=1; i<=N; ++i)
    {
        for (j=1; j<=N; ++j) printf("%.3lf ", matrix[i][N+j]);
        puts("");
    }
}
int main()
{
    //freopen("data.txt", "r", stdin);
    int N, i, j;
    while(scanf("%d", &N) != EOF)
    {
        for (i=1; i<=N; ++i)
        {
            for (j=1; j<=N+1; ++j) scanf("%lf", &matrix[i][j]);
        }
        if (GaussianElimination(N)) printInverse(N);
        else puts("Inverse Not Possible");
    }
    return 0;
}
