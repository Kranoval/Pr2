#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");

	srand(time(0));

	int arr[10];

	for (int i = 0; i < 10; i++) {
		arr[i] = rand() % 100 + 1;
		cout << arr[i] << " ";
	}
}