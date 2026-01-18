print("Gauraansh, 2210997081")

x = 1
bi = 0
oc = 0 
he = 0

print("N", "\t", "Oct(N)", "\t", "Hex(N)", "\t", "Bin(N)")

while x <= 20:
    bi = bin(x)
    oc = oct(x)
    he = hex(x)
    print(x, "\t", oc, "\t\t", he, "\t\t", bi)
    x = x + 1