#pragma once
#include "Classses.h"

class agregate{
private:
	mas aa;
	masB bb;
	masC cc;
public:
	agregate() {}
	agregate(agregate& z) : aa(z.aa), bb(z.bb), cc(z.cc) {}
	~agregate() {}
	agregate& operator=(agregate& z);
	void inputFile();
    void outputMasInfo();
    void outputMasInfoFile();
    void InputMasInfo();
    void deleteInfo();
    void sortPriceA();
    void sortOwnerA();
    void sortStructA();
    void makePerechA();
    void outputPerech();
    void outputPerechFile();
    void sortPerechName();
    void sortPerechCount();
    void findPrice();
    void outputFind();
    void outputFindFile();
    void sortFindNa();
    void sortFindPr();
    void correctMasInfo();
    friend ostream& operator<<(ostream& out, agregate& z);
};

