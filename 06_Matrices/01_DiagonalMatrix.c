#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
	int *A;
	int n;
};

void Set(struct Matrix *m, int i, int j, int x)
{
	if(i==j) m->A[i-1]=x;
}

int Get(struct Matrix m, int i, int j)
{
	if (i==j)
		return m.A[i-1];
	return 0;
}

void Display(struct Matrix m)
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
	struct Matrix m;
	m.A=(int*)malloc(4*sizeof(int));
	m.n=4;

	Set(&m,1,1,5);
	Set(&m,2,2,8);
	Set(&m,3,3,6);
	Set(&m,4,4,9);

	printf("%d\n", Get(m,3,3));

	Display(m);


	return 0;
}
