def remove_and_strip(string, word):
    newstr = string.replace(word, "")
    return newstr.strip()

#here i first created a user defined function to remove and strip the input entered by the user from the list

peace = ("    i am undefeatable    ")

x = remove_and_strip(peace,"am")

print(x)

#strip function removes extra spaces from a string