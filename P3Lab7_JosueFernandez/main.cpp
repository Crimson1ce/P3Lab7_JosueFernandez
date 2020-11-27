/* 
 * File:   main.cpp
 * Author: Josue Fernández
 *
 * Created on 27 de noviembre de 2020, 01:30 PM
 * 
 * Laboratiorio 7, Programación 3
 */

#include <cstdlib>
#include <iostream>
#include "Persona.h"
#include "Mensaje.h"

using std::cout;
using std::cin;
using std::endl;

Persona* personaActual = NULL;
Mensaje* mensajeActual = NULL;

//Prototipos 

/* Muestra el menú principal
 */
int menuPrincipal();

int main(int argc, char** argv) {

    int opcion = -1;

    while (opcion) {

        switch (opcion = menuPrincipal()) {
            case 0:
                cout << "Nos vemos!\n";
                break;

            case 1:
                cout << "Registro\n";
                break;
            case 2:
                cout << "Ingreso\n";
                break;
        }

    }

    return 0;
}

/* Muestra el menú principal
 */
int menuPrincipal() {
    int opcion = 0;

    cout << "\t\tMENU PRINCIPAL" << endl << endl
            << "1. Registrarse" << endl
            << "2. Ingresar" << endl
            << "0. Salir" << endl;

    cout << "Ingrese una opcion: ";
    cin >> opcion;
    while (opcion < 0 || opcion > 2) {
        cout << "Ingrese una opcion valida: ";
        cin >> opcion;
    }
    cout << endl;
    return opcion;
}