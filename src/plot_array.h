#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include "plot.h"
using namespace std;

class PlotArray {
protected:
    Plot* px;
    int n;
public:
    PlotArray() : px(NULL), n(0) {}
    PlotArray(PlotArray& z);
    ~PlotArray() { if (px != NULL) delete[] px; }
    PlotArray& operator=(PlotArray& z);
    void sortPrice();
    void sortOwner();
    void sortStruct();
    void inputMasInfo();
    void delInfo();
    void correctInfo();
    friend ifstream& operator>>(ifstream& fin, PlotArray& z);
    friend ofstream& operator<<(ofstream& fout, PlotArray& z);
    friend ostream& operator<<(ostream& out, PlotArray& z);
};
