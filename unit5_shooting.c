#include <stdio.h>
#include <math.h>

// Define the differential equation y''(x) = f(x, y, y')
double f(double x, double y, double y_prime) {
    return 2 * x * y_prime - 2 * y;
}

// Implement the shooting method
double shooting_method(double a, double b, double alpha, double beta, double h, double tol) {
    double y_guess = alpha;
    double y_prime_guess = (beta - alpha) / (b - a); // Initial guess for y' at a
    double error = 1.0;

    while (error > tol) {
        double y = alpha;
        double y_prime = y_prime_guess;

        // Apply the Runge-Kutta method to find y(b) and y'(b)
        for (double x = a; x < b; x += h) {
            double k1y = h * y_prime;
            double k1y_prime = h * f(x, y, y_prime);

            double k2y = h * (y_prime + k1y_prime / 2);
            double k2y_prime = h * f(x + h/2, y + k1y/2, y_prime + k1y_prime / 2);

            double k3y = h * (y_prime + k2y_prime / 2);
            double k3y_prime = h * f(x + h/2, y + k2y/2, y_prime + k2y_prime / 2);

            double k4y = h * (y_prime + k3y_prime);
            double k4y_prime = h * f(x + h, y + k3y, y_prime + k3y_prime);

            y += (k1y + 2*k2y + 2*k3y + k4y) / 6;
            y_prime += (k1y_prime + 2*k2y_prime + 2*k3y_prime + k4y_prime) / 6;
        }

        error = fabs(y - beta);
        y_prime_guess += (beta - y) / (b - a);
    }

    return y_prime_guess;
}

int main() {
    double a, b, alpha, beta, h, tol;

    printf("Enter the start of the interval (a): ");
    scanf("%lf", &a);

    printf("Enter the end of the interval (b): ");
    scanf("%lf", &b);

    printf("Enter the boundary condition at a (alpha): ");
    scanf("%lf", &alpha);

    printf("Enter the boundary condition at b (beta): ");
    scanf("%lf", &beta);

    printf("Enter the step size (h): ");
    scanf("%lf", &h);

    printf("Enter the tolerance for the shooting method: ");
    scanf("%lf", &tol);

    double y_prime = shooting_method(a, b, alpha, beta, h, tol);

    printf("The initial value of y' at a that satisfies the boundary condition at b is: %lf\n", y_prime);

    return 0;
}
