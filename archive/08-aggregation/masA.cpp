#include "Classses.h"

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

ifstream& operator>>(ifstream& fin, mas& z) {
	string init, file;
	info t;
	int n;
	cout << "Введите название входного файла: "; cin >> file;

	fin.open(file.c_str());
	if (fin.fail()) {
		cout << file << " не открывается\n";
		return fin;
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
		return fin;
	}
	if (z.px != NULL) { delete[] z.px; z.px = NULL; }
	z.px = new info[n];

	if (z.px == NULL) {
		cout << "Нет памяти\n";
		return fin;
	}
	for (int i = 0; i < n; i++) {
		fin >> t.name >> t.num >> t.owner >> init >> t.S >> t.price;
		z.px[i] = t;
		z.px[i].owner = z.px[i].owner + " " + init;
	}
	cout << "Загружено " << n << " записей\n";
	z.n = n;
	return fin;
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

ofstream& operator<<(ofstream& fout, mas& z) {
	string file;
	cout << "Имя входного файла: "; cin >> file;
	fout.open(file.c_str());
	if (fout.fail()) {
		cout << file << "\nНе создается\n";
		return fout;
	}
	fout << "  " << string(90, '-') << endl;
	fout << "  |" << "  |      Название      |       |                                |           |           |" << endl;
	fout << "  |" << "  |   садоводческого   | Номер |              ФИО               |  Площадь  | Стоимость |" << endl;
	fout << "  |" << "№ |    товарищества    |участка|           владельца            |участка,m^2|  участка  |" << endl;
	fout << "  " << string(90, '-') << endl;
	for (int i = 0; i < z.n; i++) {
		fout << left << "  |" << setw(2) << i + 1 << "|" << setw(20) << z.px[i].name << "|" << setw(7) << z.px[i].num << "|" << setw(32) << z.px[i].owner << "|" << setw(11) << z.px[i].S << "|" << setw(11) << z.px[i].price << "|" << right << endl;
	}
	fout.close();
	cout << "Массив сохранен в файле " << file << endl;
	return fout;
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