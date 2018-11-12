#Archivo para generar pruebas de complejidad. Primero, correr el archivo generate_med_querys.m.
#con eso, generar varios archivos de mediciones con sus consultas. Luego, correr este script para
#quedarse con los tiempo de ejecucion que se guardan en el archivo "complejidad.txt"
#Salu2

echo -e '\e[1;41mComplejidad Algoritmica\e[0m:'

rm salida.txt
rm complejidad.txt
rm aux.txt
rm aux1.txt

i=1
max=$1

#while [ $i -lt $max ]
#do
#	file="querys$i.txt"
#	echo $file
#	./tp1 -d mediciones.txt -i $file -o - >> salida.txt
 #   true $(( i++ ))
#done

while [ $i -lt $max ]
do
	fileDatos="mediciones$i.txt"
	fileQuerys="querys$i.txt"
	echo $fileDatos
	echo $fileQuerys
	./tp1 -d $fileDatos -i $fileQuerys -o - >> salida.txt
    true $(( i++ ))
done

echo '1' >> complejidad.txt
grep 'TP1:Tiempo de procesamiento:' salida.txt >> aux.txt
grep -Eo "[0-9]+\.[0-9]+" aux.txt >> complejidad.txt
echo '0' >> complejidad.txt
grep 'TPO:Tiempo de procesamiento:' salida.txt >> aux1.txt
grep -Eo "[0-9]+\.[0-9]+" aux1.txt >> complejidad.txt

rm mediciones*
rm querys*


