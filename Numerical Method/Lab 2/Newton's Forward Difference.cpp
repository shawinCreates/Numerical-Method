#include<stdio.h>

int main() {
	printf("\n");
    printf("NEWTON FORWARD INTERPOLATION \n");
    
    int i, j, n;
    float xp, fp, sum, pi, x[10], f[10], a[10], d[10][10];
    
    printf("\nInput number of data points: ");
    scanf("%d", &n);
    
    printf("\nInput values of x and f(x), (one set on each line) \n");
    for(i=0; i<n; i++)
        scanf("%f %f", &x[i], &f[i]);
        
    //construct difference table using forward difference formula
    for(i=0; i<n; i++) 
        d[i][0] = f[i];
    
    for(j=1; j<n; j++) {
        for(i=0; i<n-j; i++) {
            d[i][j] = d[i+1][j-1] - d[i][j-1];
        }
    }
    
    // print the forward difference table
    printf("\nForward Difference Table: \n");
    for(i=0; i<n; i++) {
        printf("%.4f\t", x[i]);
        for(j=0; j<n-i; j++) {
            printf("%.4f\t", d[i][j]);
        }
        printf("\n");
    }
    
    // set coefficient using forward differences
    for(j=0; j<n; j++)
        a[j] = d[0][j];
    
    //compute interpolation value
    printf("\nInter xp where interpolation is required: ");
    scanf("%f", &xp);
    sum = a[0];
    pi = (xp - x[0]) / (x[1] - x[0]);
    for(i=1; i<n; i++) {
        sum = sum + (pi * a[i]);
        pi = pi * (xp - x[i]) / (x[i+1] - x[i]);
    }
    
    fp = sum;
    
    //write result
    printf("\n");
    printf("Interpolated value at x=%f is %f", xp, fp);
    
    return 0;
}

