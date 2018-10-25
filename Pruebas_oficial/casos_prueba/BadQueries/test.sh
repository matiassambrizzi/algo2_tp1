echo -e '\e[1;41mBadQuerier\e[0m:'
echo -e '\e[1;42mPara usarlo ingrese ./test.sh archivo_de_datos\e[0m:'
echo ' '
echo -e '\e[1;31mTEST_1\e[0m: Falta un sensor'
echo -e '\e[1;34mARCHIVO DE CONSULTAS:\e[0m:'
cat BadQueries.csv
echo -e '\e[1;34mSALIDA:\e[0m'
./tp1 -d $1 -i BadQueries.csv -o -