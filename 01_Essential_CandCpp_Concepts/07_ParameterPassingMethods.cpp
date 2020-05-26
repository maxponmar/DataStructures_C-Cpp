#include <stdio.h>

void swap_value(int x, int y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}

void swap_address(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

// Reference is only supported in C++
// In the machine code functions called by referene literally copy and paste
// the function code, so that the function is INSIDE the main function and it
// can acces directly to the main function memory. You should be use this
// carefully, only with simple functions
void swap_reference(int &x, int &y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}

int main()
{
	int a, b;
	a = 10;
	b = 20;

	swap_value(a, b);
	printf("Swap value     => a:%d , b:%d\n", a, b);

	swap_address(&a, &b);
	printf("Swap address   => a:%d , b:%d\n", a, b);

	swap_reference(a, b);
	printf("Swap reference => a:%d , b:%d\n", a, b);

	// Another way to swap values without need another temp value
	a = b - a;
	b = b - a;
	a = b + a;
	printf("a=%d , b=%d\n", a, b);
	return 0;
}
