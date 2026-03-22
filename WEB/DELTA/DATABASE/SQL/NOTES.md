# SQL Notes

- SQL is a database language
- MySQL is a database

### Installations
- MySQL
- MySQL Workbench

### To Use MySQL
1) Start MySQL Server <br/>
Go to Setting > Bottom > MySQL > Start MySQL Server

2) Open MySQL Workbench
3) Write Code


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
<br/>


# SQL Commands

- To Create Database <br/>
```
CREATE DATABASE name;

CREATE DATABASE IF NOT EXISTS name;
```

<br/>

- To Drop/Delete Database<br/>
```
DROP DATABASE name;

DROP DATABASE IF EXISTS name;
```


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
```
SELECT col1, col2 FROM table;

SELECT DISTINCT col1 FROM table;

SELECT * FROM table;
```

<br/>
<br/>

### Clauses

<br/>

- Where Clause <br/>
```
SELECT col1, col2 FROM table WHERE conditions;
```
examples
```
SELECT name,rollNo FROM student WHERE age BETWEEN 15 AND 17;


SELECT name,rollNo FROM student WHERE rollNo IN (1039, 7081, 1099);


SELECT name,rollNo FROM student WHERE rollNo NOT IN (1039, 7081, 1099);
```

<br/>

- Limit Clause <br/>
To set the limit of output rows (tuples)
```
SELECT col1, col2 FROM table LIMIT num;
```

<br/>

- Order By Clause <br/>
```
SELECT col1, col2 FROM table ORDER BY col_name(s) ASC;

or

SELECT col1, col2 FROM table ORDER BY col_name(s) DESC;
```

<br/>
<br/>

### Aggregate Functions

COUNT() <br/>
MAX() <br/>
MIN() <br/>
SUM() <br/>
AVG()

<br/>

examples
```
SELECT max(marks) FROM student;
```

<br/>

- Group By Clause <br/>

examples
```
SELECT age,count(id) FROM user GROUP BY age;
```

<br/>

- Having Clause <br/>

examples
```
SELECT age,max(followers) FROM user GROUP BY age HAVING max(followers) > 200;
```

<br/>
<br/>

### Table Queries

<br/>

- UPDATE Rows<br/>
```
UPDATE table SET col1 = val1, col2 = val2 WHERE condition;
```

<br/>
<b><i>* If Update Query fails and show error, then run this command to fix it</i></b>
<br/>
<br/>

``SET SQL_SAFE_UPDATES = 0;``

<br/>
<br/>

- DELETE Rows<br/>
```
DELETE FROM table WHERE condition; 
```

<br/>
<br/>

- ALTER <br/>
To alter the Schema <br/>

-- To Add Column
```
ALTER TABLE table ADD COLUMN coln_name data_type constraint;
```
-- To Drop Column
```
ALTER TABLE table DROP COLUMN coln_name;
```
-- Rename Table
```
ALTER TABLE table RENAME TO new_name;
```
-- Change Column
```
ALTER TABLE table CHANGE COLUMN old_name new_name new_data_type new_constraint;
```
-- Modify Column (modify data type, constraint)
```
ALTER TABLE table MODIFY col_name new_data_type new_constraint;
```

<br/>
<br/>

- TRUNCATE <br/>
To Delete Table's Data <br/>
```
TRUNCATE TABLE table
```