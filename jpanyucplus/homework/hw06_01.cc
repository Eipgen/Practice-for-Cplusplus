#include<iostream>
using namespace std;

void swap_pointer(double *pa, double *pb)
{
    double temper;
    temper = *pa;
    *pa = *pb;
    *pb = temper;
    cout << *pa << " " << *pb << endl;
}

void swap_ref(double &ra, double &rb)
{
    double temper;
    temper = ra;
    ra = rb;
    rb = temper;
    cout << ra << " "<< rb << endl;
}

int main()
{
	double a,b;
    cout << "Input a and b: ";
    cin >>a>>b;
    
    // double a = 3.0, b = 5.0;
	swap_pointer(&a, &b);
    swap_ref(a,b);
    return 0;
}