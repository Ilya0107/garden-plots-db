#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

#include "structTypes.h"
using namespace std;

class masB;
class masC;

class mas {
private:
	info* px;
	int n;
public:
	mas() : px(NULL), n(0) {}
	mas(mas& z);
	~mas() { if (px != NULL) delete[]px; }
	int get_n() { return n; }
	info get_px(int i) { return px[i]; }
	void sortPrice();
	void sortOwner();
	void sortStruct();
	void inputMasInfo();
	void delInfo();
	friend ifstream& operator>>(ifstream& fin, mas& z);
	friend ofstream& operator<<(ofstream& fout, mas& z);
	void correctInfo();
	mas& operator=(mas& z);
	friend ostream& operator<<(ostream& out, mas& z);
	friend void makePerech(mas& v, masB& w);
	friend void findPr(mas& v, masC& w);

};
