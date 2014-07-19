# README #

This is a package of C++ files with generic utils for game building with cocos2d. 
It can be included in other projects as a git submodule.

## Include dxco in a newly created project ##

```
cd PROJECT_HOME/
git submodule add git@bitbucket.org:dxco/lib-dxco.git Classes/dxco
```

## Clone a repo that includes dxco ##

```
cd PROJECT_HOME/
git clone git@bitbucket.org:dxco/PROJECT.git .
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
```

The same can be accomplished with one command:

```
git submodule foreach git pull origin master
```

## Push changes to dxco ##

TODO

Check out the tutorial on [Git submodules](http://git-scm.com/book/en/Git-Tools-Submodules) for further details.