#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");

	srand(time(0));

	int arr[10][10], sum = 0;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			arr[i][j] = rand() % 100 + 1;
			cout << arr[i][j] << " ";
			sum += arr[i][j];
		}
		cout << endl << sum << endl;
		sum = 0;
	}
}