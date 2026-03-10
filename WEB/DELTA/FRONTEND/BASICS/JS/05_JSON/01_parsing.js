
let api = '{"fact":"A cat smell is their strongest sense, and they rely on this leading sense to identify people and objects; a feline sense of smell is 14x better than a human.","length":163}';

let jsObj = JSON.parse(api);
console.log(jsObj);

let jsonData = JSON.stringify(jsObj);
console.log(jsonData); 