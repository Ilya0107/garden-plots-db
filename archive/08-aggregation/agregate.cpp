#include "agregate.h"

agregate& agregate::operator=(agregate& z)
{
    aa = z.aa;
    bb = z.bb;
    cc = z.cc;
    return *this;
}

void agregate::inputFile(){
    ifstream fin;
    fin >> aa;
}

void agregate::outputMasInfoFile(){
    ofstream fout;
    fout << aa;
}

void agregate::outputMasInfo() {
    cout << aa;
}

void agregate::InputMasInfo(){
    aa.inputMasInfo();
}

void agregate::deleteInfo(){
    aa.delInfo();
}

void agregate::correctMasInfo() {
    aa.correctInfo();
}

void agregate::sortPriceA(){
    aa.sortPrice();
}

void agregate::sortOwnerA(){
    aa.sortOwner();
}

void agregate::sortStructA(){
    aa.sortStruct();
}

void agregate::makePerechA(){
    makePerech(aa, bb);
}

void agregate::outputPerech(){
    cout << bb;
}

void agregate::outputPerechFile(){
    ofstream fout;
    fout << bb;
}

void agregate::sortPerechName(){
    bb.sortName();
}

void agregate::sortPerechCount(){
    bb.sortCount();
}

void agregate::findPrice(){
    cc.findPr(aa);
}

void agregate::outputFind(){
    cout << cc;
}

void agregate::outputFindFile(){
    ofstream fout;
    fout << cc;
}

void agregate::sortFindNa(){
    cc.sortNa();
}

void agregate::sortFindPr(){
    cc.sortPr();
}


ostream& operator<<(ostream& out, agregate& z){
    out << z.aa;
    out << z.bb;
    out << z.cc;
    return out;
}
