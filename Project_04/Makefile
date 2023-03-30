# by listing names on the program line, Make will run the commands
# for each of the names listed.  In this case make will create
# Project_04 and run clean.  Execution is in the order of the 
# list from left to right.  remove clean from the program line
# if you want to make the user explicitly run the clean command
# which is done by typing make clean at a prompt.

# create a macro for defining what is used for compiling
# in the compile line commands below $(CC) is replaced by
# g++ -std=c++11
# give a value of g++ -std=c++11 Wall to the variable CC
#
CC = g++ -std=c++11 -Wall

#program: Project_04
program: Project_04 

# if it is desired to only run clean when we demand it,
# then take clean off of the program line:
# program: Project_04

# The following is used if there is a single file only
# that needs to be compiled
#Project_04 : Project_04.cpp
#	g++ Project_04.cpp -o Project_04

# the following commands are used to compile and link
# programs that contain 2 or more source code files
# all source code files are used to create their object(.o)
# files and then all of the .o files are compiled to
# obtain the executable.  This procedure is what is needed
# for Projects in CPE212, so we will use it even if
# we only have 1 file to compile

Project_04 : Project_04.o
	$(CC) Project_04.o -o Project_04

# the option -c with compile will create just an 
# object file (not executable)
Project_04.o : Project_04.cpp
	$(CC) -c Project_04.cpp 

# clean will remove all the object files created
# could remove clean from the program list and 
# add the name of the executable to the list
# of what to remove: rm *.o Project_04
# to run this part of the makefile, you need to 
# type   make clean    at the command prompt
clean : 
	#rm *.o Project_04
	rm *.o
