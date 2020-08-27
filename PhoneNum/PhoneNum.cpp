#include <Windows.h>
#include <map>
#include <string>
#include <iostream>
using namespace std;
/*
			0
			1
abc			2
def			3
ghi			4
jkl			5
mno			6
pqrs		7
tuv			8
wxyz		9
*/

void DFS(int _val, map<int, string> _str) {
	int decade = 0;
	int units = 0;
	decade = _val / 10;
	units = _val % 10;
	string str1,str2;
	for (map<int,string>::iterator it  = _str.begin(); it != _str.end(); it++)
	{
		if (it->first == decade) {
			str1 = it->second;
		}
		if (it->first == units) {
			str2 = it->second;
		}
	}
	for (int i = 0; i <= str1.length(); i++) {
		for (int j = 0; j <= str2.length(); j++) {
			if (j == str2.length()||i == str1.length())
				break;
			char temp = str1[i];
			char temp1 = str2[j];
			cout << temp << temp1 << endl;
		}
	}
}

int main() {
	map<int, string> valstr;
	int val1 = 0;
	valstr.insert(pair < int, string> (0, ""));
	valstr.insert(pair < int, string> (1, ""));
	valstr.insert(pair < int, string> (2, "abc"));
	valstr.insert(pair < int, string> (3, "def"));
	valstr.insert(pair < int, string> (4, "ghi"));
	valstr.insert(pair < int, string> (5, "jkl"));
	valstr.insert(pair < int, string> (6, "mno"));
	valstr.insert(pair < int, string> (7, "pqrs"));
	valstr.insert(pair < int, string> (8, "tuv"));
	valstr.insert(pair < int, string> (9, "wxyz"));
	cin >> val1;

	DFS(val1, valstr);

	return 0;
}