#include <iostream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cassert>
#include <cmath>
#include "HF.h"
#include "molecule.h"


#define BIGNUM 1000 // defining BIGNUM  
#define INDEX(i,j)(i,j) ? (ioff(i)+j):(ioff(j)+i)


#include "../Pro1/Eigen/Dense"
#include "../Pro1/Eigen/Eigenvalues"
#include "../Pro1/Eigen/Core"

typedef Eigen::Matrix<double, Eigen::Dynamic,Eigen::Dynamic,Eigen::RowMajor>Matrix;
// Eigen::RowMajor makes it so that Eigen stores matrices 
// by defaut in row-major order vs its actual default column-major order
typedef Eigen::Matrix<double, Eigen::Dynamic, 1>Vector;

// Allocat memmory for matrices after reading in norb

HatreeFock::HatreeFock(const char *filename)
{
    std::ifstream is(filename)
    assert(is.good());
    is.seekg(0,std::ios_base::end);
    char ch = " ";
    while(ch !="\n"){
        is.seekg(-2,std::ios_base::cur);
        if((int)is.tellg() <=0){
            is.seekg(0);
        } 
    }
    

}

