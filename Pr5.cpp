#include <iostream>
#include <string.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");

	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	char facl[20];

	struct student {
		char famil[20], name[20], facult[20], group[20];
		int nomrzach, year;
	} stud[2];
	for (int i = 0; i < 2; i++) {
		cout << "Фамилия и имя студента #" << i + 1 << ": ";
		cin >> stud[i].famil;
		cin >> stud[i].name;
		cout << endl;
		cout << "Название факультера студента #" << i + 1 << ": ";
		cin >> stud[i].facult;
		cout << endl;
		cout << "Группа студента #" << i + 1 << ": ";
		cin >> stud[i].group;
		cout << endl;
		cout << "Номер зачетки и год обучения студента #" << i + 1 << ": ";
		cin >> stud[i].nomrzach;
		cin >> stud[i].year;
	}

	cout << "Какой факультет искать: ";
	cin >> facl;

	for (int i = 0; i < 2; i++) {
		if (!(strcmp(stud[i].facult, facl)))
			cout << "Студент " << stud[i].famil << " " << stud[i].name << " обучается на факультете " << stud[i].facult << " в группе " << stud[i].group << " номер зачетной книжки " << stud[i].nomrzach << " на " << stud[i].year << " году обучения" << endl;
	}
}