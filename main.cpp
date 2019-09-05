#include <iostream>
#include <iomanip>

#include "Herramientas.h"

#define MAX_CAR 30

using namespace std;

int main(){
	imprimirEncabezado();

	char car;
	bool lineaimpresa = false;
	int codigociudad, cantcar = 0;
	int dia,mes,anio;
	char tipodato;
	double gradoscels, gradosfahr, temp, tiempoprec, cantprec, humedad;

        while(1){
		if(!(cin >> codigociudad)){
			cin.clear();
			car = getchar();
			do{
				cantcar++;
				putchar(car);
				car = getchar();	
			}while (car != ' ');
			cantcar++;
			putchar(car);
		} else {
			imprimirEspacios(MAX_CAR - cantcar);	
			cantcar = 0;
			cout << left << setw(12) << codigociudad;
			while(1){
			//Aqui comienza la lectura de los datos
                if(lineaimpresa){
                        imprimirEspacios(MAX_CAR + 15);                        
                } else {
                        lineaimpresa = true;
                }

        		for(int i = 0; i < 3; i++){
				cin >> ws;
				tipodato = getchar();

				switch(tipodato){
					case 'T':{
						cin >> temp;
						cin >> tipodato;

						if (tipodato == 'F'){
							gradosfahr = temp;
							gradoscels = (temp-32.0)*5.0/9.0;
						} else {
							gradoscels = temp;
							gradosfahr = (temp * 9.0 / 5.0)+ 32.0;
						}
						//cout << endl << endl << gradoscels <<' '<< gradosfahr<< endl<< endl;

						break;
					}
					case 'P':{
						//getchar();
						car = cin.peek();
            					if (car == 'H' || car == 'M' || car == 'S') {
							getchar();
							tiempoprec= 0.0;
							cantprec = 0.0;
						} else {
							cin >> tiempoprec;
							car = getchar();
							cin >> cantprec;
							switch(car){
								case 'H':
									tiempoprec *= 60;
								case 'M':
									tiempoprec *= 60;	
							}
						}
						break;
					}
					case 'H':{
						//getchar();
						//cin >> humedad;
						car = cin.peek();
						if (car == '%'){
							humedad = 0.0;
						} else {
							cin >> humedad;
							car = cin.peek();
							if (car != '%')
								humedad /= 100.0;
						}
						//cout << '*' << humedad << '*';
						break;
					}
				}
			}
			//cout << endl << "Precipitacion " << tiempoprec << ' ' << cantprec;
			//cout << endl << "Temperatura " << gradoscels << ' ' << gradosfahr;
			//cout << endl << "Humedad " << humedad << "*********"; 
			cin >> anio;
			mes = 0;
			dia = 0;
			car = cin.peek();
			if (car =='/'){
				getchar();
				mes = anio;
				cin >> anio;
			}
			car = cin.peek();
			if(car == '/'){
				getchar();
				dia = mes;
				mes = anio;
				cin >> anio;
			}
			
			if(dia == 0)
				cout << "--/";
			else
				cout << dia << '/';

			if(mes == '0')
				cout << "--/";
			else
				cout << mes << '/';

			cout << left << setw(10) << anio;

			cout << setprecision(2);
			cout << fixed;

			cout << right << setw(5) << gradoscels << "  " << setw(7) << gradosfahr;
		    cout << setw(17) << humedad;
            cout << setw(17) << tiempoprec << setw(14) << cantprec << endl;

            cin >> car;
            if(cin.eof()){
                return 0;
            } 
            if (car == '\n'){
                    lineaimpresa = false;
                    break;
            }else{
                    ungetc;                   
            }           
            }
		}
	}
	return 0;
}

