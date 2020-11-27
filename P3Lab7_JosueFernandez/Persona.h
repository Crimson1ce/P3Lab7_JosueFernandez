/* 
 * File:   Persona.h
 * Author: Josué Fernández
 *
 * Created on 27 de noviembre de 2020, 01:35 PM
 */

#include <string>
#include <vector>
#include "Mensaje.h"

#ifndef PERSONA_H
#define PERSONA_H

using std::string;
using std::vector;

class Persona {
public:
    //Constructor por defecto
    Persona();
    //Constructor de copia
    Persona(const Persona& orig);
    //Destructor
    virtual ~Persona();
    
    //Constructor con atributos
    Persona(string nombre, string apellido, string password);
    //Metodo para recibir mensajes
    void recibirMensaje(string emisor, string msj);
    //Getter de los mensajes recibidos
    Mensaje* getMensajeRecibido(int mensaje);
    //Getter del nombre
    string getNombre();
    //Getter del apellido
    string getApellido();
    //Getter de la contraseña
    string getPassword();
    //Getter de la llave
    int getLlave();
    //Getter de la cantidad de mensajes
    int getCantidadMensajes();
    //Metodo que imprime los mensajes recibidos
    void imprimirMensajes();
    
private:
    int llave;
    string nombre;
    string apellido;
    string password;
    vector<Mensaje*> mensajesRecibidos;
    int cantidadMensajes;

};

#endif /* PERSONA_H */
