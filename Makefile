
tp02: main.o graph.o
	g++ main.o graph.o -o tp02
main.o: main.cpp
	g++ -c main.cpp
graph.o: ./src/graph.cpp
	g++ -c ./src/graph.cpp
clean:
	rm *.o tp02