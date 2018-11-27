#include "functions.h"

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


}