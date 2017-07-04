CXX = g++

test: Tests/atest.exe

Tests/atest.exe: libmatarray.hpp Tests/test.cpp
	g++ --std=c++11 -I. -o Tests/atest.exe Tests/test.cpp

clean:
	rm -f Tests/atest.exe

.PHONY: test clean
