#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	const int max_iter = 100;
	double x_begin, x_end, eps, dx;
	double f, i;
	int n;

	cout << "PLease enter Xbegin";
	cin >> x_begin;
	cout << "PLease enter Xend";
	cin >> x_end;
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

	for (x_begin;  x_begin <= x_end;  x_begin = x_begin + dx)
	{
		f = 0;
		n = 1;
		i = 1;

		cout << "*" << setw(15) << x_begin;

		while (abs(i) > eps) {
			f = f + i;
			i = pow((-1), n)*((pow(x_begin, n)) / (tgamma(n + 1)));
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

		cout << setw(15) << exp(-x_begin) << setw(6) << "*";
		cout << setw(6) << n << setw(6) << "*" << endl;

	}

	cout << string(76, '*') << endl;

	return 0;
}