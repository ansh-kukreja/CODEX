

#              Output     Iterable        Condition
#                |           |                |
squareOfOdds = [i*i  for i in range(9)  if i%2 != 0]

print(squareOfOdds)




nums = [-4, -1, 9, 4, 14, 0, 79, -40]

nums = [0 if val < 0 else val     for val in nums]

print(nums)