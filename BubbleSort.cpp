#include <iostream>

using namespace std;

void swap(int*, int*);

int main() {
	int a[5] = { 17,9,11,6,3 };
	int n = sizeof(a) / sizeof(a[0]);
	for (int j = 0; j < n; j++) {
		for (int i = 1; i < n; i++) {
			if (a[i] < a[i - 1])
				swap(&a[i], &a[i - 1]);

		}
	}
	for(int i=0; i<n;i++)
		cout << a[i] << " ";
}

void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
