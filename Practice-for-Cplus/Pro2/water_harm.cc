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

typename Eigen::Matrix<double, Eigen::Dynamic,Eigen::Dynamic,Eigen::RowMajor>Matrix;

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
    return 0;
}
