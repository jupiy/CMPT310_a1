# README for ASSIGNMENT #1, CMPT310 

#### Xuanbing(Liz) Yan
#### StudentNumber: 301295772
#### SFU UserName: xya60
#### CMPT310 Fall2016 Assignment #1
#### Instructor: James Delgrande <jim@sfu.ca>
#### TA: Yajie(Jill) Zhou <yajiez@sfu.ca>


## FILES:
- Makefile
- main1.cpp
- main2.cpp
- navigation.cpp
- navigation.h
- README.md
- report.html


## HOW TO RUN:
1. Compile and run in command line:
	- open this file folder in Terminal (or other command line tools) in each workstation, using "cd [path]"
	- input "make" to build the executable program "navigation1" and "navagation2" and relevant “.o” files
	- run excutable files:
		- for problem 1, input the executable file “./navigation1" 
		- for problem 2, input the executable file "./navigation2"
	- input the coordinates of the starting node and the target node accordingly
	- get the results
	- if inputting “make clean”, the Makefile will remove the executable files and all “.o” files.
	
2. Run excetuable files manually: 
	- double click the executable files "navigation1" for problem 1 and "navigation2" for problem2
	- input the coordinates of the start and the target accordingly.


## ERROR MESSAGES
1. if the input node is an obstacle, "INPUT ERROR: the node is an obstacle!" will be printed out;
2. if the input node is out of the range, "INPUT ERROR: the node is out of range!" will be printed out.
