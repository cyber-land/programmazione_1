CC = clang++
CFLAGS += -Wall -Werror -ggdb3 -std=gnu99

main: main.o queue.o
	$(CC) $(CFLAGS) $^ -o $@
	rm -rf *.o

tests: queue_tests.o queue.o
	$(CC) $(CFLAGS) $^ -o $@
	rm -rf *.o

.PHONY: clean
clean:
	rm -rf *.o
	rm -rf main tests
