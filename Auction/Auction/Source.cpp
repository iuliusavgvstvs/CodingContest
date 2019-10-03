#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <map>

using namespace std;

vector<string> split(char *phrase, string delimiter) {
	vector<string> list;
	string s = string(phrase);
	size_t pos = 0;
	string token;
	while ((pos = s.find(delimiter)) != string::npos) {
		token = s.substr(0, pos);
		list.push_back(token);
		s.erase(0, pos + delimiter.length());
	}
	list.push_back(s);
	return list;
}

ifstream fin("in.txt");
ofstream fout("out.txt");

int main() {
	vector<string> sir;
	string nume;
	char s[301];
	int curent = 0, initial = 0, pos = 1, val = 0, elems=0;
	map<string,int> all[100];

	fin.getline(s, 300);
	sir = split(s, ",");
	stringstream nr(s);
	nr >> initial;

	while (pos < sir.size()-1) {
		nume = sir[pos];
		stringstream v(sir[pos+1]);
		v >> val;
		//cout << nume << " " << val << "\n";
		all->insert(pair<string, int>(nume, val));

		pos += 2;
	}
	fout << initial;
}