/* 
 * File:   Persona.h
 * Author: Josué Fernández
 *
 * Created on 27 de noviembre de 2020, 01:35 PM
 */

#include <string>
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
private:
    string nombre;
    string apellido;
    string password;
    int llave;
    vector<Mensaje> mensajesRecibidos;

};

#endif /* PERSONA_H */
