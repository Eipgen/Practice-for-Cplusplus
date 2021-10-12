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
R_ij=\sqrt{(x_i-x_j)^2+(y_i-y_j)^2+(z_i-z_j)^2}
$$
## Bond Angles
$$
cos(phi_{ijk})=e_{ji}*e_{jk}
$$
$$
(e^x)_{ij}=-(x_i-x_j)/R_{ij}
$$
$$
(e^y)_{ij}=-(y_i-y_j)/R_{ij}
$$
$$
(e^z)_{ij}=-(z_i-z_j)/R_{ij}
$$
## out of plane angles
$$
\sin(\theta_{ijkl})=[(e_{kj}*e_{kl})/sin(\phi_{jkl})]*e_{ki}
$$
## Torison/Dihedral Angles
$$
cos(Tau_{ijkl})=[(e_{ij}*e_{jk})(e_{jk}*e_{kl})]/(sin(phi_{ijk})*sin(\phi_{jkl}))
$$
## Center of mass translation
$$
Xcm = \sum(m_ix_i)/\sum(m_i)  
Ycm = \sum(m_iy_i)/\sum(m_i)  
Zcm = \sum(m_iz_i)/\sum(m_i)  
$$
## Principal Moments of Inertia

Diagonal:
$$
I_{xx}=\sum(mi(yi^2+zi^2))
I_{yy}=\sum(mi(xi^2+zi^2))
I_{zz}=\sum(mi(xi^2+yi^2))
$$
off_diagonal
$$
I_{xy}=\sum(m_ix_iy_i)
I_{xz}=\sum(m_ix_iz_i)
I_{yz}=\sum(m_iy_iz_i)
$$


