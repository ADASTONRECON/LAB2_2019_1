#include "Herramientas.h"

#define MAX_CAR 123

void imprimirLineas(char car){
	for(int i = 0; i < MAX_CAR; i++)
		putchar (car);
	putchar('\n');

	return;
}

void imprimirTitulo(){
	cout << setw(75) << right  <<"REGISTRO CLIMATICO DEL PAIS" << endl;
        cout << left;
	imprimirLineas('=');

	cout << left;
	return;

}

void imprimirEncabezado(){
	imprimirTitulo();

	cout << right << setw (10) << "CIUDAD" << setw(25) << "CODIGO" << setw(15) << "FECHA" << setw(20) << "TEMPERATURA" << setw(20) << "HUMEDAD" << setw(26) << "PRECIPITACIONES" << endl;

	cout << setw(71) << "°C    °F" << setw(19) << '%' << setw(32) << "TIEMPO(seg)   CANTIDAD" << endl;


	imprimirLineas('-');

	cout << left;
	return;
}

void imprimirEspacios(int cant){
	for(int i = 0; i < cant; i++) putchar(' ');
	return;
}

bool esDigito(char car){
	if(car >= '0' && car <= '9')
		return true;
	return false;
}
