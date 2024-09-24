#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to represent a data point
typedef struct {
    double x;
    double y;
} DataPoint;

// Function to perform polynomial regression
void polynomialRegression(DataPoint data[], int n, int degree) {
    double X[2 * degree + 1];
    double Y[degree + 1];
    double B[degree + 1][degree + 2];

    for (int i = 0; i <= 2 * degree; i++) {
        X[i] = 0;
        for (int j = 0; j < n; j++) {
            X[i] += pow(data[j].x, i);
        }
    }

    for (int i = 0; i <= degree; i++) {
        for (int j = 0; j <= degree; j++) {
            B[i][j] = X[i + j];
        }
    }

    for (int i = 0; i <= degree; i++) {
        Y[i] = 0;
        for (int j = 0; j < n; j++) {
            Y[i] += pow(data[j].x, i) * data[j].y;
        }
    }

    for (int i = 0; i <= degree; i++) {
        B[i][degree + 1] = Y[i];
    }

    degree++;

    // Applying Gauss Elimination
    for (int i = 0; i < degree; i++) {
        for (int k = i + 1; k < degree; k++) {
            if (B[i][i] < B[k][i]) {
                for (int j = 0; j <= degree; j++) {
                    double temp = B[i][j];
                    B[i][j] = B[k][j];
                    B[k][j] = temp;
                }
            }
        }
    }

    for (int i = 0; i < degree - 1; i++) {
        for (int k = i + 1; k < degree; k++) {
            double t = B[k][i] / B[i][i];
            for (int j = 0; j <= degree; j++) {
                B[k][j] = B[k][j] - t * B[i][j];
            }
        }
    }

    for (int i = degree - 1; i >= 0; i--) {
        data[i].y = B[i][degree];
        for (int j = 0; j < degree; j++) {
            if (j != i) {
                data[i].y = data[i].y - B[i][j] * data[j].y;
            }
        }
        data[i].y = data[i].y / B[i][i];
    }

    printf("\nThe polynomial equation is:\n");
    printf("y = ");
    for (int i = 0; i < degree; i++) {
        printf("%.2fx^%d ", data[i].y, i);
        if (i < degree - 1) {
            printf("+ ");
        }
    }
    printf("\n");
}

int main() {
    int n, degree;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    DataPoint *data = (DataPoint *)malloc(n * sizeof(DataPoint));

    printf("Enter the data points:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d: ", i + 1);
        scanf("%lf", &data[i].x);
        printf("y%d: ", i + 1);
        scanf("%lf", &data[i].y);
    }

    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);

    polynomialRegression(data, n, degree);

    free(data);

    return 0;
}

