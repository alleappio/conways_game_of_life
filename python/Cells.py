import numpy as np
import random

class Cells:
    def __init__(self, gridWidth, gridHeight):
        self.cellNumber = gridHeight * gridWidth  
        self.gridWidth = gridWidth
        self.gridHeight = gridHeight
        self.cellMatrix = np.zeros((gridWidth, gridHeight))
    
    def randomFill(self, number=-1):
        if number==-1:
            for i in range(self.gridWidth):
                for j in range(self.gridHeight):
                    self.cellMatrix[i,j] = random.randint(0,1)
        else:
            for _ in range(number):
                i = random.randint(0,self.gridWidth-1)
                j = random.randint(0,self.gridHeight-1)
                self.cellMatrix[i,j] = 1

    def createGlider(self, x=None, y=None):
        """Creates a glider pattern on the grid."""
        self.cellMatrix.fill(0)  # Clear the grid

        if x is None:
            x = self.gridWidth // 2
        if y is None:
            y = self.gridHeight // 2

        # Glider pattern relative to (x, y)
        glider_pattern = [(0, 1), (1, 2), (2, 0), (2, 1), (2, 2)]

        for i_offset, j_offset in glider_pattern:
            i, j = x + i_offset, y + j_offset
            if 0 <= i < self.gridWidth and 0 <= j < self.gridHeight:
                self.cellMatrix[i, j] = 1

    
    def checkRules(self):
        newMatrix = np.zeros((self.gridWidth, self.gridHeight))
        for i in range(self.gridWidth):
            for j in range(self.gridHeight):
                nNumber = self.getNeighbors( i, j) 
                newMatrix[i,j] = self.applyRules(nNumber, self.cellMatrix[i,j])
        self.cellMatrix = newMatrix

    def applyRules(self, nNeighbors, cellValue):
        if cellValue==1:
            if nNeighbors<2:
                return 0
            elif nNeighbors==2 or nNeighbors==3:
                return 1
            elif nNeighbors>3:
                return 0

        elif cellValue==0:
            if nNeighbors==3:
                return 1
            else:
                return 0
        else:
            return 0

    def getNeighbors(self, x, y):
        nNumber = 0;
        for i in range(x-1,x+2):
            for j in range(y-1,y+2):
                if i >= 0 and i < self.gridWidth and j >= 0 and j < self.gridHeight:
                    nNumber += self.cellMatrix[i, j]
        nNumber -= self.cellMatrix[x,y]
        return nNumber

    def getCellMatrix(self):
        return self.cellMatrix

    def getCellMatrix(self):
        return self.cellMatrix
