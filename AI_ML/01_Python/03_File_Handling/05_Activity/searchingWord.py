
data = True
line = 1

with open("03_File_Handling/05_Activity/sample.txt", "r") as f:
    while data:
        data = f.readline()

        if("talent" in data):
            print(f"\nWord mill gya bhai-jaan, at line no. {line}\n")
            break

        line += 1
