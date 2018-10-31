#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main()
{

	double a, b, c, x_begin, x_end, dx, f;
	const double eps = 1e-15;


	cout << "PLease enter a ";
	cin >> a;
	cout << "PLease enter b ";
	cin >> b;
	cout << "PLease enter c ";
	cin >> c;
	cout << "PLease enter Xbegin ";
	cin >> x_begin;
	cout << "PLease enter Xend ";
	cin >> x_end;
	cout << "PLease enter dX ";
	cin >> dx;


	if (dx > 0) {
		cout << string(37, '*') << endl;
		cout << "*" << setw(9) << "X" << setw(9);
		cout << "*" << setw(9) << "F" << setw(9) << " *" << endl;
		cout << fixed;
		cout.precision(5);

		for (x_begin; x_begin <= x_end; x_begin = x_begin + dx) {
			if ((x_begin + 5 < 0) && (c == 0) and x_begin != 0) {
				f = (1 / (a*x_begin)) - b;
			}
			else {
				if ((x_begin + 5 > 0 && c != 0) and x_begin != 0) {
					f = (x_begin - a) / x_begin;
				}
				else
				{
					if (c != 4)
					{
						f = 10 * x_begin / (c - 4);
					}
					else
					{
						cout << "*" << setw(9) << x_begin << setw(9) << "*" << setw(9) << "*" << setw(9) << "*" << endl;
						goto err;
					}
				}
			}
			if ((((int)a & (int)b) | ((int)b & (int)c)) == 0)
			{
				cout << "*" << setw(9) << x_begin << setw(9) << "*" << setw(9) << (int)f << setw(9) << "*" << endl;
			}
			else
			{
				cout << "*" << setw(9) << x_begin << setw(9) << "*" << setw(9) << f << setw(9) << "*" << endl;
			}
		err:
			x_begin = x_begin + dx;
		}
		cout << string(37, '*') << endl;
	}
	else
	{
		cout << "dX is incorrect";
	}
	return 0;
}