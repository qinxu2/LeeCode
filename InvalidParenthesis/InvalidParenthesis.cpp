#include <Windows.h>
#include <iostream>
#include <stack>
#include <list>
using namespace std;

void ClearContext(string& s)
{
	stack<int> st;
	list<int> stk;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		if (s[i] == '(')
			stk.push_front(i);
		else if (s[i] == ')') {
			if (!stk.empty())
				stk.pop_back();
			else 
				s[i] = ' ';//标记下待会删掉
		}
	}
	int temp;
	while (!stk.empty()) {
		temp = stk.front();
		stk.pop_front();
		s[temp] = ' ';
	}
}

void ClearContext1(string& s) {
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
	string str1;
	cin >> str;
	ClearContext(str);
	cout << "list storage from    " << str << endl;
	cin >> str1;
	ClearContext1(str1);
	cout << "stack storage from   " << str1 << endl;
	return 0;
}
