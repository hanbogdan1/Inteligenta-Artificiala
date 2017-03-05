#include<stdio.h>
#include <stdlib.h>
#include <string>
#include<iostream>
#include<map>
#include <sstream> 
#include<algorithm>



using std::string;
string cerinta_1() {
	string text;

	std::getline(std::cin, text);
	string cuvant;


	std::stringstream ss(text);

	string max = "";
	while (ss >> cuvant) {

		if (cuvant.length() > max.length())
			max = cuvant;
	}



	std::cout << max;
	return max;
	

}


int cerinta_2() {
	string text;

	std::getline(std::cin, text);
	string cuvant;
	std::cin >> cuvant;
	std::stringstream ss(text);
	std::map<string, int> aux;
	string item;
	while (ss >> item) {

		aux[item]++;
	}
	std::cout << "\n";
	for (auto x : aux) {
		std::cout << x.first << ":" << x.second << ";";
	}

	std::cout << "\n";

	return aux[cuvant];
}

string cerinta_3() {

	string text;
	std::map<string, int> aux;
	std::getline(std::cin, text);
	string cuvant;


	std::stringstream ss(text);

	
	while (ss >> cuvant) {

		aux[cuvant]++;
	}
	
	string rez;
	int i = 0;

	for (auto x : aux) {
		if (x.second > i) {
			i = x.second;
			rez = x.first;
		}
	}
	std::cout << "\n";
	std::cout << rez << ":" << i;
	std::cout << "\n";
	return rez;

}


void cerinta_4() {
	string text;

	std::getline(std::cin, text);
	text.erase(std::remove(text.begin(),text.end(),' '),text.end());
	std::cout << text;
	std::map<string, int> auxMap;
	int n;
	std::cin >> n;

	for (int i = 0; i <= text.size() - n; i++) {
			string aux = text.substr(i, n);
			int count = 0;
			size_t nPos = text.find(aux, 0); 
			while (nPos != string::npos)
			{
				count++;
				nPos = text.find(aux, nPos + 1);
			}
			auxMap[aux] = count;
		}


	std::cout << "\n";
	for (auto x : auxMap) {
		std::cout << x.first << ":" << x.second << ";";
	}

	std::cout << "\n";
}


void cerinta_5() {
	string text;
	std::getline(std::cin, text);
	text.erase(std::remove(text.begin(), text.end(), ' '), text.end());
	std::cout << text;
	std::map<string, int> auxMap;
	int n;
	std::cin >> n;

	for (int i = 0; i <= text.size() - n; i++) {
		string aux = text.substr(i, n);
		int count = 0;
		size_t nPos = text.find(aux, 0);
		while (nPos != string::npos)
		{
			count++;
			nPos = text.find(aux, nPos + 1);
		}
		auxMap[aux] = count;
	}

	string rez;
	int i = 0;
	for (auto x : auxMap) {
		if (x.second > i) {
			i = x.second;
			rez = x.first;
		}
	}
	std::cout << "\n";
	std::cout << rez << ":" << i;
	std::cout << "\n";

	
}


int main()
{
	/*cerinta_1();
	cerinta_2();*/
	//std::cout<<cerinta_3();
	//cerinta_4();
	cerinta_5();
	int x;
	std::cin >> x;
	return 0;
}





