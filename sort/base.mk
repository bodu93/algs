PROJECTS_PATH=~/Projects
THIRD_PATH = $(PROJECTS_PATH)/third

GTEST_INCLUDE=$(THIRD_PATH)/gtest_build/include
SORT_INCLUDE=../include/
TOYS_INCLUDE=$(PROJECTS_PATH)/gits/toys/

GTEST_LIBS=$(THIRD_PATH)/gtest_build/lib

CC=clang++
CXXFLAGS=-std=c++11 -Werror -I $(GTEST_INCLUDE) -I $(SORT_INCLUDE) -I $(TOYS_INCLUDE)

objects := $(patsubst %.cc, %.o, $(wildcard *.cc))
objects += $(patsubst %.cc, %.o, $(wildcard ../src/*.cc))


$(target):$(objects)
	$(CC) -L $(GTEST_LIBS) -lgmock_main $(objects) -o $(target)

$(objects):%.o:%.cc
	$(CC) -c $(INCLUDES) $(CXXFLAGS) $< -o $@

.PHONY : clean
clean :
	-rm *.out $(objects)
