#include <stdio.h>

struct Rectangle
{
	int length;
	int breadth;
};

struct Test
{
	int A[5];
	int n;
};

int area(struct Rectangle &r1)
{
	r1.length++;
	return r1.length * r1.breadth;
}

void changeLength(struct Rectangle *r, int l)
{
	r->length = l;
}

// An array cannot be passed by value, only by address. But
// even if a struct has an array inself you can pass that struct by value
void testFunc(struct Test t1)
{
	t1.A[0]	= 10;
	t1.A[1] = 9;
	t1.n = 1;
}

int main()
{
	struct Rectangle r = {10, 5};
	printf("Area = %d\n", area(r));

	changeLength(&r, 12);
	printf("Length: %d\n", r.length);

	// TEST
	struct Test t = {{2,4,6,8,10}, 5};
	return 0;
}
