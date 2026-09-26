#pragma once
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

#include "structTypes.h"
using namespace std;

class masB;
class mas;

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
	void findPr(mas& v);
	void sortPr();
	friend ostream& operator<<(ostream& out, masC& z);
	friend ofstream& operator<<(ofstream& fout, masC& z);

};

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


class mas {
private:
	info* px;
	int n;
public:
	mas() : px(NULL), n(0) {}
	mas(mas& z);
	~mas() { if (px != NULL) delete[]px; }
	void sortPrice();
	void sortOwner();
	void sortStruct();
	void inputMasInfo();
	void delInfo();
	void correctInfo();
	friend ifstream& operator>>(ifstream& fin, mas& z);
	friend ofstream& operator<<(ofstream& fout, mas& z);
	mas& operator=(mas& z);
	
	
	friend ostream& operator<<(ostream& out, mas& z);
	friend void makePerech(mas& v, masB& w);
	friend void masC::findPr(mas& v);

};






