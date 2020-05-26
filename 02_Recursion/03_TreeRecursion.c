#include <stdio.h>

void fun(int n)
{
	// Iime - O(2^n)
	// Space - O(n)
	if (n>0)
	{
		printf("%d",n);
		fun(n-1);
		fun(n-1);
	}
}

int main()
{
	int a=3;
	fun(a);
	return 0;
}
