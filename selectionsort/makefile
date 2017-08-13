include ../env

selectionsort.out : selectionsort_test.o selectionsort.o
	$(CC) -o selectionsort.out -L $(LIBS) -lgmock_main

selectionsort_test.o : selectionsort_test.cc
	$(CC) -c -I $(INCLUDES) $(CXXFLAGS) selectionsort_test.cc

selectionsort.o : selectionsort.cc selectionsort.h
	$(CC) -c -I $(INCLUDES) $(CXXFLAGS) selectionsort.cc

clean:
	rm -rf *.out *.o
