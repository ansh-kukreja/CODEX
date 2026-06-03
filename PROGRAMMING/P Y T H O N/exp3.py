print("Gauraansh, 2210997081")
x = int(input("Enter the value of x : "))
y = int(input("Enter the value of y : "))

sum = 1

for i in range(1, y+1):
    sum = sum + 1 / (x ** i)

print("Sum is : ", sum)