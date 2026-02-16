class Panda:
    color = "blackwhite"
    
    def __init__(self, weight):
        self.weight = weight


class DragonWarrior():
    knowsKungFu = True

    def __init__(self, name):
        self.name = name



class PO(Panda, DragonWarrior):    # Multiple Inheritance
    spell = "Skudoosshhhh"

    def __init__(self, weight, name, isAwesome):
        super().__init__(weight)
        DragonWarrior.__init__(self, name)
        self.isAwesome = isAwesome



po = PO(400, "Po", True)

print(po.color)
print(po.weight)
print(po.spell)
print(po.isAwesome)