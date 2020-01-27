CXX = g++
CXXFLAG = -Wall -Wextra -std=c++11
EXE = main.x

all: $(EXE)

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

$(EXE): main.o src/heap.cpp
	$(CXX) $^ -o $(EXE)

main.o: src/heap.o

src/heap.o: include/heap.hpp



clean:
	@rm -r *.x *.o src/*.o

.PHONY: clean all