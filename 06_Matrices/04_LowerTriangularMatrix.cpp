#include <iostream>

using namespace std;

class LowTriangular
{
	private:
		int n;
		int *A;
	public:
		LowTriangular(int n)
		{
			this->n=n;
			A=new int[n*(n+1)/2];
		}
		void set(int i, int j, int x);
		int get(int i, int j);
		void Display();
		~LowTriangular() { delete []A;}
};

void LowTriangular::set(int i, int j, int x)
{
	if(i>=j) A[i*(i-1)/2+j-1]=x;
}

int LowTriangular::get(int i, int j)
{
	if(i>=j)
		return A[i*(i-1)/2+j-1];
	return 0;
}

void LowTriangular::Display()
{
	int i,j;
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			if (i>=j)
				cout << A[i*(i-1)/2+j-1] << " ";
			else
				cout << "0 ";
		}
		cout << "\n";
	}
}

int main()
{
	int d;
	cout<<"Enter Dimensions: ";
	cin>>d;
	LowTriangular m(d);

	cout<<"Enter all elements\n";
	int i,j,x;
	for(i=1;i<=d;i++) {
		for(j=1;j<=d;j++) {
			if (i>=j) {
				printf("Element [%d,%d]: ", i,j);
				scanf("%d",&x);
				m.set(i,j,x);
			}
		}
	}

	printf("Your Lower Triangular Matrix:\n");
	m.Display();

	return 0;
}
