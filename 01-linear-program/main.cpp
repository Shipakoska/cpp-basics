#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double a, z1, z2;
	const double pi = 4 * atan(1);


	cout << "Enter alpha coal " << "a=";
	cin >> a;


	z1 = cos(a) + sin(a) + sin(3 * a) + cos(3 * a);
	z2 = 2 * sqrt(2)*cos(a)*sin(2 * a + pi / 4);


	cout << "z1=" << z1 << endl;
	cout << "z2=" << z2 << endl;


	return 0;

}