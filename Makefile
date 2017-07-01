CXX = g++
BOOSTDIR = /Users/Josh/Library/Cpp/boost_1_64_0

all: test.exe

test.exe: matrix_utils.cpp
	$(CXX) -I$(BOOSTDIR) -o $@ $^

clean:
	rm *.exe *.o

.PHONY: all clean
