CC = clang++

main: matris.o
	$(CC) -stdlib=libc++ -std=c++0x -o main matris.o

matris.o: matris.cpp matris.h
	$(CC) -stdlib=libc++ -std=c++0x -c matris.cpp
