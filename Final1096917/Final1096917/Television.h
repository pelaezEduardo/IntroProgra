#pragma once
#include "Electrodomestico.h"
#include <string>
#include <iostream>

using namespace std;
class Television: public Electrodomestico
{
public:
	Television();
	Television(float ePrecio, string eColor, string eConsumo, int ePeso, int tResolucion, string tSintonizador);
	int getResolucion();
	void setResolucion(int tResolucion);
	bool getSintonizador();
	void setSintonizador(bool tSintonizador);
	void toString();
	float calcularPrecio();
	~Television();
private:
	int resolucion;
	bool sintonizador;
};

