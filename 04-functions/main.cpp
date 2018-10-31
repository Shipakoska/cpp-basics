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


void Calculations(double eps, double f, double n, double x_begin, const int max_iter)
{
	double fi = 1;
	while (abs(fi) > eps) {
		f = f + fi;
		fi = pow((-1), n)*((pow(x_begin, n)) / (tgamma(n + 1)));
		n++;
		if (n > max_iter) {
			break;
		}
	}
}


void PrintResult(int n, int max_iter, double f, double x_begin)
{
	cout << "*" << setw(15) << x_begin;
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


int main()
{
	const int max_iter = 100;
	double x_begin, x_end, eps, dx;
	double f;
	int n;

	cout << "PLease enter Xbegin " << "Xbegin=";
	cin >> x_begin;
	cout << "PLease enter Xend " << "Xend=";
	cin >> x_end;
	cout << "PLease enter dX " << "dX=";
	cin >> dx;
	cout << "Please enter Eps " << "Eps=";
	cin >> eps;

	PrintTable();

	cout << fixed;
	cout.precision(9);

	for (x_begin; x_begin <= x_end; x_begin = x_begin + dx) {
		f = 0;
		n = 1;
		Calculations(eps, f, n, x_begin, max_iter);
		PrintResult(n, max_iter, f, x_begin);
	}

	cout << string(76, '*') << endl;

	return 0;


}