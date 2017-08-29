PROJECTS_PATH=~/Projects
THIRD_PATH = $(PROJECTS_PATH)/third
ALGS_PATH = $(PROJECTS_PATH)/gits/algs
UTILITY_PATH = $(ALGS_PATH)/utility
GRAPH_PATH = $(ALGS_PATH)/graph

# headers
GTEST_INCLUDE=$(THIRD_PATH)/gtest_build/include

# libs
GTEST_LIBS=$(THIRD_PATH)/gtest_build/lib

CC=clang++
CXXFLAGS=-std=c++14 -Werror -I $(GTEST_INCLUDE)

objects := $(patsubst %.cc, %.o, $(wildcard *.cc))
objects += $(UTILITY_PATH)/ufset.o

$(target):$(objects)
	$(CC) -L $(GTEST_LIBS) -lgmock_main $(objects) -o $(target)

$(objects):%.o:%.cc
	$(CC) -c $(INCLUDES) $(CXXFLAGS) $< -o $@

.PHONY : clean
clean :
	-rm *.out $(objects)
