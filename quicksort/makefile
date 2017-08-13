include ../env
qsort : qsort_test.o quicksort.o partition.o
	$(CC) -L $(LIBS) -lgmock_main -o qsort qsort_test.o quicksort.o partition.o

qsort_test.o : qsort_test.cc quicksort.h
	$(CC) -c -I $(INCLUDES) qsort_test.cc $(CXXFLAGS)
	
quicksort.o : quicksort.cc quicksort.h partition.h
	$(CC) -c -I $(INCLUDES) quicksort.cc $(CXXFLAGS)

partition.o : partition.cc partition.h
	$(CC) -c -I $(INCLUDES) partition.cc $(CXXFLAGS)



clean :
	rm *.out quicksort.o partition.o
