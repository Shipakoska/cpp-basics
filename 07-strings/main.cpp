#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string search_word;
	cout << "PLease enter word for searching: ";
	cin >> search_word;

	string file_name;
	cout << "PLease enter file name: ";
	cin >> file_name;

	ifstream fin(file_name.c_str());
	if (!fin)
		cout << "Wrong file name" << endl;
	else
	{
		string sentence;
		while (getline(fin, sentence, '.'))
		{
			string s = "";
			getline(fin, s);
			if (s.find(search_word, 0) != -1)
				cout << s << endl;
		}
		fin.close();
	}
	return 0;
}