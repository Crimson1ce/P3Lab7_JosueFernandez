/* 
 * File:   Persona.cpp
 * Author: Josué Fernández
 * 
 * Created on 27 de noviembre de 2020, 01:35 PM
 */

#include "Persona.h"
#include "Mensaje.h"

#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>

using std::cout;
using std::endl;

/*Constructor por defecto
 */
Persona::Persona()
: nombre(""), apellido(""), password("1234"), cantidadMensajes(0) {
    srand(time(0));
    llave = (rand() % 15) + 1;
}

/*Constructor de copia
 */
Persona::Persona(const Persona& orig) {

}

/*Destructor
 */
Persona::~Persona() {
}

/*Constructor con atributos
 */
Persona::Persona(string nombre, string apellido, string password)
: nombre(nombre), apellido(apellido), password(password), cantidadMensajes(0) {
    srand(time(0));
    llave = (rand() % 15) + 1;
}

/*Metodo para recibir mensajes
 */
void Persona::recibirMensaje(string emisor, string msj) {
    //Se recibe el mensaje ya encriptado
    Mensaje mensaje(emisor, msj);
    mensajesRecibidos.push_back(mensaje);
    cantidadMensajes++;
}

/*Getter de los mensajes recibidos
*/
Mensaje* Persona::getMensajeRecibido(int mensaje){
    if(mensaje<1 || mensaje>cantidadMensajes)
        return NULL;
    return &(mensajesRecibidos.at(mensaje-1));
}

/*Getter del nombre
*/
string Persona::getNombre(){
    return nombre;
}

/*Getter del apellido
*/
string Persona::getApellido(){
    return apellido;
}

/*Getter de la contraseña
*/
string Persona::getPassword(){
    return password;
}

/*Getter de la llave
*/
int Persona::getLlave(){
    return llave;
}

/*Getter de la cantidad de mensajes
*/
int Persona::getCantidadMensajes(){
    return cantidadMensajes;
}

/*Metodo que imprime los mensajes recibidos
*/
void Persona::imprimirMensajes(){
    cout << "\t~~~ Ver Mensajes ~~~\n" << endl;
    for (int i = 0; i < cantidadMensajes; i++) {
        cout << "\t" << (i+1) << ". De: " << ((Mensaje)mensajesRecibidos[i]).getEmisor() << " -> " << ((Mensaje)mensajesRecibidos[i]).getMensajeEncriptado() << endl;
    }
}