//
//  Proceso.cpp
//  Planificacion De Procesos
//
//  Created by Yoco Hernández on 17/10/15.
//  Copyright © 2015 Yoco. All rights reserved.
//

#include "Proceso.h"

//Destructor
Proceso::~Proceso() { }

//Constructor sin parámetros
Proceso::Proceso() { }

//Constructor con parámetros
Proceso::Proceso(std::string _id, float _tiempoLlegada, float _tiempoProceso, bool _terminado, float _tiempoEspera) : procesoID(_id), tiempoLlegada(_tiempoLlegada), tiempoProceso(_tiempoProceso), terminado(_terminado), tiempoEspera(_tiempoEspera) { }

/*
 Getters para:
 - procesoID
 - tiempoLlegada
 - tiempoProceso
 - terminado
 - tiempoEspera
*/

std::string Proceso::getProcesoID()
{
  return procesoID;
}

float Proceso::getTiempoLlegada()
{
  return tiempoLlegada;
}

float Proceso::getTiempoProceso()
{
  return tiempoProceso;
}

bool Proceso::getTerminado()
{
  return terminado;
}

float Proceso::getTiempoEspera()
{
  return tiempoEspera;
}

/*
 Setters para:
 - tiempoProceso
 - terminado
 - tiempoEspera
*/
void Proceso::setTiempoProceso(float tiempo)
{
  tiempoProceso = tiempo;
}

void Proceso::setTerminado(bool term)
{
  terminado = term;
}

void Proceso::setTiempoEspera(float tiempo)
{
  tiempoEspera = tiempo;
}



