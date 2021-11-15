import numpy as np
import glob as glob

class Readcoord:
    def __init__(self,filename):
        self.filename = filename
        self.coord = []
        #self.atomname=np.array([])
        self.coords=np.array([])
        #self.xyz=np.array([])
        #self.readfile()
        #self.atomnum()

    def readfile(self):
        with open(self.filename) as f:
            for line in f:
                self.coord.append(line.split())
        self.coord = self.coord[2:]
        self.coords = np.array(self.coord,dtype=float)
        #self.atomnum=len(self.coord)
        return self.coords
    
    def distance(self):
        T=np.array(self.readfile())
        print("Interatomic distances (bohr):")
        for i in range(len(T)):
            for j in range(i+1,len(T)):
                    print(str(j)+" "+str(i),np.linalg.norm(T[i][1:]-T[j][1:]))
    def angle(self):
        T=np.array(self.readfile())
        print("Angles (degrees):")
        for i in range(len(T)):
            for j in range(i+1,len(T)):
                for k in range(j+1,len(T)):
                    print(str(k)+" "+str(j)+" "+str(i),np.rad2deg(np.arccos(np.dot(T[i][1:]-T[j][1:],T[k][1:]-T[j][1:])/np.linalg.norm(T[i][1:]-T[j][1:])/np.linalg.norm(T[k][1:]-T[j][1:]))))
    def dihedral(self):
        T=np.array(self.readfile())
        print("Dihedral angles (degrees):")
        for i in range(len(T)):
            for j in range(i+1,len(T)):
                for k in range(j+1,len(T)):
                    for l in range(k+1,len(T)):
                        print(str(l)+" "+str(k)+" "+str(j)+" "+str(i),np.rad2deg(np.arctan2(np.linalg.norm(np.cross(T[i][1:]-T[j][1:],T[k][1:]-T[j][1:])),np.dot(T[i][1:]-T[j][1:],T[k][1:]-T[j][1:]))))
    def outofplane(self):
        T=np.array(self.readfile())
        print("Out-of-plane angles (degrees):")
        for i in range(len(T)):
            
print(Readcoord("data/acetaldehyde.dat").dihedral())



