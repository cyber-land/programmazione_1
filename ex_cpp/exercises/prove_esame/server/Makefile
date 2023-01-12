CC = clang++
CFLAGS += -Wall -Werror -ggdb3 -std=gnu99

PROG_NAME = main

$(PROG_NAME): main.o dati.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

.PHONY: clean
clean:
	rm -rf *.o
	# rm -rf $(PROG_NAME)
