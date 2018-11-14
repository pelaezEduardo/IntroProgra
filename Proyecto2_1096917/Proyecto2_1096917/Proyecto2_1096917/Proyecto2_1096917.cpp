// Proyecto2_1096917.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include "BinaryTree.h"
#include "BinaryTree.cpp"
#include "Jugador.h"
#include "Persona.h"
#include <iostream>
#include <string>

void showTeam(TreeNode<Jugador> *root, string team);
using namespace std;
int main()
{    
	BinaryTree<Jugador> *guard = new BinaryTree<Jugador>();
	BinaryTree<Jugador> *forward = new BinaryTree<Jugador>();
	BinaryTree<Jugador> *center = new BinaryTree<Jugador>();
	int opt = 0;
	cout << "SEGUNDO PROYECTO \nClasificacion para el juego de las estrellas." << endl;

	do {
		cout << "\nSELECCIONE UNA OPCION" << endl;
		cout << "1. MANEJO DE DATOS" << endl;
		cout << "2. REPORTE ESTADISTICAS" << endl;
		cout << "3. SIMULACION"<< endl;
		cout << "4. SALIR" << endl;
		cin >> opt;

		switch (opt)
		{
		case 1: {
			cout << "DATOS CARGADOS AL SISTEMA CORRECTAMENTE." << endl;


			FILE *archivo;
			char caracter;		
			string cadena = "";
			string atributos[18];
			archivo = fopen("Prueba.txt", "r");
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
						Jugador aux;
						aux = *new Jugador(atributos[0], atributos[1], atributos[2], atributos[3], atributos[4], atoi(atributos[5].c_str()), atoi(atributos[6].c_str()),
							atributos[7], atributos[8], atributos[9], atributos[10], atoi(atributos[11].c_str()), atributos[12], atoi(atributos[13].c_str()),
							atoi(atributos[14].c_str()), atoi(atributos[15].c_str()), atoi(atributos[16].c_str()), atoi(atributos[17].c_str()));
						if (atributos[4] == "G") {
							guard->add(aux, aux.getId());
						}
						else if (atributos[4] == "F") {
							forward->add(aux, aux.getId());
						}
						else {
							center->add(aux, aux.getId());
						}
						cont = 0;
						caracter = fgetc(archivo);
					}
				}
			}
			fclose(archivo);
					
		}break;

		case 2: {
			int option = 0;
			cout << "\nSELECCIONE LA OPCIÓN DE SU REPORTE DE ESTADISTICAS: " << endl;
			cout << "1. POR JUGADOR" << endl;
			cout << "2. POR EQUIPO" << endl;
			cout << "3. LISTADO" << endl;
			cin >> option;

			if (option == 1) {
				Jugador response;
				int id = 0;
				cout << "\nINGRESE EL CODIGO DEL JUGADOR QUE DESEA CONSULTAR: " << endl;
				cin >> id;
				if (guard->elementExists(guard->root, id)) {
					response = guard->showElement(guard->root, id);
					response.toString();
				}
				else if (forward->elementExists(forward->root, id)) {
					response = forward->showElement(forward->root, id);
					response.toString();
				}
				else if (center->elementExists(center->root, id)) {
					response = center->showElement(center->root, id);
					response.toString();
				}
				else {
					cout << "\nEL CODIGO DEL JUGADOR NO EXISTE O ES INCORRECTO." << endl;
				}
			}
			else if (option == 2) {
				string team = "";
				cout << "\nINGRESE EL NOMBRE DEL EQUIPO DE SU CONSULTA: " << endl;
				cin >> team;
				showTeam(guard->root, team);
				showTeam(forward->root, team);
				showTeam(center->root, team);
			}

		}break;

		case 3: {
		}break; 		

		default:
			cout << "GRACIAS POR USAR EL PROGRAMA" << endl;
			break;
		}

	} while (opt != 4);
}

void showTeam(TreeNode<Jugador> *root, string team) {
	if (root != NULL) {
		if (root->getElement().getTeam() == team) {
			root->getElement().toString();
			cout << endl;
			cout << endl;
		}		
		showTeam(root->getLeft(), team);
		showTeam(root->getRight(), team);
	}
}