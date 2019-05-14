#!make -f

all: demo
	./$<

demo:  Demo.o 
	clang++ -std=c++17 $^ -o demo

test:  Test.o 
	clang++ -std=c++17 $^ -o test

%.o: %.cpp range.hpp chain.hpp powerset.hpp product.hpp zip.hpp
	clang++ -std=c++17 --compile $< -o $@

version:
	clang++ --version

clean:
	rm -f *.o demo test
