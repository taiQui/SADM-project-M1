all: main
	rm *.o
main: getinput.o ./main.cpp
	g++ -Wall -o prog getinput.o ./main.cpp -lpthread
getinput.o: ./implementation/getInput.cpp
	g++ -Wall -c -o getinput.o ./implementation/getInput.cpp
