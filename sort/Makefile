include env

sortalgs = selectionsort insertionsort quicksort

.PHONY:all clean run
all :
	for alg in $(sortalgs); do \
		cd $$alg && $(MAKE); \
	done
run :
	for alg in $(sortalgs); do \
		-./$$alg/$(addsuffix .out, $$alg); \
	done

clean :
	for alg in $(sortalgs); do \
		cd $$alg && $(MAKE) clean; \
	done

unexport