#include <stdio.h>

// If the recursive function is called at the end of itself,
// Then it is tail recursion

// Tail recursion can be easily convert to a loop
void func1(int n)
{
	if (n>0) {
		printf("%d",n);
		func1(n-1);
	}
	/*
	The difference is that this code is O(1), while
	the previous one is O(n) (In terms of space)
	while(n>0)
	{
		printf("%d",n);
		n--;
	}
	*/
}


void func2(int n)
{
	if (n>0) {
		func2(n-1);
		printf("%d",n);
	}
}

int main()
{
	int x=3;

	printf("===Function 1===\n");
	func1(x);

	printf("\n===Function 2===\n");
	func2(x);

	return 0;
}
