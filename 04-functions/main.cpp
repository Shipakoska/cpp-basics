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


void Calculations(double Eps, double F, double n, double Xbegin, const int max_iter)
{
	double Fi = 1;
	while (abs(Fi) > Eps) {
		F = F + Fi;
		Fi = pow((-1), n)*((pow(Xbegin, n)) / (tgamma(n + 1)));
		n++;
		if (n > max_iter) {
			break;
		}
	}
}


void PrintResult(int n, int max_iter, double F, double Xbegin)
{
	cout << "*" << setw(15) << Xbegin;
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


int main()
{
	const int max_iter = 100;
	double Xbegin, Xend, Eps, dX;
	double F;
	int n;

	cout << "PLease enter Xbegin " << "Xbegin=";
	cin >> Xbegin;
	cout << "PLease enter Xend " << "Xend=";
	cin >> Xend;
	cout << "PLease enter dX " << "dX=";
	cin >> dX;
	cout << "Please enter Eps " << "Eps=";
	cin >> Eps;

	PrintTable();

	cout << fixed;
	cout.precision(9);

	for (Xbegin; Xbegin <= Xend; Xbegin = Xbegin + dX) {
		F = 0;
		n = 1;
		Calculations(Eps, F, n, Xbegin, max_iter);
		PrintResult(n, max_iter, F, Xbegin);
	}

	cout << string(76, '*') << endl;

	return 0;


}