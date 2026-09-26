#pragma once
#include "plot_summary.h"

class PlotSearch : public PlotSummary {
protected:
    Plot* pz;
    int l;
public:
    PlotSearch() : pz(NULL), l(0) {}
    PlotSearch(PlotSearch& z);
    ~PlotSearch() { if (pz != NULL) delete[] pz; }
    PlotSearch& operator=(PlotSearch& z);
    void sortNa();
    void findPr();
    void sortPr();
    friend ostream& operator<<(ostream& out, PlotSearch& z);
    friend ofstream& operator<<(ofstream& fout, PlotSearch& z);
};
