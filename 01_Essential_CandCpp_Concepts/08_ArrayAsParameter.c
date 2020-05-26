#include <stdio.h>
#include <stdlib.h>

// A[] is actualy a pointer to an array, so it doesn't know its length
void fun(int A[], int n)
{
	int i;
	for (i=0; i<n; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}

int * func(int n) {
	int *p;
	p = (int *)malloc(n*sizeof(int));
	return p;
}

int main()
{
	int A[5] = {2,4,6,8,10};
	fun(A, 5);

	int *B;
	B = func(5);

	return 0;
}
