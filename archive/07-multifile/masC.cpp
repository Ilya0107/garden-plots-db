#include "Classes.h"

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

void masC::sortPr() {
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


ofstream& operator<<(ofstream& fout, masC& z) {
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
	for (int i = 0; i < z.l; i++) {
		fout << left << "  |" << setw(2) << i + 1 << "|" << setw(20) << z.pz[i].name << "|" << setw(7) << z.pz[i].num << "|" << setw(32) << z.pz[i].owner << "|" << setw(11) << z.pz[i].S << "|" << setw(11) << z.pz[i].price << "|" << right << endl;
	}
	fout.close();
	cout << "Массив сохранен в файле " << file << endl;
	return fout;
}

void masC::findPr(mas& v)
{
	double in0;
	info* p;
	int n = v.n;
	cout << "Поиск в массиве участков цена которых превышает N\n Введите N: "; cin >> in0;

	p = new info[n];
	if (p == NULL) {
		cout << "Нет памяти (поиск)\n";
		return;
	}

	l = 0;
	for (int i = 0; i < n; i++) {
		if (in0 <= v.px[i].price) {
			p[l] = v.px[i];
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
