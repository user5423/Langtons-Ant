# BUILD=RELEASE

## NOTE: Automatically link dependencies and source files using gcc -MMD to create dependency files, and then use makefile to include them -- (If I have time)
## NOTE: I decided to structure this makefile with smaller short recipes, to reduce execution time, and allow the user to access certain "protected" target options directly

## -Wall turns on most compiler warnings alhtough not all of them
## -I includes the paths for the compiler to search for headers

CC = gcc
CFLAGS = -c -fPIC -I$(libp) -Wall -Wextra
VPATH = ./tests

libraries = libant.so
objects = langton.o visualiser.o main.o
execs = main.out test.out

## TODO: Handle include and libpath -- ask teacher where they want it
includep = .
libp = .

##TODO: See if we can shorten any of the below paths
##TODO: Does all need to run main?

all: libant.so main

main: main.c libant.so
	$(CC) $< -o $@.out -Wl,-rpath=.,-lant,-lncurses -L. -I.

libant.so: visualiser.o langton.o ant.o
	$(CC) $^ -shared -o libant.so

langton.o: langton.c langton.h
visualiser.o: visualiser.c visualiser.h langton.h
ant.o: ant.c ant.h
# langton.h is included in visualiser.h

clean: clean-executables clean-objectfiles clean-precompiled-headers clean-dylibraries## clean-dependencies
clean-executables: ; rm -f $(execs) *.out
clean-objectfiles: ; rm -f $(objects) *.o
clean-precompiled-headers: ; rm -f *.gch
clean-dylibraries: ; rm -f $(libraries) *.so

test: test.c libant.so
	$(CC) $< -o $@.out -Wl,-rpath=.,-lant,-lncurses -L. -I.
	./$@.out
