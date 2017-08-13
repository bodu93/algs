PROJECTS_PATH=~/Projects
INCLUDE_PATH=$(PROJECTS_PATH)/gtest_build/include
LIB_PATH=$(PROJECTS_PATH)/gtest_build/lib

CC=clang++
CXXFLAGS=-std=c++11 -Werror
LIBS=-lpthread -lm

qsort.out : partition.o quicksort.o
	$(CC) -o qsort.out partition.o quicksort.o

quicksort.o : quicksort.cc partition.h
	$(CC) -c quicksort.cc $(CXXFLAGS)

partition.o : partition.cc partition.h
	$(CC) -c partition.cc $(CXXFLAGS)



clean :
	rm *.out quicksort.o partition.o
