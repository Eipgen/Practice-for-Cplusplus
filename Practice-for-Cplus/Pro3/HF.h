// the .h file will contail the declaration of varibale nad functions

#include <string>
#include "../Pro1/Eigen/Dense"
#include "../Pro1/Eigen/Eigenvalues"
#include "../Pro1/Eigen/Core"

typedef Eigen::Matrix<double, Eigen::Dynamic,Eigen::Dynamic,Eigen::RowMajor>Matrix;
// Eigen::RowMajor makes it so that Eigen stores matrices 
// by defaut in row-major order vs its actual default column-major order
typedef Eigen::Matrix<double, Eigen::Dynamic, 1>Vector;

using namespace std;

class HatreeFock
{
    public:                // this mean that all the code can be use of an object called Hatree Fock
        double enuc;       // Nuclear repulsion energy
        int norb;          // Number of orbitals in file(for H2O, 1s for each H; 1s,2s,3 wp for O)
        Matrix S;          // The OverLap intergral is 7x7 integral so s[i][j]=1.0000 if i=j=1
        Matrix T;
        Matrix V;
        Matrix Core;       // My Core Hamiltionian will be made up of the t and v(kinetic and Potential)
        Matrix SOM;        // Two electron repulsion integral
        Vector TEI         // the electron repulsion integral
        Vector ioff;
        Matrix D;          // Density Matrix
        Matrix F;          // New Fock matrix formed from 
        Matrix F_p;
        Matrix C;
        int iter;
        int inter_max;
        double SCF;
        double tot_E;
        double old_SCF; // For my while loop, that tests for convergence
        Matrix old_D;

        //Functions
        void print_matrix(string mat_string,Matrix matrix);
        void print_vector(string mat_string,Vector vect);

        double read_enuc(const char *filename);
        int read_overlap(HatreeFock& hf,const char *filename);
        int read_kinetic(HatreeFock& hf,const char *filename);
        int read_potential(HatreeFock& hf,const char *filename);
        int build_core(HatreeFock& hf);
        int read_tei(HatreeFock& hf,const char *filename);

        int build_orthog(HatreeFock& hf,const char *filename);
        int build_density(HatreeFock& hf,const char *filename);
        
        int compute_SCF(HatreeFock& hf);
        int update_SCF(HatreeFock& hf);

        HatreeFock(const char *filename);
        ~HatreeFock();
        
};

