#include "string"
#include "iostream"
#include "cstdlib"
#include "sstream"
using namespace std;

const int n = 5;

class Workers {

public:
	int age, zp;
	string surname, name, patr;
	Workers() {
	}
	void add(int age_, string surname_, string name_, string patr_, int zp_) {
		age = age_;
		surname = surname_;
		name = name_;
		patr = patr_;
		zp = zp_;
	}
	void out() {
		cout << age << " " << surname << " " << name << " " << patr << " " << zp << endl;
	}
};
Workers w[n];
void Sort() {
	Workers tmp;
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > i; j--) {
			if (w[j].age < w[j - 1].age) {
				tmp = w[j];
				w[j] = w[j - 1];
				w[j - 1] = tmp;
			}
		}
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");

	int x = 1;
	int age, zp;
	string surname, name, patr;
	for (int i = 0; i < n; i++) {
		w[i].add(0, "", "", "", 0);
	}
	int i = 0;
	while (x != 0) {
		cout << "Добавить сотрудника - 1, вывести сотрудников - 2, отсортировать по возрасту - 3, выйти - 0: ";
		cin >> x;
		switch (x) {
		case 0: break;
		case 1:
			cout << "\nВозраст: ";
			cin >> age;
			cout << "Фамилия: ";
			cin >> surname;
			cout << "Имя: ";
			cin >> name;
			cout << "Отчество: ";
			cin >> patr;
			cout << "Зарплата: ";
			cin >> zp;
			w[i].add(age, surname, name, patr, zp);
			i++;
			if (i > 4) {
				i = 0;
			}
			break;
		case 2:
			for (int i = 0; i < n; i++) {
				w[i].out();
			}
			break;
		case 3:
			Sort();
			break;
		}
	}
	cout << "\n\n\n";
	system("pause");
	return 0;
}
