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

<br>
<br>

### To Count Set-bits (1s) of an Integer 
```
int n = 4;
int noOfSetBits = __builtin_popcount(n);
```

## To Do (Doubts)
- Difference between "Set" and "Unordered Set" in detail

