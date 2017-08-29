target = scc_test.out

PROJECTS_PATH=~/Projects
THIRD_PATH = $(PROJECTS_PATH)/third
GRAPH_PATH = $(PROJECTS_PATH)/gits/algs/graph

# headers
GTEST_INCLUDE=$(THIRD_PATH)/gtest_build/include

# libs
GTEST_LIBS=$(THIRD_PATH)/gtest_build/lib

CC=clang++
CXXFLAGS=-std=c++14 -Werror -I $(GTEST_INCLUDE)

objects := $(patsubst %.cc, %.o, $(wildcard *.cc))
objects += $(patsubst %.cc, %.o, $(wildcard $(GRAPH_PATH)/search/graph.cc))

$(target):$(objects)
	$(CC) -L $(GTEST_LIBS) -g -lgmock_main $(objects) -o $(target)

$(objects):%.o:%.cc
	$(CC) -c -g $(INCLUDES) $(CXXFLAGS) $< -o $@

.PHONY : clean
clean :
	-rm *.out $(objects)
