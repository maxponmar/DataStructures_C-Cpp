#include <stdio.h>
#include <stdlib.h>

struct ToeplitzMatrix
{
	int *A;
	int n;
};

struct ToeplitzMatrix Create(int n)
{
	struct ToeplitzMatrix m;
	m.A=(int*)malloc((2*n-1)*sizeof(int));
	m.n=n;
	return m;
}

void Set(struct ToeplitzMatrix *m, int i, int j, int x)
{
	if(i<=j) m->A[j-i]=x;
	else m->A[m->n+i-j-1]=x;
}

int Get(struct ToeplitzMatrix m, int i, int j)
{
	if (i<=j)
		return m.A[j-i];
	return m.A[m.n+i-j-1];
}

void Display(struct ToeplitzMatrix m)
{
	int i,j;
	for(i=0;i<m.n;i++) {
		for(j=0;j<m.n;j++) {
			if (i<=j)
				printf("%d ", m.A[j-i]);
			else
				printf("%d ", m.A[m.n+i-j-1]);

		}
		printf("\n");
	}
}

int main()
{
	struct ToeplitzMatrix m;
	int n;
	printf("Enter Dimension: ");
	scanf("%d", &n);
	m=Create(n);
	printf("Enter all elements\n");
	int i,j,x;
	for(j=0;j<m.n;j++) {
		printf("Element [%d,%d]: ", 0,j);
		scanf("%d",&x);
		Set(&m,0,j,x);
	}
	for(i=1;i<m.n;i++) {
		printf("Element [%d,%d]: ", i,0);
		scanf("%d",&x);
		Set(&m,i,0,x);
	}



	printf("Your Toeplitz Matrix:\n");
	Display(m);

	return 0;
}
