#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main()
{

	double a, b, c, Xbegin, Xend, dX, F;
	const double Eps = 1e-15;


	cout << "PLease enter a ";
	cin >> a;
	cout << "PLease enter b ";
	cin >> b;
	cout << "PLease enter c ";
	cin >> c;
	cout << "PLease enter Xbegin ";
	cin >> Xbegin;
	cout << "PLease enter Xend ";
	cin >> Xend;
	cout << "PLease enter dX ";
	cin >> dX;


	if (dX > 0) {
		cout << string(37, '*') << endl;
		cout << "*" << setw(9) << "X" << setw(9);
		cout << "*" << setw(9) << "F" << setw(9) << " *" << endl;
		cout << fixed;
		cout.precision(5);

		for (Xbegin; Xbegin <= Xend; Xbegin = Xbegin + dX) {
			if ((Xbegin + 5 < 0) && (c == 0) and Xbegin != 0) {
				F = (1 / (a*Xbegin)) - b;
			}
			else {
				if ((Xbegin + 5 > 0 && c != 0) and Xbegin != 0) {
					F = (Xbegin - a) / Xbegin;
				}
				else
				{
					if (c != 4)
					{
						F = 10 * Xbegin / (c - 4);
					}
					else
					{
						cout << "*" << setw(9) << Xbegin << setw(9) << "*" << setw(9) << "*" << setw(9) << "*" << endl;
						goto err;
					}
				}
			}
			if ((((int)a & (int)b) | ((int)b & (int)c)) == 0)
			{
				cout << "*" << setw(9) << Xbegin << setw(9) << "*" << setw(9) << (int)F << setw(9) << "*" << endl;
			}
			else
			{
				cout << "*" << setw(9) << Xbegin << setw(9) << "*" << setw(9) << F << setw(9) << "*" << endl;
			}
		err:
			Xbegin = Xbegin + dX;
		}
		cout << string(37, '*') << endl;
	}
	else
	{
		cout << "dX is incorrect";
	}
	return 0;
}