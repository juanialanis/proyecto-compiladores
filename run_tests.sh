echo "------------------------------------------------------------------------------------"
echo "----------------------------- Execute all tests SUCCESS ----------------------------"
echo "------------------------------------------------------------------------------------"
echo
read -p "Precione enter para comenzar"
for archivoActual in $(ls test/success);do
	clear
	echo "------------------------------------------------------------------------------------"
	echo "Running "$archivoActual" ..."
             ./ctds21  < "./test/success/"$archivoActual
	echo
	read -p "Precione enter para seguir"
done  
echo "------------------------------------------------------------------------------------"
echo "----------------------------- Execute all tests FAIL -------------------------------"
echo "------------------------------------------------------------------------------------"
echo
read -p "Precione enter para seguir"
for archivoActual in $(ls test/fail);do
	clear
	echo "------------------------------------------------------------------------------------"
	echo "Running "$archivoActual" ..."
             ./ctds21  < "./test/fail/"$archivoActual
	echo
	read -p "Precione enter para seguir"
done