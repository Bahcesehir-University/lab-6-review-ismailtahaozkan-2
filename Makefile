CXX = g++
CXXFLAGS = -Wall --std=c++17

all: main

main: MainProgram.cpp
	$(CXX) $(CXXFLAGS) -o main MainProgram.cpp

test_build: test.cpp MainProgram.cpp catch_amalgamated.cpp
	$(CXX) $(CXXFLAGS) -o test_bin test.cpp catch_amalgamated.cpp

test: test_build
	./test_bin

test1: test_build
	./test_bin [constructors]

test2: test_build
	./test_bin [copy]

test3: test_build
	./test_bin [encapsulation]

test4: test_build
	./test_bin [strings]

test5: test_build
	./test_bin [operators]

test6: test_build
	./test_bin [functions]

clean:
	rm -f main test_bin

.PHONY: all test test1 test2 test3 test4 test5 test6 clean
