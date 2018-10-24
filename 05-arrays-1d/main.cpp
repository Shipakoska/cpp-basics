#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

double SumOfPositiveElements(double *arr, int n);
double MultiplicationOfMaxAndMinModulElem(double *arr, int n);
void ChangeArray(double *arr, int n);


int main()
{
	int n = 0;
	cout << "PLease enter n ";
	cin >> n;
	double *arr = new double[n];

	for (int i = 0; i < n; i++)
	{
		cout << "Enter " << i + 1 << " element:";
		cin >> arr[i];
	}

	cout << "\n Sum of positive elements of the array is : " << SumOfPositiveElements(arr, n) << endl;
	cout << "\n Multiplication of the max and min  modulo elements: " << MultiplicationOfMaxAndMinModulElem(arr, n) << endl;
	cout << "\n Change array:" << endl;


	ChangeArray(arr, n);
	for (int i = 0; i < n; i++)
	{
		cout << " [" << i << "] = ";
		cout << arr[i] << endl;
	}

	delete[] arr;

	return 0;
}

double SumOfPositiveElements(double *arr, int n)
{
	double sum = 0.0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > 0)
		{
			sum = sum + arr[i];
		}
	}
	return sum;
}

double  MultiplicationOfMaxAndMinModulElem(double *arr, int n)
{
	double p = 1;
	double maxabs = 0;
	double minabs = 0;
	for (int i = 0; i < n; i++)
	{
		if (abs(arr[i]) > maxabs)
		{
			maxabs = arr[i];
		}
		if (abs(arr[i]) < minabs)
		{
			minabs = arr[i];
		}
	}
	for (int i = minabs + 1; i <= maxabs - 1; i++)
	{
		p = p * arr[i];
	}
	return p;
}

void ChangeArray(double *arr, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				double tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
}