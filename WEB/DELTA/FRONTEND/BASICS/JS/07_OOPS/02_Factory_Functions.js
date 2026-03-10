function PersonMaker(name, age){
    const person = {
        name: name,
        age: age,
        talk(){
            console.log(`Hi!, I am ${name}`);
        }
    }
    return person;
}

let p1 = PersonMaker("Ansh", 22);

// each object like "p1" gets their own memory separately, so its not an efficient way