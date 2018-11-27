#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

template <class T>
T SumOfRow(T **arr, int i, int n, int k)
{
	T sum = 0;
	for (int j = 1; j < k; j += 2)
	{
		if (arr[i][j] > 0)
		{
			sum += arr[i][j];
		}
	}
	return sum;
}

template <class T>
void SortArr(T **arr, int n, int k)
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

template <class T>
int Execute(string file_name) {
	ifstream fin(file_name);
	if (!fin.is_open())
	{
		cout << "Wrong file name";
		return 1;
	}

	int n = 0, k = 0;

	fin >> n;
	fin >> k;

	T** arr = new T*[n];
	for (int i = 0; i < n; i++)
		arr[i] = new T[k];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			fin >> arr[i][j];
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
	cout << endl;

	for (int i = 0; i < k; i++) delete[] arr[i];
	delete[] arr;
	return 0;
}

int main()
{
	while (true) {
		string type;
		cout << "Select type(1 - int, 2 - float, 3 - double, exit - to close): ";
		cin >> type;

		if (type == "exit") {
			return 0;
		}
		else if (type == "1") {
			Execute<int>("int.txt");
		}
		else if (type == "2") {
			Execute<float>("float.txt");
		}
		else if (type == "3") {
			Execute<double>("double.txt");
		}
	}

}