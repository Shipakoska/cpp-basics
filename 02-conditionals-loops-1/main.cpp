#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main()
{

	double a, b, c, xb, xe, dx, f;
	const double eps = 1e-15;


	cout << "PLease enter a ";
	cin >> a;
	cout << "PLease enter b ";
	cin >> b;
	cout << "PLease enter c ";
	cin >> c;
	cout << "PLease enter Xbegin ";
	cin >> xb;
	cout << "PLease enter Xend ";
	cin >> xe;
	cout << "PLease enter dX ";
	cin >> dx;


	if (dx > 0) {
		cout << string(37, '*') << endl;
		cout << "*" << setw(9) << "X" << setw(9);
		cout << "*" << setw(9) << "F" << setw(9) << " *" << endl;
		cout << fixed;
		cout.precision(5);

		for (xb; xb <= xe; xb = xb + dx) {
			if ((xb + 5 < 0) && (c == 0) and xb != 0) {
				f = (1 / (a*xb)) - b;
			}
			else {
				if ((xb + 5 > 0 && c != 0) and xb != 0) {
					f = (xb - a) / xb;
				}
				else
				{
					if (c != 4)
					{
						f = 10 * xb / (c - 4);
					}
					else
					{
						cout << "*" << setw(9) << xb << setw(9) << "*" << setw(9) << "*" << setw(9) << "*" << endl;
						goto err;
					}
				}
			}
			if ((((int)a & (int)b) | ((int)b & (int)c)) == 0)
			{
				cout << "*" << setw(9) << xb<< setw(9) << "*" << setw(9) << (int)f << setw(9) << "*" << endl;
			}
			else
			{
				cout << "*" << setw(9) << xb << setw(9) << "*" << setw(9) << f << setw(9) << "*" << endl;
			}
		err:
			xb = xb + dx;
		}
		cout << string(37, '*') << endl;
	}
	else
	{
		cout << "dX is incorrect";
	}
	return 0;
}