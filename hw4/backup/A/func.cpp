#include "header.h"

using namespace std;

double *Polygon::FindCentroid() const{
    double *c = new double[this->_n];
    for(int i=0; i<(this->_n); i++){
        double sum = 0;
        for(int j=0; j<(this->_m); j++){
            sum += _point[j][i];
        }
        /* cout << sum << endl; */
        c[i] = sum / this->_m;
    }
    return c;
};

const int Polygon::getNumOfPoints() const{
    return this->_m;
}

const int Polygon::getDimension() const {
    return this->_n;
}

// Accessor: Get the value stored at the m-th point and n-th
// dimension
const double Polygon::getValue (unsigned int m, unsigned int n) const {
    if (m<0 || m>=_m || n<0 || n>=_n) {
        cerr << "ERROR: Index our of range" << endl;
        exit(-1);
    }
    else 
        return _point[m][n];
}

// Mutator: Set the value at the m-th point and n-th coordinate
bool Polygon::setValue (double & value, unsigned int m, unsigned int n) {
    if (m>=0 && m<_m && n>=0 && n<_n) {
        _point[m][n] = value;
        return true;
    }
    else
        return false;
}

void PrintPoints (Polygon p) {
    /* cout << p.getNumOfPoints() << endl; */
    /* cout << p.getDimension() << endl; */
    for(unsigned int i=0; i<p.getNumOfPoints(); i++){
        for(unsigned int j=0; j<p.getDimension(); j++){
            cout << p.getValue(i, j) << " " ;
        }
        cout << endl;
    }
}
