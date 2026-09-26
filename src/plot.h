#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


// Видимая ширина строки в символах (а не в байтах): в UTF-8 русская буква
// занимает 2 байта, поэтому стандартный setw по байтам ломает выравнивание.
inline size_t textWidth(const string& s) {
	size_t w = 0;
	for (unsigned char c : s) if ((c & 0xC0) != 0x80) ++w;
	return w;
}

// Дополняет строку пробелами до заданной видимой ширины.
inline string pad(const string& s, size_t width) {
	size_t w = textWidth(s);
	return w < width ? s + string(width - w, ' ') : s;
}


struct Plot {
	string name;
	int num;
	string owner;
	double area;
	double price;
};

struct PlotCount {
	string name;
	int count;
};
bool operator>(Plot& v, Plot& w);
istream& operator>>(istream& in, Plot& z);
ostream& operator<<(ostream& out, Plot& z);
ostream& operator<<(ostream& out, PlotCount& z);

