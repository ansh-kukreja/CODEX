username = input("Setup Your Username: ")
a = int(len(username))

if(a>10):
    print("Username available")
elif(a==10):
    print("Username available")
else:
    print("Username Must Be Atleast 10 characters long, try using another username")
