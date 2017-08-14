include env

sortalgs = selectionsort insertionsort quicksort

.PHONY:all clean run
all : $(sortalgs)
$(sortalgs):
	cd $@/ && $(MAKE)
run :
	-./$@/$(addsuffix .out $@)

clean:$(addprefix clean_, $@)

clear_selectionsort:
	cd selectionsort/ && $(MAKE) clean

clear_insertionsort:
	cd insertionsort/ && $(MAKE) clean

clear_quicksort:
	cd quicksort/ && $(MAKE) clean
