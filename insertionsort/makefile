include ../env

insertionsort : insertionsort_test.o insertionsort.o
	$(CC) -L $(LIBS) -lgmock_main -o insertionsort insertionsort_test.o insertionsort.o

insertionsort_test.o : insertionsort_test.cc
	$(CC) -I $(INCLUDES) -c insertionsort_test.cc $(CXXFLAGS)

insertionsort.o : insertionsort.cc insertionsort.h
	$(CC) -I $(INCLUDES) -c insertionsort.cc $(CXXFLAGS)

clean:
	rm -rf *.out *.o
