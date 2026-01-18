num1 = int(input("Enter Your Number 1: "))
num2 = int(input("Enter Your Number 2: "))
num3 = int(input("Enter Your Number 3: "))
num4 = int(input("Enter Your Number 4: "))

if(num1>num4):
    f1 = num1

else:
    f1 = num4

if(num2>num3):
    f2 = num2

else:
    f2 = num3

if(f1>f2):
    print("The Greatest Number Among These is: ",f1)

else:
    print("The Greatest Number Among These is: ",f2)
