#include <stdio.h>
#include <stdlib.h>

struct UpTriMatrix
{
	int *A;
	int n;
};

struct UpTriMatrix Create(int n)
{
	struct UpTriMatrix m;
	m.A=(int*)malloc(n*(n+1)/2*sizeof(int));
	m.n=n;
	return m;
}

void Set(struct UpTriMatrix *m, int i, int j, int x)
{
	if(i<=j) m->A[j*(j+1)/2+i]=x;
}

int Get(struct UpTriMatrix m, int i, int j)
{
	if (i<=j)
		return m.A[j*(j+1)/2+i];
	return 0;
}

void Display(struct UpTriMatrix m)
{
	int i,j;
	for(i=0;i<m.n;i++) {
		for(j=0;j<m.n;j++) {
			if (i<=j)
				printf("%d ", m.A[j*(j+1)/2+i]);
			else
				printf("0 ");
		}
		printf("\n");
	}
}

int main()
{
	struct UpTriMatrix m;
	int n;
	printf("Enter Dimension: ");
	scanf("%d", &n);
	m=Create(n);
	printf("Enter all elements\n");
	int i,j,x;
	for(i=0;i<m.n;i++) {
		for(j=0;j<m.n;j++) {
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
