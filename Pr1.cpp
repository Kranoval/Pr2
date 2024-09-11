#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");

	int arr[10];

	cin >> arr[0];

	int max = arr[0], min = max;

	for (int i = 1; i < 10; i++) {
		cin >> arr[i];
		if (max < arr[i]) max = arr[i];
		if (min > arr[i]) min = arr[i];
	}

	cout << max - min;
}