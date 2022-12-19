CC = clang++
CFLAGS += -Wall -Werror -ggdb3 -std=gnu99

main: main.o stack.o
	$(CC) $(CFLAGS) $^ -o $@
	rm -rf *.o

tests: stack_tests.o stack.o
	$(CC) $(CFLAGS) $^ -o $@
	rm -rf *.o

.PHONY: clean
clean:
	rm -rf *.o
	rm -rf main tests
