#include <stdio.h>
#include <stdlib.h>

struct SquareMatrix
{
	int *A;
	int n;
};

struct SquareMatrix Create(int n)
{
	struct SquareMatrix m;
	m.A=(int *)malloc(n*n*sizeof(int));
	m.n=n;
	return m;
}

void Set(struct SquareMatrix *m, int i, int j, int x)
{
	m->A[i*m->n+j]=x;
}

int Get(struct SquareMatrix m, int i, int j)
{
	return m.A[i*m.n+j];
}

void Display(struct SquareMatrix m)
{
	int i,j;
	for(i=0;i<m.n;i++) {
		for(j=0;j<m.n;j++)
			printf("%d ", m.A[i*m.n+j]);
		printf("\n");
	}
}

int main()
{
	struct SquareMatrix m;
	m = Create(3);
	Set(&m, 1, 1, 5);

	Display(m);


	return 0;
}
