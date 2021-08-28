rectangle: Rectangle.o main.o
	g++ main.o Rectangle.o -o rectangle

main.o: main.cpp
	g++ -c main.cpp

Rectangle.o: Rectangle.cpp Rectangle.h
	g++ -c Rectangle.cpp