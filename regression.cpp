#include <stdio.h>
int main()
{
	float sx, sy, sxy, sx2, a, b,xi;
	int n,i;
	printf("Enter number of points: ");
	scanf("%d",&n);
	printf("Enter the value of x to estimate: ");
	scanf("%f",&xi);
	float x[n],y[n];
	for (i=0;i<=n-1;i++)
	{
		printf("\nEnter x%d: ",i+1);
		scanf("%f",&x[i]);
		printf("Enter fx: ");
		scanf("%f",&y[i]);
	}
	for (i=0;i<=n-1;i++)
	{
		sx = sx + x[i];
		sy = sy + y[i];
		sxy = sxy + x[i]*y[i];
		sx2 = sx2 + x[i]*x[i];
	}
	b = ((n*sxy - (sx*sy)) / ( (n*sx2) - (sx*sx) ));
	a = (sy/n) - (b*sx/n);
	
	printf("\nRegression equation:\ny = %.2f + %.2fx",a,b);
	printf("\nf(%.1f) = %.2f",xi,(a+b*xi));
	return 0;
}