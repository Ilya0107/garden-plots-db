#include "plot_summary.h"

ostream& operator<<(ostream& out, PlotSummary& z) {
	if (z.k == 0) {
		out << "Перечень пуст\n";
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

PlotSummary::PlotSummary(PlotSummary& z): PlotArray(z) {
	k = z.k;
	if (z.py == NULL) { py = NULL; exit(0); }
	py = new PlotCount[k];
	if (py == NULL) { cout << "Нет памяти\nКонструктор копирования перечня\n"; exit(0); }
	for (int i = 0; i < k; i++) py[i] = z.py[i];
}

PlotSummary& PlotSummary:: operator=(PlotSummary& z) {
	if (&z == this) { return *this; }

	PlotArray::operator=(z);
	if (py != NULL) delete py;

	k = z.k;
	if (z.py == NULL) {
		py = NULL;
		return*this;
	}

	py = new PlotCount[k];
	if (py == NULL) { cout << "Нет памяти\nОператор = перечня\n"; exit(0); }
	for (int i = 0; i < k; i++) py[i] = z.py[i];
	return*this;
}

void PlotSummary::sortName() {
	int kk; kk = k;
	bool fl;
	PlotCount t;
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

void PlotSummary::sortCount() {
	int kk; kk = k;
	bool fl;
	PlotCount t;
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

void PlotSummary::makePerech() {
	int fl, kk;
	PlotCount* p = new PlotCount[n];
	if (p == NULL) {
		cout << "Нет памяти (Создание перечня)\n";
		return;
	}
	kk = 0;

	if (py != NULL) delete[]py;

	for (int i = 0; i < n; i++) {
		fl = 0;
		for (int j = 0; j < kk; j++) {
			if (p[j].name == px[i].name) {
				fl = 1;
				p[j].count++;
			}
		}
		if (fl == 0) {
			p[kk].name = px[i].name;
			p[kk].count = 1;
			kk++;
		}
	}
	k = kk;
	py = new PlotCount[k];
	if (py == NULL) {
		cout << "Нет памяти (Создание перечня)\n";
		k = 0;
		delete[] p;
		return;
	}
	for (int i = 0; i < k; i++)
		py[i] = p[i];
	delete[] p;
	k = k;
	cout << "Перечень создан\n";
	return;
}

ofstream& operator<<(ofstream& out, PlotSummary& z) {
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
