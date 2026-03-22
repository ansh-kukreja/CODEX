class BankAccount:
    def __init__(self, name, accNumber, balance):
        self.name = name
        self._accNumber = accNumber   # '_' creates Protected Variables
        self.__balance = balance      # '__' creates Private Variables



b1 = BankAccount("Ansh", "7081", 900_000)

print(b1.name)
print(b1._accNumber)
print(b1._BankAccount__balance)

# Like we can see that we can actually access the "protected" and even "private" members
# of a class..

# So in Python, access specifiers are used just for convention (for developers to understand)
# it doesn't enforces the compulsion and doesn't throw error

