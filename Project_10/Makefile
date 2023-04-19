# #!/bin/bash
# make file for class Date
# create a macro for the compiler command
CC = g++ -std=c++11 -Wall

# create the exectuable by linking the object files
Project_10:  Project_10.o  Project_10_main.o
	$(CC)   Project_10.o Project_10_main.o -o Project_10

# create the object files that will be linked.  
# the -c option is what causes the object file to be 
# created instead of an executable
Project_10.o: Project_10.cpp Project_10.h
	$(CC)   -c  Project_10.cpp

Project_10_main.o:  Project_10.h  Project_10_main.cpp
	$(CC)   -c  Project_10_main.cpp
clean:
	rm *.o 
	rm Project_10 

