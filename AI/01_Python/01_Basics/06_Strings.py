word1 = "python"
word2 = " anaconda"

# Length of a String
print(len(word1))

# String Concatenation
print(word1 + word2)


# Strings are IMMUTABLE in Python
# word1[4] = 'u'     <-- Throws Error


# Slicing: string[ start_index : end_index ]
# exclusive of end index
print(word1[2:4])
print(word1[-4:-1])  # Can also give -ve indices, means index from right to left side



# ------ Old skool formatting ------

a = 4
b = 5

# Normal Formatting
print("Sum of {} and {} is {}".format(a, b, a+b))

# Index Formatting
print("Sum of {1} and {0} is {2}".format(a, b, a+b))

# Value Formatting
print("Values:  {a} , {b} , {c}".format(c=0, a=4, b=5))


# ------ Latest formatting ------
# F-Strings

print(F"Sum of {a} and {b} is {a+b}")

