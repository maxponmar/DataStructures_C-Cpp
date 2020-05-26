#include <stdio.h>

struct Reactangle
{
	int lenght;
	int breadth;
};


struct Complex
{
	int real;
	int img;
};

struct Card
{
	int face;
	int shape;
	int color;
};

int main()
{
	printf("=== Reactangle ===\n");

	// Only declaration
	//struct Reactangle r;

	// Declaration + initialization
	struct Reactangle r = {10, 5};

	r.lenght = 20;
	r.breadth = 30;

	printf("Area of Reactangle is %d\n", r.lenght * r.breadth);

	printf("=== Card ===");

	// Defining a card deck (array of cards)

	//struct Card deck[52];

	struct Card deck[52] = {{1,0,0},{2,0,0},{3,0,1}};// and so on
	deck[40].color=1;
	deck[40].face=10;
	deck[40].shape=2;
	return 0;
}
