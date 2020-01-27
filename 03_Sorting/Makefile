EXE = sorting_main.x

CXX = g++
CXXFLAGS = -Wall -std=c++11

all: $(EXE)

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)


$(EXE): sorting_main.o src/array_utilities.o src/sorting.o src/heap.o
	$(CXX) $^ -o $(EXE) 

sorting_main.o: src/sorting.o src/array_utilities.o src/heap.o

src/array_utilities.o: include/array_utilities.hpp

src/sorting.o: include/sorting.hpp

src/heap.o: include/heap.hpp

format: $(SRC) include/array_utilities.hpp include/sorting.hpp include/heap.hpp
	@clang-format -i $^ 2>/dev/null || echo "Please install clang-format to run this commands"

clean:
	rm -rf src/*.o *.o $(EXE) 

.PHONY: clean all format