#include<stdio.h>
#include<math.h>
#define F(x) sqrt(1 - (x) * (x))
int main() {
	int i;
	float x0, xn, x1, x2, h;
	
	printf("\nGive initial value of x: ");
	scanf("%f", &x0);
	printf("\nGive final value of x: ");
	scanf("%f", &xn);
	
	h = (xn-x0) / 3;
	
	x1 = x0 + h;
	x2 = x0 + 2*h;

	double integration = (3*h/8) * (F(x0) + 3 * (F(x1) + F(x2)) + F(xn));
	
	printf("\n");
	printf("INTEGRATION BY 3/8 SIMPSON'S RULE");
	printf("\n \n");
	printf("Integration between %.2f and %.2f \n", x0, xn);
	printf("When h=%.2f is %f \n", h, integration);
	printf("\n");
	
	return 0;
}
