const { faker } = require('@faker-js/faker');
const mysql = require("mysql2");

const connection = mysql.createConnection({
  host: 'localhost',
  user: 'root',
  database: 'node_sql_app',
  password: 'idontlikesql90'
});

let getRandomUser  = () => {
  return [
    faker.string.uuid(),
    faker.internet.username(),
    faker.internet.email(),
    faker.internet.password(),
  ];
}

let q = "INSERT INTO user (id, username, email, password) VALUES ?";

let users = [];

for(let i=1; i<=100; i++){
    users.push(getRandomUser());
}


try{
    connection.query( q, [users], (err, result) => {
            if(err) throw err;
            console.log(result);
        }
    );
}
catch(err){
    console.log(err);
}

connection.end();
