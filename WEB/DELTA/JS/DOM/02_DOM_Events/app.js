
let btn = document.querySelector('button');
console.dir(btn);

btn.onclick = function(){
    alert("Button was clicked!");
}

// ===== To apply a function on Multiple Elements at once =====

// let btns = document.querySelectorAll('button');
// for(btn of btns){
//     btn.onclick = function(){

//     }
// }


// == Some Other Events ==

btn.onmouseenter = function(){
    console.log("Triggered when cursor is hovered on the Element");
}


// ----------------------------------------------
// Another Way to Handle Events

// ( We can add multiple "addEventListener" to a Single element, which is not possible in "onClick" )

btn.addEventListener("click", function(){

});

// ----------------------------------------------
// 'This' Keyword

btn.addEventListener("click", changeColor);

function changeColor(){
    this.style.backgroundColor = "blue";  // 'this' here refers to the 'btn', either write 'btn' or 'this'
}

// ** Notice that we didn't pass 'this' object to the function **


// -------------------------------------------------------------------------------------------

// ====  KEYBOARD EVENTS  ====

let inp = document.querySelector("input");

inp.addEventListener("keydown", function(event){
    console.log("Key was Pressed!")
    console.log("Key: " + event.key);
    console.log("Code: " + event.code);
});

inp.addEventListener("keyup", function(event){
    console.log("Key was Released!")
});


// -------------------------------------------------------------------------------------------

// ====  FORM EVENTS  ====

let form = document.querySelector("form");

form.addEventListener("submit", function(event){
    event.preventDefault();
    alert("Form Submitted!");

    let inp = document.querySelector("form input");
    console.log(inp.value);

    // **** We can access elements inside a form simply by this way! ****
    let userName = form.elements[0];  // this.elements[0];
    let submitButton = form.elements[1];  // this.elements[1];
    console.dir(form.elements);
});


// "Change" Event triggers when we change the value and press anywhere else or submit the form
let uId = document.querySelector("#userId");

uId.addEventListener("change", function(event){
    console.log("Input Changed to " + uId.value);
})

// "Input" Event triggers when we do any small change in the element
let addr = document.querySelector("#address");

addr.addEventListener("input", function(event){
    console.log("Input Changed to " + addr.value);
})


// -------------------------------------------------------------------------------------------

// ====  EVENT BUBBLINNG  ====

// Problem is that, when we click on 'li' it will also triggers all its Parent's Events too.
// To prevent that, we can write "event.stopPropagation();"

let box = document.querySelector(".box");
let ul = document.querySelector("ul");
let listItems = document.querySelectorAll("li");

box.addEventListener("click", function(){
    console.log("Box was Clicked");
});

ul.addEventListener("click", function(){
    console.log("UL was Clicked");
});

for(lit of listItems){
    lit.addEventListener("click", function(event){
        event.stopPropagation();
        console.log("List Items were Clicked");
    });
}


