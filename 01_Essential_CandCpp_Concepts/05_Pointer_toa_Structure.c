#include <stdio.h>
#include <stdlib.h>

struct Rectangle
{
	int length;
	int breadth;
};


int main()
{

	struct Rectangle r = {10,5};

	// Size of a pointer = size of an integer
	struct Rectangle *p = &r;

	// Both do the same
	//(*p).length = 10;
	p->length = 55;

	printf("Length of rectangle %d\n", r.length);


	// Dynamically
	struct Rectangle *pointer;

	// Allocate a rectangle structure in heap memory

	// remember that malloc function returns a void pointer (generic pointer)
	pointer = (struct Rectangle *)malloc(sizeof(struct Rectangle));

	pointer->length = 10;
	pointer->breadth = 5;

	return 0;
}
