#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <math.h>
#include <fcntl.h>
#include <limits.h>
#include <iostream>
#define MaxLine 1024

using namespace std;

class Polygon{

private:
    unsigned int _m;
    unsigned int _n;
    double **_point;

public:
    //  Default Constructor
    Polygon(): _m(0), _n(0){
        printf("Default constructor with initial value %d %d\n", this->_m, this->_n);
        fflush(stdout);
    };
    Polygon(unsigned int m, unsigned int n): _m(m), _n(n){
        printf("Default constructor with initial value %d %d\n", this->_m, this->_n);
        //  Allocate _point according to m and n
        this->_point = new double*[this->_m];
        for(int i=0; i<this->_m; i++){
            this->_point[i] = new double[this->_n];
        }
        fflush(stdout);
    };

    //  Copy Constructor
    Polygon(const Polygon &cp){
        cout << "Copy Constructor..." << endl;
        this->_m = cp._m;
        this->_n = cp._n;
        this->_point =  cp._point;
    };
    
    //  Destructor
    ~Polygon(){
        cout << "Destructor..." << endl;
    };


    double* FindCentroid() const; // return the centroid of the polygon
    const int getNumOfPoints() const;
    const int getDimension() const;
    const double getValue (unsigned int m, unsigned int n) const;
    bool setValue (double & value, unsigned int m, unsigned int n);

};

void PrintPoints(Polygon p);
