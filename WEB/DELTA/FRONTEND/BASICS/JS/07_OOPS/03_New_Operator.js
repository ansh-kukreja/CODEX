function Person(name, age){
    this.name,
    this.age
};

Person.prototype.sayHello = function(){
     console.log(`Hi!, my name is ${this.name}`);
}

let p1 = new Person("Ansh", 22);


// This is a good way to create objects