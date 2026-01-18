print("Gauraansh, 2210997081")

n = int(input("Enter the Annual Salary : "))

if n < 300000:
    print("No Income Tax")

elif n >= 300000 and n < 600000:
    print("tax 5%")
    n = n * (5/100)
    print("Income Tax is : ", n)

elif n >= 600000 and n < 900000:
    print("tax 10%")
    n = n * (10/100)
    print("Income Tax is : ", n)

elif n >= 900000 and n < 1200000:
    print("tax 15%")
    n = n * (15/100)
    print("Income Tax is : ", n)

elif n >= 1200000 and n < 1500000:
    print("tax 20%")
    n = n * (20/100)
    print("Income Tax is : ", n)

else : 
    print("tax 30%")
    n = n * (30/100)
    print("Income Tax is : ", n)