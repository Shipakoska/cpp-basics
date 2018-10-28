#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

void PrintTable()
{
	cout << string(76, '*') << endl;
	cout << "*          X         *";
	cout << "       e^(-X)       *";
	cout << "         Y          *";
	cout << " Iterations* " << endl;
	cout << string(76, '*') << endl;
}


void Calculations(double eps, double f, double n, double xb, const int max_iter)
{
	double fi = 1;
	while (abs(fi) > eps) {
		f = f + fi;
		fi = pow((-1), n)*((pow(xb, n)) / (tgamma(n + 1)));
		n++;
		if (n > max_iter) {
			break;
		}
	}
}


void PrintResult(int n, int max_iter, double f, double xb)
{
	cout << "*" << setw(15) << xb;
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


int main()
{
	const int max_iter = 100;
	double xb, xe, eps, dx;
	double f;
	int n;

	cout << "PLease enter Xbegin " << "Xbegin=";
	cin >> xb;
	cout << "PLease enter Xend " << "Xend=";
	cin >> xe;
	cout << "PLease enter dX " << "dX=";
	cin >> dx;
	cout << "Please enter Eps " << "Eps=";
	cin >> eps;

	PrintTable();

	cout << fixed;
	cout.precision(9);

	for (xb; xb <= xe; xb = xb + dx) {
		f = 0;
		n = 1;
		Calculations(eps, f, n, xb, max_iter);
		PrintResult(n, max_iter, f, xb);
	}

	cout << string(76, '*') << endl;

	return 0;


}