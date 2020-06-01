#include <stdio.h>
#include <stdlib.h>

struct DiagonalMatrix
{
	int *A;
	int n;
};

struct DiagonalMatrix Create(int n)
{
	struct DiagonalMatrix m;
	m.A=(int*)malloc(n*sizeof(int));
	m.n=n;
	return m;
}
void Set(struct DiagonalMatrix *m, int i, int j, int x)
{
	if(i==j) m->A[i]=x;
}

int Get(struct DiagonalMatrix m, int i, int j)
{
	if (i==j)
		return m.A[i];
	return 0;
}

void Display(struct DiagonalMatrix m)
{
	int i,j;
	for(i=0;i<m.n;i++) {
		for(j=0;j<i;j++) printf("0 ");
		printf("%d ", m.A[i]);
		for(j=i+1;j<m.n;j++) printf("0 ");
		printf("\n");
	}
}

int main()
{
	struct DiagonalMatrix m;
	m=Create(4);
	Set(&m,0,0,9);
	Set(&m,1,1,5);
	Set(&m,2,2,8);
	Set(&m,3,3,6);

	printf("%d\n", Get(m,3,3));

	Display(m);


	return 0;
}
