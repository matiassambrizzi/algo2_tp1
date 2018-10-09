CCFLAGS = -Wall -g 
CC = g++
EXE = segmentTree

all: segmentTree clean

segmentTree: main.obj array.obj sensor.obj dato.obj segmentTree.obj node.obj
	$(CC) $(CCFLAGS) -o $(EXE) main.obj array.obj sensor.obj dato.obj segmentTree.obj node.obj 

main.obj: main.cpp
	$(CC) $(CCFLAGS)  -c main.cpp -o main.obj

array.obj: array.cpp array.hpp
	$(CC) $(CCFLAGS)  -c array.cpp -o array.obj

sensor.obj: sensor.cpp sensor.hpp
	$(CC) $(CCFLAGS)  -c sensor.cpp -o sensor.obj

dato.obj: dato.cpp dato.hpp
	$(CC) $(CCFLAGS)  -c dato.cpp -o dato.obj

segmentTree.obj: segmentTree.cpp segmentTree.hpp
	$(CC) $(CCFLAGS)  -c segmentTree.cpp -o segmentTree.obj

node.obj: node.cpp node.hpp
	$(CC) $(CCFLAGS)  -c node.cpp -o node.obj

runs:
	./$(EXE)

TestValgrind:
	valgrind --leak-check=full ./$(EXE)

clean:
	rm *.obj