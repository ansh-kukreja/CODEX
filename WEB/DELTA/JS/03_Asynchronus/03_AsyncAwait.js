
// ==== Async Function ====

// returns a Promise (Resolve or Reject)
 
let fun = async () => {
    return "Yo";
}

async function greet(){
    // throw "Some random error"
    return "Hello";
}


greet()
.then((result) => {
    console.log("Promise was Resolved")
    console.log("Result was : ", result)
})
.catch((err) => {
    console.log("Promise was Rejected")
    console.log("Error was : ", err)
});




// ==== Await Keyword ====

// pauses the execution of its surrounding async functions until
// the promise is settled (resolved or rejected)

function getNum(){
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            let num = Math.floor(Math.random() * 10) + 1;
            console.log(num);
            resolve();
        }, 1000);
    })
}

async function demo(){
    await getNum();
    await getNum();
    await getNum();
    await getNum();
}

demo();