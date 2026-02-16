
// ==== getElementById ====
// If we give invalid ID, then it will return "NULL"

let mainImageObject = document.getElementById("mainImg");
mainImageObject.src = "./assets/spiderman_img.png";



// ==== getElementsByClassName ====
// Returns the Elements as HTML Collection or empty Collection (if not found)
// If we give invalid Class Name, then it will return an empty Collection

let oldImagesObject = document.getElementsByClassName("oldImg");

for(let i=0; i<oldImagesObject.length; i++){
    console.dir(oldImagesObject[i]);
}


// ==== getElementsByTagName ====

let tagElementObject = document.getElementsByTagName("p");
tagElementObject[0].innerText = "Marvel Cinematic Universe";

// -----------------------------------------------------------------------------------------------

// ==== QUERY SELECTORS ====
// Allows us to use any CSS Selector

// "querySelector" does not returns a Collection or Array, It returns the First element as an Object
// that matches the given selector

document.querySelector('p');  // Selecting by Tag Name
document.querySelector('#myId');  // Selectiong by Id
document.querySelector('.myClass');  // Selecting by Class Name
document.querySelector('.myClass div p a');  // Selecting specific Element

// "querySelectorAll" returns all Elements that matches the given selector
// It returns a "NodeList" containing all the Elements that matches
document.querySelectorAll('.myClass');
document.querySelectorAll('p');


// -----------------------------------------------------------------------------------------------

// ==== Manipulation of Content ====

let para = document.querySelector('p');

// ".innerText"
// Returns the Text that is Visible on Screen
// Fetches Data from the Output Screen of Browser
console.log(para.innerText);

// ".textContent"
// Returns all the Text of an Element whether it is Hidden or Displayed on Screen
// Fetches data from where the code is written
console.log(para.textContent);

// ".innerHTML"
// Returns the all HTML content including HTML tags
console.log(para.innerHTML);




// ==== Manipulation of Attributes ====

let img = document.querySelector('#mainImg');

let idOfImage = img.getAttribute('id');  // fetching ID of an Element
img.setAttribute('id', 'newIdOfImage');  // Will set the ID of the Image Element to "newIdOfImage"
img.setAttribute('src', 'assets/creation_2.jpeg');



// ==== Manipulation of Style ====

// e.g. 1
let heading = document.querySelector('h1');

heading.style.color = 'purple';
heading.style.fontStyle = 'italic';


// e.g. 2
let links = document.querySelectorAll('.box a');

for(let i=0; i<links.length; i++){
    links[i].style.color = 'green';
}

// e.g. 3 Manipulating Classes
heading.classList.add("newClass");
heading.classList.remove("newClass");
heading.classList.contains("newClass");
heading.classList.toggle("newClass");  // If class exists then it will remove it, and if it doesn't exists, then it will add it


// -----------------------------------------------------------------------------------------------

// Checking 'Parent', 'Children', 'Sibling' elements of any given element

let box = document.querySelector('.box');

box.parentElement;
box.children;
box.childElementCount;
box.previousSibling;
box.nextSibling
box.previousElementSibling;
box.nextElementSibling;

// -----------------------------------------------------------------------------------------------

// Inserting a New Element

let newPara = document.createElement('p');

newPara.innerText = "Hi! I'm a new paragraph";

let body = document.querySelector('body');
body.appendChild(newPara);
box.appendChild(newPara);

newPara.append(", Dhak Dhak!");  // used to Append in String

newPara.prepend("RAGA!, ");  // used to Prepend String in the Starting



// Adding Elements at different locations
let para2 = document.querySelector('#description');

para2.insertAdjacentElement('beforebegin', newPara);
para2.insertAdjacentElement('afterbegin', newPara);
para2.insertAdjacentElement('beforeend', newPara);
para2.insertAdjacentElement('afterend', newPara);

// To Remove an Element
para2.remove();



