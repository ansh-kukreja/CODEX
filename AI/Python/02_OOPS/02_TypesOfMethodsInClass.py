class Student:
    subject = "Python",
    college = "IIITV",
    course = "MCA"

    def __init__(self, name, age):  # Constructor Method
        print("Constructor was called..")
        self.name = name  
        self.age = age     


    def get_new_age(self): # Instance Method (can access both Class and Instance attributes)
        return self.age + 2
    

    @classmethod
    def get_college(cls):    # Class Methods (can only access Class attributes)
        print(f"College: {cls.college}")

    
    @staticmethod            # Static Method (No compulsory parameter required like "self", "cls")
    def discount(price, discount):
        ans = price - (discount * price / 100)
        print(f"Discounted Price: {ans}")



Student.get_college()
Student.discount(2799, 29) 