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
		cout << "������� � ��� �������� #" << i + 1 << ": ";
		cin >> stud[i].famil;
		cin >> stud[i].name;
		cout << endl;
		cout << "�������� ���������� �������� #" << i + 1 << ": ";
		cin >> stud[i].facult;
		cout << endl;
		cout << "������ �������� #" << i + 1 << ": ";
		cin >> stud[i].group;
		cout << endl;
		cout << "����� ������� � ��� �������� �������� #" << i + 1 << ": ";
		cin >> stud[i].nomrzach;
		cin >> stud[i].year;
	}

	cout << "����� ��������� ������: ";
	cin >> facl;

	for (int i = 0; i < 2; i++) {
		if (!(strcmp(stud[i].facult, facl)))
			cout << "������� " << stud[i].famil << " " << stud[i].name << " ��������� �� ���������� " << stud[i].facult << " � ������ " << stud[i].group << " ����� �������� ������ " << stud[i].nomrzach << " �� " << stud[i].year << " ���� ��������" << endl;
	}
}