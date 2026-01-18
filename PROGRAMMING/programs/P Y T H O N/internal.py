#Program 1
def count_vow(input):
    vowels = "aeiouAEIOU"
    vowelCount = 0
    for char in input:
        if char in vowels:
            vowelCount += 1
    return vowelCount

userInput = input("Enter a string: ")
print("Number of vowels:", count_vow(userInput))


# Program 2
user_input = input("Enter a string: ")
print("Length of the entered string:", len(user_input))



#Program 3
input_string = input("Enter a string: ")

uppercase_string = input_string.upper()
print("Uppercase:", uppercase_string)

lowercase_string = input_string.lower()
print("Lowercase:", lowercase_string)

capitalized_string = input_string.capitalize()
print("Capitalized:", capitalized_string)

titlecased_string = input_string.title()
print("Titlecased:", titlecased_string)

swappedcase_string = input_string.swapcase()
print("Swappedcase:", swappedcase_string)


#Program 4
string1 = "Hello, World!"
print(string1[1::2])

