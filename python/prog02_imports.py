# from math import *
import math
import os
from sys import path

for directory in path:  # Module path
    print(directory)

print("Root:", os.path.abspath(os.curdir), end='\n\n')

print("Pi:", math.pi, end='\n\n')

import playgrounds.algorithms
print(playgrounds.algorithms.circle_surface(1), end='\n\n')
print("Pi:", playgrounds.algorithms.pi, end='\n\n')

