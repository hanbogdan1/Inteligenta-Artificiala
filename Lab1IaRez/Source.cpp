#include<stdio.h>
#include <stdlib.h>
#include <string>
#include<iostream>
#include<map>
#include <sstream> 
#include<algorithm>
#include <assert.h>
using std::string;
string cerinta_1(string text) {
	text.erase(std::remove(text.begin(), text.end(), ','), text.end());
	if (text == "")
		return text;
	string cuvant;
	std::stringstream ss(text);

	string max = "";
	while (ss >> cuvant) {

		if (cuvant.length() >= max.length())
			max = cuvant;
	}
	/*std::cout << max;*/
	return max;
}

void test_1() {
	string text = "";
	assert(cerinta_1(text) == "");
	text = "abc, ssse";
	assert(cerinta_1(text) == "ssse");
	text = "ana are mere multe albe";
	assert(cerinta_1(text) == "multe");
	text = "ana,";
	assert(cerinta_1(text) == "ana");
	text = "ana ,are";
	assert(cerinta_1(text) == "are");

	std::cout << "\ntest 1 nu a intampinat erori! \n";
}

std::map<string,int> cerinta_2(string text) {
	text.erase(std::remove(text.begin(), text.end(), ','), text.end());
	std::stringstream ss(text);
	std::map<string, int> aux;
	string item;
	while (ss >> item) {

		aux[item]++;
	}
	/*std::cout << "\n";
	for (auto x : aux) {
		std::cout << x.first << ":" << x.second << ";";
	}
	std::cout << "\n";*/


	return aux;
}



void test_2() {
	string text = "";
	std::map<string, int> rez;
	rez = cerinta_2("");
	assert(rez.size() == 0);
	text = "ana are mere";
	rez = cerinta_2(text);
	assert(rez["ana"] == 1);
	rez = cerinta_2("ana a, fost la doamna ana acasa");
	assert(rez["ana"] == 2);
	text = "mircea mircea, mircea mircea mirceaa";
	rez = cerinta_2(text);
	assert(rez["mircea"] == 4);
	rez = cerinta_2("ana, are mere");
	assert(rez["altceva"] == 0);
	std::cout << "\ntest 2 nu a intampinat erori! \n";
}

string cerinta_3(string text) {
	if (text == "")
		return "";
	text.erase(std::remove(text.begin(), text.end(), ','), text.end());
	std::map<string, int> aux;
	string cuvant;
	std::stringstream ss(text);	
	while (ss >> cuvant) {
		aux[cuvant]++;
	}	
	string rez;
	int i = 0;
	for (auto x : aux) {
		if (x.second >= i) {
			i = x.second;
			rez = x.first;
		}
	}
	/*std::cout << "\n";
	std::cout << rez << ":" << i;
	std::cout << "\n";*/
	return rez;
}
void test_3() {	
	assert(cerinta_3(",") == "");	
	assert(cerinta_3("ana are, mere") == "mere");
	assert(cerinta_3("Ana multe Ana") == "Ana");
	assert(cerinta_3("ana are, multe mere de la, doamna ana") == "ana");
	assert(cerinta_3("elefant mircea, elefant") == "elefant");
	std::cout << "\ntest 3 nu a intampinat erori! \n";
}

std::map<string, int> cerinta_4(string text, int n) {	
	text.erase(std::remove(text.begin(),text.end(),' '),text.end());
	text.erase(std::remove(text.begin(), text.end(), ','), text.end());

	std::map<string, int> auxMap;
	if (text == "" || n<=0)
		return auxMap;
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
	//std::cout << "\n";
	//for (auto x : auxMap) {
	//	std::cout << x.first << ":" << x.second << ";";
	//}

	//std::cout << "\n";
	return auxMap;
}
void test_4() {
	std::map<string, int> rez;
	rez = cerinta_4("ana andrei a fost",2);
	assert(rez["an"] == 2);
	assert(rez[""] == 0);
	assert(rez["ana"] == 0);
	rez = cerinta_4("ana a fost la ana sa vada ana", 3);
	assert(rez["ana"] == 3);
	rez = cerinta_4("ana a fost la ana sa vada ana", 4);
	assert(rez["aana"] == 2);
	rez = cerinta_4("an an ana", 2);
	assert(rez["an"] == 3);
	std::cout << "\ntest 4 nu a intampinat erori! \n";
}
string cerinta_5(string text, int n) {

	text.erase(std::remove(text.begin(), text.end(), ' '), text.end());
	text.erase(std::remove(text.begin(), text.end(), ','), text.end());
	if (text == "" || n<=0)
		return text;
	std::map<string, int> auxMap;	
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
		if (x.second >= i) {
			i = x.second;
			rez = x.first;
		}
	}
	//std::cout << "\n";
	//std::cout << rez << ":" << i;
	//std::cout << "\n";
	return rez;
}



void test_5() {	
	assert(cerinta_5("ana andrei a fost", 2) == "an");
	assert(cerinta_5("ana a fost la ana sa vada ana", 4) == "aana");
	assert(cerinta_5("abc deabcd cdeb cda", 3) == "bcd");
	assert(cerinta_5("ursul copacul u lalea", 2) == "ul");
	assert(cerinta_5("", 2) == "");	
	std::cout << "\ntest 5 nu a intampinat erori! \n";
}





int main()
{
	/*std::cout << "textul este :";
	string text;
	std::getline(std::cin, text);	
	std::cout<<"\nNumarul de cuvinte in datagrama =";
	int n;
	std::cin >> n;*/
	

	test_1();
	test_2();
	test_3();
	test_4();	
	test_5();


	int x;
	std::cin >> x;
	return 0;
}





