#include <string>
 
using namespace std;
 
class Molecule // The Name of our class will be Molecule
{
  public:       // This means all the fuctions and variables can be used by any code
                // That makes use of an object called Molecule
    int natom;
    int charge;
    double *zvals;                 // zvals will be an array so it needs a pointers * (pointers to int)
    double **geom;              // geom is a pointer-to-pointer to into int array
    string point_group;         // Need to define a string varable although I don't know why it doesn't light up
 
    void print_geom();
    void print_hessian();
    void rotate(double phi);
    void translate(double x, double y, double z);
    double bond(int atom1, int atom2);
    double angle(int atom1, int atom2, int atom3);
    double torsion(int atom1, int atom2, int atom3, int atom4);
    double oop(int atom1,int atom2,int atom3,int atom4);
    double unit(int cart,int atom1, int atom2);
    int electron_count();
    
    Molecule(const char *filename, int q);
    ~Molecule();
};
