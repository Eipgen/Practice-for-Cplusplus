# TEST
```sh
C++ -c  readmol_old.cc && c++ readmol_old.o -o readold && readold
```
Number of atoms: 7
Input Cartesian coordinates:
6       0.000000000000       0.000000000000       1.889725988579
6       2.551130084582       0.000000000000       1.889725988579
6      -2.551130084582       0.000000000000       1.889725988579
1       3.495993078871       1.157216106424       0.732509882155
1       3.495993078871      -1.157216106424       3.046942095003
1      -3.495993078871      -1.157216106424       0.732509882155
1      -3.495993078871       1.157216106424       3.046942095003


## Bond Length

R_ij=sqrt((x_i-x_j)^2+(y_i-y_j)^2+(z_i-z_j)^2)

## Bond Angles
cos(phi_ijk)=e_ji*e_jk

(e^x)_ij=-(x_i-x_j)/R_ij
(e^y)_ij=-(y_i-y_j)/R_ij
(e^z)_ij=-(z_i-z_j)/R_ij

## out of plane angles

sin(theta_ijkl)=[(e_kj*e_kl)/sin(phi_jkl)]*e_ki

## Torison/Dihedral Angles

Cos(Tau_ijkl)=(e_ij*e_jk)

