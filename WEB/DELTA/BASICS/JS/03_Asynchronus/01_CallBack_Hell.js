let head1 = document.querySelector("h1");

function changeColor(color, delay, nextColorChange){
    setTimeout(() => {
        head1.style.color = color;
        if(nextColorChange) nextColorChange();
    }, delay);
}

// ==== This is called "Callback Hell"

changeColor("red", 1000, () => {
    changeColor("cyan", 1000, () => {
        changeColor("pink", 1000, () => {
            changeColor("purple", 1000, () => {
            
            });
        });
    });
});