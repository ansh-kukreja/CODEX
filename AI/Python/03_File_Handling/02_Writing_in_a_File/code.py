f = open("03_File_Handling/02_Writing_in_a_File/sample.txt", "w")  # returns a "file object"

data = f.write("Mr Rambo")

f.close()