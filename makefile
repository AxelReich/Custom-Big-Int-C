# Final executable target
int: myint.o main.o 
	g++ myint.o main.o -o a 

# Rule to compile myint.cpp into myint.o
myint.o: myint.cpp myint.h
	g++ -c myint.cpp -o myint.o

# Rule to compile main.cpp into main.o
main.o: main.cpp myint.h
	g++ -c main.cpp -o main.o 

# Clean up rule to remove object files and the executable
clear:
	rm -f *.o a
