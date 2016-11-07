# README #

This is a package of C++ files with generic utils for game building with cocos2d. 
It can be included in other projects as a git submodule.

## Include dxco in a newly created project ##

```
cd PROJECT_HOME/
git submodule add git@github.com:DxCo-Games/lib-dxco.git Classes/dxco
```

## Clone a repo that includes dxco ##

```
cd PROJECT_HOME/
git clone <repo> .
git submodule init
git submodule update
```

## Pull remote changes in dxco ##

```
cd PROJECT_HOME/Classes/dxco
git pull origin master
cd ../..
git add Classes/dxco/
git commit -m "updated submodule version"
git push origin master
```

The same can be accomplished with one command:

```
git submodule foreach git pull origin master
```

## Push changes to dxco from another project##

```
cd PROJECT_HOME/Classes/dxco
git add <stuff>
git commit -m "updating dxco lib"
git push origin master

cd ../..
git add Classes/dxco/
git commit -m "updated submodule version"
git push origin master
```

Check out the tutorial on [Git submodules](http://git-scm.com/book/en/Git-Tools-Submodules) for further details.
