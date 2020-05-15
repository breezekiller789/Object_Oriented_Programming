#include "header.h"

using namespace std;

int main(int argc, char *argv[]){
    Polygon p(8, 2);
    double k = 0;
    for(int i=0; i<p.getNumOfPoints(); i++){
        for(int j=0; j<p.getDimension(); j++){
            k += 1;
            p.setValue(k, i, j);
            /* cout << p.getValue(i, j) << " "; */
        }
        /* cout << endl; */
    }
    PrintPoints(p);
    double *centroid = p.FindCentroid();
    for(int i=0; i<p.getDimension(); i++){
        printf("centroid[%d] = %f\n", i, centroid[i]);
    }
}
