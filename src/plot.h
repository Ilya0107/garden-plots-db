#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


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

