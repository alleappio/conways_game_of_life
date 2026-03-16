import numpy as np
import random

class Cells:
    def __init__(self, gridWidth, gridHeight):
        self.cellNumber = gridHeight * gridWidth  
        self.gridWidth = gridWidth
        self.gridHeight = gridHeight
        self.cellMatrix = np.zeros((gridWidth, gridHeight))
    
    def randomFill(self):
        for i in range(self.gridWidth):
            for j in range(self.gridHeight):
                self.cellMatrix[i,j] = random.randint(0,1)

    def getCellMatrix(self):
        return self.cellMatrix
    
    def checkRules(self):
        for i in range(self.gridWidth):
            for j in range(self.gridHeight):
               nNumber = self.getNeighbors( i, j) 
               self.cellMatrix[i,j] = self.applyRules(nNumber, self.cellMatrix[i,j])

    def applyRules(self, nNeighbors, cellValue):
        if nNeighbors<2 and cellValue==1:
            return 0
        elif nNeighbors==2 or nNeighbors==3 and cellValue==1:
            return 1
        elif nNeighbors>3 and cellValue==1:
            return 0
        elif nNeighbors==3 and cellValue==0:
            return 1
        else:
            return 0

    def getNeighbors(self, x, y):
        nNumber = 0;
        for i in (-1,0,1):
            for j in (-1,0,1):
                if x+i < 0 or x+i > self.gridWidth-i or y+j < 0 or y+j > self.gridHeight-1 or (i==0 and j==0):
                    nNumber+=0
                else:
                    nNumber+= self.cellMatrix[x+i, y+j]
        return nNumber

