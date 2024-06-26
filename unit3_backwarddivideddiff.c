#include <stdio.h>

// Function to calculate the derivative of a function using the backward divided difference formula
double backwardDifference(double (*f)(double), double x, double h) {
    return (f(x) - f(x - h)) / h;
}

// Example function
double square(double x) {
    return x * x;
}

int main() {
    double x, h;
    printf("Enter the value of x: ");
    scanf("%lf", &x);
    printf("Enter the step size (h): ");
    scanf("%lf", &h);

    double derivative = backwardDifference(square, x, h);

    printf("The derivative of f(x) = x^2 at x = %.2f is approximately %.2f\n", x, derivative);

    return 0;
}