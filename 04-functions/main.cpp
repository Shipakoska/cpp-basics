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


double Calculations(double x_begin, double eps, int &n, const int max_iter)
{
	n = 1;
	double nth_term = 1;
	double func = nth_term;
	while (abs(nth_term) > eps) {
		nth_term = pow((-1), n)*((pow(x_begin, n)) / (tgamma(n + 1)));
		func += nth_term;
		n++;
		if (n > max_iter) break;
	}
		return func;
	
	
}


void PrintResult(double x_begin, double func, int n, const int max_iter)
{
	cout << "*" << setw(15) << x_begin;
	cout << setw(6) << "*" << setw(15);
	if (n < max_iter) {
		cout << func << setw(6) << "*";
	}
	else {
		cout << "    One more chance  " << setw(3) << "*";
	}
	cout << setw(15) << exp(-x_begin) << setw(6) << "*";
	cout << setw(6) << n << setw(6) << "*" << endl;
}


int main()
{
	const int max_iter = 1000;
	double x_begin, x_end, eps, dx;
	double f;
	int n;

	cout << "PLease enter Xbegin " << "=";
	cin >> x_begin;
	cout << "PLease enter Xend " << "=";
	cin >> x_end;
	cout << "PLease enter dX " << "=";
	cin >> dx;
	cout << "Please enter Eps " << "=";
	cin >> eps;

	PrintTable();

	cout << fixed;
	cout.precision(9);

	for (x_begin; x_begin <= x_end; x_begin = x_begin + dx) {
		f = 0;
		n = 1;
		double func= Calculations(x_begin, eps, n,max_iter);
		PrintResult(x_begin, func, n, max_iter);
	}

	cout << string(76, '*') << endl;

	return 0;


}