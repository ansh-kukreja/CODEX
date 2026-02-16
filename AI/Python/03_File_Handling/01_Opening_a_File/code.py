f = open("03_File_Handling/01_Opening_a_File/sample.txt", "r")  # returns a "file object"

data = f.read()
data2 = f.readline()

print(data)
print(data2)

f.close()