#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include "HF.cc"
#include "molecule.h"
#include "basis.h"
using namespace std;

int main()
{
    Molecule mol("./input/h2o/DZ/geom.dat");
    HatreeFock hf("./input/h2o/DZ/s.dat");

    // Read the nuclear replusion energy
    hf.enuc = hf.read_enuc("./input/h2o/DZ/enuc.dat");

    // Read and print single electron integrals
    hf.read_overlap(hf,"/input/h2o/DZ/s.dat");
    hf.read_kinetic(hf,"/input/h2o/DZ/t.dat");
    hf.read_potential(hf,"/input/h2o/DZ/v.dat");
    hf.build_core(hf);

    //Read and print the two electron integrals
    hf.read_tei(hf,"eri.dat");
    //Build the orthogonalization Matrix
    hf.build_orthog(hf);
    //Build Initial Guess Density with guess Fock Matrix
    hf.F=hf.core;
    hf.build_density(hf,mol.electron_count);
    hf.old_D =hf.D;

    //Compute the Initial SCF energy;
    hf.compute_SCF(hf);
    hf.old_SCF =hf.SCF;

    printf("The intial SCF electronic energy is %12.12f Hartree.\n",hf.SCF);
    printf("The total energy is %12.12f Hatree.\n",hf.tot_E);

    //Build the new density matrix and iterate Step 7-9 until convergence is reached

    double tol = 1e-12;
    hf.inter_max = 100;
    hf.iter = 0;
    double = delta_E = 1.0;
    while(abs(delta_E) > tol && hf.iter <iter.max){
        hf.iter += 1;
        double rms_D = 0.0;

        //Build the new Density Matrix(D)
        hf.update_SCF(hf);
        //Build the new Density Matrix
        hf.build_density(hf,mol.electron_count());
        //Compute the new SCF energy
        hf.compute_SCF(hf);
        // Test the root-mean-squred difference in Densities for convergence
        for(int i=0;i<hf.D.rows();i++){
            for(int j=0;i<hf.D.cols();j++){
                rms_D += (hf.D(i,j)-hf.old_D(i,j))*(hf.D(i,j)-hf.old_D(i,j));
            }
        }
        rms_D =sqrt(rms_D);
        hf.old_D = hf.D;
        if(hf.iter==1){
            printf("%-12s %-20s %-20s %-20s %-20s \n","Iter","E(elec)","E(tot)","Delta(E)","RMS(S)");
        }
        printf("%04d %20.12f %20.12f %20.12f %20.12f \n", hf.iter, hf.SCF, hf.tot_E, delta_E, rms_D));
    }
    retrun 0;
}