#include <stdio.h>

// Function to define the ODE dy/dx = f(x, y)
double f(double x, double y) {
    return x + y;
}

// Function to solve ODE using Euler's method
void euler_method(double x0, double y0, double h, int num_steps) {
    double x = x0;
    double y = y0;
    
    printf("x\t\t y (approx)\n");
    printf("%0.6f\t %0.6f\n", x, y);
    
    for (int i = 1; i <= num_steps; i++) {
        double y_prime = f(x, y);
        y = y + h * y_prime;
        x = x0 + i * h;
        printf("%0.6f\t %0.6f\n", x, y);
    }
}

int main() {
    double x0 = 0.0;    // Initial value of x
    double y0 = 1.0;    // Initial value of y(x0)
    double h = 0.1;     // Step size
    int num_steps = 100; // Number of steps
    
    printf("Solving ODE using Euler's method:\n");
    euler_method(x0, y0, h, num_steps);
    
    return 0;
}
