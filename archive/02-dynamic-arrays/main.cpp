#include <iostream>
#include <windows.h>
#include <string.h>
#include <fstream>
#include <format>
#include <iomanip>
#include <conio.h>

using namespace std;
struct info {
	string name;
	int num;
	string owner;
	double S;
	double price;
};

void addInfo(info*& pa, int& n) {
	info t, * p; string init;
	p = new info[n + 1];

	if (p == NULL) {
		cout << "Нет памяти для массива структур. \n";
		cout << "Добавить не удается. \n";
		return;
	}

	cout << "Название товарищества: "; cin >> t.name;
	cout << "Номер участка: "; cin >> t.num;
	cout << "ФИО владельца: "; cin >> t.owner >> init;
	t.owner = t.owner + " " + init;
	cout << "Площадь: "; cin >> t.S;
	cout << "Стоимость: "; cin >> t.price;

	for (int i = 0; i < n; i++) p[i] = pa[i];
	p[n] = t;
	n++;
	if (pa != NULL) delete[] pa;
	pa = p;
	cout << "Элемент добавлен\n";
	cout << endl;
}
void inputMasInfo(info*& pa, int& n) {
	int k;
	cout << "Сколько записей хотите добавить? "; cin >> k;
	for (int i = 0; i < k; i++) addInfo(pa, n);
	cout << "Массив введен\n";
	cout << endl;
}
void outputMasInfo(info* X, int n) {
	if (n == 0) {
		cout << "Массив пустой\n";
		return;
	}
	cout << "  " << string(88, '-') << endl;
	cout << "  |" << "  |      Название      |       |                                |           |         |" << endl;
	cout << "  |" << "  |   садоводческого   | Номер |              ФИО               |  Площадь  |Стоимость|" << endl;;
	cout << "  |" << "№ |    товарищества    |участка|           владельца            |участка,m^2| участка |" << endl;;
	cout << "  " << string(88, '-') << endl;
	for (int i = 0; i < n; i++) {
		cout << fixed << setprecision(1) << left << "  |" << setw(2) << i + 1 << "|" << setw(20) << X[i].name << "|" << setw(7) << X[i].num << "|" << setw(32) << X[i].owner << "|" << setw(11) << X[i].S << "|" << setw(9) << X[i].price << "|" << right << endl;
	}
}

void delInfo(info* X, int& n) {
	int R;
	char q;
	outputMasInfo(X, n);
	cout << "\n Введите номер строки, которую хотите удалить: "; cin >> R;
	if (R < 0 || R > n) {
		cout << "Введена неверная строка\n";
		return;
	}
	R--;
	cout << "Выбранная строка:\n";
	cout << X[R].name << " " << X[R].num << " " << X[R].owner << " " << X[R].S << " " << X[R].price;
	cout << "\nУдалить строку? (Y/N): "; cin >> q;
	if (q == 'N') {
		cout << "Отмена удаления\n";
		return;
	}
	if (q != 'Y') {
		cout << "Неверный выбор\n";
		return;
	}
	for (int i = R + 1; i < n; i++) X[i - 1] = X[i];
	n--;
	cout << "Запись удалена\n";
}
void inputInfoFile(info*& px, int& n)
{
	ifstream fin;
	string file;
	string iniz;
	info t;

	cout << "Имя входного файла: ";
	cin >> file;
	fin.open(file.c_str());

	if (fin.fail()) {
		cout << file << " не открывается\n";
		return;
	}
	n = 0;
	while (true)
	{
		fin >> t.name >> t.num >> t.owner >> iniz >> t.S >> t.price;
		if (fin.fail()) break;
		n++;
	}
	fin.close();

	fin.open(file.c_str());
	if (fin.fail()) {
		cout << file << "Повторно не открывается\n";
		n = 0; return;
	}

	if (px != NULL) { delete[] px; px = NULL; }

	px = new info[n];



	if (px == NULL) {
		cout << "Нет памяти.\n"; fin.close();
		cout << "Ввести файл не удается.\n";
		n = 0; return;
	}

	for (int i = 0; i < n; i++)
	{
		fin >> px[i].name >> px[i].num >> px[i].owner >> iniz >> px[i].S >> px[i].price;
		px[i].owner = px[i].owner + " " + iniz;
	}
	fin.close();

	cout << "Файл введен " << endl;
}

void correctInfo(info* X, int n) {
	if (n == 0) {
		cout << "Массив пустой\n";
		return;
	}
	int d;
	string init;
	info t;
	outputMasInfo(X, n);
	cout << "Введите номер строки, которую хотите изменить: "; cin >> d;
	d--;
	cout << "\nВаша строка:\n";
	cout << X[d].name << " " << X[d].num << " " << X[d].owner << " " << X[d].S << " " << X[d].price << endl;
	cout << "Введите новую строку\n";
	cout << "Название товарищества: "; cin >> t.name;
	cout << "Номер участка: "; cin >> t.num;
	cout << "ФИО владельца: "; cin >> t.owner >> init;
	t.owner = t.owner + " " + init;
	cout << "Площадь: "; cin >> t.S;
	cout << "Стоимость: "; cin >> t.price;
	X[d] = t;
	cout << "\nЗапись изменена\n";
}

void outputInfoFile(info* X, int n) {
	ofstream fout;
	string file;
	cout << "Имя выходного файла: "; cin >> file;
	fout.open(file.c_str());
	if (fout.fail()) {
		cout << file << "\nНе открывается\n";
		return;
	}
	fout << "  " << string(88, '-') << endl;
	fout << "  |" << "  |      Название      |       |                                |           |         |" << endl;
	fout << "  |" << "  |   садоводческого   | Номер |              ФИО               |  Площадь  |Стоимость|" << endl;;
	fout << "  |" << "№ |    товарищества    |участка|           владельца            |участка,m^2| участка |" << endl;;
	fout << "  " << string(88, '-') << endl;
	for (int i = 0; i < n; i++) {
		fout << fixed << setprecision(1) << left << "  |" << setw(2) << i + 1 << "|" << setw(20) << X[i].name << "|" << setw(7) << X[i].num << "|" << setw(32) << X[i].owner << "|" << setw(11) << X[i].S << "|" << setw(9) << X[i].price << "|" << right << endl;
	}
	fout.close();
	cout << "Массив сохранен в файле " << file << endl;
}

void sortPrice(info* X, int n) {
	if (n == 0) {
		cout << "Массив пустой\n";
		return;
	}
	bool fl;
	info t;
	do {
		fl = false;
		n--;
		for (int i = 0; i < n; i++) {
			if (X[i].price > X[i + 1].price) {
				fl = true;
				t = X[i];
				X[i] = X[i + 1];
				X[i + 1] = t;
			}
		}
	} while (fl);
	cout << "Массив упорядочен\n";
}

void sortOwner(info* X, int n) {
	if (n == 0) {
		cout << "Массив пустой\n";
		return;
	}
	bool fl;
	info t;
	do {
		fl = false;
		n--;
		for (int i = 0; i < n; i++) {
			if (X[i].owner > X[i + 1].owner) {
				fl = true;
				t = X[i];
				X[i] = X[i + 1];
				X[i + 1] = t;
			}
		}
	} while (fl);
	cout << "Массив упорядочен\n";
}
void sortNamePrice(info* X, int n) {
	if (n == 0) {
		cout << "Массив пустой\n";
		return;
	}
	bool fl;
	info t;
	do {
		fl = false;
		n--;
		for (int i = 0; i < n; i++) {
			if (X[i].name > X[i + 1].name) {
				fl = true;
				t = X[i];
				X[i] = X[i + 1];
				X[i + 1] = t;
			}
			else if ((X[i].name == X[i + 1].name) and (X[i].owner > X[i + 1].owner)) {
				fl = true;
				t = X[i];
				X[i] = X[i + 1];
				X[i + 1] = t;
			}
		}
	} while (fl);
	cout << "Массив упорядочен\n";
}

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	info* pa(NULL);
	int an(0), choice(0);
	while (true) {
		system("cls"); //Для очистки экрана 
		cout << "Программа для обработки файлов Садоводческих участков\n";
		cout << "\nМеню функций:\n";
		cout << "1.  Ввод информации с клавиатуры\n";
		cout << "2.  Просмотр существующего массива данных\n";
		cout << "3.  Удаление строки \n";
		cout << "4.  Вывод БД из файла на экран\n";
		cout << "5.  Редактирование записи в базе  данных\n";
		cout << "6.  Сохранить массив в файл\n";
		cout << "7.  Сортировка массива по цене\n";
		cout << "8.  Сортировка массива по имени владельца в алфавитном порядке\n";
		cout << "9.  Сортировка по названию товарищества и по цене\n";
		cout << "10. Выход из программы\n";
		cout << "\nВаш выбор: "; cin >> choice; cout << "\n";

		if (cin.fail()) {
			cin.clear();
			string s;
			cin >> s;
			cout << "Это не пункт меню\n";
			system("pause");
			continue;
		}

		switch (choice) {
		case 1:
			inputMasInfo(pa, an);
			system("pause");
			break;
		case 2:
			outputMasInfo(pa, an);
			system("pause");
			break;
		case 3:
			delInfo(pa, an);
			system("pause");
			break;
		case 4:
			inputInfoFile(pa, an);
			system("pause");
			break;
		case 5:
			correctInfo(pa, an);
			system("pause");
			break;
		case 6:
			outputInfoFile(pa, an);
			system("pause");
			break;
		case 7:
			sortPrice(pa, an);
			system("pause");
			break;
		case 8:
			sortOwner(pa, an);
			system("pause");
			break;
		case 9:
			sortNamePrice(pa, an);
			system("pause");
			break;
		case 10:
			cout << "\nКонец работы\n";
			system("pause");
			if (pa != NULL) delete[] pa;
			return 1;
		default: {
			cout << "Неверная команда\n";
			system("pause");
			break;
		}
		}
	}
	cout << "Конец работы\n";
	return 1;
}
