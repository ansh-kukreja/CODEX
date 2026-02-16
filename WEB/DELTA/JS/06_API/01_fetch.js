let url = "https://catfact.ninja/fact";


// yeh hai aam zindagi

fetch(url)
.then((res) => {
    console.log(res);

    res.json()
    .then((data) => {
        console.log(data);
    });

})
.catch((err) => {
    console.log(err);
})



// Yeh hai Mentos xindagi

async function getFacts(){
    try{
        let data = await fetch(url);
        let jsObj = await data.json();
        console.log(jsObj);
    }
    catch(err){
        console.log("Error: " + err);
    }
}

getFacts();