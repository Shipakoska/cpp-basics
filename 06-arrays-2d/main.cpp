#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

int SumOfRow(int **arr, int i, int n, int k)
{
	int sum = 0;
	for (int j = 1; j < k; j += 2)
	{
		if (arr[i][j] > 0)
		{
			sum += arr[i][j];
		}
	}
	return sum;
}

void SortArr(int **arr, int n, int k)
{
	for (int i = 0; i < n - 1; n--)
	{


		for (int j = i; j < n - 1; j++)
		{
			if (SumOfRow(arr, j, n, k) > SumOfRow(arr, j + 1, n, k))
			{
				for (int l = 0; l < k; l++)
					swap(arr[j][l], arr[j + 1][l]);
			}

		}

	}
}

int main()
{
	int n = 0, k = 0;


	cout << "PLease enter number of rows ";
	cin >> n;
	cout << "PLease enter number of colomns ";
	cin >> k;


	int** arr = new int*[n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[k];

	cout << "Enter file name ";
	string file_name;
	cin.ignore();
	getline(cin, file_name);

	ifstream fin(file_name);
	if (!fin.is_open())
	{
		cout << "Wrong file name";
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < k; j++)
			{
				fin >> arr[i][j];
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cout << arr[i][j] << "  ";
		}
		cout << endl;	
	}
	cout << endl;


	int num_of_col;
	num_of_col = 0;


	for (int j = 0; j < k; j++)
	{
		for (int i = 0; i < n; i++)
		{
			if (arr[i][j] != 0)
			{
				if (i + 1 == n)
					num_of_col++;
			}
			else
				break;
		}
	}



	SortArr(arr, n, k);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cout << arr[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "Number of colomns not containing zeros = " << num_of_col;

	for (int i = 0; i < k; i++) delete[] arr[i];
	delete[] arr;

}