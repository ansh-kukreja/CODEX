# SQL Notes

- SQL is a database language
- MySQL is a database

### Installations
- MySQL
- MySQL Workbench

<br/>
<br/>

SQL is NOT Case Sensitive e.g.
```
CREATE DATABASE name

create database name
```

<br/>

### Keys
- Foreign Keys can be Null, Duplicate


<br/>



## SQL Commands

- To Create Database <br/>
``
CREATE DATABASE name;
``
<br/>
``
CREATE DATABASE IF NOT EXISTS name;
``

<br/>

- To Drop/Delete Database<br/>
``
DROP DATABASE name;
``
<br/>
``
DROP DATABASE IF EXISTS name;
``


<br/>

- To Use a Database<br/>
``
USE db_name;
``

<br/>

- To View a Table<br/>
``
SELECT * FROM table_name;
``

<br/>

- To View all Databases<br/>
``
SHOW DATABASES;
``

<br/>

- To View all Tables in a Database<br/>
``
SHOW TABLES;
``

<br/>

- To Create a Table
```
CREATE TABLE name(
    column1 TYPE CONSTRAINT,
    column2 TYPE CONSTRAINT,
    column3 TYPE CONSTRAINT,
);
```



<br/>

- To Insert in a Table
```
e.g.

INSERT INTO student VALUES (1039, "Ansh", 22), (1099, "Utsav", 21);
```



<br/>

- To Insert in a Table
```
e.g.

INSERT INTO user (id, age, name)
VALUES 
(1039, 22, "Ansh"),
(1040, 22, "Nitin"),
(1041, 22, "Tanya"),
```



<br/>

- To Create a Primary Key
```
CREATE TABLE temp(
	id INT NOT NULL,
    PRIMARY KEY (id)
);
```
or
```
CREATE TABLE temp2(
	id INT PRIMARY KEY
);
```



<br/>

- To Create a Foreign Key
```
CREATE TABLE temp(
	cust_id INT,
    FOREIGN KEY (cust_id) REFERENCES customer(id)
);
```
where "customer(id)" is the "table(column)" where "cust_id" is the Primary key



<br/>

- To View Data from Table <br/>
``
SELECT col1, col2 FROM table;
``
<br/>
``
SELECT DISTINCT col1 FROM table;
``
<br/><br/>
``
SELECT * FROM table;
``
