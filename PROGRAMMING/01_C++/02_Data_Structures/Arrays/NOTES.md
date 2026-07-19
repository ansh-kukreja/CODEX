# Important Array Notes

### Circular Array

When we have to find an <b>Index</b> in a Circular Array, then use this formula

<b>index:</b> where we currently are

<b>shift:</b> how much we need to shift, can be a -ve/+ve value, +ve means right shift, -ve means left shift

<b>n:</b> Size of Array

```
((index + shift) % n + n) % n
```

for reference Leetcode #3379