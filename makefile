CCFLAGS = -Wall -g
CC = g++
EXE = tp0

all: tp0 clean

tp0: main.obj errors.obj	array.obj cmdline.obj	sensor.obj	sensor_network.obj 	dato.obj 	#Los Objetos
	$(CC) $(CCFLAGS) -o $(EXE) main.obj errors.obj array.obj cmdline.obj sensor.obj sensor_network.obj dato.obj

main.obj: main.cpp main.hpp
	$(CC) $(CCFLAGS) -c -o main.obj main.cpp

errors.obj: errors.cpp errors.hpp
	$(CC) $(CCFLAGS) -c -o errors.obj errors.cpp

array.obj: array.cpp array.hpp
	$(CC) $(CCFLAGS) -c -o array.obj array.cpp

cmdline.obj: cmdline.cpp cmdline.hpp
	$(CC) $(CCFLAGS) -c -o cmdline.obj cmdline.cpp

sensor.obj: sensor.cpp sensor.hpp
	$(CC) $(CCFLAGS) -c -o sensor.obj sensor.cpp

sensor_network.obj: sensor_network.hpp sensor_network.cpp
	$(CC) $(CCFLAGS)  -c sensor_network.cpp -o sensor_network.obj

dato.obj: dato.cpp dato.hpp
	$(CC) $(CCFLAGS) -c -o dato.obj dato.cpp

test:
	./$(EXE) -d CPU_Temp.csv -i Consultas_CPU_temp.csv -o -

testValgrind:
	valgrind --leak-check=full ./$(EXE) -d CPU_Temp.csv -i Consultas_CPU_temp.csv -o -

clean:
	rm *.obj

clear:
	clear

git_push:
	git add .
	git commit -m "Modificaciones"
	git push origin master --force

git_pull:
	git pull origin master
