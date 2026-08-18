/* 
 * Assignment 4 - Gauraansh Gaur
 */
"use strict";

var welcome = document.getElementById("welcome");
var hello = document.getElementById("hello");

window.onload = function() {
  const fontSlider = document.getElementById('fontSize');
  const sizeValue = document.getElementById('sizeValue');
  const textBox = document.getElementById('target');
  const dropdown = document.getElementById('textAlignment');

    dropdown.addEventListener('change', function() {
        textBox.style.textAlign = this.value;
    });

  sizeValue.textContent = `${fontSlider.value}%`;
  const initialFontSize = 10 + ((fontSlider.value - 50) / 10);
  textBox.style.fontSize = `${initialFontSize}px`;

  fontSlider.addEventListener('input', function() {
    sizeValue.textContent = `${this.value}%`;
    const fontSize = 10 + ((this.value - 50) / 10);
    textBox.style.fontSize = `${fontSize}px`;
  });
};


function nameChanged() {
    var fname = document.forms["names"]["firstname"].value;
    var lname = document.forms["names"]["lastname"].value;
    var name;

    if(fname.length == 0) {
        if(lname.length == 0){
            name = "{name}";
        }
        else {
            name = lname;
        }
    }
    else {
        if(lname.length == 0) {
            name = fname;
        }
        else {
            name = fname + " " + lname;
        }
    }

    hello.innerHTML = "Hello, "+name+"!";
    return false;
}

function alignmentChanged() {
    const dropdown = document.getElementById('textAlignment');
    const textBox = document.getElementById('target');

    dropdown.addEventListener('change', function() {
      textBox.style.textAlign = this.value;
    });
}


function sizeChanged() {
   const fontSlider = document.getElementById('fontSize');
   const sizeValue = document.getElementById('sizeValue');
   const textBox = document.getElementById('target');

    fontSlider.addEventListener('input', function() {
      sizeValue.textContent = `${this.value}%`;
      const fontSize = 10 + ((this.value - 50) / 10);
      textBox.style.fontSize = `${fontSize}px`;
    });
}


