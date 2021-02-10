CC = clang++

mytestrunner: matris.o matris.cpp mytest.h
	python cxxtest-4.4/bin/cxxtestgen --error-printer -o myrunner.cpp mytest.h
	$(CC) -stdlib=libc++ -std=c++0x -c -o matris.o matris.cpp
	$(CC) -stdlib=libc++ -std=c++0x -o mytestrunner myrunner.cpp -Icxxtest-4.4 matris.o
	

main: matris.o
	$(CC) -stdlib=libc++ -std=c++0x -o main matris.o

matris.o: matris.cpp matris.h
	$(CC) -stdlib=libc++ -std=c++0x -c matris.cpp
