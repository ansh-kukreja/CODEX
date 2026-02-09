num = input("Enter a Num in Words: ")

match num:
    case "One":
        print("1")

    case "Two":
        print("2")

    case "Three":
        print("3")

    case "Four":
        print("4")
        
    case _:
        print("Default Case!")