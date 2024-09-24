#include<stdio.h>

int main() {
	printf("\n");
    printf("NEWTON INTERPOLATION \n");
    int i, j, n;
    float xp, fp, sum, pi, x[10], f[10], a[10], d[10][10];
    
    printf("\nInput number of data points: ");
    scanf("%d", &n);
    
    printf("\nInput values of x and f(x), (one set on each line) \n");
    for(i=0; i<n; i++)
        scanf("%f %f", &x[i], &f[i]);
        
    //construct difference table
    for(i=0; i<n; i++) 
        d[i][0] = f[i];
    
    for(j=1; j<n; j++) {
        for(i=0; i<n-j; i++) {
            d[i][j] = (d[i+1][j-1]-d[i][j-1])/(x[i+j]-x[i]);
        }
    }
    
    // print the divided difference table
    printf("\nDivided Difference Table: \n");
    for(i=0; i<n; i++) {
        printf("%.4f\t", x[i]);
        for(j=0; j<n-i; j++) {
            printf("%.4f\t", d[i][j]);
        }
        printf("\n");
    }
    
    //set coefficient
    for(j=0; j<n; j++)
        a[j] = d[0][j];
    
    
    //compute interpolation value
    printf("\nInter xp where interpolation is required: ");
    scanf("%f", &xp);
    sum = a[0];
    for(i=1; i<n; i++) {
        pi = 1.0;
        for(j=0; j<i; j++) {
            pi = pi*(xp-x[j]);
        }
        sum = sum + a[i] * pi;
    }
    
    fp = sum;
    
    //write result
    
    printf("\n");
    printf("Interpolated value at x=%f is %f", xp, fp);
    
    return 0;
}

