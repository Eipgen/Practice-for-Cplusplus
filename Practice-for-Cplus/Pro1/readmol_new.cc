// read the data
#include "molecule.h"
#include "masses.h"

#include <iostream> // the input and ouptput; the cin and cout, and cerr
#include <fstream>  // both funtcion from the ofstream and ifstream 
#include <iomanip>
#include <cstdio>
#include <cmath>

#include "Eigen/Dense"
#include "Eigen/Eigenvalues"
#include "Eigen/Core"

typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor>Matrix;
//this code defines a new type called Matrix that may be dynamically allocated and contains only doubles
typedef Eigen::Matrix<double, Eigen::Dynamic, 1> Vector;


using namespace std;

int main()
{
    Molecule mol("acetaldehyde.dat",0);
    cout << "Number of atoms: " << mol.natom << endl;
    cout << "Input Cartesian coordinates:\n";
    mol.print_geom();

    cout << "Interatomic distances (bohr):\n";
    for (int i=0;i<mol.natom;i++)
        for(int j=0;j<i;j++)
            printf("%d %d %8.5f\n", i, j, mol.bond(i,j));

    cout << "\nBond angles:\n";
    for (int i=0;i < mol.natom;i++){
        for (int j=0;j<i;j++){
            for (int k=0;k<j;k++){
                if (mol.bond(i,j)< 4.0 && mol.bond(j,k) <4.0) // the bond cut is 4.0 bohr
                    printf("%2d %2d %2d %10.6f\n", i, j, k, mol.angle(i,j,k)*(180.0/acos(-1.0)));
            }
        }
    }

    cout << "\nOut of Plane angles:\n";
    for (int i=0;i < mol.natom;i++){
        for (int k=0;k<mol.natom;k++){
            for (int j=0;j<mol.natom;j++) {
                for (int l=0;l<j;l++){
                    if(i!=j && i!=k && i!=l && j!=k &&k!=l && mol.bond(i,k)<4.0 && mol.bond(k,j)<4.0 && mol.bond(k,l)<4.0) // the imporer is confused
                        printf("%2d-%2d-%2d-%2d %10.6f\n", i, j, k, l, mol.oop(i,j,k,l)*(180.0/acos(-1.0)));

                }

            }
        }
    }

    cout << "\nTorison angles\n\n";
    for(int i=0; i < mol.natom; i++) {
        for(int j=0; j < i; j++) {
            for(int k=0; k < j; k++) {
                for(int l=0; l < k; l++) {
                    if(mol.bond(i,j) <4.0 && mol.bond(j,k)<4.0 && mol.bond(k,l)<4.0)
                        printf("%2d-%2d-%2d-%2d %10.6f\n", i, j, k, l, mol.torsion(i,j,k,l)*(180.0/acos(-1.0)));

                }
            }
        }
    }
    /*find the center of mass*/
    double M=0.0;
    for(int i=0;i<mol.natom;i++) M+=an2masses[(int) mol.zvals[i]];

    double xcm=0.0;
    double ycm=0.0;
    double zcm=0.0;
    double mi;
    for(int i=0;i<mol.natom;i++) {
        mi=an2masses[(int) mol.zvals[i]];
        xcm +=mi*mol.geom[i][0];
        ycm +=mi*mol.geom[i][1];
        zcm +=mi*mol.geom[i][2];
    }
    xcm /=M;
    ycm /=M;
    zcm /=M;
    printf("\n Molecular center of mass: %12.8f %12.8f %12.8f\n",xcm,ycm,zcm);

    mol.translate(-xcm,-ycm,-zcm);

    Matrix I(3,3);

    for(int i=0;i<mol.natom;i++) {
        mi = an2masses[(int) mol.zvals[i]];
        I(0,0) += mi*(mol.geom[i][1]*mol.geom[i][1]+mol.geom[i][2]*mol.geom[i][2]);
        I(1,1) += mi*(mol.geom[i][0]*mol.geom[i][0]+mol.geom[i][2]*mol.geom[i][2]);
        I(2,2) += mi*(mol.geom[i][1]*mol.geom[i][1]+mol.geom[i][0]*mol.geom[i][0]);

        I(0,1) -= mi*mol.geom[i][0]*mol.geom[i][1];
        I(0,2) -= mi*mol.geom[i][0]*mol.geom[i][2];
        I(0,2) -= mi*mol.geom[i][1]*mol.geom[i][2];

    }
    I(1,0)=I(0,1);
    I(2,0)=I(0,2);
    I(2,1)=I(1,2);

    cout << "\nMoment of interia tensor (amu bohr^2): \n";
    cout << I << endl;

    // find the principle moments
    Eigen::SelfAdjointEigenSolver<Matrix> solver(I);
    Matrix evecs = solver.eigenvectors();
    Matrix evals = solver.eigenvalues();

    cout << "\nPrinciples moments of inertia (amu*bohr^2):\n";
    cout << evals <<endl;

    double conv=0.529177249*0.529177249;
    cout << "\nPrinciples moments of inertia (amu*AA^2):\n";
    cout << evals*conv <<endl;

    double conv1=0.529177249E-8*0.529177249E-8*1.6605402E-24;
    cout << "\nPrinciples moments of inertia (g*cm^2):\n";
    cout << evals*conv1 <<endl;

    return 0;
}