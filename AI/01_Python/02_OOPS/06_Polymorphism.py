
# Operator Overriding

print(2 + 4, "Young Sammy in the building" + " brudar")



# Function Overriding

class Employee:
    def get_designation(self):
        print("Designation: Employee")


class Clerk(Employee):
    def get_designation(self):
        print("Designation: Clerk")


cl = Clerk()
cl.get_designation()




# Duck Typing

class Dog:
    def speak(self):
        print("Bark")

class Cat:
    def speak(self):
        print("Meow")

class Bird:
    def speak(self):
        print("Chirp")


def make_it_speak(entity):
    entity.speak()


d = Dog()
c = Cat()
b = Bird()

for e in[d, c, b]:
    make_it_speak(e)