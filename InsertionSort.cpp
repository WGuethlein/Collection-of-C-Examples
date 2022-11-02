#include <iostream>

using namespace std;

int main() {
	int a[5] = { 1,3,2,5,4 };
	int n = sizeof(a) / sizeof(a[0]);


	for (int j = 1; j < n; j++) {
		int key = a[j];
		int i = j - 1;
		while (i > 0 && a[i] > key) {
			a[i + 1] = a[i];
			i--;
		}
		a[i + 1] = key;
	}

	for (int i = 0; i < n; i++) {
		cout << a[i];
	}
}