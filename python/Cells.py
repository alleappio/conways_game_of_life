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
