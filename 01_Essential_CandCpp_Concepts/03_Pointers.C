#include <stdio.h>
#include <stdlib.h>

int main()
{
	// data variable
	int a = 10;

	// address variable (Pinter)
	int *p;

	p = &a; // p = address of a

	printf("Variable a: %d\n",a);
	printf("Pointer p: %d\n",*p);

	// Accesing to heap memory
	// you can only acces to heap memory by using pointers
	// need sdtlib.h to use malloc
	// malloc func returns void pointer, you need to type-cast it (int *)
	p = (int *)malloc(5*sizeof(int));
	printf("Pointer address: %p\n", p);

	// In C++ you need to do this:
	// p = new int[5];

	return 0;
}
