// EjerciciosFinal.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "MyLinkedList.h"
#include "MyLinkedList.cpp"
#include "DoubleLinkedList.h"
#include "DoubleLinkedList.cpp"

using namespace std;
int main(){
	bool flag = true;
	DoubleLinkedList<char> *lde = new DoubleLinkedList<char>();
	FILE *archivo;
	char caracter;		
	archivo = fopen("Prueba.txt", "r");

	if (archivo == NULL) {
		cout << "Error en apertura de archivo";
	}
	else {
		caracter = fgetc(archivo);
		while (caracter != EOF) {
			if (caracter != '\n' && flag) {
				lde->addLast(caracter);
				caracter = fgetc(archivo);
			}
			else {
				caracter = fgetc(archivo);


			}
		}
	}
	fclose(archivo);
}