
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




