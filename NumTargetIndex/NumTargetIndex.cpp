#include <Windows.h>
#include <iostream>
using namespace std;

int main() {

	int num[6] = { 0 };
	int target = 0;
	int val1 = -1;
	int val2 = -1;
	bool one = true;

	for (int i = 0; i < 6; i++) {
		cin >> num[i];
	}
	printf("scanf index:");
	cin >> target;

	for (int i = 0; i < 6; i++) {
		if (target == num[i] && one) {
			val1 = i;
			one = false;
			continue;
		}
		if (target == num[i] && !one ) {
			val2 = i;
		}
	}
	printf("put firsr Index and second Index : %d,%d", val1, val2);
}