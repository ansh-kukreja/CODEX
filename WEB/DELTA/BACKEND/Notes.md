# Backend Notes

### GET and POST Requests
GET
```
- Used to get some response
- Data sent in query strings 
- (it is limited, only string data, Visible in URL)
```

POST
```
- Used to post something for (create, write, update)
- Data sent via Request body(any type of data)
```

<br>

### Accessing data from "req.body"
By default we can't access data from "req.body".
So we have to parse the data using these two middlewares
```
app.use(express.urlencoded({extended: true}));
app.use(express.json());
```

<br/>
<hr/>
<br/>

### REST
( Representational State Transfer ) <br/>
REST is an Architectural style that defines a set of constraints to be used for creating web APIs
<br/>
<br/>
APIs that follows the REST architecture are called RESTful APIs