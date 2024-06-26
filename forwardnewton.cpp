//Newton's forward divided difference interpolation
#include <stdio.h>
#include <math.h>
// #include <conio.h>
int factorial(int i)
{
	if (i==0 || i==1)
		return 1;
	else
		return i*factorial(i-1);
}
int main()
{
	float xp,xj,h,s,v,p;
	int i,j,n,k;
	printf("Enter  the number of points: ");
	scanf("%d",&n);
	printf("Enter interpolated value: ");
	scanf("%f",&xp);
	float x[n],fd[n],fx[n];
	for (i=0;i<n;i++)
	{
		printf("Enter x%d: ",i+1);
		scanf("%f",&x[i]);
		printf("Enter fx: ");
		scanf("%f",&fx[i]);
	}
	h=x[1]-x[0];
	s=(xp-x[0])/h;
	for (i=0;i<=n-1;i++)
	{
		fd[i] = fx[i];
	}
	for (i=0;i<=n-1;i++)
	{
		for (j=n-1;j>i;j--)
		{
			fd[j] = fd[j]-fd[j-1];
		}
	}
	v=fd[0];
	p=1;
	for (i=1;i<=n-1;i++)
	{
		for (k=1;k<=i;k++)
		{
			p=p*(s-k+1);
		}
		v=v+((fd[i]*p)/factorial(i));
		p=1;
	}
	printf("Interpolated value at %.1f = %.3f\n",xp,v);
	return 0;
}