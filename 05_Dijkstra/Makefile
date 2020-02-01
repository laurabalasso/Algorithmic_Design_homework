EXE = main.x 

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 

all: $(EXE)

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)


$(EXE): main.o src/dijkstra_utility.o src/Dijkstra_array.o src/Dijkstra_heap.o src/heap.o 
	$(CXX) $^ -o $(EXE) 

main.o: src/dijkstra_utility.o src/Dijkstra_array.o src/Dijkstra_heap.o src/heap.o 

src/dijkstra_utility.o: include/dijkstra_utility.hpp

src/Dijkstra_array.o: include/Dijkstra_array.hpp include/dijkstra_utility.hpp

src/Dijkstra_heap.o: include/Dijkstra_heap.hpp include/dijkstra_utility.hpp

src/heap.o: include/heap.hpp include/dijkstra_utility.hpp

clean:
	rm -rf src/*.o *.o $(EXE) 

.PHONY: clean all format