all: main
	rm *.o
main: getinput Solution MB ./main.cpp
	g++ -Wall -o prog getinput.o sol.o mb.o ./main.cpp
getinput: ./implementation/getInput.cpp
	g++ -Wall -c -o getinput.o ./implementation/getInput.cpp
Solution: ./implementation/Solution.cpp
	g++ -Wall -c -o sol.o ./implementation/Solution.cpp
MB: ./implementation/MB.cpp
	g++ -Wall -c -o mb.o ./implementation/MB.cpp
