
with open("sample.txt", "r") as f:
    data = f.read()
    print(len(data))

# No need to close the file explicitly using "with" keyword