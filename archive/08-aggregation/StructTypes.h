#pragma once
#include <iostream>
#include <string>
#include <iomanip>
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
bool operator>(info& v, info& w);
istream& operator>>(istream& in, info& z);
ostream& operator<<(ostream& out, info& z);
ostream& operator<<(ostream& out, nameCount& z);

