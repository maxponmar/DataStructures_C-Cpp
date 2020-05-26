#include <stdio.h>

int fact(int n)
{
	if(n==0)return 1;
	return fact(n-1)*n;
}

int nCr(int n, int r)
{
	int num, den;
	num=fact(n);
	den=fact(r)*fact(n-r);

	return num/den;
}


int NCR(int n, int r)
{
	if(n==r||r==0)
		return 1;
	return NCR(n-1,r-1)+NCR(n-1,r);
}


int C(int n, int r)
{
	if(r>n-r) r=n-r; //C(n,r)==C(n,n-r)
	long ans = 1;
	int i;
	for(i=1;i<=r;i++)
	{
		ans *= n-r+i;
		ans /= i;
	}
	return ans;
}

int main()
{
	printf("%d\n", nCr(4, 2));

	printf("%d\n", NCR(4, 2));

	printf("%d\n", C(27, 8));
	return 0;
}
