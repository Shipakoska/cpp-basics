#include "functions.h"



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
	double max = 0;
	double min = 0;
	for (int i = 0; i < n; i++)
	{

		if (abs(arr[i]) > max)
		{
			max = arr[i];
		}
		if (abs(arr[i]) < min)
		{
			min = arr[i];
		}
	}
		for (int i = (int)min + 1; i <= max - 1; i++)
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