## Making a ***Number*** by using Digits ( 1,2,3 -> 123 )

- In Same Order
```
ans = (ans * 10) + digit

Gives -> 123
```


<br>

- In Reverse Order
```
ans = (digit * (10 ^ i)) + ans
```
```
ans = (1 * (10 ^ 0)) + 0    = 1
ans = (2 * (10 ^ 1)) + 1    = 21
ans = (3 * (10 ^ 2)) + 21   = 321

Gives -> 321
```

<br><br>

## Calculating Power 2ⁿ
#### -- For Even
```
2⁴ = 2² * 2²
```
#### -- For Odd
```
2ⁿ = 2 * (2^n/2 * 2^n/2)
2⁷ = 2 * (2³ * 2³)
```


<br><br>

## Calculating no. of elements in a Power Set
```
set = {a,b,c}
Power Set = {{a} ,{b}, {c}, {a,b}, {b,c}, {a,c}, {a,b,c}, {}}

for elements 'n' in set
No. of elements in Power Set = 2ⁿ
```


<br><br>
## Permutations & Combinations
```
for a string s="abc" with length 3

the number of Permutations possible will be 3! (3 factorial)
```

