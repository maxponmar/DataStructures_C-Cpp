#include <iostream>

using namespace std;


int main()
{
	// Reference is only available in c++

	int a = 10;

	// r is referring to a (are the same)
	int &r = a;

	cout << a << endl;
	r++;
	cout << a << endl;

	return 0;
}
