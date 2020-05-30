#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
	int *A;
	int n;
};

void Set(struct Matrix *m, int i, int j, int x)
{
	int z = i-j;
	if(z==1){
		m->A[j]=x;
	}
	if(z==0){
		m->A[m->n+i-2]=x;
	}
	if(z==-1) m->A[2*m->n+i-2]=x;
}

int Get(struct Matrix m, int i, int j)
{
	int z = i-j;
	if(z==1) return m.A[j];
	if(z==0) return m.A[m.n+i-2];
	if(z==-1) return m.A[2*m.n+i-2];
	return 0;
}

void Display(struct Matrix m)
{
	int i,j,z;
	for(i=1;i<=m.n;i++) {
		for(j=1;j<=m.n;j++) {
			z=i-j;
			if(z==1) printf("%d ", m.A[j]);
			else if(z==0) printf("%d ", m.A[m.n+i-2]);
			else if(z==-1) printf("%d ", m.A[2*m.n+i-2]);
			else printf("0 ");
		}
		printf("\n");
	}
}

int main()
{
	struct Matrix m;

	printf("Enter Dimension: ");
	scanf("%d", &m.n);
	m.A=(int*)malloc(m.n*3-2*sizeof(int));

	printf("Enter all elements\n");
	int i,j,z,x;
	for(i=1;i<=m.n;i++) {
		for(j=1;j<=m.n;j++) {
			z=i-j;
			if (z==-1||z==0||z==1) {
				printf("Element [%d,%d]: ", i,j);
				scanf("%d",&x);
				Set(&m,i,j,x);
			}
		}
	}

	printf("Your Simetric Matrix:\n");
	Display(m);

	return 0;
}
