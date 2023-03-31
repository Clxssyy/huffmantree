all:
	g++ -std=c++11 -c *.cpp
	g++ -std=c++11 *.o -o huffman.out

run:
	g++ -std=c++11 -c *.cpp
	g++ -std=c++11 *.o -o huffman.out
	./huffman.out