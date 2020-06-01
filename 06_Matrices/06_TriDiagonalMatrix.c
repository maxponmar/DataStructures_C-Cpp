#include <stdio.h>
#include <stdlib.h>

struct TriDiagonalMatrix
{
	int *A;
	int n;
};

struct TriDiagonalMatrix Create(int n)
{
	struct TriDiagonalMatrix m;
	m.A=(int*)malloc((3*n-2)*sizeof(int));
	m.n=n;
	return m;
}

void Set(struct TriDiagonalMatrix *m, int i, int j, int x)
{
	int z = i-j;
	if(z==1) m->A[j]=x;
	else if(z==0) m->A[m->n-1+i]=x;
	else if(z==-1) m->A[2*m->n-1+i]=x;
}

int Get(struct TriDiagonalMatrix m, int i, int j)
{
	int z = i-j;
	if(z==1) return m.A[j];
	else if(z==0) return m.A[m.n+i-1];
	else if(z==-1) return m.A[2*m.n-1+i];
	return 0;
}

void Display(struct TriDiagonalMatrix m)
{
	int i,j,z;
	for(i=0;i<m.n;i++) {
		for(j=0;j<m.n;j++) {
			z=i-j;
			if(z==1) printf("%d ", m.A[j]);
			else if(z==0) printf("%d ", m.A[m.n-1+i]);
			else if(z==-1) printf("%d ", m.A[2*m.n-1+i]);
			else printf("0 ");
		}
		printf("\n");
	}
}

int main()
{
	struct TriDiagonalMatrix m;

	printf("Enter Dimension: ");
	int n;
	scanf("%d", &n);
	m=Create(n);

	printf("Enter all elements\n");
	int i,j,z,x;
	for(i=0;i<m.n;i++) {
		for(j=0;j<m.n;j++) {
			z=i-j;
			if(z==-1||z==0||z==1) {
				printf("\nElement [%d,%d]: ", i,j);
				scanf("%d",&x);
				Set(&m,i,j,x);
			}
		}
	}

	printf("Your Tri-Diagonal Matrix:\n");
	Display(m);

	return 0;
}
