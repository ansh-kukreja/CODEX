# i = 1
# print('\nN\tSQ(N)\tCube(N)  Binary\n')
# while i<=10:
#     print(i, '\t', (i*i), '\t', (i*i*i), '\t', bin(i))
#     i = i+1
# print('\n')



# PRINT THE TABLE

# x = input("Enter a Number : ")
# n = int(x)
# i = 1

# print('\n')
# while i<=10:
#     print(n, " X ",i," = ", (n*i))
#     i = i + 1
# print('\n')



# SUM OF ALL DIGITS FROM 1 - 10

x = input("Enter a Number : ")
n = int(x)
sum = 0


while n!=0:
    l = n % 10
    sum = sum + l
    n = int(n/10)

print("Sum of all digits is :", sum)
