#include <iostream>
#include <windows.h>
#include <string.h>
#include <fstream>
#include <format>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
using namespace std;


struct info {
	string name;
	int num;
	string owner;
	double S;
	double price;
};

class mas {
private:
	info *px;
	int n;
public:
	mas(): px(NULL), n(0){}
	mas(mas& z);
	~mas() { if (px != NULL) delete[]px; }
	void sortPrice();
	void sortOwner();
	void sortStruct();
	void inputMasInfo();
	void outputMasInfo();
	void delInfo();
	void inputInfoFile();
	void correctInfo();
	void outputInfoFile();
};



//Основной код
int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	mas A, B;
	int choice(0);
	while (true) {
		system("cls"); //Для очистки экрана 
		cout << "Программа для обработки файлов Садоводческих участков\n";
		cout << "\nМеню функций:\n";
		cout << "1.   Ввод информации с клавиатуры\n";
		cout << "2.   Просмотр существующего массива данных\n";
		cout << "3.   Удаление строки \n";
		cout << "4.   Вывод БД из файла\n";
		cout << "5.   Редактирование записи в базе данных\n";
		cout << "6.   Сохранить массив в файл\n";
		cout << "7.   Сортировка массива по цене\n";
		cout << "8.   Сортировка массива по имени владельца в алфавитном порядке\n";
		cout << "9.   Сортировка массива по названию товарищества и имени владельца\n";
		cout << "10.  Проверка конструктора копирования\n";
		cout << "11.  Выход из программы\n";
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
		case 10: {
			mas B(A);
			A.outputMasInfo();
			B.outputMasInfo();
			B.sortOwner();
			A.outputMasInfo();
			B.outputMasInfo();
			system("pause");
			break;
		}
		case 11:
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

mas::mas(mas& z): n(z.n){
	int i;
	if (z.px == NULL) px = NULL;
	else {
		px = new info[n];
		if (px == NULL) {
			cout << "нет памяти.\n";
			cout << "Конструктор копирования.\n";
			exit(0); 
		}
		for (i = 0; i < n; i++)
		px[i] = z.px[i];
	}
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
			if (px[i].price > px[i + 1].price) {
				fl = true;
				t = px[i];
				px[i] = px[i + 1];
				px[i + 1] = t;
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
			if (px[i].owner > px[i + 1].owner) {
				fl = true;
				t = px[i];
				px[i] = px[i + 1];
				px[i + 1] = t;
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
			if (px[i].name > px[i + 1].name) {
				fl = true;
				t = px[i];
				px[i] = px[i + 1];
				px[i + 1] = t;
			}
			else if ((px[i].name == px[i + 1].name) and (px[i].owner > px[i + 1].owner)) {
				fl = true;
				t = px[i];
				px[i] = px[i + 1];
				px[i + 1] = t;
			}
		}
	} while (fl);
	cout << "Массив упорядочен\n";
}

void mas::inputMasInfo() {
	info* p;
	string init;
	p = new info[n + 1];
	if (p == NULL) { cout << "Нет памяти\n"; return; }
	for (int i = 0; i < n; i++) p[i] = px[i];
	n++;
	cout << "Название товарищества: "; cin >> p[n - 1].name;
	cout << "Номер участка: "; cin >> p[n - 1].num;
	cout << "ФИО владельца: "; cin >> p[n - 1].owner >> init;
	p[n - 1].owner = p[n - 1].owner + " " + init;
	cout << "Площадь: "; cin >> p[n - 1].S;
	cout << "Стоимость: "; cin >> p[n - 1].price;
	if (px != NULL)delete[]px;
	px = p;
	cout << "Запись добавлена\n";
}

void mas::outputMasInfo() {
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
		cout << fixed << setprecision(1) << left << "  |" << setw(2) << i + 1 << "|" << setw(20) << px[i].name << "|" << setw(7) << px[i].num << "|" << setw(32) << px[i].owner << "|" << setw(11) << px[i].S << "|" << setw(9) << px[i].price << "|" << right << endl;
	}
}

void mas::delInfo() {
	int R;
	char q;
	outputMasInfo();
	if (n == 0) return;
	cout << "Введите номер строки, которую хотите удалить: "; cin >> R;
	if (R < 0 || n < R){
		cout << "Нет такой строки\n";
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
		cout << px[R].name << " " << px[R].num << " " << px[R].owner << " " << px[R].S << " " << px[R].price << endl;
		cout << "\nУдалить строку? (Y/N): "; cin >> q;
		if (q == 'N') {
			cout << "Отмена удаления\n";
			return;
		}
		if (q != 'Y') {
			cout << "Неверный выбор\n";
			return;
		}
		for (int i = R + 1; i < n; i++) px[i - 1] = px[i];
		n--;
		cout << "Запись удалена\n";
}

void mas::inputInfoFile() {
	ifstream fin;
	string init, file;
	info t;
	cout << "Введите название входного файла: "; cin >> file;

	fin.open(file.c_str());
	if (fin.fail()) {
		cout << file << " не открывается\n";
		return;
	}
	n = 0;
	while (true) {
		fin >> t.name >> t.num >> t.owner >> init >> t.price >> t.S;
		if (fin.fail()) break;
		n++;
	}
	fin.close(); fin.open(file.c_str());
	if (fin.fail()) {
		cout << file << " не открывается повторно\n";
		return;
	}
	if (px != NULL) { delete[] px; px = NULL; }
	px = new info[n];

	if (px == NULL) {
		cout << "Нет памяти\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		fin >> t.name >> t.num >> t.owner >> init >> t.price >> t.S;
		px[i] = t;
		px[i].owner = px[i].owner + " " + init;
	}
	cout << "Загружено " << n << " записей\n";
}

void mas::correctInfo() {
	if (n == 0) {
		cout << "Массив пустой\n";
		return;
	}
	int d;
	char q;
	string init;
	info t;
	outputMasInfo();
	cout << "Введите номер строки, которую хотите изменить: "; cin >> d;
	d--;
	if (d < 0 || n < d) {
		cout << "Нет такой строки\n";
		return;
	}

	cout << "\nВаша строка:\n";
	cout << px[d].name << " " << px[d].num << " " << px[d].owner << " " << px[d].S << " " << px[d].price << endl;
	cout << "Подтвердить редактировние (Y/N)? "; cin >> q;
	if (q == 'N') {
		cout << "Отмена удаления\n";
		return;
	}
	if (q != 'Y') {
		cout << "Неверный выбор\n";
		return;
	}

	cout << "Введите новую строку\n";
	cout << "Название товарищества: "; cin >> t.name;
	cout << "Номер участка: "; cin >> t.num;
	cout << "ФИО владельца: "; cin >> t.owner >> init;
	t.owner = t.owner + " " + init;
	cout << "Площадь: "; cin >> t.S;
	cout << "Стоимость: "; cin >> t.price;
	px[d] = t;
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
		fout << left << "  |" << setw(2) << i + 1 << "|" << setw(20) << px[i].name << "|" << setw(7) << px[i].num << "|" << setw(32) << px[i].owner << "|" << setw(11) << px[i].S << "|" << setw(11) << px[i].price << "|" << right << endl;
	}
	fout.close();
	cout << "Массив сохранен в файле " << file << endl;
}