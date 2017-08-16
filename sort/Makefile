include env

sortalgs = selectionsort insertionsort quicksort
#sortalgs = ./%sort

.PHONY:all clean run
all : $(sortalgs)
	cd $^/ && $(MAKE)
run : $(sortalgs)
	-./$</$(addsuffix .out, $<)

clean:$(addprefix clean_, $(sortalgs))
clear_$<:
	cd clear_$</ && $(MAKE) clean
