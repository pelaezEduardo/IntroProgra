// HojaDeTrabajo_Punteros.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
using namespace std;
char *eliminarEspacioDerecha(char *str);
char *cambioCaracter(char *str);
char *obtenerPalabra(char *p, int n);

int main()
{
	char s1[20];
	char s2[20];
	char *s;
	char info[] = "primera,segunda,tercera,cuarta";
	s = obtenerPalabra(info, 3);
	strcpy_s(s2, "test#test2#test3");
	strcpy_s(s1, "Test    ");
	cout << "EJERCICIO 1:" << endl;
	cout << "Antes: |" << s1 << "|" << endl;
	eliminarEspacioDerecha(s1);
	cout << "Despues : |" << s1 << "|" << endl;
	
	cout << "\nEJERCICIO 2:" << endl;
	cout << "Antes: |" << s2 << "|" << endl;
	cambioCaracter(s2);
	cout << "Despues : |" << s2 << "|" << endl;

	cout << "\nEJERCICIO 3:" << endl;
	cout << "Palabra: " << s << endl;
	return 1; 
}

char *eliminarEspacioDerecha(char *str) {
	char *p;
	int len = strlen(str);

	p = &str[len - 1];
	
	while (*p == ' ') {
		--p;
	}
	++p;
	*p = '\0';
	return str;
}

char *cambioCaracter(char *str) {
	char *p;
	int len = strlen(str);
	p = str;

	for (int i = 0; i < len; i++)
	{
		if (*p == '#')
		{
			*p = ' ';
		}
		++p;
	}
	return str;
}

char *obtenerPalabra(char *p, int n) {
	int cont = 0;
	while (cont != n - 1) {
		p++;
		if (*p == ',')
		{
			cont++;
		}
	}
	++p;
	int size = strlen(p);
	while (*p != ',')
	{
		if (*p == ',')
		{
			for (int i = 0; i < size; i++)
			{
				p++;
			}
		}
	}
	return p;
}
// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
