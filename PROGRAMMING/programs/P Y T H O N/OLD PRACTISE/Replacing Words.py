letter = ('''<|NAME|>: hey <|NAME2|> aapke father aaye hai!
<|NAME2|>: Nahi milegi chaabii..
<|NAME|>: <|NAME2|>! maan jao.. Aapke Father Aaye hai!
<|NAME2|>: Mere Dad Ji kyu aayenge????
<|NAME|>: Vo to yahi aadmi bata payega!''')

First_Person = input("Enter First Person's Name\n")
Second_Person = input("Enter Second Person's Name\n")

letter = letter.replace("<|NAME|>",First_Person)
letter = letter.replace("<|NAME2|>",Second_Person)

print(letter)