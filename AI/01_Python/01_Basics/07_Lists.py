
# ==== LISTS ARE MUTABLE ====

list1 = ["Ansh", 94, True, 9.45]
marks = [99, 98, 90, 94]

marks[2] = 79

print(marks[0])
print(marks[len(marks)-1])


# "Slicing" works same as it works on Strings 

# Some List Methods :-
marks.append(96)
marks.insert(2,729)   #(index, value)
marks.sort()
marks.sort(reverse=True)
marks.reverse()

for i in marks:
    print(i)

