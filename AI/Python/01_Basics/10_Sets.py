
# SETS are collection of Unique elements

# Sets are MUTABLE but all its items must be IMMUTABLE


s = {1,2,2,4,5,4,9}

# To create an empty Set
s2 = set()

# because, this will create a dictionary by default
s3 = {}


s.add(0)
s.remove(5)
s.clear()     # Empties the Set
s.pop()       # Removes a Random Value
s.union(s2)   # Returns a new Union
s.intersection(s2)   # Returns a new Intersection

print(s)