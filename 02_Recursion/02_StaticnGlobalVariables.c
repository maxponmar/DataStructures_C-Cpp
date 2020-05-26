#include <stdio.h>

// Original function
int fun(int n)
{
	if (n>0)
	{
		return fun(n-1)+n;
	}
	return 0;
}

// Static variable function
int fun_static(int n)
{
	static int x=0;
	if (n>0)
	{
		x++;
		return fun_static(n-1)+x;
	}
	return 0;
}

// Global variable function
int x=0;

int fun_global(int n)
{
	if (n>0)
	{
		x++;
		return fun_global(n-1)+x;
	}
	return 0;
}



int main()
{
	int a=5;

	printf("=== Original Function ===\n%d\n", fun(a));

	printf("=== Static Variable Function ===\n%d\n", fun_static(a));

	printf("=== Global Variable Function ===\n%d\n", fun_global(a));

	return 0;
}
