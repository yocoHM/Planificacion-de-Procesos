/*
 * Clase ManejoArchivo (archivo .h)
 *
 * Clase que maneja las lecturas y escrituras de archivos.
 *
 * Autor: Moises Alencastre Miranda
 * Version: 1.0
 */

#ifndef MANEJOARCHIVO_H
#define MANEJOARCHIVO_H

#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

#include "Proceso.h"

using namespace std;

class ManejoArchivo {
public:

  vector<Proceso*> leer(string archivo);

};

#endif
