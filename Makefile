# Flags for the compiler:
#  -z7 - generate code for debugger
#       - generate warnings about suspect operations ...
#       -c - generate binary object code
CFLAGS= -z7  -c

# Flags to generate the executable program:
#       -o - used to give a name to the program
OFLAGS = -o

#Name of C++ compiler
#       cl - GNU C++ compiler
CC = cl

# Project name
PNAME = p2

# Project submission dir
DIRNAME=$(USER)$(PNAME)

all: list_test EventManager

# compiles the cdlist_node module
cdlist_node.o: cdlist_node.h cdlist_node.cpp
	$(CC) $(CFLAGS) cdlist_node.cpp

# compiles the List module
List.o: List.h List.cpp
	$(CC) $(CFLAGS) List.cpp

# compiles the list_test_exp module
list_test_exp.o: cdlist_node.h cdlist_node.cpp List.h List.cpp 
	$(CC) $(CFLAGS) list_test_exp.cpp

# compiles the list_test module
list_test.o: List.h list_test.cpp
	$(CC) $(CFLAGS) list_test.cpp

# compiles the Date Module
Date.o: Date.h Date.cpp
	$(CC) $(CFLAGS) Date.cpp

# compiles the explicit Module
explicit.o: cdlist_node.h cdlist_node.cpp List.h List.cpp Event.h Room.h \
	explicit.cpp
	$(CC) $(CFLAGS) explicit.cpp

# compiles the Event module
Event.o: Event.h Event.cpp
	$(CC) $(CFLAGS) Event.cpp

# compiles the Room module
Room.o: Date.h Event.h List.h Room.h Room.cpp
	$(CC) $(CFLAGS) Room.cpp

# compiles the Scheduler module
Scheduler.o: Date.h Event.h List.h Room.h Scheduler.h Scheduler.cpp
	$(CC) $(CFLAGS) Scheduler.cpp

# compiles the EventManager module
EventManager.o: Date.h Event.h List.h Room.h Scheduler.h EventManager.h \
	EventManager.cpp
	$(CC) $(CFLAGS) EventManager.cpp

# generates the list_test executable program
list_test: cdlist_node.o List.o list_test_exp.o list_test.o
	$(CC) cdlist_node.o List.o list_test_exp.o list_test.o \
	$(OFLAGS) list_test

# generates the EventManager executable program
EventManager: cdlist_node.o List.o explicit.o Date.o Event.o Room.o \
	Scheduler.o EventManager.o
	$(CC) cdlist_node.o List.o Date.o Event.o Room.o \
	Scheduler.o explicit.o EventManager.o $(OFLAGS) EventManager

# removes all .o files
clean:
	/bin/rm -f *.o

# removes all .o files, backups and executables
delete:
	/bin/rm -rf *.o core
	/bin/rm -rf list_test EventManager
	/bin/rm -f *~

#################### Submit Stuff

# Create project submit directory
sdir:
	/bin/rm -rf $(DIRNAME)
	mkdir $(DIRNAME)
	cp cdlist_node.* List.* Room.* Scheduler.* $(DIRNAME)
	tar -cvf $(USER).tar $(DIRNAME)

# Submit the project
submit: 
	/home/profs/manuel/bin/submit 3 $(USER).tar
