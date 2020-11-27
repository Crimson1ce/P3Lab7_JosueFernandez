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
#include <vector>
#include <string>

#include "Persona.h"
#include "Mensaje.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

//using namespace std;

Persona* receptorActual = NULL;
Persona* personaActual = NULL;
int indiceActual = -1;
Mensaje* mensajeActual = NULL;

vector<Persona*> registrados;
int cantidadRegistrados = 0;

//Prototipos 

/* Muestra el menú principal
 */
int menuPrincipal();

/* Muestra el menú al ingresar con el usuario
 */
int menuIngreso();

/* Se ejecuta cuando un usuario ingresa
 */
void ingreso();

/* Encripta una cadena de acuerdo a una llave
 */
string encriptado(string mensaje, int llave, bool codificar);

int main(int argc, char** argv) {

    int opcion = -1;

    
//    string en = encriptado("adios",15,true);
//    cout << "adios -> " << en << " -> " << encriptado(en,15,false);
    
    string nombre = "", apellido = "", password = "";

    //    cout << "Nombre: "; cin >> nombre;
    //    cout << "Apellido: "; cin >> apellido;
    //    cout << "Password: "; cin >> password;
    //    
    //    Persona* p = new Persona(nombre,apellido,password);
    //    
    //    registrados.push_back(p);
    //    cantidadRegistrados++;
    //    
    //    cout << "\n" << nombre << " " << apellido << " " << password;
    //    cout << "\n" << p->getNombre() << " " << p->getApellido() << " " << p->getPassword();
    //    cout << "\n" << ((Persona*)(registrados.at(0)))->getNombre() << " " << ((Persona*)(registrados.at(0)))->getApellido() << " " << ((Persona*)(registrados.at(0)))->getPassword();
    //    
    //    delete ((Persona*)(registrados.at(0)));


    while (opcion) {

        switch (opcion = menuPrincipal()) {
            case 0:
            {
                cout << "Nos vemos!\n";
                break;
            }
            case 1:
            {
                cout << "### REGISTRO ###\n";

                cout << "\nIngrese su nombre: ";
                cin >> nombre;

                cout << "Ingrese su apellido: ";
                cin >> apellido;

                cout << "Ingrese su contrasena: ";
                cin >> password;

                Persona* persona = new Persona(nombre, apellido, password);
                registrados.push_back(persona);
                cantidadRegistrados++;

                cout << "\nRegistro exitoso!\n\n"
                        << "\tSu usuario es:\n"
                        << "\t--------------"
                        << "\n\tNombre: " << ((Persona*) registrados.at(cantidadRegistrados - 1))->getNombre()
                        << "\n\tApellido: " << ((Persona*) registrados.at(cantidadRegistrados - 1))->getApellido()
                        << "\n\tContrasena: " << ((Persona*) registrados.at(cantidadRegistrados - 1))->getPassword() << endl;

                nombre = apellido = password = "";

                break;
            }
            case 2:
            {
                cout << "### INGRESO ###\n";

                cout << "\nIngrese su nombre: ";
                cin >> nombre;
                cout << "Ingrese su contrasena: ";
                cin >> password;

                bool coinciden = false;

                for (int i = 0; i < cantidadRegistrados; i++) {
                    if (nombre.compare(((Persona*) registrados.at(i))->getNombre()) == 0
                            && password.compare(((Persona*) registrados.at(i))->getPassword()) == 0) {
                        personaActual = ((Persona*) registrados.at(i));
                        cout << "\n\t Bienvenid@: " << personaActual->getNombre() << "\n";
                        coinciden = true;
                        indiceActual = i;
                        break;
                    }
                }

                if (coinciden == true) {
                    ingreso();
                } else {
                    cout << "\nEl nombre o la contrasena no es correcta.\n";
                }

                nombre = apellido = password = "";

                break;
            }
        }

    }

    for (int i = 0; i < cantidadRegistrados; i++) {
        delete ((Persona*) registrados.at(i));
    }

    return 0;
}

/* Muestra el menú principal
 */
int menuPrincipal() {
    int opcion = 0;

    cout << "\n\tC.S.I. MESSENGER SERVICE" << endl << endl
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

int menuIngreso() {
    int opcion = 0;

    cout << "\n\tOpciones de Usuario" << endl << endl
            << "1. Enviar mensaje" << endl
            << "2. Ver mensajes" << endl
            << "3. Ver mi llave" << endl
            << "0. Salir" << endl;

    cout << "Ingrese una opcion: ";
    cin >> opcion;
    while (opcion < 0 || opcion > 3) {
        cout << "Ingrese una opcion valida: ";
        cin >> opcion;
    }
    cout << endl;
    return opcion;
}

/* Se ejecuta cuando un usuario ingresa
 */
void ingreso() {

    int opcion = -1;
    while (opcion) {

        switch (opcion = menuIngreso()) {
            case 1:
            {
                cout << "### ENVIAR MENSAJE ###\n\n";

                if (cantidadRegistrados < 2) {
                    cout << "-> No hay otro usuario al que enviarle un mensaje.\n";
                    break;
                } else {
                    int resta = 0;
                    for (int i = 0; i < cantidadRegistrados; i++) {
                        if (indiceActual == i) {
                            resta = 1;
                        } else {
                            cout << "\t" << (i + 1 - resta) << ". " << ((Persona*) registrados.at(i))->getNombre() << endl;
                        }
                    }

                    int receptor = -1;
                    cout << "\nIngresa la persona a quien quieres enviarle un mensaje: ";
                    cin >> receptor;

                    while (receptor < 1 || receptor > cantidadRegistrados - 1) {
                        cout << "\nIngresa la persona a quien quieres enviarle un mensaje: ";
                        cin >> receptor;
                    }
                    
                    receptor--;
                    
                    if( receptor >= indiceActual ){
                        receptor++;
                    }
                    
                    string mensaje = "";
                    
                    cout << "Ingresa el mensaje que deseas enviar: ";
                    cin >> mensaje;
                    
                    receptorActual = ((Persona*) registrados.at(receptor));
                    
                    mensaje = encriptado(mensaje,receptorActual->getLlave(),true);
                    
                    receptorActual->recibirMensaje(personaActual->getNombre(), mensaje);
                    cout << "El mensaje ha sido codificado y enviado.\n";
                    receptorActual = NULL;
                    
                }

                break;
            }
            case 2:
            {
                cout << "### VER MENSAJES ###\n\n";
                
                personaActual->imprimirMensajes();
                if(personaActual->getCantidadMensajes() == 0){
                    cout << "No ha recibido ningun mensaje.\n";
                    break;
                }
                int numMensaje;
                cout << "\nIngrese el mensaje que desea ver: ";
                cin >> numMensaje;
                
                while(numMensaje < 1 || numMensaje > personaActual->getCantidadMensajes()){
                    cout << "Ingrese un numero de mensaje valido: ";
                    cin >> numMensaje;
                }
                
                Mensaje* message = personaActual->getMensajeRecibido(numMensaje);
                
                if(message == NULL){
                    break;
                }
                
                cout << "[TEXT]: " << encriptado(message->getMensajeEncriptado(),personaActual->getLlave(),false) << "\n";
                
                message = NULL;
                
                break;
            }
            case 3: 
            {
                cout << "### VER MI LLAVE ###\n\n";
                cout << personaActual->getNombre() << ", tu llave es ";
                cout << personaActual->getLlave() << ".\n";
                break;
            }
            case 0:
            {
                cout << "Vuelve pronto!\n";
                personaActual = NULL;
                break;
            }
        }

    }

}

/* Encripta una cadena de acuerdo a una llave
 */
string encriptado(string mensaje, int llave, bool codificar){
    //Caso base
    if(llave == 0){
        return mensaje;
    }
    
    int caracteres = llave;
    int adelante = codificar;
    int factor = 1;
    for (int i = 0; i < mensaje.size(); i++) {
        factor = adelante ? 1 : -1 ;
        
        int valorAscii = ((int)mensaje[i]) + (factor * llave);
        mensaje = mensaje.substr(0,i) + ((char)valorAscii) + mensaje.substr(i+1);
        caracteres--;
        
        if(caracteres == 0){
            adelante = !adelante;
            caracteres = llave;
        }
    }
    return encriptado(mensaje,llave-1,codificar);
}