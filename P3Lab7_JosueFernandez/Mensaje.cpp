/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mensaje.cpp
 * Author: IT
 * 
 * Created on 27 de noviembre de 2020, 01:40 PM
 */

#include "Persona.h"
#include "Mensaje.h"

Mensaje::Mensaje() {
}

Mensaje::Mensaje(const Mensaje& orig) {
}

Mensaje::~Mensaje() {
}

/*Constructor con parámetros
 */
Mensaje::Mensaje(string emisor, string mensajeEncriptado)
: emisor(emisor), mensajeEncriptado(mensajeEncriptado) {
}

/*Getter del emisor
 */
string Mensaje::getEmisor() {
    return emisor;
}

/*Getter del mensaje
 */
string Mensaje::getMensajeEncriptado() {
    return mensajeEncriptado;
}
