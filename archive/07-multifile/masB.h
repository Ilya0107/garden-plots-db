#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <fstream>

#include "masA.h"
#include "structTypes.h"
using namespace std;

class masB {
private:
	nameCount* py;
	int k;
public:
	masB() : py(NULL), k(0) {}
	masB(masB& z);
	~masB() { if (py != NULL) delete[] py; }
	masB& operator=(masB& z);
	void sortName();
	void sortCount();
	friend ostream& operator<<(ostream& out, masB& z);
	friend void makePerech(mas& v, masB& w);
	friend ofstream& operator<<(ofstream& fout, masB& z);

};
