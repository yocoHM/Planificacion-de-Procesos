//
//  Proceso.h
//  Planificacion De Procesos
//
//  Created by Yoco Hernández on 17/10/15.
//  Copyright © 2015 Yoco. All rights reserved.
//

#ifndef Proceso_h
#define Proceso_h

#include <iostream>

//clase para guardar los datos de cada proceso en un objeto individual
class Proceso{
private:
  //id del proceso. e.g. "Proc1"
  std::string procesoID;
  //tiempo de llegada del proceso
  float tiempoLlegada;
  //tiempo que necesita el proceso para ser completado
  float tiempoProceso;
  //booleano para identificar si ya acabó el proceso
  bool terminado;
  //tiempo de espera del proceso
  float tiempoEspera;
  
public:
  ~Proceso();
  Proceso();
  Proceso(std::string _id, float _tiempoLlegada, float _tiempoProceso, bool _terminado, float _tiempoEspera);
  std::string getProcesoID();
  float getTiempoLlegada();
  float getTiempoProceso();
  bool getTerminado();
  float getTiempoEspera();
  
  void setTiempoProceso(float tiempo);
  void setTerminado(bool term);
  void setTiempoEspera(float tiempo);
  
};


#endif /* Proceso_h */
