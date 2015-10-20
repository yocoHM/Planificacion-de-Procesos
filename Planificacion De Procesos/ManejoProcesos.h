//
//  ManejoProcesos.h
//  Planificacion De Procesos
//
//  Created by Yoco Hernández on 17/10/15.
//  Copyright © 2015 Yoco. All rights reserved.
//

#ifndef ManejoProcesos_h
#define ManejoProcesos_h

#include <iostream>
#include <vector>
#include <algorithm>

#include "Proceso.h"

//clase para manejar los procesos en conjunto
class ManejoProcesos {
private:
  void ordenarProcesos(std::vector<Proceso*> &procesosPendientes, int tam);

public:
  void borrarProcesos(std::vector<Proceso*> procesos);
  void imprimirTiemposEsperaInd(std::vector<Proceso*> procesos);
  void imprimirTiempoPromedio(std::vector<Proceso*> procesos);
  void shortestJobFirst(std::vector<Proceso*> procesos);
  void roundRobin(std::vector<Proceso*> procesos);
  bool compDouble(double a, double b);
   

};

#endif /* ManejoProcesos_h */
