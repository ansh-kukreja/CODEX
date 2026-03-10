## Notes of This Project

### Using UUID Package
```
Step 1: Search "npm uuid" on google and follow steps

Step 2: npm install uuid

Step 3:
import { v4 as uuidv4 } from 'uuid';

uuidv4(); // ⇨ '9b1deb4d-3b7d-4bad-9bdd-2b0d7b3dcb6d'
```
<br/>
<br/>

### HTML Forms
HTML forms only support "GET" and "PUT" requests,  so we use "method-override" package from "npm" to modify the form request
```
npm install --save @types/method-override


```