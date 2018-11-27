#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string file_name;
	cout << "PLease write file name: ";
	cin >> file_name;

	ifstream fin(file_name);
	if (!fin) {
		cout << "Can't open file!\n";
		return 1;
	}

	string word;
	cout << "PLease write a word for searching: ";
	cin >> word;

	string line, sentence = "";

	while (getline(fin, line)) {

		for (size_t i = 0; i < line.length(); i++) {

			sentence += line[i];

			if (line[i] == '.' || line[i] == '!' || line[i] == '?') {

				if (sentence.find(word) != -1) {

					if (sentence[0] == ' ')
						sentence = sentence.substr(1, sentence.length());
					cout << sentence << endl;
				}
				sentence = "";
			}
		}


		if (sentence != "")
			sentence += " ";

	}
	return 0;
}