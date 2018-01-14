# Project Postmortem

## Introduction

This is a postmortem of the project. In the UMLs section an overview of the
design is presented. The rest of the document discusses design decisions, the
new requirements and some other relevant information.

## UMLs

This section presents UMLs of the design.

### MVC Diagram

This is an overview of the MVC model. SDL handles both view and controller, so internal parts were not shown in the UML.

![MVC UML](doc/mvc.png)

### Model Big Picture

This is an overview of the Model.

![Model UML](doc/uml.png)

## Design Decisions

This section discusses some of the key design descisions.

### General folder structure
In general, we agreed on separating the header and 
src files throughout the project. 

In header files, we define the structure of classes. 
In src files, we define the functionality of said classes. 

There are five different folders called 
* Symbols
* Map
* Game
* Helpers
* Resources


#### Symbols

In the symbols folder, there are six different symbols. These are Bottle, Keys, Sword, Skull, Hat, and Pistol. 
These symbols are the very core of the game. In order to keep them tidy, we also have an abstract class called 
`symbol` that forces other symbols to behave the same. Please do keep that in mind while developing the code,
if some function is behaviorally the same, please include it to the symbol class.

#### Map

In the map folder, we have things that create the map. One cell contains a symbol and one segment contains 6
of these cells. A map also contains pirates which move according to the players.

#### Game

In the game folder, currently we have cards and map. These are the highest classes that holds information 
and/or collection of other sub classes.

#### Helpers

In the helpers folder, we have helpers classes to be able to control our game state and symbols.

#### Resources

In the resources folder, we currently have images to use in the game.

### Helpers

Helpers bridge the connection between classes and their functions. 

### Patterns
* ***MVC pattern*** used to establish interaction between simulator and user interface.
* ***Null Design Pattern*** used in both cell and card objects in order to denote "no object" situations.


## Bugs

#### Pointer hell

You can see comments in the source code such as:

This should happen but it does, i don't know why!

and

~~I don't know what the f- is happening.~~

Basically, writing a C++ project with relatively limited time was a regret that we will never repeat again.


## Thanks C++!
