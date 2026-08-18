
let tiles = [];

function shuffleTiles() {
    tiles = [];
    for (let i = 1; i <= 15; i++) tiles.push(i);
    tiles.push("");

    for(let i = tiles.length - 1; i > 0; i--) {
        let j = Math.floor(Math.random() * (i + 1));
        [tiles[i], tiles[j]] = [tiles[j], tiles[i]];
    }
}

const board = document.getElementById("board");

function drawBoard() {
    board.innerHTML = "";
    let index = 0;

    for (let r = 0; r < 4; r++) {
        let row = document.createElement("tr");

        for (let c = 0; c < 4; c++) {
            let cell = document.createElement("td");
            let value = tiles[index];

            cell.textContent = value;
            cell.setAttribute("data-index", index);

            if (value === "") {
                cell.className = "empty";
            }
            cell.setAttribute("onclick", "tileClicked(" + index + ")");

            row.appendChild(cell);
            index++;
        }
        board.appendChild(row);
    }
}

function tileClicked(i) {
    let emptyIndex = tiles.indexOf("");

    let possibleMoves = [];

    if (i % 4 !== 0) possibleMoves.push(i - 1);  
    if (i % 4 !== 3) possibleMoves.push(i + 1);  
    if (i >= 4) possibleMoves.push(i - 4);       
    if (i < 12) possibleMoves.push(i + 4);     

    if (possibleMoves.includes(emptyIndex)) {
        [tiles[i], tiles[emptyIndex]] = [tiles[emptyIndex], tiles[i]];
        drawBoard();
        checkWin();
    }
}

function checkWin() {
    for (let i = 0; i < 15; i++) {
        if (tiles[i] !== i + 1) return;
    }
    alert("Congrats! You solved the puzzle!");
}

shuffleTiles();
drawBoard();