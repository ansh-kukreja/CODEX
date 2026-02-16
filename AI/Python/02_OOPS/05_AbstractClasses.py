from abc import ABC, abstractmethod

class Animal(ABC):
    @abstractmethod
    def make_sound(self):
        pass


class Sher(Animal):
    def make_sound(self):
        print("Roar!")

class Cat(Animal):
    def make_sound(self):
        print("Meow!")



sher = Sher()
sher.make_sound()