#include <iostream>
#include <windows.h>
#include <string.h>
#include <fstream>
#include <format>
#include <iomanip>
#include <conio.h>
using namespace std;

const int N = 100;

struct info {
	string name;
	int num;
	string owner;
	double S;
	double price;
};

class mas {
private:
	info X[N];
	int n = 0;
public:
	void inputMasInfo();
	void outputMasInfo();
	void delInfo();
	void correctInfo();
	void outputInfoFile();
	void inputInfoFile();
	void sortPrice();
	void sortOwner();
	void sortStruct();
};

//Основной код
int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	mas A;
	int choice(0);
	while (true) {
		system("cls"); //Для очистки экрана 
		cout << "Программа для обработки файлов Садоводческих участков\n";
		cout << "\nМеню функций:\n";
		cout << "1.   Ввод информации с клавиатуры\n";
		cout << "2.   Просмотр существующего массива данных\n";
		cout << "3.   Удаление строки \n";
		cout << "4.   Вывод БД из файла на экран\n";
		cout << "5.   Редактирование записи в базе  данных\n";
		cout << "6.   Сохранить массив в файл\n";
		cout << "7.   Сортировка массива по цене\n";
		cout << "8.   Сортировка массива по имени владельца в алфавитном порядке\n";
		cout << "9.   Сортировка массива по названию товарищества и имени владельца\n";
		cout << "10.  Выход из программы\n";
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
			A.inputMasInfo();
			system("pause");
			break;
		case 2:
			A.outputMasInfo();
			system("pause");
			break;
		case 3:
			A.delInfo();
			system("pause");
			break;
		case 4:
			A.inputInfoFile();
			system("pause");
			break;
		case 5:
			A.correctInfo();
			system("pause");
			break;
		case 6:
			A.outputInfoFile();
			system("pause");
			break;
		case 7:
			A.sortPrice();
			system("pause");
			break;
		case 8:
			A.sortOwner();
			system("pause");
			break;
		case 9:
			A.sortStruct();
			system("pause");
			break;
		case 10:
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


//Объявление функций

void mas::inputMasInfo() {
	int k; info t; string init;
	cout << "Сколько записей хотите добавить? "; cin >> k;
	if (k > N) {
		cerr << "Нет места в массиве\n";
		return;
	}
	for (int i = 0; i < k; i++) {
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
}
void mas::outputMasInfo() {
	if (n == 0) {
		cout << "Массив пустой\n";
		return;
	}
	cout << "  " << string(90, '-') << endl;
	cout << "  |" << "  |      Название      |       |                                |           |           |" << endl;
	cout << "  |" << "  |   садоводческого   | Номер |              ФИО               |  Площадь  | Стоимость |" << endl;
	cout << "  |" << "№ |    товарищества    |участка|           владельца            |участка,m^2|  участка  |" << endl;
	cout << "  " << string(90, '-') << endl;
	for (int i = 0; i < n; i++) {
		cout << left << "  |" << setw(2) << i + 1 << "|" << setw(20) << X[i].name << "|" << setw(7) << X[i].num << "|" << setw(32) << X[i].owner << "|" << setw(11) << X[i].S << "|" << setw(11) << X[i].price << "|" << right << endl;
	}
}

void mas::delInfo() {
	int R;
	char q;
	outputMasInfo();
	cout << "\n Введите номер строки, которую хотите удалить: "; cin >> R;
	if (R < 0 || R > n) {
		cout << "Введена неверная строка\n";
		return;
	}
	if (cin.fail()) {
		string s1;
		cin.clear(); cin >> s1;
		cout << "Введены некорректные данные\n";
		return;
	}
	R--;
	cout << "Выбранная строка:\n";
	cout << "  " << string(90, '-') << endl;
	cout << "  |" << "  |      Название      |       |                                |           |           |" << endl;
	cout << "  |" << "  |   садоводческого   | Номер |              ФИО               |  Площадь  | Стоимость |" << endl;
	cout << "  |" << "№ |    товарищества    |участка|           владельца            |участка,m^2|  участка  |" << endl;
	cout << "  " << string(90, '-') << endl;
	cout << left << "  |" << setw(2) << R + 1 << "|" << setw(20) << X[R].name << "|" << setw(7) << X[R].num << "|" << setw(32) << X[R].owner << "|" << setw(11) << X[R].S << "|" << setw(11) << X[R].price << "|" << right << endl;
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

void mas::correctInfo() {
	if (n == 0) {
		cout << "Массив пустой\n";
		return;
	}
	int d;
	string init;
	info t;
	outputMasInfo();
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

void mas::outputInfoFile() {
	ofstream fout;
	string file;
	cout << "Имя входного файла: "; cin >> file;
	fout.open(file.c_str());
	if (fout.fail()) {
		cout << file << "\nНе создается\n";
		return;
	}
	fout << "  " << string(90, '-') << endl;
	fout << "  |" << "  |      Название      |       |                                |           |           |" << endl;
	fout << "  |" << "  |   садоводческого   | Номер |              ФИО               |  Площадь  | Стоимость |" << endl;
	fout << "  |" << "№ |    товарищества    |участка|           владельца            |участка,m^2|  участка  |" << endl;
	fout << "  " << string(90, '-') << endl;
	for (int i = 0; i < n; i++) {
		fout << left << "  |" << setw(2) << i + 1 << "|" << setw(20) << X[i].name << "|" << setw(7) << X[i].num << "|" << setw(32) << X[i].owner << "|" << setw(11) << X[i].S << "|" << setw(11) << X[i].price << "|" << right << endl;
	}
	fout.close();
	cout << "Массив сохранен в файле " << file << endl;
}

void mas::inputInfoFile() {
	string file, init;
	info t;
	ifstream fin;
	cout << "Имя выходного файла: "; cin >> file;
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
		X[i].owner = X[i].owner + " " + init;
	}
	fin.close();
	cout << "\nЗагружено " << n << " записей\n";
}

void mas::sortPrice() {
	int nn = n;
	if (nn == 0) {
		cout << "Массив пустой\n";
		return;
	}
	bool fl;
	info t;
	do {
		fl = false;
		nn--;
		for (int i = 0; i < nn; i++) {
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

void mas::sortOwner() {
	int nn = n;
	if (nn == 0) {
		cout << "Массив пустой\n";
		return;
	}
	bool fl;
	info t;
	do {
		fl = false;
		nn--;
		for (int i = 0; i < nn; i++) {
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

void mas::sortStruct() {
	int nn = n;
	if (nn == 0) {
		cout << "Массив пустой\n";
		return;
	}
	bool fl;
	info t;
	do {
		fl = false;
		nn--;
		for (int i = 0; i < nn; i++) {
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