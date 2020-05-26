#include <stdio.h>

int power(int m, int n)
{
	if (n==0)
		return 1;
	return power(m, n-1)*m;
}

int powerBetter(int m, int n)
{
	if (n==0)
		return 1;
	if (n%2==0)
		return powerBetter(m*m, n/2);
	return m*power(m*m, (n-1)/2);
}
int main()
{
	printf("3^4=%d\n", power(3, 4));
	printf("3^4=%d", powerBetter(3, 4));
	return 0;
}
