CXX = gcc
SOURCE = src/matrix.c src/strassen.c src/Strassen_improved.c
FLAG = -std=c99 -O3

all: main.x

main.x:
	$(CXX) -o $@ main.c $(SOURCE) $(FLAG)
clean:
	@rm -r *.x

.PHONY: clean all