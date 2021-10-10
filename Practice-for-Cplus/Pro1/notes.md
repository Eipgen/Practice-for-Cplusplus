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
$$
R_ij=\sqrt((x_i-x_j)^2+(y_i-y_j)^2+(z_i-z_j)^2)
$$
## Bond Angles
$$
cos(phi_ijk)=e_ji*e_jk
$$
$$
(e^x)_ij=-(x_i-x_j)/R_ij
$$
$$
(e^y)_ij=-(y_i-y_j)/R_ij
$$
$$
(e^z)_ij=-(z_i-z_j)/R_ij
$$
## out of plane angles
$$
\sin(theta_ijkl)=[(e_kj*e_kl)/sin(phi_jkl)]*e_ki
$$
## Torison/Dihedral Angles
$$
cos(Tau_ijkl)=[(e_ij*e_jk)(e_jk*e_kl)]/(sin(phi_ijk)*sin(phi_jkl))
$$
## Center of mass translation
$$
Xcm = \sum(mixi)/\sum(mi)
Ycm = \sum(miyi)/\sum(mi)
Zcm = \sum(mizi)/\sum(mi)
$$
## Principal Moments of Inertia

Diagonal:
$$
I_xx=sum(mi(yi^2+zi^2))
I_yy=sum(mi(xi^2+zi^2))
I_zz=sum(mi(xi^2+yi^2))
$$
off_diagonal
$$
I_xy=sum(mixiyi)
I_xz=sum(mixizi)
I_yz=sum(mi)
$$


