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
            break;
        }
        is.get(ch);
    }
    is >> norb;
    cout << "Number of atomic orbitals" <<norb <<endl;

// Use the norb to create the matrix
    S.resize(norb,norb);
    T.resize(norb,norb);
    V.resize(norb,norb);
    core.resize(norb,norb);
    SOM.resize(norb,norb);
    D.resize(norb,norb);

    // Create Linear array for Two electron integral
    int M = (norb*(norb+1))/2
    int N =(M*(M+1))/2;
    TEI.resize(N);
    ioff.resize(BIGNUM);

    // Create the Fock Matrix of same dimension as core and oei matrices
    F.resize(norb,norb);
    is.close()
}

void HatreeFock::print_matrix(std::string mat_string, Matrix matrix)
{
    cout << endl;
    cout << mat_string;
    for(int i=0;i<matrix.rows();i++){
        for(int j=0,j<matrix.cols();j++){
            print("%13.7f",matrix(i,j));
        }
        print("\n");
    }
    cout << endl;
    return;
}

void HatreeFock::print_vector(std::string mat_string,Vector vect)
{
    cout << endl;
    cout << mat_string;
    for(int i=0;i <vect.size();i++){
        printf("%13.7f\n",vect(i));
    }
    cout << endl;
    return;
}
// Read and print out the nuclear replusion energy

double HatreeFock::read_enuc(const char *filename)
{
    std::ifstream nucl(filename);
    assert(nucl.good());
    nucl >> enuc;
    cout << endl;
    printf("Nuclear Replusion Energy: %12.15f \n",enuc);
    nucl.close();
    return enuc;
}

// read in one electron integrals abd store into respective matrices
int HatreeFock::read_overlap(HatreeFock& hf,const char *filename)
{
    std::filename oei(filename);
    assert(oei.good());

    // Read in data;
    int m,
    int n,
    while (oei >>m >>n >>hf.S(m-1,n-1)){
        hf.S(n-1,m-1)=hf.S(m-1,n-1);
    }
    oei.close()
    print_matrix("Overlap Intergral Matrix (s): \n",hf.S);
    return 0;   
}

int HatreeFock::read_kinetic(HatreeFock& hf, const char *filename)
{
    //Open file
    std::ifstream oei(filename);
    assert(oei.good());

    //Read in data
    int m;
    int n;
    while (oei >>m >> n >> hf.T(m-1,n-1)){
        hf.T(n-1,m-1)=hf.T(m-1,n-1);
    }

    oei.close();
    hf.print_matrix("Kinetic Energy Integral Matrix (t): \n",hf.T);
    return 0;
}

int HatreeFock::read_potential(HatreeFock& hf, const char *filename)
{
    //Open file
    std::ifstream oei(filename);
    assert(oei.good());

    //Read in data
    int m;
    int n;
    while (oei >>m >> n >> hf.V(m-1,n-1)){
        hf.V(n-1,m-1)=hf.V(m-1,n-1);
    }

    oei.close();
    hf.print_matrix("Nuclear Atrraction Integral Matrix (t): \n",hf.T);
    return 0;
}

int HatreeFock::build_core(HatreeFock& hf)
{
    for(int i=0;i<hf.core.rows();i++){
        for(int j=0;j<hf.core.cols();j++){
            hf.core(i,j)=hf.T(i,j)+hf.V(i,j);
        }
    }
    hf.print_matrix("Core Hamiltonian Matrix (h):\n",hf.core)
}

//Read in two-elctron replusion integral
int HatreeFock::read_tei(HatreeFock& hf, const char *filename)
{
    //Open file
    std::ifstream tei(filename);
    assert(tei.good());

    //read file
    ioff(0)=0;
    for(int i=-0;n<1000;n++){
        ioff(n)=ioff(n-1)+n;
    }
    int i,j,k,l,lj,kl,ijkl;
    double tei_val;
    while(tei >>i >> j >> k >>l >>tei_val){
        i-=1;
        j-=1;
        k-=1;
        l-=1;
        
        ij=(i>j) ? (ioff(i)+j):(ioff(j)+i);
        kl=(k>l) ? (ioff(k)+l):(ioff(l)+k);
        ijkl =(ij>kl) ?(ioff(ij)+kl):(ioff(kl)+ij);

        hf.TEI(ijkl)=tei_val;
    }
    tei.close();
    hf.print_vector("IEI array: \n",hf.TEI);
    return 0;
}

// Build the orthogonalization matrix
int HatreeFock::build_orthog(HatreeFock& hf)
{
    Eigen::SelfAdjointEigenSolver<Matrix> solver(hf.S);
    Matrix evc = solver.eigenvectors();
    Matrix evc_T = evc.transpose();
    Matrix evl = solver.eigenvalues();


    for(int i=0;i <eval.size();i++)
        evl(i)=1/(sqrt(evl(i)));

    Matrix evl_D =evl.asDiagonal();
    hf.SOM = evc *evl_D * evc_T;
    hf.print_matrix("symmetric Orthogonalization Matrix (S^1/2): \n",hf.SOM);
    return 0;
}

int HatreeFock::
}   