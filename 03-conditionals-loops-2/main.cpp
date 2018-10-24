#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	const int max_iter = 100;
	double Xbegin, Xend, Eps, dX;
	double F, Fi;
	int n;

	cout << "PLease enter Xbegin";
	cin >> Xbegin;
	cout << "PLease enter Xend";
	cin >> Xend;
	cout << "PLease enter dX";
	cin >> dX;
	cout << "Please enter Eps";
	cin >> Eps;

	cout << string(76, '*') << endl;
	cout << "*          X         *";
	cout << "       e^(-X)       *";
	cout << "         Y          *";
	cout << " Iterations* " << endl;
	cout << string(76, '*') << endl;
	cout << fixed;
	cout.precision(9);

	for (Xbegin; Xbegin <= Xend; Xbegin = Xbegin + dX) {
		F = 0;
		n = 1;
		Fi = 1;
		cout << "*" << setw(15) << Xbegin;

		while (abs(Fi) > Eps) {
			F = F + Fi;
			Fi = pow((-1), n)*((pow(Xbegin, n)) / (tgamma(n + 1)));
			n++;
			if (n > max_iter) {
				break;
			}
		}

		cout << setw(6) << "*" << setw(15);

		if (n < max_iter) {
			cout << F << setw(6) << "*";
		}

		else {
			cout << "    One more chance  " << setw(3) << "*";
		}

		cout << setw(15) << exp(-Xbegin) << setw(6) << "*";
		cout << setw(6) << n << setw(6) << "*" << endl;

	}

	cout << string(76, '*') << endl;

	return 0;
}