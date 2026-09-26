#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <format>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

#include "masA.h"	
#include "structTypes.h"



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
	friend void findPr(mas& v, masC& w);
	void sortPr();
	friend ostream& operator<<(ostream& out, masC& z);
	friend ofstream& operator<<(ofstream& fout, masC& z);

};
