#include "molecule.h"
 
using namespace std;
 
int main(int argc, char *argv[])
{
    Molecule h2o("geom.dat",0);
    h2o.print_geom();
    h2o.translate(5, 0, 0);
    h2o.print_geom();
    return 0;
}