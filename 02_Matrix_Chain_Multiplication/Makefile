
CXX = gcc
OPT = -O4
SOURCE = matrix.c chain_mm.c 
FLAG = -std=c99 -Wall -Wextra

all: main.x

main.x:
	$(CXX) -o $@ main.c $(SOURCE) $(FLAG)
clean:
	@rm -r *.x

.PHONY: clean all