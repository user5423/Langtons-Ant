# BUILD=RELEASE

CC = gcc
CFLAGS = -fPIC $(general_flags)
VPATH = ./tests

library = libant.so
objects = langton.o visualiser.o main.o
execs = ant.out test.out

## LLFLAGS are options for compiling files that need to be linked with the library
## We are using "ncursesw" for support for unicode characters
LLFLAGS = -Wl,-rpath=.,-lant,-lncursesw
## GFLAGS are general options that are required for multiple reasons
GFLAGS = -L. -I. -Wall

## TODO: Ask the teacher if they want to use a different directory for include and lib
# includep = .
# libp = .

all: library ant
	./ant LLRR

ant: main.c library
	$(CC) $< -o $@ $(LLFLAGS) $(GFLAGS)

library: visualiser.o langton.o ant.o
	$(CC) $^ -shared -o $(library)


ant.o: ant.c ant.h
langton.o: langton.c langton.h
# langton.h is included in visualiser.h
visualiser.o: visualiser.c visualiser.h langton.h

clean: clean-executables clean-objectfiles clean-precompiled-headers clean-dylibraries## clean-dependencies
clean-executables: ; rm -f $(execs) *.out
clean-objectfiles: ; rm -f $(objects) *.o
clean-precompiled-headers: ; rm -f *.gch
clean-dylibraries: ; rm -f $(library) *.so

test: test.c library
	$(CC) $< -o $@.out $(LLFLAGS) $(GFLAGS)
	./$@.out
