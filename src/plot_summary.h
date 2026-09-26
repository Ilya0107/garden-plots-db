#pragma once
#include "plot_array.h"

class PlotSummary : public PlotArray {
protected:
    PlotCount* py;
    int k;
public:
    PlotSummary() : py(NULL), k(0) {}
    PlotSummary(PlotSummary& z);
    ~PlotSummary() { if (py != NULL) delete[] py; }
    PlotSummary& operator=(PlotSummary& z);
    void sortName();
    void sortCount();
    void makePerech();
    friend ostream& operator<<(ostream& out, PlotSummary& z);
    friend ofstream& operator<<(ofstream& fout, PlotSummary& z);
};
