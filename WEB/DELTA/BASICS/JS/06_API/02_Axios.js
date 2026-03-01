
// AXIOS: Library to make HTTP requests

let url = "https://catfact.ninja/fact";


async function getFacts(){
    try{
        let res = await axios.get(url);
        return res.data.fact;
    }
    catch(err){
        console.log("Error: " + err);
        return "Something went wrong!";
    }
}


let btn = document.querySelector("button");

btn.addEventListener("click", async () => {
    let p = document.querySelector("#result");

    p.innerText = "Loading...";
    let fact = await getFacts();
    p.innerText = fact;
});





let url2 = "https://icanhazdadjoke.com/";

async function getJokes(){
    try{
        const config = { headers: { Accept: "application/json"} };
        let res = await axios.get(url2, config);
        console.log(res.data);
    }
    catch(err){
        console.log(err);
    }
}