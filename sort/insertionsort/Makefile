include ../env

objects := $(patsubst %.cc, %.o, $(wildcard *.cc))
target = insertionsort.out

$(target):$(objects)
	$(CC) -L $(LIBS) -lgmock_main $(objects) -o $(target)

$(objects):%.o:%.cc
	$(CC) -c -I $(INCLUDES) $(CXXFLAGS) $< -o $@

.PHONY : clean

clean :
	-rm *.out $(objects) 
