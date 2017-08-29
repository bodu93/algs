PROJECTS_PATH=~/Projects
THIRD_PATH = $(PROJECTS_PATH)/third
GITS_PATH = $(PROJECTS_PATH)/gits

# headers
GTEST_INCLUDE=$(THIRD_PATH)/gtest_build/include
SORT_PATH=$(GITS_PATH)/algs/sort

# libs
GTEST_LIBS=$(THIRD_PATH)/gtest_build/lib

CC=clang++
CXXFLAGS=-std=c++14 -Werror -I $(GTEST_INCLUDE) -I $(SORT_PATH)/include

objects := $(patsubst %.cc, %.o, $(wildcard *.cc))
objects += $(patsubst %.cc, %.o, $(wildcard $(SORT_PATH)/src/*.cc))


$(target):$(objects)
	$(CC) -L $(GTEST_LIBS) -lgmock_main $(objects) -o $(target)

$(objects):%.o:%.cc
	$(CC) -c $(INCLUDES) $(CXXFLAGS) $< -o $@

.PHONY : clean
clean :
	-rm *.out $(objects)
