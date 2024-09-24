#include <stdio.h>

#define N 10

void print(double mat[N][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2lf\t", mat[i][j]);
        }
        printf("\n");
    }
}

void doolittleLU(double mat[N][N], double L[N][N], double U[N][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                L[i][j] = 1;
            else
                L[i][j] = 0;
            U[i][j] = 0;
        }
    }

    // Perform the Do-Little decomposition
    for (int k = 0; k < n; k++) {
        for (int j = k; j < n; j++) {
            U[k][j] = mat[k][j];
            for (int p = 0; p < k; p++) {
                U[k][j] -= L[k][p] * U[p][j];
            }
        }
        for (int i = k + 1; i < n; i++) {
            L[i][k] = mat[i][k];
            for (int p = 0; p < k; p++) {
                L[i][k] -= L[i][p] * U[p][k];
            }
            L[i][k] /= U[k][k];
        }
    }
}

int main() {
    int n;
    double mat[N][N], L[N][N], U[N][N];
    
    printf("\nDOOLITTLE LU DECOMPOSITION\n");

    printf("\nEnter the size of the square matrix: ");
    scanf("%d", &n);

    printf("\nEnter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &mat[i][j]);
        }
    }

    doolittleLU(mat, L, U, n);

    printf("\nLower triangular matrix (L):\n");
    print(L, n);

    printf("\nUpper triangular matrix (U):\n");
    print(U, n);

    return 0;
}

