// EjerciciosFinal.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "DoubleLinkedList.h"
#include "DoubleLinkedList.cpp"
#include "CircularLinkedList.h"
#include "CircularLinkedList.cpp"

bool validacion1(CircularLinkedList<char> *lc, DoubleLinkedList<char> *lde);

using namespace std;
int main(){
	bool flag = true;
	DoubleLinkedList<char> *lde = new DoubleLinkedList<char>();
	CircularLinkedList<char> *lc = new CircularLinkedList<char>();
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
				flag = false;
				caracter = fgetc(archivo);
				lc->addLast(caracter);
			}
		}
	}
	fclose(archivo);
	cout << "LA LECTURA DEL ARCHIVO SE REALIZO CORRECTAMENTE" << endl;	
	lc->showElements();	
	cout << validacion1(lc, lde);	
}

bool validacion1(CircularLinkedList<char> *lc, DoubleLinkedList<char> *lde) {
	bool response = true;	
	CircularLinkedList<char> *lc2 = lc;
	NodeD<char> *aux = lde->header->getNext();
	char comp = lc2->removeFirst();

	while (!lc2->isEmpty()) {		
		if (aux->getElement() == comp) {
			aux = lde->header->getNext();
			comp = lc2->removeFirst();
			response = true;
		}
		else {
			aux = aux->getNext();
			if (aux == lde->trailer) {				
				break;
			}
			else {				
				response = false;
			}
		}
	}
	return response;
}