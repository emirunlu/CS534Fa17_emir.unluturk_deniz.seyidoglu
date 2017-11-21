# CS534 Fall 2017 Project

## Getting Started

### Prerequisites

You have to have the following tools in order to sucesfully compile the code.
```
GNU Make
GCC 
```

### Installation

In order to compile the code, please run the makefile first by executing the command: 
```
make
```

In order to clean the project folder from \*.o files, you can execute the command:
```
make clean
```

### Running the code

After you execute the make file, there will be an executable called
"cartagena", execute it using `./cartagena`




## Project Structure

### General folder structure
In general, we agreed on seperating the header and 
src files throughout the project. 

In header files, we define the structure of classes. 
In src files, we define the functionality of said classes. 

There are three different folders called 
* Symbols
* Map
* Game


#### Symbols

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;In the symbols folder, there are six different symbols.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;These are Bottle, Keys, Sword, Skull, Hat, and Pistol.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;These symbols are the very core of the game. In order to<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;make them tidy, we also have an abstract class called<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`symbol` that forces other symbols to behave the same.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Please do keep that in mind while developing the code,<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if some function is behaviourly same, include it to the<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;symbol class.<br>

#### Map

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;In the map folder, we have things that create the map.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;One cell contains a symbol and one segment contains 6<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;of these cells. A map also contains pirates which move<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;according to players.<br>

#### Game

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;In the game folder, currently we have cards and map.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;These things are the highest classes that holds information<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;and/or collection of other sub classes.<br>

## Testing 

The `./cartagena` executable directly looks at the `main.cpp` that
stays in the project folder itself. If you changed the code, please
test it using the `main.cpp` file.

## Contributing

Please do keep in mind to run the `make` command after every time you
make a change in the code. 


Also, please don't make direct changes to the master branch. Use a 
seperate branch with 
```
git checkout -b <things-that-you're-going-to-change>
```
and after testing it thoroughly, merge it to master and inform your
partner about master changes. 

## Authors
* **Deniz Seyidoğlu**
* **Emir Ünlütürk**

<sup>Contents of the project are subject to change, do keep in mind that project is under active development</sup>