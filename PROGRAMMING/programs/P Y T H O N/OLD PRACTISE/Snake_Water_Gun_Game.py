
#here i am using random function which gives me a randum output

import random

#i created a user defined function Named "game" and created my own rules of the game

def game(comp, you):
    if comp == you:
        return None 

    elif comp == 's':
        if you == 'w':
            return False
        elif you =='g':
            return True
    
    elif comp == 'w':
        if you == 'g':
            return False
        elif you =='s':
            return True

    elif comp == 'g':
        if you == 's':
            return False
        elif you =='w':
            return True



print("comp turn: Snake(s) Water(w) Gun(g)")
randNo = random.randint(1,3)
print(randNo)

if randNo == 1:
    comp = 's'
elif randNo == 2:
    comp = 'w'
elif randNo == 3:
    comp = 'g'

you = input("Your Turn: Snake(s) Water(w) Gun(g)")

a = game(comp,you)

if a == None:
    print("The Game Is A Tie!")
elif a:
    print("You Won!")
else:
    print("You Lose!")