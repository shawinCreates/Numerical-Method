#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	printf("\n");
    printf("NEWTON BACKWARD INTERPOLATION \n");
    float x[20], y[20], dif[20][20], f, s, d, h, p;
    int j, i, k, n;

    // Prompt user for the number of elements
    printf("\nInput the number of data points: ");
    scanf("%d", &n);

    // Input x values
    printf("\nInput values of x and f(x), (one set on each line) \n");
    for(i = 0; i < n; i++) {
        scanf("%f %f", &x[i], &y[i]);
    }
	//construct difference table using forward difference formula
    for(i=0; i<n; i++) 
        dif[i][0] = y[i];
    
    for(j=1; j<n; j++) {
        for(i=0; i<n-j; i++) {
            dif[i][j] = dif[i+1][j-1] - dif[i][j-1];
        }
    }
    
    // print the forward difference table
    printf("\nBackward Difference Table: \n");
    for(i=0; i<n; i++) {
        printf("%.4f\t", x[i]);
        for(j=0; j<n-i; j++) {
            printf("%.4f\t", dif[i][j]);
        }
        printf("\n");
    }
    // Prompt user for the searching point
    printf("\nInter xp where interpolation is required: ");
    scanf("%f", &f);

    // Calculate h
    h = x[1] - x[0];

    // Initialize variables for the finite difference method
    s = (f - x[n-1]) / h;
    d = y[n-1];
    p = 1;

    // Finite difference method calculation
    for(i = n-1, k = 1; i >= 1 && k < n; i--, k++) {
        for(j = n-1; j >= 1; j--) {
            y[j] = y[j] - y[j-1];
        }

        p = p * (s + k - 1) / k;
        d = d + p * y[n-1];
    }

    // Print the result
    printf("\nInterpolated value at x=%f is %f", f, d);

    return 0;
}

/*
100 10.63
150 13.03
200 15.04
250 16.81
300 18.42
350 19.90
400 21.27
*/
