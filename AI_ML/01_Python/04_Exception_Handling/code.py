x = int(input("Enter x: "))


try:
    ans = 10/x

except ZeroDivisionError:  # This block invokes when exception occurs
    print("Division by 0 is Not Allowed na bhai, fir kyu krr rha haii...")

except ValueError:
    print("Only Numeric inputs are allowed broo")

else:  # This block invokes when everything is fine
    print(f"Answer: {ans}")

finally:  # Ye block invoke hoga hi hoga chahe kuch bhi hojaye
    print("Ye line in every case print hogi")