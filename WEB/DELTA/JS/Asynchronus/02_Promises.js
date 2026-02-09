
function saveToDb(data){

    return new Promise((resolve, reject) => {
        let internetSpeed = Math.floor(Math.random() * 10) + 1;

        if(internetSpeed > 4){
            resolve("Success: Data was Saved");
        }
        else{
            reject("Failure: Weak Connection");
        }
    });
}

saveToDb("Ansh")
.then((result) => {
    console.log("1st Promise was Resolved!");
    console.log(result);

    return saveToDb("Kukreja");   // Will return the Promise
})

.then((result) => {
    console.log("2nd Promise was Resolved!");
    console.log(result);
})

.catch((error) => {
    console.log("Promise was Rejected!");
    console.log(error);
});