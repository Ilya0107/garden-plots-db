#include "StructTypes.h"

bool operator>(info& v, info& w) {
	if (v.name > w.name) return 1;
	if ((v.name == w.name) and (v.owner > w.owner)) return 1;
	return 0;
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