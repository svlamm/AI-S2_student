from math import *
import os
from sys import path

for directory in path:  # Module path
    print(directory)
print("Root:", os.path.abspath(os.curdir), end='\n\n')

print("Pi:", pi, end='\n\n')

from playgrounds.algorithms import *
print(circle_surface(1), end='\n\n')
print("Pi:", pi, end='\n\n')
