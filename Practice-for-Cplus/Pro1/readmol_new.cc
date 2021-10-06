// read the data
#include "molecule.h"
#include <iostream> // the input and ouptput; the cin and cout, and cerr
#include <fstream>  // both funtcion from the ofstream and ifstream 
#include <iomanip>
#include <cstdio>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
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
    return 0;
}