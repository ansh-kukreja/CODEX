# Swift Notes

### What "Class" provides.. but "Struct" does not. </br>

- Inheritance is Possible
- Swift wont generate a memberwise initializer for classes
- If we copy an instance of a class, then both copies share the same data
- We can add a deinitializer to run when the final copy is destroyed
- Constant class instances can have their variable properties changed