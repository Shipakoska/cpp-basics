#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	const int max_iter = 100;
	double xb, xe, eps, dx;
	double f, i;
	int n;

	cout << "PLease enter Xbegin";
	cin >> xb;
	cout << "PLease enter Xend";
	cin >> xe;
	cout << "PLease enter dX";
	cin >> dx;
	cout << "Please enter Eps";
	cin >> eps;

	cout << string(76, '*') << endl;
	cout << "*          X         *";
	cout << "       e^(-X)       *";
	cout << "         Y          *";
	cout << " Iterations* " << endl;
	cout << string(76, '*') << endl;
	cout << fixed;
	cout.precision(9);

	for (xb; xb <= xe; xb = xb + dx)
	{
		f = 0;
		n = 1;
		i = 1;

		cout << "*" << setw(15) << xb;

		while (abs(i) > eps) {
			f = f + i;
			i = pow((-1), n)*((pow(xb, n)) / (tgamma(n + 1)));
			n++;
			if (n > max_iter) {
				break;
			}
		}

		cout << setw(6) << "*" << setw(15);

		if (n < max_iter) {
			cout << f << setw(6) << "*";
		}

		else {
			cout << "    One more chance  " << setw(3) << "*";
		}

		cout << setw(15) << exp(-xb) << setw(6) << "*";
		cout << setw(6) << n << setw(6) << "*" << endl;

	}

	cout << string(76, '*') << endl;

	return 0;
}