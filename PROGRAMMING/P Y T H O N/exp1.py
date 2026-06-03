print("Gauraansh, 2210997081")

choice = input("Enter 1 for Celsius to Fahrenheit, \n Enter 2 for Fahrenheit to Celsius : ")

if choice == '1':
    cel = float(input("Enter Temperature in Celsius : "))
    fah = (cel * (9/5)) +32
    print("Value in Fahrenheit is : ", fah)

if choice == '2':
    f = float(input("Enter Temperatur in Fahrenheit : "))
    c = (f-32) * (5/9)
    print("Value in Celsius : ", c)