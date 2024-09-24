#include<stdio.h>
#include<math.h>

int fact(int n){
    if(n==0) return 1; 
    else return(n*fact(n-1));
}

int main(){
	printf("\nDerivation Using Forward Difference Formula\n\n");
    int n, i, j;
    float val=0, p, term1, term2, xp, x[10], fx[10], fd[10], h, s;

    printf("Enter the number of points: ");
    scanf("%d", &n);

    printf("Enter values of data points:\n");
    for(i=0; i<n; i++){
        scanf("%f%f", &x[i], &fx[i]);
    }

    printf("Enter the value at which derivative is required: ");
    scanf("%f", &xp);

    h = x[1] - x[0];
    s = (xp - x[0]) / h;

    // calculating forward difference
    for(i=0; i<n; i++){
        fd[i] = fx[i];
    }

    for(i=0; i<n; i++){
        for(j=0; j<n-1-i; j++) { 
            fd[j] = fd[j+1] - fd[j];
        }
    }

    // calculating value of derivative
     val = fd[0];
    for (i = 1; i < n; i++) {
        val += (fd[i] * s) / fact(i);
        s *= (s - 1);
    }

    // Normalize by step size 'h'
    val /= h;

    printf("Value of first derivative = %f\n", val);

    return 0;
}

