/*
 * File:   Mensaje.h
 * Author: Josué Fernández
 *
 * Created on 27 de noviembre de 2020, 01:40 PM
 */

#include <string>

#ifndef MENSAJE_H
#define MENSAJE_H

using std::string;

class Mensaje {
public:
    //Constructor por defect
    Mensaje();
    //Constructor de copia
    Mensaje(const Mensaje& orig);
    //Destructor
    virtual ~Mensaje();
    //Constructor con parámetros
    Mensaje(string emisor, string mensajeEncriptado);
    
    //Getter del emisor
    string getEmisor();
    //Getter del mensaje
    string getMensajeEncriptado();
    
private:
    string emisor;
    string mensajeEncriptado;

};

#endif /* MENSAJE_H */

