#include <stdio.h>


double e(int x, int n)
{
	static double p=1, f=1;
	double r;
	if (n==0){
		return 1;
	} else {
		r = e(x, n-1);
		p=p*x;
		f=f*n;
		return r+p/f;
	}
}

// Using Horner's rule

// Using loop
double e_HL(int x, int n)
{
	double s=1;
	for (;n>0;n--)
		s = 1 + x*s/n;
	return s;
}
// Recursive version
double e_HR(int x, int n)
{
	static double s;
	if(n==0)
		return s;
	s=1+x*s/n;
	return e_HR(x,n-1);
}

int main()
{
	printf("10 terms of e^x, x=1 => %f\n", e(1,10));
	printf("10 terms of e^x, x=1 => %f\n", e_HL(1,10));
	printf("10 terms of e^x, x=1 => %f\n", e_HR(1,10));
	return 0;
}
