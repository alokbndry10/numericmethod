#include <stdio.h>
#include <math.h>

float a3, a2, a1, a0;

float f(float x) {
    return (a3 * x * x * x + a2 * x * x + a1 * x + a0);
}

int main() {
    float xl, xm, xu, fxl, fxm, fxu, E, Era;
    
    printf("Enter the coefficients a3, a2, a1, and a0: \n");
    scanf("%f%f%f%f", &a3, &a2, &a1, &a0);
    
    printf("Enter initial bracket and E: \n");
    scanf("%f%f%f", &xl, &xu, &E);
    
    fxl = f(xl);
    fxu = f(xu);
    
    if ((fxl * fxu) > 0) {
        printf("Invalid input!\n");
        return 0;
    }
    
    int iter = 0; // Debugging: iteration counter
    
    while (1) {
        iter++; // Debugging: increment iteration counter
        
        fxl = f(xl);
        fxu = f(xu);
        xm = (xl + xu) / 2;
        fxm = f(xm);
        
        printf("Iteration %d: xl = %f, xu = %f, xm = %f, fxm = %f\n", iter, xl, xu, xm, fxm); // Debugging output
        
        if (fabs(fxm) < E) { // Check if the function value is close to zero
            printf("Root found within tolerance. Root = %f\n", xm);
            break;
        }
        
        if ((fxl * fxm) < 0)
            xu = xm;
        else
            xl = xm;
            
        Era = fabs((xu - xl) / xu);
        
        if (Era < E) {
            printf("Root found within tolerance. Root = %f\n", xm);
            break;
        }
    }
    
    return 0;
}
