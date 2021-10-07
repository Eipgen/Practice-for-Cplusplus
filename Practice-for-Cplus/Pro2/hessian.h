#include <string>

using namespace std;

class Hessian
{
    public:
        int natom;
        int charge;
        double **H;
        string point_group;
        void print_hessian();


        Hessian(const char *filename);
        ~Hessian();

};