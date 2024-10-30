int : myint.o main.o 
	g++ myint.o main.o -o a 

int.o : myint.o myint.h
	g++ -c myint.cpp

main.o : main.o myint.h
	g++ -c main.cpp 

clear :
	rm -f  *.o myint