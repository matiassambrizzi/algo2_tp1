CCFLAGS = -Wall -g
CC = g++
EXE = segmentTree

EXE_TEST_NODE = testNode

all: segmentTree clean

segmentTree: main.obj array.obj sensor.obj dato.obj segmentTree.obj node.obj
	$(CC) $(CCFLAGS) -o $(EXE) main.obj array.obj sensor.obj dato.obj segmentTree.obj node.obj

testNode: test_node.obj dato.obj array.obj node.obj
	$(CC) $(CCFLAGS) -o $(EXE_TEST_NODE) test_node.obj dato.obj array.obj node.obj

test_node.obj: test_node.cpp
	$(CC) $(CCFLAGS)  -c test_node.cpp -o test_node.obj

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

run_program:
	./$(EXE)

run_node_test:
	./$(EXE_TEST_NODE)

TestValgrind:
	valgrind --leak-check=full ./$(EXE)

clean:
	rm *.obj
