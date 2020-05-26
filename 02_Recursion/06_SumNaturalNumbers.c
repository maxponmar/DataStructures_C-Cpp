#include <stdio.h>

int sumR(int n)
{
	if(n==0)
		return 0;
	return sumR(n-1)+n;
}

int sumF(int n)
{
	return n*(n+1)/2;
}

int sumL(int n)
{
	int i, s=0;
	for (i=1; i<=n; i++)
		s=s+i;
	return s;
}

int main()
{
	printf("Recursion (n=10): %d \n", sumR(10));

	printf("With formula: %d \n", sumF(10));

	printf("Using loop: %d", sumL(10));

	return 0;
}
