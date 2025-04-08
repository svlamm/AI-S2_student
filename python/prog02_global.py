from math import *

print(f"waarde van pi na math import: {pi}")
from playgrounds.algorithms import pi, circle_surface


def change_pi():
    global pi
    print(f"id van pi (2): {id(pi)}")
    pi = 10
    print(f"id van pi (3): {id(pi)}")


change_pi()
print(f"id van pi (4): {id(pi)}")
print(f"circle_surface(1): {circle_surface(1)}")
