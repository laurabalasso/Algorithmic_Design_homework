CXX = g++
CXXFLAGS =  -Wall -Wextra -std=c++11 

all: sorting_main.x sorting_tests.x select_main.x

sorting_main.x: src/array_utilities.cpp src/heap.cpp src/sorting.cpp src/Select.cpp
	$(CXX) -O3 -I include $^ sorting_main.cpp -o $@ $(CXXFLAGS)

sorting_tests.x: src/array_utilities.cpp src/heap.cpp src/sorting.cpp
	$(CXX) -O3 -I include $^ sorting_tests.cpp -o $@ $(CXXFLAGS)

select_main.x: src/array_utilities.cpp src/Select.cpp
	$(CXX) -O3 -I include $^ select_main.cpp -o $@ $(CXXFLAGS)

clean:
	rm -rf src/*.o *.o *.x

.PHONY: clean all format