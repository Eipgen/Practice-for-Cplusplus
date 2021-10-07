#include "molecule.h"
#include "masses.h"
#include "hessian.h"

#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <cmath>

#include "../Pro1/Eigen/Dense"
#include "../Pro1/Eigen/Eigenvalues"
#include "../Pro1/Eigen/Core"

typedef Eigen::Matrix<double, Eigen::Dynamic,Eigen::Dynamic,Eigen::RowMajor>Matrix;

using namespace std;
 

int main()
{
    Molecule mol("geom.dat",0);
    cout << "\nnumber of atoms\n" << mol.natom <<endl;
    cout << endl;
    cout << "\nInput Cartesian corrdinates: \n";
    mol.print_geom();
    cout << endl;

    Hessian hess("h2o_hessian.txt");
    if (mol.natom !=hess.natom)
    {
        cout << "\n The hessian does not correspond to the geometry\n" <<endl;
        exit(0);
    }

    cout << "Input Hessian Matrix: \n";
    hess.print_hessian();
    cout << endl;

    //Mass weighted Hessian Matrix

    double m[mol.natom];
    for (int i=0; i<mol.natom;i++)
        m[i]=an2masses[(int) mol.zvals[i]];
    
    cout << "Weight of atoms(amu):\n";
    for(int i=0;i<mol.natom;i++)
        printf("%14.6f\n",m[i]);
    cout << endl;

    for(int i=0;i<3*mol.natom;i++){
        for(int j=0; j<3*mol.natom;j++){
            hess.H[i][j]/=sqrt(m[i/3]*m[j/3]);
        }
    }

    cout << "mass weighted hessian Matrix:\n";
    hess.print_hessian();
    cout << endl;
    
    // Diagnonalize the hessian matrix using the Eigen Package
    
    Matrix F(3*mol.natom,3*mol.natom);
    
    for(int i=0;i<3*mol.natom;i++){
        for(int j=0;j<3*mol.natom;j++){
            F(i,j)=hess.H[i][j];
        }
    }
    cout << "dig of\n";
    cout << F <<endl;
    cout << endl;

    Eigen::SelfAdjointEigenSolver<Matrix> solver(F);
    Matrix evecs = solver.eigenvectors();
    Matrix evals = solver.eigenvalues();

    cout << "Eigenvalues of the Hessian Matrix (hatree/amu*bohr^2 )\n";
    cout << evals << endl;
    cout << endl;

    int size=evals.size();
    double w[size];

    double conv = 1.0;
    conv /=2.293712278e17;

    conv /=1.660539066e-27;

    conv /= (5.291772109e-11)*(5.291772109e-11);

    double c = 2.99792458e10;
    double pi = 3.141592653;

    for(int i=0;i<size;i++)
        w[i]=(sqrt(conv*evals(i)))/(2*pi*c);
    cout << "Harmonic Vibractional Frequency(cm^-1): \n";
    for(int i=0; i<size; i++)
        printf("%12.6f \n", w[i]);
    cout << endl;
    return 0;
}
