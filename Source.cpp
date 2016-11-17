#include <iostream>
#include <string>
using namespace std;


bool kontrola(string vstup) {
	int size = vstup.size();
	for (int i = 0; i < size; i++) {
		if ((vstup.at(i) != '1') && (vstup.at(i) != '0')) {
			return 0;
		}
	}
	return 1;
}

void doplnNuly(string &str, unsigned int max) {
	unsigned int stringSize = str.size();
	unsigned int pocetCyklu = max - stringSize;
	for (unsigned int i = 0; i < pocetCyklu; i++) {
		str.insert(0, "0");
	}
}

string soucetbinaru(string bin1, string bin2) {
	string vysledek;
	int size = bin1.size();
	vysledek.reserve(size);
	int counter = size - 1;
	char carryon = 0;
	while (counter >= 0) {
		int firstbit = bin1.at(counter) - '0';
		int secondbit = bin2.at(counter) - '0';
		counter--;
		int sum = (firstbit ^ secondbit ^ carryon) + '0';
		vysledek = (char)sum + vysledek;
		carryon = ((firstbit&secondbit) || (secondbit&carryon) || (firstbit&carryon));
	}
	if (carryon) {
		vysledek = '1' + vysledek;
	}
	return vysledek;
}

string upravitbinar(string binar) {
	int size = binar.size();
	string result;
	for (int i = 0; i < size; i++) {
		if (binar.at(0) == '0') {
			binar.erase(0, 1);
		}
		else {
			break;
		}
	}
	result = binar;
	if (result.size() == 0) {
		result = "0";
	}
	return result;

}


int main() {
	string binary1;
	string binary2;
	unsigned int size1;
	unsigned int size2;
	unsigned int maxSizeOfString = 0;

	cout << "Zadejte dve binarni cisla:" << endl;

	cin >> binary1 >> binary2;
	size1 = binary1.size();
	size2 = binary2.size();

	if (!(binary1.size() > 0 && binary2.size() > 0)) {
		cout << "Nespravny vstup." << endl;
		return 0;
	}

	if (!kontrola(binary1) || !kontrola(binary2)) {
		cout << "Nespravny vstup." << endl;
		return 0;
	}

	maxSizeOfString = size1;
	if (size2 > maxSizeOfString) {
		maxSizeOfString = size2;
	}


	if (size1 < maxSizeOfString) {
		doplnNuly(binary1, maxSizeOfString);
	}

	if (size2 < maxSizeOfString) {
		doplnNuly(binary2, maxSizeOfString);
	}

	string neupravenybinar;
	neupravenybinar = soucetbinaru(binary1, binary2);
	string upravenybinar;
	upravenybinar = upravitbinar(neupravenybinar);
	cout << "Soucet: " << upravenybinar << endl;




	return 0;
}