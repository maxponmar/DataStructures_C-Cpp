#include <stdio.h>

int fact(int n)
{
	if (n==0)
		return 1;
	return fact(n-1)*n;
}

int main()
{
	printf("Factorial using recursion, 5!=%d", fact(5));
	return 0;
}
