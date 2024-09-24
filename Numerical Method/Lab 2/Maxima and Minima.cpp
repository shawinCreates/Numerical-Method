#include <stdio.h>
#include <math.h>

int main() {
  printf("Maxima minima of tabulated function\n");
  float x[20], y[20], fd[20];
  int n, i, j;
  float a, b, c;

  printf("Enter the number of data points: ");
  scanf("%d", &n);

  if (n < 3) {
    printf("Error: Minimum 3 data points required.\n");
    return 1;
  }

  printf("Enter the data (x, y) format: ");
  for (i = 0; i < n; i++) {
    scanf("%f %f", &x[i], &y[i]);
  }

  float h = x[1] - x[0];

  for (i = 0; i < n; i++) {
    fd[i] = y[i];
  }

  for (i = 0; i < n; i++) {
    for (j = n - 1; j > i; j--) {
      fd[j] = fd[j] - fd[j - 1];
    }
  }

  // Compute the value of a, b, and c coefficients
  a = (fd[2] - fd[0]) / (2 * h * h);
  b = (fd[1] - fd[0]) / h - a * (x[1] + x[0]);
  c = fd[0];

  // Compute maxima and minima
  float discriminant = b * b - 4 * a * c;
  if (discriminant < 0) {
    printf("No real roots, unable to compute maxima and minima.\n");
  } else {
    float s1 = (-b + sqrt(discriminant)) / (2 * a);
    float s2 = (-b - sqrt(discriminant)) / (2 * a);

    float x1 = x[1] + s1 * h;
    float x2 = x[1] + s2 * h;

    float value1 = (fd[1] + ((6 * s1 - 6) * fd[2]) / 6) / (h * h);
    float value2 = (fd[1] + ((6 * s2 - 6) * fd[2]) / 6) / (h * h);

    float max_value, min_value, max_x, min_x;
    if (value1 > value2) {
      max_value = value1;
      max_x = x1;
      min_value = value2;
      min_x = x2;
    } else {
      max_value = value2;
      max_x = x2;
      min_value = value1;
      min_x = x1;
    }

    printf("Maximum value = %.2f at x = %.2f\n", max_value, max_x);
    printf("Minimum value = %.2f at x = %.2f\n", min_value, min_x);
  }

  return 0;
}

//input values
/* n=4
x y
0 -5
1 -7
2 -3
3 13 */
