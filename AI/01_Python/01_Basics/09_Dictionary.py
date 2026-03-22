
# Dictionaries are Unordered and Mutable in Python

info = {
    "name": "Ansh Kukreja",
    "age": 22,
    "cgpa": 9.2,
    "subjects": ["OOPS", "DS", "DBMS", "OS"],
    22: "age",
    14.5: "arm size"
}

print(type(info)) 

print(info["name"])
print(info["subjects"])
print(info[22])
print(info[14.5])

print(info.keys())       # Returns all Keys
print(info.values())     # Returns all Values
print(info.items())      # Returns all Keys:Value pairs

info.update({
    "city": "Kurukshetra" # adds new key:value to the dictionary
})

print(info.get("name"))  # To access a Value

# If we access a value using this method ( info["name"] ) 
# and if Key doesn't exists then it will throw Error

# To Fix this, we can use (  info.get("key")  ) it will return "None" if Key doesn't exists



