#include <iostream>

using namespace std;

class Diagonal
{
	private:
		int n;
		int *A;
	public:
		Diagonal(int n)
		{
			this->n=n;
			A=new int[n];
		}
		void set(int i, int j, int x);
		int get(int i, int j);
		void Display();
		~Diagonal() { delete []A;}
};

void Diagonal::set(int i, int j, int x)
{
	if(i==j) A[i-1]=x;
}

int Diagonal::get(int i, int j)
{
	if(i==j) return A[i-1];
	return 0;
}

void Diagonal::Display()
{
	int i,j;
	for(i=0;i<n;i++) {
		for(j=0;j<i;j++) cout << "0 ";
		cout << A[i] << " ";
		for(j=i+1;j<n;j++) cout << "0 ";
		cout << "\n";
	}
}

int main()
{
	Diagonal A(3);
	A.set(1,1,2);
	A.set(2,2,3);
	A.set(3,3,4);
	A.Display();
	return 0;
}
