# Starter Makefile
# add .cpp and .h files as specified in each task. 

main: main.o reservoir.o reverseorder.o
	g++ main.o reservoir.o reverseorder.o -o main

main.o: main.cpp
	g++ -c main.cpp

reservoir.o: reservoir.cpp
	g++ -c reservoir.cpp

reverseorder.o: reverseorder.cpp
	g++ -c reverseorder.cpp

clean:
	rm -f main.o reservoir.o reverseorder.o 
