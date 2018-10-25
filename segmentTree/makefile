CCFLAGS = -Wall -g
CC = g++
EXE = segmentTree
EXE_TEST_NODE = testNode
EXE_TEST_SEGMENT = testSegment


all: segmentTree clean

#*****************************PROGRAMA_PRINCPIAL**************************#
segmentTree: main.obj array.obj sensor.obj dato.obj segmentTree.obj node.obj
	$(CC) $(CCFLAGS) -o $(EXE) main.obj array.obj sensor.obj dato.obj segmentTree.obj node.obj

#*****************************TESTEO_CLASE_NODO**************************#
testNode: test_node.obj dato.obj array.obj node.obj
	$(CC) $(CCFLAGS) -o $(EXE_TEST_NODE) test_node.obj dato.obj array.obj node.obj

#*****************************TESTEO_CLASE_ARBOL_DE_SEGMENTOS**************************#
testSegmentTree:	test_segment_tree.obj dato.obj array.obj node.obj segmentTree.obj
	$(CC) $(CCFLAGS) -o $(EXE_TEST_SEGMENT) test_segment_tree.obj dato.obj array.obj node.obj segmentTree.obj

#*****************************ARCHIVOS.OBJ**************************#
test_segment_tree.obj: test_segment_tree.cpp
	$(CC) $(CCFLAGS)  -c test_segment_tree.cpp -o test_segment_tree.obj

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


#*****************************MACROS_PARA_FACILITAR_COSAS**************************#
run_program:
	./$(EXE)

run_node_test:
	./$(EXE_TEST_NODE)

run_segment_test:
	./$(EXE_TEST_SEGMENT)

TestValgrind:
	valgrind --leak-check=full ./$(EXE)

clean:
	rm *.obj
