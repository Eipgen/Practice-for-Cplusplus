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
R_{ij}=\sqrt{(x_i-x_j)^2+(y_i-y_j)^2+(z_i-z_j)^2}
$$
## Bond Angles
$$
cos(\phi_{ijk})=e_{ji}*e_{jk}
$$

$$
e_{ij}^x=-(x_i-x_j)/R_{ij}
$$

$$
e_{ij}^y=-(y_i-y_j)/R_{ij}
$$

$$
e_{ij}^z=-(z_i-z_j)/R_{ij}
$$

## out of plane angles
$$
\sin(\theta_{ijkl})=[(e_{kj}*e_{kl})/sin(\phi_{jkl})]*e_{ki}
$$
## Torison/Dihedral Angles
$$
cos(\tau_{ijkl})=[(e_{ij}*e_{jk})(e_{jk}*e_{kl})]/(sin(\phi_{ijk})*sin(\phi_{jkl}))
$$
## Center of mass translation
$$
X_{cm} = \sum(m_ix_i)/\sum(m_i)
$$
$$
Y_{cm} = \sum(m_iy_i)/\sum(m_i)  
$$
$$
Z_{cm} = \sum(m_iz_i)/\sum(m_i)  
$$
## Principal Moments of Inertia

Diagonal:
$$
I_{xx}=\sum(m_i(y_i^2+z_i^2))
$$
$$
I_{yy}=\sum(m_i(x_i^2+z_i^2))
$$
$$
I_{zz}=\sum(m_i(x_i^2+y_i^2))
$$
off_diagonal
<<<<<<< HEAD
I_xy=sum(mixiyi)
I_xz=sum(mixizi)
I_yz=sum(miyizi)



=======
$$
I_{xy}=\sum(m_ix_iy_i)
$$
$$
I_{xz}=\sum(m_ix_iz_i)
$$
$$
I_{yz}=\sum(m_iy_iz_i)
$$
>>>>>>> 2ec9263ca1d425fd46956e45eb4077458710c649


