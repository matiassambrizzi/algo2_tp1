echo -e '\e[1;41mGoodQueries\e[0m:'
echo -e '\e[1;42mPara usarlo ingrese ./test.sh \e[0m:'
echo ' '
echo -e '\e[1;31mTEST_1\e[0m: Sensores sin datos'
echo -e '\e[1;34mSALIDA:\e[0m'
./tp1 -d Data1_soloNombres.csv -i Query1_soloNombres.csv -o -
echo ' '
echo -e '\e[1;31mTEST_2\e[0m: Archivos de datos vacío'
echo -e '\e[1;34mSALIDA:\e[0m'
./tp1 -d Data2_archivoDataVacio.csv -i Query2_archivoDataVacio.csv -o -
echo ' '
echo -e '\e[1;31mTEST_3\e[0m: Mediciones Vacias'
echo -e '\e[1;34mSALIDA:\e[0m'
./tp1 -d Data3_medicionesVacias.csv -i Query3_medicionesVacias.csv -o -
echo ' '
echo -e '\e[1;31mTEST_4\e[0m: Algunas mediciones vacias'
echo -e '\e[1;34mSALIDA:\e[0m'
./tp1 -d Data4_mezclaConVacio.csv -i Query4_mezclaConVacio.csv -o -
echo ' '
echo -e '\e[1;31mTEST_5\e[0m: Querys Absurdas'
echo -e '\e[1;34mSALIDA:\e[0m'
./tp1 -d Data5_queriesAbsurdas.csv -i Query5_queriesAbsurdas.csv -o -
echo ' '
echo -e '\e[1;31mTEST_6\e[0m: Mismo Nombre'
echo -e '\e[1;34mSALIDA:\e[0m'
./tp1 -d Data6_mismoNombre.csv -i Query6_mismoNombre.csv -o -
