#include <stdio.h>
#include <stdlib.h>

struct GeneralMatrix
{
	int *A;
	int m;
	int n;
};

struct GeneralMatrix Create(int m, int n)
{
	struct GeneralMatrix M;
	M.A=(int *)malloc(m*n*sizeof(int));
	M.m=m;
	M.n=n;
	return M;
}

void Set(struct GeneralMatrix *m, int i, int j, int x)
{
	m->A[i*m->m+j]=x;
}

int Get(struct GeneralMatrix m, int i, int j)
{
	return m.A[i*m.m+j];
}

void Display(struct GeneralMatrix m)
{
	int i,j;
	for(i=0;i<m.m;i++) {
		for(j=0;j<m.n;j++)
			printf("%d ", m.A[i*m.m+j]);
		printf("\n");
	}
}

int main()
{
	struct GeneralMatrix m;
	m = Create(3,4);
	Set(&m, 1, 1, 5);

	Display(m);


	return 0;
}
