#include <bits/types/struct_tm.h>
#include <iostream>
#include <ostream>

using namespace std;

// Generic Class => Tempalte Class

template<class T>
class Arithmetic
{
	private:
		T a;
		T b;
	public:
		Arithmetic(T a, T b);
		T add();
		T sub();
};

template<class T>
Arithmetic<T>::Arithmetic(T a, T b)
{
	this->a = a;
	this->b = b;
}

template<class T>
T Arithmetic<T>::add()
{
	T c;
	c = a+b;
	return c;
}

template<class T>
T Arithmetic<T>::sub()
{
	T c;
	c = a-b;
	return c;
}

int main()
{
	Arithmetic<int> ar(10,5);
	cout << ar.add() << endl;

	Arithmetic<float> ar1(1.1f,1.2f);
	cout << ar1.add() << endl;

	Arithmetic<double> ar2(1.65, 0.89);
	cout << ar2.sub() << endl;

	return 0;
}
