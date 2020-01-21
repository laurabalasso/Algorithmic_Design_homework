CXX = gcc
OPT = -O4
SOURCE = matrix.c strassen.c
FLAG = -std=c99 -Wall -Wextra

all: main.x

main.x:
	$(CXX) -o $@ main.c $(SOURCE) $(FLAG)
clean:
	@rm -r *.x

.PHONY: clean all