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
const int N = 100;

void addInfo(info X[], int& n) {
	info t; string init;
	if (n == N - 1) {
		cerr << "Нет места в массиве";
		return;
	}
	cout << "Название товарищества: "; cin >> t.name;
	cout << "Номер участка: "; cin >> t.num;
	cout << "ФИО владельца: "; cin >> t.owner >> init;
	t.owner = t.owner + " " + init;
	cout << "Площадь: "; cin >> t.S;
	cout << "Стоимость: "; cin >> t.price;
	X[n] = t;
	n++;
	cout << "Элемент добавлен\n";
	cout << endl;
}
void inputMasInfo(info X[], int& n) {
	int k;
	cout << "Сколько записей хотите добавить? "; cin >> k;
	if (k > N) {
		cerr << "Нет места в массиве\n";
		return;
	}
	for (int i = 0; i < k; i++) addInfo(X, n);
	cout << "Массив введен\n";
	cout << endl;
}
void outputMasInfo(info X[], int n) {
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
		cout << left << "  |" << setw(2) << i + 1 << "|" << setw(20) << X[i].name << "|" << setw(7) << X[i].num << "|" << setw(32) << X[i].owner << "|" << setw(11) << X[i].S << "|" << setw(9) << X[i].price << "|" << right << endl;
	}
}

void findPrice(info X[], int n, info Y[], int& m) {
	double w;
	cout << "Поиск в массиве участков, цена, которых меньше "; cin >> w;
	for (int i = 0; i < n; i++) {
		if (X[i].price < w) {
			Y[m] = X[i];
			m++;
		}
	}
}
void findName(info X[], int n, info Y[], int& m) {
	string w;
	cout << "Поиск в массиве участков, с указанным названием товарищества\n Введите название товарищества"; cin >> w;
	for (int i = 0; i < n; i++) {
		if (X[i].name == w) {
			Y[m] = X[i];
			m++;
		}
	}
}

void findNamePrice(info X[], int n, info Y[], int& m) {
	double p;
	string name;
	cout << "Поиск по названию  товарищества и меньше указанной цены\n";
	cout << "Введите название "; cin >> name;
	cout << " Введите максимальную цену "; cin >> p;
	for (int i = 0; i < n; i++) {
		if ((X[i].name == name) && (X[i].price < p)) {
			Y[m] = X[i];
			m++;
		}
	}
}

void delInfo(info X[], int& n) {
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
void inputInfoFile(info X[], int& n) {
	string file, init;
	info t;
	ifstream fin;
	cout << "Имя входного файла: "; cin >> file;
	fin.open(file.c_str());
	if (fin.fail()) {
		cout << file << "\nНе открывается\n";
		return;
	}
	n = 0;
	while (true) {
		fin >> t.name >> t.num >> t.owner >> init >> t.S >> t.price;
		if (fin.fail()) break;
		n++;
	}
	if (n > N) { cout << "Нет места в массиве\n";  n = 0; return; }
	fin.close(); fin.open(file.c_str());
	for (int i = 0; i < n; i++) {
		fin >> X[i].name;
		fin >> X[i].num;
		fin >> X[i].owner;
		fin >> init;
		fin >> X[i].S;
		fin >> X[i].price;
		X[i].owner = X[i].owner + init;
	}
	fin.close();
	cout << "\nЗагружено " << n << " записей\n";
}
void correctInfo(info X[], int n) {
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

void outputInfoFile(info X[], int n) {
	ofstream fout;
	string file;
	cout << "Имя входного файла: "; cin >> file;
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
		fout << left << "  |" << setw(2) << i + 1 << "|" << setw(20) << X[i].name << "|" << setw(7) << X[i].num << "|" << setw(32) << X[i].owner << "|" << setw(11) << X[i].S << "|" << setw(9) << X[i].price << "|" << right << endl;
	}
	fout.close();
	cout << "Массив сохранен в файле " << file << endl;
}

void sortPrice(info X[], int n) {
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

void sortOwner(info X[], int n) {
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

struct countName {
	string name;
	int k;
};
void makeP_name(info X[], int n, countName Y[], int& yn) {
	bool fl;
	yn = 0;
	for (int i = 0; i < n; i++) {
		fl = 1;
		for (int j = 0; j < yn; j++) {
			if (X[i].name == Y[j].name) {
				fl = 0;
				Y[j].k++;
			}
		}
		if (fl == 1) {
			Y[yn].name = X[i].name;
			Y[yn].k = 1;
			yn++;
		}
	}
	cout << "Перечень сформирован\n";
}
void printP_name(countName Y[], int n) {
	if (n == 0) {
		cout << "Массив пустой\n";
		return;
	}
	cout << "  " << string(36, '-') << endl;
	cout << "  |" << "  |      Название      |          |" << endl;
	cout << "  |" << "  |   садоводческого   |Количество|" << endl;
	cout << "  |" << "№ |    товарищества    |          |" << endl;
	cout << "  " << string(36, '-') << endl;
	for (int i = 0; i < n; i++) {
		cout << left << "  |" << setw(2) << i + 1 << "|" << setw(20) << Y[i].name << "|" << setw(10) << Y[i].k << "|" << endl;
	}
}
void outputPnameFile(countName Y[], int n) {
	ofstream fout;
	string file;
	cout << "Имя входного файла: "; cin >> file;
	fout.open(file.c_str());
	if (fout.fail()) {
		cout << file << "\nНе открывается\n";
		return;
	}
	fout << "  " << string(36, '-') << endl;
	fout << "  |" << "  |      Название      |          |" << endl;
	fout << "  |" << "  |   садоводческого   |Количество|" << endl;;
	fout << "  |" << "№ |    товарищества    |          |" << endl;;
	fout << "  " << string(36, '-') << endl;
	for (int i = 0; i < n; i++) {
		fout << left << "  |" << setw(2) << i + 1 << "|" << setw(20) << Y[i].name << "|" << setw(10) << Y[i].k << "|" << endl;
	}
	fout.close();
	cout << "Перечень сохранен в файле " << file << endl;
}
void sortNameP(countName X[], int n) {
	if (n == 0) {
		cout << "Массив пустой\n";
		return;
	}
	bool fl;
	countName t;
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
		}
	} while (fl);
	cout << "Массив упорядочен\n";
}
void sortCountP(countName X[], int n) {
	if (n == 0) {
		cout << "Массив пустой\n";
		return;
	}
	bool fl;
	countName t;
	do {
		fl = false;
		n--;
		for (int i = 0; i < n; i++) {
			if (X[i].k > X[i + 1].k) {
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
	info A[N], B[N], C[N], D[N];
	countName Pn[N];
	int an(0), bn(0), cn(0), dn(0), choice(0), pn(0);
	while (true) {
		system("cls"); //Для очистки экрана 
		cout << "Программа для обработки файлов Садоводческих участков\n";
		cout << "\nМеню функций:\n";
		cout << "1.   Ввод информации с клавиатуры\n";
		cout << "2.   Просмотр существующего массива данных\n";
		cout << "3.   Поиск в массиве по стоимости участков и вывод на экран\n";
		cout << "4.   Поиск в массиве участков по названию товарищества с выводом на экран\n";
		cout << "5.   Поиск в массиве участков по названию товарищества, с ценой меньше заданной с выводом на экран\n";
		cout << "6.   Удаление строки \n";
		cout << "7.   Вывод БД из файла на экран\n";
		cout << "8.   Редактирование записи в базе  данных\n";
		cout << "9.   Сохранить массив в файл\n";
		cout << "10.  Сортировка массива по цене\n";
		cout << "11.  Сортировка массива по имени владельца в алфавитном порядке\n";
		cout << "12.  Формирование перечня названий товариществ\n";
		cout << "13.  Вывод перечня на экран\n";
		cout << "14.  Сохранение перечня в файл\n";
		cout << "15.  Сортировка перечня в алфавитном порядке\n";
		cout << "16.  Сортировка перечня по количеству\n";
		cout << "17.  Выход из программы\n";
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
			inputMasInfo(A, an);
			system("pause");
			break;
		case 2:
			outputMasInfo(A, an);
			system("pause");
			break;
		case 3:
			findPrice(A, an, B, bn);
			outputMasInfo(B, bn);
			system("pause");
			break;
		case 4:
			findName(A, an, C, cn);
			outputMasInfo(B, bn);
			system("pause");
			break;
		case 5:
			findNamePrice(A, an, D, dn);
			outputMasInfo(D, dn);
			system("pause");
			break;
		case 6:
			delInfo(A, an);
			system("pause");
			break;
		case 7:
			inputInfoFile(A, an);
			system("pause");
			break;
		case 8:
			correctInfo(A, an);
			system("pause");
			break;
		case 9:
			outputInfoFile(A, an);
			system("pause");
			break;
		case 10:
			sortPrice(A, an);
			system("pause");
			break;
		case 11:
			sortOwner(A, an);
			system("pause");
			break;
		case 12:
			makeP_name(A, an, Pn, pn);
			system("pause");
			break;
		case 13:
			printP_name(Pn, pn);
			system("pause");
			break;
		case 14:
			outputPnameFile(Pn, pn);
			system("pause");
			break;
		case 15:
			sortNameP(Pn, pn);
			system("pause");
			break;
		case 16:
			sortCountP(Pn, pn);
			system("pause");
			break;
		case 17:
			cout << "\nКонец работы\n";
			system("pause");
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
