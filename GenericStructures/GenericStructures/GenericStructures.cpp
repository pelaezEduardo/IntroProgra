// GenericStructures.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include "MyLinkedList.h"
#include "MyLinkedList.cpp"

using namespace std;
int main() {
	MyLinkedList<int> myList;
	myList.addLast(1);
	myList.addLast(2);
	myList.addLast(3);
	myList.addLast(4);
	myList.addLast(5);
	cout << "LISTAS GENERICAS EN C++" << endl;
	cout << "El primer elemento de la lista es: " << myList.first() << endl;
	cout << "El ultimo elemento de la lista es: " << myList.last() << endl;
	cout << "Los elementos de la lista son: " << endl;
	myList.showElements();	
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
