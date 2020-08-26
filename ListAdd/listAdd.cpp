
#include <Windows.h>
#include <stdio.h>
#include <list>
using namespace std;

void listadd(list<int> l1, list<int> l2)
{
	int length = l1.size();
	list<int> listval;
	int val = 0;
	bool run = false;
	for (int i = 0;;i++) {
		if (i >= length) {
			break;
		}
		val = l1.front() + l2.front();
		if (run) {
			val = val + 1;
			if (val >= 10) {
				val = val - 10;
				run = true;
			}
		}
		if (val >= 10) {
			val = val - 10;
			run = true;
		}
		else
		{
			run = false;
		}
		if (l1.size() != 1) {
			l1.pop_front();
			l2.pop_front();
		}
		listval.push_back(val);

	}
	for (list<int>::iterator iter = listval.begin(); iter != listval.end(); ++iter)
		printf("%d", *iter);
}

void listBackAdd(list<int> l1, list<int> l2) {
	int l11 = 0;
	int l21 = 0;
	int l22 = 0;
	int val = 0;
	int val2 = 0;
	list<int> ll;
	int i = 1;
	int j = 1;
	for (list<int>::iterator iter = l1.begin(); iter != l1.end(); ++iter) 
	{
		l11 += *iter * i;
		i = i * 10;
	}
	for (list<int>::iterator iter = l2.begin(); iter != l2.end(); ++iter) 
	{
		l21 += *iter * j;
		j = j * 10;
	}
	l22 = l11 + l21;
	
	for (int a = 100; a > 0; a/=10) {
		if (a == 100) {
			val = l22 / 100;
			val2 = l22 % 100;
			if (val > 10) {
				val = val % 10;
			}
		}
		else {
			val = val2 / a;
			val2 = val2 % a;
			if (val > 10) {
				val = val % 10;
			}
		}
		ll.push_front(val);
	}

	for (list<int>::iterator iter = ll.begin(); iter != ll.end(); ++iter)
	{
		printf("%d", *iter);
	}
}

int main() {

	list<int> l1;
	list<int> l2;
	int val = 0;
	/*do {
		scanf("%d", &val);
		if (val != 0) {
			l1.push_back(val);
		}
	} while (0 != val);*/
	for (int i = 0; i < 3; i++) {
		scanf("%d", &val);
		if (i == 0 && val == 0) {
			i--;
			continue;
		}
		l1.push_back(val);
	}
	
	for (int i = 0; i < l1.size(); i++) {
		scanf("%d", &val);
		l2.push_back(val);
	}
	listadd(l1, l2);

	/*for (int i = 0; i < 3; i++) {
		scanf("%d", &val);
		if (i == 0 && val == 0) {
			i--;
			continue;
		}
		l1.push_back(val);
	}
	for (int i = 0; i < l1.size(); i++) {
		scanf("%d", &val);
		l2.push_back(val);
	}
	listBackAdd(l1,l2);*/
	return 0;
}