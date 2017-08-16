include ../env

objects := $(patsubst %.cc, %.o, $(wildcard *.cc))

quicksort.out:$(objects)
	$(CC) -L $(LIBS) -lgmock_main $(objects) -o quicksort.out

$(objects):%.o:%.cc
	$(CC) -c -I $(INCLUDES) $(CXXFLAGS) $< -o $@

.PHONY : clean

clean :
	-rm *.out $(objects) 
