
# ==== TUPLES ARE IMMUTABLE ====

tup = (2, 4, 4.9, 90, "Four", True, 66, 90)

# tup[1] = 0     <-- Not Allowed: Throws Error

print(type(tup))
print(len(tup)) 
print(tup[2]) 

# Tuple Methods
tup.index(90)   # Returns Index of first occurence
tup.count(90)   # Returns number of occurences of given element
