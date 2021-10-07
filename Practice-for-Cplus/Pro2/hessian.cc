#include "hessian.h"
#include <cstdio>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cassert>

Hessian::Hessian(const char *filename)
{
    std::ifstream hessian(filename);
    assert(hessian.good());
    hessian >>natom;

    H=new double* [natom*3];
    for(int i = 0;i < natom*3;i++)
        H[i] =new double[natom*3];
    
    for(int i=0;i<natom*3;i++){
        for(int j=0;j<natom;j++) {
            hessian >> H[i][3*j] >>H[i][3*j+1]>>H[i][3*j+2];
        }
    }
    hessian.close();
}

void Hessian::print_hessian()
{
    for(int i=0;i<natom*3;i++){
        for(int j=0;j<natom*3;j++){
            printf("%14.6f", H[i][j]);
        }
        printf("\n");
    }
}

Hessian::~Hessian()
{
    for(int i=0;i <natom*3;i++)
        delete[] H[i];
    delete[] H;
}
