class Person{
    constructor(name, age){
        this.name,
        this.age
    }

    talk(){
        console.log(`Hi!, my name is ${this.name}`);
    }
}

class Student extends Person{
    constructor(name, age, course, rollNo){
        super(name, age);
        this.course,
        this.rollNo
    }
}