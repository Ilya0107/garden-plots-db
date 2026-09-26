#include "Classses.h"

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
		out << left << "  |" << setw(2) << i + 1 << z.py[i] << endl;
	return out;
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
		return*this;
	}

	py = new nameCount[k];
	if (py == NULL) { cout << "Нет памяти\nОператор = перечня\n"; exit(0); }
	for (int i = 0; i < k; i++) py[i] = z.py[i];
	return*this;
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

void makePerech(mas& v, masB& w) {
	int fl, k;
	nameCount* p;
	int n = v.n;
	p = new nameCount[n];
	if (p == NULL) {
		cout << "Нет памяти (Создание перечня)\n";
		return;
	}
	k = 0;

	if (w.py != NULL) delete[]w.py;

	for (int i = 0; i < n; i++) {
		fl = 0;
		for (int j = 0; j < k; j++) {
			if (p[j].name == v.px[i].name) {
				fl = 1;
				p[j].count++;
			}
		}
		if (fl == 0) {
			p[k].name = v.px[i].name;
			p[k].count = 1;
			k++;
		}
	}
	w.py = new nameCount[k];
	if (w.py == NULL) {
		cout << "Нет памяти (Создание перечня)\n";
		k = 0;
		delete[] p;
		return;
	}
	for (int i = 0; i < k; i++)
		w.py[i] = p[i];
	delete[] p;
	w.k = k;
	cout << "Перечень создан\n";
	return;
}

ofstream& operator<<(ofstream& out, masB& z) {
	string file;
	cout << "Имя входного файла: "; cin >> file;
	out.open(file.c_str());
	if (out.fail()) {
		cout << file << "\nНе создается\n";
		return out;
	}
	if (z.k == 0) { cout << "Массив пустой\n"; return out; }
	out << "  " << string(36, '-') << endl;
	out << "  |" << "  |      Название      |          |" << endl;
	out << "  |" << "  |   садоводческого   |Количество|" << endl;
	out << "  |" << "№ |    товарищества    |          |" << endl;
	out << "  " << string(36, '-') << endl;
	for (int i = 0; i < z.k; i++)
		out << left << "  |" << setw(2) << i + 1 << z.py[i] << endl;
	out << "  " << string(36, '-') << endl;
	cout << "Перечень сохранен в " << file << endl;
	return out;
}
