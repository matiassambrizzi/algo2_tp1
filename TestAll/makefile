CCFLAGS = -Wall -g
CC = g++
EXE = tp1
EXE_TEST_NODE = testNode
EXE_TEST_SEGMENT = testSegment
EXE_TEST_SENSOR = testSensor


all: tp1 clean

tp1: main.obj errors.obj	array.obj cmdline.obj	sensor.obj	sensor_network.obj 	dato.obj node.obj segmentTree.obj 	#Los Objetos
	$(CC) $(CCFLAGS) -o $(EXE) main.obj errors.obj array.obj cmdline.obj sensor.obj sensor_network.obj dato.obj node.obj segmentTree.obj

#*****************************TESTEO_CLASE_NODO****************************************#
testNode: test_node.obj dato.obj array.obj node.obj
	$(CC) $(CCFLAGS) -o $(EXE_TEST_NODE) test_node.obj dato.obj array.obj node.obj

#*****************************TESTEO_CLASE_ARBOL_DE_SEGMENTOS**************************#
testSegmentTree:	test_segment_tree.obj dato.obj array.obj node.obj segmentTree.obj
	$(CC) $(CCFLAGS) -o $(EXE_TEST_SEGMENT) test_segment_tree.obj dato.obj array.obj node.obj segmentTree.obj

#*****************************CLASE_SENSOR*********************************************#
testSensor:	test_sensor.obj dato.obj array.obj node.obj segmentTree.obj sensor.obj
	$(CC) $(CCFLAGS) -o $(EXE_TEST_SENSOR) test_sensor.obj dato.obj array.obj node.obj segmentTree.obj sensor.obj

#*****************************ARCHIVOS.OBJ*********************************************#
test_sensor.obj: test_sensor.cpp
		$(CC) $(CCFLAGS)  -c test_sensor.cpp -o test_sensor.obj

test_segment_tree.obj: test_segment_tree.cpp
		$(CC) $(CCFLAGS)  -c test_segment_tree.cpp -o test_segment_tree.obj

test_node.obj: test_node.cpp
		$(CC) $(CCFLAGS)  -c test_node.cpp -o test_node.obj

main.obj: main.cpp
		$(CC) $(CCFLAGS)  -c main.cpp -o main.obj

cmdline.obj: cmdline.cpp cmdline.hpp
		$(CC) $(CCFLAGS) -c -o cmdline.obj cmdline.cpp

array.obj: array.cpp array.hpp
		$(CC) $(CCFLAGS)  -c array.cpp -o array.obj

sensor.obj: sensor.cpp sensor.hpp
		$(CC) $(CCFLAGS)  -c sensor.cpp -o sensor.obj

sensor_network.obj: sensor_network.hpp sensor_network.cpp
		$(CC) $(CCFLAGS)  -c sensor_network.cpp -o sensor_network.obj

dato.obj: dato.cpp dato.hpp
		$(CC) $(CCFLAGS)  -c dato.cpp -o dato.obj

segmentTree.obj: segmentTree.cpp segmentTree.hpp
		$(CC) $(CCFLAGS)  -c segmentTree.cpp -o segmentTree.obj

node.obj: node.cpp node.hpp
		$(CC) $(CCFLAGS)  -c node.cpp -o node.obj

errors.obj: errors.cpp errors.hpp
		$(CC) $(CCFLAGS) -c -o errors.obj errors.cpp

test:
	./$(EXE) -d CPU_Temp.csv -i Consultas_CPU_temp.csv -o -

run_node_test:
	./$(EXE_TEST_NODE)

run_segment_test:
	./$(EXE_TEST_SEGMENT)

run_sensor_test:
	./$(EXE_TEST_SENSOR)

testValgrind:
	valgrind --leak-check=full ./$(EXE) -d CPU_Temp.csv -i Consultas_CPU_temp.csv -o -

clean:
	rm *.obj

clear:
	clear

git_push:
	git add .
	git commit -m "Modificaciones"
	git push origin Testing --force

git_pull:
	git pull origin master
