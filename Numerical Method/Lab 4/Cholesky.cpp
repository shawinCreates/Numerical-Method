#include <stdio.h>
#include <math.h>

#define N 10

void print(double mat[N][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2lf\t", mat[i][j]);
        }
        printf("\n");
    }
}

void cholesky(double mat[N][N], double L[N][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (i == j) {
                double sum = 0;
                for (int k = 0; k < j; k++) {
                    sum += L[j][k] * L[j][k];
                }
                L[j][j] = sqrt(mat[j][j] - sum);
            } else {
                double sum = 0;
                for (int k = 0; k < j; k++) {
                    sum += L[i][k] * L[j][k];
                }
                L[i][j] = (mat[i][j] - sum) / L[j][j];
            }
        }
    }
}

int main() {
    int n;
    double mat[N][N], L[N][N];
    
    printf("\nCHOLESKY METHOD\n");

    printf("\nEnter the size of the square matrix: ");
    scanf("%d", &n);

    printf("\nEnter the elements of the symmetric positive-definite matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &mat[i][j]);
        }
    }

    cholesky(mat, L, n);

    printf("\nLower triangular matrix (L) from Cholesky decomposition:\n");
    print(L, n);

    return 0;
}

