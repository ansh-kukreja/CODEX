let url = "http://universities.hipolabs.com/search?name=";

let btn = document.querySelector("button");

btn.addEventListener("click", async () => {
    let country = document.querySelector("input").value;

    let list = document.querySelector("#list");
    list.innerText = "Fetching Colleges...";

    let clgList = await getColleges(country);
    show(clgList);
});

function show(clgList){
    let list = document.querySelector("#list");
    list.innerText = "";

    for(clg of clgList){
        let li = document.createElement("li");
        li.innerText = clg.name;
        list.appendChild(li);
    }
}

async function getColleges(country){
    try{
        let res = await axios.get(url + country);
        return res.data;
    }
    catch(err){
        console.log("Error: " + err);
        return [];
    }
}