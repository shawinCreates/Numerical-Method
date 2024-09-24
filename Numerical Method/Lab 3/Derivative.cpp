#include<stdio.h>
#define F(x) (x) * (x)

int main() {
	float h, x;
	int choice;
	
	printf("Enter the value of x:");
	scanf("%f", &x);
	
	printf("\nEnter the value for h: ");
	scanf("%f", &h);

	printf("\nChoose the type of finite difference formula:\n");
	printf("1. Forward difference formula\n");
	printf("2. Central difference formula\n");
	printf("3. Backward difference formula\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	double derivative;

	switch(choice) {
		case 1:
			derivative = (F(x+h)-F(x)) / h;
			printf("\nThe derivative of the function at x = %.2f using forward difference formula is: %.4f\n", x, derivative);
			break;
		case 2:
			derivative = (F(x+h) - F(x-h)) / (2*h);
			printf("\nThe derivative of the function at x = %.2f using central difference formula is: %.4f\n", x, derivative);
			break;
		case 3:
			derivative = (F(x) - F(x-h)) / h;
			printf("\nThe derivative of the function at x = %.2f using backward difference formula is: %.4f\n", x, derivative);
			break;
		default:
			printf("\nInvalid choice!\n");
			return 1;
	}
	
	return 0;
}

