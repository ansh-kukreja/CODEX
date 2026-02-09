# Javascript Notes

- JS Console follows REPL (Read, Evaluate, Print, Loop) in Browser's Console Window
- JS is Case Sensitive


### Data Types in JS

1) Number 
2) Boolean 
3) String 
4) Undefined 
5) NULL 

<br>
    
- <b>NaN</b> = means 'Not a Number' it is used to 
represent numbers like "0/0"

<br>

### Operators Precedence (Top to Down) & (Left to Right)
``
()
``
<br>
``
**
``
<br>
``
*, /, %
``

<br>

### Declaring Variables
1) let
2) const
3) var

<br>

### JS is Dynamic-Typed
means  we can change the type of a variable
```
let a = 40;

a = true;

a = "Ansh";
```
this is allowed

<br>

### In JS while comparing two Variables their 'Data Types' are not compared, only their 'Values' are compared

e.g. ``4 == '4'`` gives ``true``

### If we want to compare both "Data Types" and "Values"

e.g. ``4 === '4'`` gives ``false``

<br>

### Some Important comparisons
- ``0 == ' '`` gives ``true``
- ``0 === ' '`` gives ``false``

<br>

- ``0 == false`` gives ``true``
- ``0 === false`` gives ``false``

<br>

- ``null == undefined`` gives ``true``
- ``null === undefined`` gives ``false``

<br>

### Like in C/C++ we have ASCII codes, in JS we have UNICODES
```
'a' = 61
'A' = 41
```
<br>

### Truthy and Falsy
Everything in JS is true or false

#### 1) Falsy values
```
false, 0, -0, 0n (BigInt), "", null, undefined, NaN
```

#### 2) Truthy values
```
Everything else e.g.
" ", "a"
```
<br>

e.g.
```
if(null){
    console.log("Yoo!");
}
else{
    console.log("This will print");
}
```
<br>
<br>

### -> JavaScript Strings are Immutable

<br>

### Arrays
- Arrays are Mutable in JavaScript
- Arrays are of type "Object" in JavaScript
- Arrays are Collection of <b>Heterogeneous</b> elements in JS

<br>

```
let arr = ["Ansh", 49, true, 98.49];
arr[2] = "xyz";
```
this is allowed in JS

<br>

```
let str = "mango";
str[1] = "o";
```
this is NOT allowed in JS

<br>

### For-of Loop
- This is a new loop in JS, it is generally used to iterate collections

```
let arr = ["Porsche", "Bentley", "G-Wagon", "Pagani"];

for(car of arr){
    console.log(car);
}
```

<br>
<br>

<h3>-> JavaScript is Single Threaded</h3>