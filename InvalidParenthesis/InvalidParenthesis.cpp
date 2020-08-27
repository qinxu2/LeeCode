#include <Windows.h>
#include <iostream>
#include <stack>
using namespace std;

void ClearContext(string& s) 
{
	stack<int> stk;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		if (s[i] == '(')
			stk.push(i);
		else if (s[i] == ')') {
			if (!stk.empty())
				stk.pop();
			else 
				s[i] = ' ';//标记下待会删掉
		}
	}
	int temp;
	while (!stk.empty()) {
		temp = stk.top();
		stk.pop();
		s[temp] = ' ';
	}
}


int main() 
{
	string str;
	cin >> str;
	ClearContext(str);
	cout << str << endl;
	return 0;
}
