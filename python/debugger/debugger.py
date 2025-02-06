import random
import string
import math

random.seed(10)
x = 2

class Student:
    def __init__(self, name, age=20):
        print(id(name))
        name = "Davis"
        self.name = name
        x = 4
        self._secret = 0

    def tell_name(self, name):
        print(self.name)

    def change_name(self, name=None):
        self.naem = name

    def set_serial(self):
        # Define the characters you want to include in the random string
        characters = string.ascii_letters + string.digits + string.punctuation
        # Use random.choice to randomly select characters and join them into a string
        random_string = ''.join(random.choice(characters) for _ in range(1000))
        self.serial = random_string

    def incomprehensible_code(self):
        what_am_i, count = 2, 0
        for v1, v2 in zip(self.serial, reversed(self.serial)):
            what_am_i += random.randint(1, 10)
            what_am_i = math.pow(what_am_i, True / (random.randint(1, 3)))
            count += 1
        if self.name == "David":
            self._secret = what_am_i


naam = "David"
s1 = Student(naam)
s1.change_name(naam)
s1.set_serial()
s1.incomprehensible_code()
print(s1.serial)
print(s1._secret)

while round(s1._secret, 4) != 2.1648:
    pass

s2 = Student(naam)
