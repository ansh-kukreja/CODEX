### Cloning a Repository from Github to Local Storage
```
git clone https://link_of_project
```
### Checking Status
```
git status
```
### To stage (upload) a new file / or to update the existing one
```
git add filename
```
### Updates all the changes at once
```
git add .
```
### Commit all the changes
```
git commit -m "some message"
```
### Upload all changes to GitHub
```
git push origin main
```
### Download all changes from GitHub to local storage
```
git pull origin main
```

<br>
<br>


## To upload Local Files/Folder to Github

#### To make a normal folder into git Repo
```
git init
```
#### Updates all the changes at once
```
git add .
```
#### Commit all the changes
```
git commit -m "some message"
```
#### To push a Local Repository to GitHub for the first time
```
git remote add origin link-Of-Repo-From-Github
```
#### (To Verify Remote)
```
git remote -v
```
#### (To Remove Remote Origin)
```
git remote remove origin
```
#### (To Check Branch)
```
git branch
```
#### (To Update Branch)
```
git branch -M main
```

#### Upload All Files/Folder
```
git push -u origin main
```

<br>
<br>

### Branch Commands

#### To check Branch
```
git branch
```

#### To rename Branch
```
git branch -M main
```

#### To Navigate
```
git checkout branchname
```

#### To create new Branch
```
git checkout -b newBranchName
```

#### To delete branch
```
git branch -d branchName
```