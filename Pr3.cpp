#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");

	srand(time(0));

	int** arr, k;

	cin >> k;

	arr = new int*[k];

	for (int i = 0; i < k; i++) {
		arr[i] = new int[k];
	}

	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++) {
			arr[i][j] = rand() % 100 + 1;
		}

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}