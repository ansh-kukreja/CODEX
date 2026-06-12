# for x in range(10,0,-1):
#     print(x, end = ' ')


# Example of a for Loop
# i = 1
# while i<=5:
#     j=1
#     while j<=i:
#         print(j, end = '')
#         j=j+1
#     print()
#     i=i+1


# Nested for loop

# print('\n* ----------------- *\n')
# for i in range(1, 6, 1):
#     for j in range(1, i+1, 1):
#         print(j, end=' ')
#     print()

# print('\n* ----------------- *\n')


# Celsius to Farehneit converter

c = int(input("Enter Value in Celsius : "))
f = (c * (9/5)) + 32
print("Value in Fahrenheit : ", f)


# Fahrenheit to Celsius converter

f = int(input("Enter Value in Fahrenheit : "))
c = (f - 32) * (5/9)
print("Value in Celsius : ", c)

    
# x = int(input("Enter a Number : "))
# y = x
# fact = 1
# while (x != 0):
#     fact *= x
#     x -= 1

# print("Factorial of ", y, " is :",fact)