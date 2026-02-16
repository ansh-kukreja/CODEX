
# We can only write one constructor at a time in a class
 
class Student:
    # These are Class attributes (like static variables, same for all objects)
    subject = "Python",
    college = "IIITV",
    course = "MCA"

    def __init__(self, name, age):
        print("Constructor was called..")
        self.name = name   # Instance attribute (different for all objects, "self" is diff for every object)
        self.age = age     # Instance attribute


    def get_new_age(self): # Instance Method (can access both Class and Instance attributes)
        return self.age + 2




stud1 = Student("Ansh", 22)
stud2 = Student("Sahiba", 19)


print(stud1.subject)
print(stud1.name)
print(stud2.name)
print(stud2.get_new_age())


# We can access Class Attributes using Class Name and also using its Object name
# We can access Instance Attributes using objects only

Student.subject
# Student.age   <-- throws error

 