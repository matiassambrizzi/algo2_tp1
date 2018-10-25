echo -e '\e[1;41mBadDataFiles/BadFormat\e[0m:'
echo -e '\e[1;42mPara usarlo ingrese ./test.sh archvio_consuta\e[0m:'
echo -e '\e[1;31mConsultas\e[0m:'
cat $1
echo ' '
echo -e '\e[1;31mTEST_1\e[0m: Falta un sensor'
echo -e '\e[1;34mARCHIVO DE DATOS:\e[0m:'
cat BadDataF1_missingSensor.csv
echo -e '\e[1;34mSALIDA:\e[0m'
./tp1 -d BadDataF1_missingSensor.csv -i $1 -o -
echo ' '
echo -e '\e[1;31mTEST_2\e[0m: Datos extra'
echo -e '\e[1;34mARCHIVO DE DATOS:\e[0m:'
cat BadDataF2_extraData.csv
echo -e '\e[1;34mSALIDA:\e[0m'
./tp1 -d BadDataF2_extraData.csv -i $1 -o -
echo ' '
echo -e '\e[1;31mTEST_3\e[0m: Faltan datos'
echo -e '\e[1;34mARCHIVO DE DATOS:\e[0m:'
cat BadDataF3_missingData.csv
echo -e '\e[1;34mSALIDA:\e[0m'
./tp1 -d BadDataF3_missingData.csv -i $1 -o -