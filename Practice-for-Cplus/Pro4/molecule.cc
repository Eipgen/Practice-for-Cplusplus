#include "molecule.h"
#include <iostream> // define the cin;cout;cerr;clog
#include <fstream>  //  ofstream and ifstream. ouput the file and read file 
#include <iomanip>  // contriol the ouput
#include <cstdio>
#include <cassert>  // Aborts program if user-specified condition NOT true
#include <cmath>    // use the cmath function


// First dedin how to obtain the information from an input file 
Molecule::Molecule(const char *filename,int q)
{
    charge=q;
    //Open file here
    std::ifstream is(filename); //"is" name of input file in code,get input filename 
    assert(is.good());          // assert can tell us the file opened or not
    is >>natom;                 // first is to read the atom

    //allocate space using next lines to be read

    zvals = new double[natom];
    geom = new double* [natom];

    for(int i=0;i<natom;i++)
        geom[i] = new double[3]; // natom # of rows and then we set up coordinates next for each atom
    
    for(unsigned int i=0; i<natom;i++)
        // unsigned is a data type specifier;make variable be only positive or zero

        is >>zvals[i] >>geom[i][0] >> geom[i][1] >> geom[i][2];
        // "is" a file we obtain data from, and info in each line is read in this order;sep by space
    is.close();
}

// define how to print out the data

void Molecule::print_geom()
{
    for(int i=0;i<natom;i++)
        printf("%20.12f %20.12f %20.12f %20.12f\n",zvals[i], geom[i][0], geom[i][1],geom[i][2]);
        // display the type atom and its coordinate
}

// calculte the number of electrons in the molecule
int Molecule::electron_count()
{
    int electron=0;
    for(int i=0;i<natom;i++){
        electron += (int) zvals[i]; // (int) is typecasting where it transforms my double zval int an int
    }
    return electron;
}

// This function will move my molecule around

void Molecule::translate(double x,double y,double z)
{
    for(int i=0;i<natom;i++)
    {
        geom[i][0] += x;
        geom[i][1] += y;
        geom[i][2] += z;
    }
}

//bond distance
double Molecule::bond(int a, int b)
{
    return sqrt((geom[a][0]-geom[b][0])*(geom[a][0]-geom[b][0])
                +(geom[a][1]-geom[b][1])*(geom[a][1]-geom[b][1])
                +(geom[a][2]-geom[b][2])*(geom[a][2]-geom[b][2]));
}

// This finds the unit vectors between atoms and respective coordinates
// 0=x,1=y,2=z;

double Molecule::unit(int cart, int a,int b)
{
    return -(geom[a][cart]-geom[b][cart])/bond(a,b);
}

double Molecule::angle(int a, int b,int c)
{
  return acos(unit(0,b,a)*unit(0,b,c)+unit(1,b,a)*unit(1,b,c)+unit(2,b,a)*unit(2,b,c));
}

double Molecule::oop(int a ,int b, int c, int d)
{
  double ebcd_x=(unit(1,c,b)*unit(2,c,d)-unit(2,c,b)*unit(1,c,d));
  double ebcd_y=(unit(2,c,b)*unit(0,c,d)-unit(0,c,b)*unit(2,c,d));
  double ebcd_z=(unit(0,c,b)*unit(1,c,d)-unit(1,c,b)*unit(0,c,d));

  double exx = ebcd_x*unit(0,c,a);
  double eyy = ebcd_y*unit(1,c,a);
  double ezz = ebcd_z*unit(2,c,a);

  double theta=(exx+eyy+ezz)/sin(angle(b,c,d));

  if(theta <-1.0) theta=asin(-1.0);
  else if (theta>1.0) theta=asin(-1.0);
  else theta=asin(theta);
  return theta;
}


// compute the the angle between the a-b-c and b-c-d
double Molecule::torsion(int a,int b,int c,int d)
{
  double eabc_x=(unit(1,b,a)*unit(2,b,c)-unit(2,b,a)*unit(1,b,c));
  double eabc_y=(unit(2,b,a)*unit(0,b,c)-unit(0,b,a)*unit(2,b,c));
  double eabc_z=(unit(0,b,a)*unit(1,b,c)-unit(1,b,a)*unit(0,b,c));

  double ebcd_x=(unit(1,c,b)*unit(2,c,d)-unit(2,c,b)*unit(1,c,d));
  double ebcd_y=(unit(2,c,b)*unit(0,c,d)-unit(0,c,b)*unit(2,c,d));
  double ebcd_z=(unit(0,c,b)*unit(1,c,d)-unit(1,c,b)*unit(0,c,d));

  double exx=eabc_x*ebcd_x;
  double eyy=eabc_y*ebcd_y;
  double ezz=eabc_z*ebcd_z;

  double tau=(exx+eyy+ezz)/(sin(angle(a,b,c))*sin(angle(b,c,d)));

  if(tau <-1.0) tau=acos(-1.0);
  else if (tau >1.0) tau=acos(1.0);
  else tau=acos(tau);

  //compute the the sign of torison

  double cross_x=eabc_y*ebcd_z-eabc_z*ebcd_y;
  double cross_y=eabc_z*ebcd_x-eabc_x*ebcd_z;
  double cross_z=eabc_x*ebcd_y-eabc_y*ebcd_x;

  double norm=cross_x*cross_x+cross_y*cross_y+cross_z*cross_z;

  cross_x /=norm;
  cross_y /=norm;
  cross_z /=norm;
  
  double sign=1.0;
  double dot=cross_x*unit(0,b,c)+cross_y*unit(1,b,c)+cross_z*unit(2,b,c);
  if(dot <0.0) sign=1.0;

  return tau*sign;


}
Molecule::~Molecule()
{
    delete[] zvals;
    for(int i=0; i<natom; i++)
        delete[] geom[i];
    delete[] geom;
}