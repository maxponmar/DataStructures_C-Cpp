#include <stdio.h>
#include <stdlib.h>

struct LowTriMatrix
{
	int *A;
	int n;
};

struct LowTriMatrix Create(int n)
{
	struct LowTriMatrix m;
	m.A=(int*)malloc(n*(n+1)/2*sizeof(int));
	m.n=n;
	return m;
}

void Set(struct LowTriMatrix *m, int i, int j, int x)
{
	if(i>=j) m->A[i*(i+1)/2+j]=x;
}

int Get(struct LowTriMatrix m, int i, int j)
{
	if (i>=j)
		return m.A[i*(i+1)/2+j];
	return 0;
}

void Display(struct LowTriMatrix m)
{
	int i,j;
	for(i=0;i<m.n;i++) {
		for(j=0;j<m.n;j++) {
			if (i>=j)
				printf("%d ", m.A[i*(i+1)/2+j]);
			else
				printf("0 ");
		}
		printf("\n");
	}
}

int main()
{
	struct LowTriMatrix m;
	int n;
	printf("Enter Dimension: ");
	scanf("%d", &n);
	m=Create(n);
	printf("Enter all elements\n");
	int i,j,x;
	for(i=0;i<m.n;i++) {
		for(j=0;j<m.n;j++) {
			if (i>=j) {
				printf("Element [%d,%d]: ", i,j);
				scanf("%d",&x);
				Set(&m,i,j,x);
			}
		}
	}

	printf("Your Lower Triangular LowTriMatrix:\n");
	Display(m);

	return 0;
}
