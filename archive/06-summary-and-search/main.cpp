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

struct nameCount {
	string name;
	int count;
};

istream& operator>>(istream& in, info& z);
ostream& operator<<(ostream& out, info& z);
ostream& operator<<(ostream& out, nameCount& z);

bool operator>(info& v, info& w);

class mas {
private:
	info* px;
	int n;
public:
	mas() : px(NULL), n(0) {}
	mas(mas& z);
	~mas() { if (px != NULL) delete[]px; }
	int get_n() { return n; }
	info get_px(int i) { return px[i]; }
	void sortPrice();
	void sortOwner();
	void sortStruct();
	void inputMasInfo();
	void delInfo();
	void inputInfoFile();
	void correctInfo();
	void outputInfoFile();
	mas& operator=(mas& z);
	friend ostream& operator<<(ostream& out, mas& z);
};

class masB {
private:
	nameCount* py;
	int k;
public:
	masB(): py(NULL), k(0){}
	masB(masB& z);
	~masB() { if (py != NULL) delete[] py; }
	masB& operator=(masB& z);
	void sortName();
	void sortCount();
	friend ostream& operator<<(ostream& out, masB& z);
	void makePerech(mas& v);
	void PoutputFile();

};

class masC {
private:
	info* pz;
	int l;
public:
	masC() : pz(NULL), l(0) {}
	masC(masC& z);
	~masC() { if (pz != NULL) delete[]pz; }
	masC& operator=(masC& z);
	void sortNa();
	void sortPr();
	friend ostream& operator<<(ostream& out, masC& z);
	void findPr(mas& z);
	void searchOutputFIle();
};


//Основной код
int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	mas A, X;
	masB B, Z;
	masC C, Y;
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
		cout << "11   Проверка оператора присваивания\n";
		cout << "------------------------Перечень------------------------------------\n";
		cout << "12.   Создание перечня\n";
		cout << "13.   Вывод перечня на экран\n";
		cout << "14.   Проверка конструктора копирования перечня\n";
		cout << "15.   Проверка оператора присваивания перечня\n";
		cout << "16.   Сортировка перечня в алфавитном порядке\n";
		cout << "17.   Сортировка перечня по возрастанию\n";
		cout << "18.   Сохранения перечня в файл\n";
		cout << "------------------------Поиск по цене--------------------------------\n";
		cout << "19.   Поиск в масcиве участков цена которых превышает заданную\n";
		cout << "20.   Вывод результатов поиска\n";
		cout << "21.   Проверка конструктора копирования поиска\n";
		cout << "22.   Проверка оператора присваивания поиска\n";
		cout << "23.   Сортировка поиска в алфавитном порядке\n";
		cout << "24.   Сортировка поиска по возрастанию цены\n";
		cout << "25.   Сохранения поиска в файл\n";
		cout << "-------------------------------------------------------------------------\n";
		cout << "26.  Выход из программы\n";
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
			cout << A;
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
			mas X(A);
			cout << "Исходные массивы:\n";
			cout << A << X;
			X.sortOwner();
			cout << "Неизмененный массив\n\n";
			cout << A << "Измененный массив\n\n" << X;
			system("pause");
			break;
		}
		case 11: {
			mas f, d; f = d = A;
			cout << f << d << A;
			A.sortPrice();
			cout << f << d << A;
			system("pause");
			break;
		}
		case 12:
			B.makePerech(A);
			system("pause");
			break;
		case 13:
			cout << B;
			system("pause");
			break;
		case 14:
		{
			masB Z(B);
			cout << Z << B;
			Z.sortName();
			cout << Z << B;
			system("pause");
			break;
		}
		case 15:
		{
			masB q, w; q = w = B;
			cout << q << w << B;
			B.sortCount();
			cout << q << w << B;
			system("pause");
			break;
		}
		case 16:
			B.sortName();
			system("pause");
			break;
		case 17:
			B.sortCount();
			system("pause");
			break;
		case 18:
			B.PoutputFile();
			system("pause");
			break;
		case 19:
			C.findPr(A);
			system("pause");
			break;
		case 20:
			cout << C;
			system("pause");
			break;
		case 21:
		{
			masC Y(C);
			cout << Y << C;
			Y.sortNa();
			cout << Y << C;
			system("pause");
			break;
		}
		case 22:
		{
			masC v, b;
			v = b = C;
			cout << v << b << C;
			v.sortPr();
			cout << v << b << C;
			system("pause");
			break;
		}
		case 23:
			C.sortNa();
			system("pause");
			break;
		case 24:
			C.sortPr();
			system("pause");
			break;
		case 25:
			C.searchOutputFIle();
			system("pause");
			break;
		case 26:
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

mas::mas(mas& z) : n(z.n) {
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
			if (px[i] > px[i + 1]) {
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
	cin >> p[n - 1];
	if (px != NULL)delete[]px;
	px = p;
	cout << "Запись добавлена\n";
}

void mas::delInfo() {
	int R;
	char q;
	cout << *this;
	if (n == 0) return;
	cout << "Введите номер строки, которую хотите удалить: "; cin >> R;
	if (R < 0 || n < R) {
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
		fin >> t.name >> t.num >> t.owner >> init >> t.S >> t.price;
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
		fin >> t.name >> t.num >> t.owner >> init >> t.S >> t.price;
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
	cout << *this;
	cout << "Введите номер строки, которую хотите изменить: "; cin >> d;
	d--;
	if (d < 0 || n < d) {
		cout << "Нет такой строки\n";
		return;
	}

	cout << "\nВаша строка:\n";
	cout << px[d].name << " " << px[d].num << " " << px[d].owner << " " << px[d].S << " " << px[d].price << endl;
	cout << "Подтвердить редактирование (Y/N)? "; cin >> q;
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

mas& mas:: operator=(mas& z) {
	if (this == &z) return *this;
	if (px != NULL) delete[]px;
	n = z.n;
	if (z.px == NULL)  px = NULL;
	else {
		px = new info[n];
		for (int i = 0; i < n; i++)
			px[i] = z.px[i];
	}
	return *this;
}
istream& operator>>(istream& in, info& z) {
	string init;
	cout << "Название товарищества: "; in >> z.name;
	cout << "Номер участка: "; in >> z.num;
	cout << "ФИО владельца: "; in >> z.owner >> init;
	z.owner = z.owner + " " + init;
	cout << "Площадь: "; in >> z.S;
	cout << "Стоимость: "; in >> z.price;
	return in;
}

ostream& operator<<(ostream& out, info& z) {
	out << fixed << setprecision(1) << left << "|" << setw(20) << z.name << "|" << setw(7) << z.num << "|" << setw(32) << z.owner << "|" << setw(11) << z.S << "|" << setw(9) << z.price << "|" << right << endl;
	return out;
}
ostream& operator<<(ostream& out, nameCount& z) {
	out << fixed << left << '|' << setw(20) << z.name << '|' << setw(10) << z.count << '|';
	return out;
}

ostream& operator<<(ostream& out, mas& z) {
	if (z.n == 0) {
		out << "Массив пустой\n";
		return out;
	}
	out << "  " << string(88, '-') << endl;
	out << "  |" << "  |      Название      |       |                                |           |         |" << endl;
	out << "  |" << "  |   садоводческого   | Номер |              ФИО               |  Площадь  |Стоимость|" << endl;;
	out << "  |" << "№ |    товарищества    |участка|           владельца            |участка,m^2| участка |" << endl;;
	out << "  " << string(88, '-') << endl;
	for (int i = 0; i < z.n; i++)
		out << fixed << setprecision(1) << left << "  |" << setw(2) << i + 1 << z.px[i];
	return out;
}

ostream& operator<<(ostream& out, masB& z) {
	if (z.k == 0) {
		cout << "Перечень пуст\n";
		return out;
	}
	out << "  " << string(36, '-') << endl;
	out << "  |" << "  |      Название      |          |" << endl;
	out << "  |" << "  |   садоводческого   |Количество|" << endl;
	out << "  |" << "№ |    товарищества    |          |" << endl;
	out << "  " << string(36, '-') << endl;
	for (int i = 0; i < z.k; i++)
		out << left << "  |" << setw(2) << i + 1 << z.py[i]  << endl;
	return out;
}
ostream& operator<<(ostream& out, masC& z) {
	if (z.l == 0) {
		out << "Массив пустой\n";
		return out;
	}
	out << "  " << string(88, '-') << endl;
	out << "  |" << "  |      Название      |       |                                |           |         |" << endl;
	out << "  |" << "  |   садоводческого   | Номер |              ФИО               |  Площадь  |Стоимость|" << endl;;
	out << "  |" << "№ |    товарищества    |участка|           владельца            |участка,m^2| участка |" << endl;;
	out << "  " << string(88, '-') << endl;
	for (int i = 0; i < z.l; i++)
		out << fixed << setprecision(1) << left << "  |" << setw(2) << i + 1 << z.pz[i];
	return out;
}
bool operator>(info& v, info& w) {
	if (v.name > w.name) return 1;
	if ((v.name == w.name) and (v.owner > w.owner)) return 1;
	return 0;
}

masB::masB(masB& z) {
	k = z.k;
	if (z.py == NULL) { py = NULL; exit(0); }
	py = new nameCount[k];
	if (py == NULL) { cout << "Нет памяти\nКонструктор копирования перечня\n"; exit(0); }
	for (int i = 0; i < k; i++) py[i] = z.py[i];
}

masB& masB:: operator=(masB& z) {
	if (&z == this) { return *this; }
	if (py != NULL) delete py;

	k = z.k;
	if (z.py == NULL) { 
		py = NULL; 
		return*this; }
	
	py = new nameCount[k];
	if (py == NULL) { cout << "Нет памяти\nОператор = перечня\n"; exit(0); }
	for (int i = 0; i < k; i++) py[i] = z.py[i];
	return* this;
}

void masB::sortName() {
	int kk; kk = k;
	bool fl;
	nameCount t;
	if (kk == 0) {
		cout << "Массив пустой\n";
		return;
	}
	do {
		fl = false;
		kk--;
		for (int i = 0; i < kk; i++) {
			if (py[i].name > py[i + 1].name) {
				fl = true;
				t = py[i + 1];
				py[i + 1] = py[i];
				py[i] = t;
			}
		}
	} while (fl);
	cout << "Перечень отсортирован\n";
}

void masB::sortCount() {
	int kk; kk = k;
	bool fl;
	nameCount t;
	if (kk == 0) {
		cout << "Массив пустой\n";
		return;
	}
	do {
		fl = false;
		kk--;
		for (int i = 0; i < kk; i++) {
			if (py[i].count > py[i + 1].count) {
				fl = true;
				t = py[i + 1];
				py[i + 1] = py[i];
				py[i] = t;
			}
		}
	} while (fl);
	cout << "Перечень отсортирован\n";
}

void masB::makePerech(mas& v) {
	int fl;
	nameCount* p;
	int n = v.get_n();
	p = new nameCount[n];
	if (p == NULL) {
		cout << "Нет памяти (Создание перечня)\n";
		return;
	}
	k = 0;

	if (py != NULL) delete[]py;
	
	for (int i = 0; i < n; i ++){
		fl = 0;
		for (int j = 0; j < k; j++) {
			if (p[j].name == v.get_px(i).name) {
				fl = 1;
				p[j].count++;
			}
		}
		if (fl == 0) {
			p[k].name = v.get_px(i).name;
			p[k].count = 1;
			k++;
		}
	}
	py = new nameCount[k];
	if (py == NULL) {
		cout << "Нет памяти (Создание перечня)\n";
		k = 0;
		delete[] p;
		return;
	}
	for (int i = 0; i < k; i++)
		py[i] = p[i];
	delete[] p;
	cout <<  "Перечень создан\n";
	return;
}

void masB::PoutputFile() {
	ofstream fout;
	string file;
	cout << "Имя входного файла: "; cin >> file;
	fout.open(file.c_str());
	if (fout.fail()) {
		cout << file << "\nНе создается\n";
		return;
	}
	fout << *this;
	cout << "Перечень сохранен в " << file << endl;
}

masC::masC(masC& z) : l(z.l) {
	int i;
	if (z.pz == NULL) pz = NULL;
	else {
		pz = new info[l];
		if (pz == NULL) {
			cout << "нет памяти.\n";
			cout << "Конструктор копирования поиска.\n";
			exit(0);
		}
		for (i = 0; i < l; i++)
			pz[i] = z.pz[i];
	}
}

masC& masC:: operator=(masC& z) {
	if (this == &z) return *this;
	if (pz != NULL) delete[]pz;
	l = z.l;
	pz = new info[l];
	if (pz == NULL) { cout << "Нет памяти. Оператор присваивания поиска"; exit(1); }
	for (int i = 0; i < l; i++) 
		pz[i] = z.pz[i];
	return *this;
}

void masC::sortNa() {
	int nn = l;
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
			if (pz[i].name > pz[i + 1].name) {
				fl = true;
				t = pz[i];
				pz[i] = pz[i + 1];
				pz[i + 1] = t;
			}
		}
	} while (fl);
	cout << "Массив упорядочен\n";
}

void masC:: sortPr() {
	int nn = l;
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
			if (pz[i].price > pz[i + 1].price) {
				fl = true;
				t = pz[i];
				pz[i] = pz[i + 1];
				pz[i + 1] = t;
			}
		}
	} while (fl);
	cout << "Массив упорядочен\n";
}

void masC::findPr(mas& v) {
	double in0;
	info* p;
	int n = v.get_n();
	cout << "Поиск в маccиве участков цена которых превышает N\n Введите N: "; cin >> in0;
	p = new info[n];
	if (p == NULL) {
		cout << "Нет памяти (поиск)\n";
		return;
	}
	
	l = 0;
	for (int i = 0; i < n; i++) {
		if (in0 <= v.get_px(i).price) {
			p[l] = v.get_px(i);
			l++;
		}
	}
	pz = new info[l];
	if (pz == NULL) {
		cout << "Нет памяти (поиск)\n";
		delete[] p;
		l = 0;
		return;
	}
	for (int i = 0; i < l; i++)
		pz[i] = p[i];
	cout << "Поиск завершен\n";
	delete[] p;
	return;
}

void masC::searchOutputFIle() {
	ofstream fout;
	string file;
	cout << "Имя входного файла: "; cin >> file;
	fout.open(file.c_str());
	if (fout.fail()) {
		cout << file << "\nНе создается\n";
		return;
	}
	fout << *this;
	cout << "Поиск сохранен в " << file << endl;
}