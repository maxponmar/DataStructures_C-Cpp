#include <stdio.h>
#include <stdlib.h>

// Columns major mapping
struct Matrix
{
	int *A;
	int n;
};

void Set(struct Matrix *m, int i, int j, int x)
{
	if(i<=j) m->A[j*(j-1)/2+i-1]=x;
}

int Get(struct Matrix m, int i, int j)
{
	if (i<=j)
		return m.A[j*(j-1)/2+i-1];
	return 0;
}

void Display(struct Matrix m)
{
	int i,j;
	for(i=1;i<=m.n;i++) {
		for(j=1;j<=m.n;j++) {
			if (i<=j)
				printf("%d ", m.A[j*(j-1)/2+i-1]);
			else
				printf("0 ");
		}
		printf("\n");
	}
}

int main()
{
	struct Matrix m;

	printf("Enter Dimension: ");
	scanf("%d", &m.n);
	m.A=(int*)malloc(m.n*(m.n+1/2*sizeof(int)));

	printf("Enter all elements\n");
	int i,j,x;
	for(i=1;i<=m.n;i++) {
		for(j=1;j<=m.n;j++) {
			if (i<=j) {
				printf("Element [%d,%d]: ", i,j);
				scanf("%d",&x);
				Set(&m,i,j,x);
			}
		}
	}

	printf("Your Upper Triangular Matrix:\n");
	Display(m);

	return 0;
}
