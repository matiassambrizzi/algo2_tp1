echo -e '\e[1;41mBadDataFiles/BadContent\e[0m:'
echo -e '\e[1;42mPara usarlo ingrese ./test.sh archvio_consuta\e[0m:'
echo -e '\e[1;31mConsultas\e[0m:'
cat $1
echo ' '
echo -e '\e[1;31mTEST_1\e[0m: Letra en el archivo de datos'
echo -e '\e[1;34mARCHIVO DE DATOS:\e[0m:'
cat BadDataC1_letra.csv
echo -e '\e[1;34mSALIDA:\e[0m'
./tp1 -d BadDataC1_letra.csv -i $1 -o -
echo ' '
echo -e '\e[1;31mTEST_2\e[0m: Simbolo en el archivo de datos'
echo -e '\e[1;34mARCHIVO DE DATOS:\e[0m'
cat BadDataC2_simbolo.csv
echo -e '\e[1;34mSALIDA:\e[0m'
./tp1 -d BadDataC2_simbolo.csv -i $1 -o -
echo ' '
echo -e '\e[1;31mTEST_3\e[0m: Doble punto en el archivo de datos'
echo -e '\e[1;34mARCHIVO DE DATOS:\e[0m'
cat BadDataC3_doblePunto.csv
echo -e '\e[1;34mSALIDA:\e[0m'
./tp1 -d BadDataC3_doblePunto.csv -i $1 -o -
echo ' '
echo -e '\e[1;31mTEST_4\e[0m: Un punto solo en el archivo de datos'
echo -e '\e[1;34mARCHIVO DE DATOS:\e[0m'
cat BadDataC4_puntoSolo.csv
echo -e '\e[1;34mSALIDA:\e[0m'
./tp1 -d BadDataC4_puntoSolo.csv -i $1 -o -
echo ' '
echo -e '\e[1;31mTEST_5\e[0m:Letra con número'
echo -e '\e[1;34mARCHIVO DE DATOS:\e[0m'
cat BadDataC5_letrayNumero.csv
echo -e '\e[1;34mSALIDA:\e[0m'
./tp1 -d BadDataC5_letrayNumero.csv -i $1 -o -
echo ' '
echo -e '\e[1;31mTEST_6\e[0m:Simbolo y numero'
echo -e '\e[1;34mARCHIVO DE DATOS:\e[0m'
cat BadDataC6_simboloyNumero.csv
echo -e '\e[1;34mSALIDA:\e[0m'
./tp1 -d BadDataC6_simboloyNumero.csv -i $1 -o -



