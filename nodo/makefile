CCFLAGS = -Wall -g
CC = g++
EXE = segmentTree

all: segmentTree clean

segmentTree: main.obj array.obj sensor.obj dato.obj
	$(CC) $(CCFLAGS) -o $(EXE) main.obj array.obj sensor.obj dato.obj

main.obj: main.cpp
	$(CC) $(CCFLAGS)  -c main.cpp -o main.obj

array.obj: array.cpp array.hpp
	$(CC) $(CCFLAGS)  -c array.cpp -o array.obj

sensor.obj: sensor.cpp sensor.hpp
	$(CC) $(CCFLAGS)  -c sensor.cpp -o sensor.obj

dato.obj: dato.cpp dato.hpp
	$(CC) $(CCFLAGS)  -c dato.cpp -o dato.obj

runs:
	./$(EXE)

TestValgrind:
	valgrind --leak-check=full ./$(EXE)

clean:
	rm *.obj
