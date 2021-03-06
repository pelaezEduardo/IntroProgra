// Final1096917.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include "Electrodomestico.h"
#include "Lavadora.h"
#include "Television.h"
#include "MyLinkedListC.h"

MyLinkedListC *electrodomesticos = new MyLinkedListC();
void resumenTotal();

using namespace std;
int main() {    	
	FILE *archivo;
	char caracter;
	string cadena = "";
	string atributos[7];
	archivo = fopen("informacion.txt", "r");
	int cont = 0;

	if (archivo == NULL) {
		cout << "Error en apertura de archivo";
	}
	else {
		caracter = fgetc(archivo);
		while (caracter != EOF) {
			if (caracter != '\n') {
				if (caracter != '|') {
					cadena += caracter;
					caracter = fgetc(archivo);
				}
				else {
					atributos[cont] = cadena;
					cadena = "";
					caracter = fgetc(archivo);
					cont++;
				}
			}
			else {
				atributos[cont] = cadena;
				cadena = "";				
				//inicializar electrodomestico con su constrcutor e ingresarlo a la lista enlazda.
				if (atributos[0] == "Lavadora") {
					Lavadora aux = *new Lavadora(stof(atributos[1].c_str()), atributos[2], atributos[3], atoi(atributos[4].c_str()), atoi(atributos[5].c_str()));
					electrodomesticos->addLast(1, aux);
				}				
				else if(atributos[0] == "Television") {
					Television aux = *new Television(stof(atributos[1].c_str()), atributos[2], atributos[3], atoi(atributos[4].c_str()), atoi(atributos[5].c_str()), atributos[6]);
					electrodomesticos->addLast(2, aux);
				}
				cont = 0;
				caracter = fgetc(archivo);
			}			
		}
		//para agregar ultima linea del archivo 
		atributos[cont] = cadena;
		if (atributos[0] == "Lavadora") {
			Lavadora aux = *new Lavadora(stof(atributos[1].c_str()), atributos[2], atributos[3], atoi(atributos[4].c_str()), atoi(atributos[5].c_str()));
			electrodomesticos->addLast(1, aux);
		}
		else {
			Television aux = *new Television(stof(atributos[1].c_str()), atributos[2], atributos[3], atoi(atributos[4].c_str()), atoi(atributos[5].c_str()), atributos[6]);
			electrodomesticos->addLast(2, aux);
		}
	}
	fclose(archivo);
	electrodomesticos->showElements();//mostrar electrodomesticos [resumen 1] 

	//resumen total
	resumenTotal();
}

void resumenTotal() {
	int cantidadLavadoras = 0;
	int cantidadTelevisiones = 0;
	float precioTotalLavadoras = 0;
	float precioToralTelevisiones = 0;

	//recorrer lista
	Node *aux = electrodomesticos->head;
	while (aux != NULL) {
		if (aux->getTipo() == 1) {// 1 lavadoras, 2 televisiones
			cantidadLavadoras++;
			precioTotalLavadoras += aux->getLavadora().calcularPrecio();
		}
		else {
			cantidadTelevisiones++;
			precioToralTelevisiones += aux->getTelivision().calcularPrecio();
		}
		aux = aux->getNext();
	}

	cout << "\nRESUMEN TOTAL" << endl;
	cout << "TIPO" << "\t\t" << "CANTIDAD" << "\t" << "PRECIO" << endl;
	cout << "Lavadoras" << "\t" << cantidadLavadoras << "\t\t" << precioTotalLavadoras << endl;
	cout << "Televisiones" << "\t" << cantidadTelevisiones << "\t\t" << precioToralTelevisiones << endl;
}