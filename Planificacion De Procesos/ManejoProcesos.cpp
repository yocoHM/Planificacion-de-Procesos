//
//  ManejoProcesos.cpp
//  Planificacion De Procesos
//
//  Created by Yoco Hernández on 17/10/15.
//  Copyright © 2015 Yoco. All rights reserved.
//

#include "ManejoProcesos.h"
#include <math.h>
#include <fstream>

bool ManejoProcesos::compDouble(double a, double b)
{
  if (fabs(a-b) < 1e-1)
  {
    return true;
  }
  else
  {
    return false;
  }
}

//método para liberar la memoria de los apuntadores a procesos que están guardados en el vector de procesos
void ManejoProcesos::borrarProcesos(std::vector<Proceso*> procesos)
{
  //cuando existen apuntadores a procesos en el vector, se eliminan uno por uno recorriendo el vector de procesos
  if (!procesos.empty()) {
    for (int i = 0; i < procesos.size(); i++) {
      delete procesos[i];
    }
  }
  
}//cierre de borrarProcesos

void ManejoProcesos::imprimirTiemposEsperaInd(std::vector<Proceso*> procesos)
{
  
  if (!procesos.empty()) {
    for (int i = 0; i < procesos.size(); i++) {
      std::cout << procesos[i]->getProcesoID() << ". Tiempo de espera: ";
      std::cout << procesos[i]->getTiempoEspera() << std::endl;
    }
  }
  //cuando está vacío el vector se da un aviso de ello
  else {
    std::cout << "El arreglo de procesos está vacío" << std::endl;
  }
  
}//cierre de imprimirTiemposEsperaInd

void ManejoProcesos::imprimirTiempoPromedio(std::vector<Proceso*> procesos)
{
  float tiempoPromedio = 0.0;
  
  if (!procesos.empty()) {
    for (int i = 0; i < procesos.size(); i++) {
      tiempoPromedio += procesos[i]->getTiempoEspera();
    }
  }
  //cuando está vacío el vector se da un aviso de ello
  else {
    std::cout << "El arreglo de procesos está vacío" << std::endl;
  }
  
  std::cout << "El tiempo promedio total es: " << (tiempoPromedio /= procesos.size()) << std::endl;
  
}

void ManejoProcesos::shortestJobFirst(std::vector<Proceso*> procesos)
{
  float incremento = 0.5;
  int completados = int(procesos.size());
  int pos = 0;
  float tiempo = 0;
  Proceso * procesoActual = procesos[pos];
  std::vector<Proceso*> procesosPendientes;
  
  while (completados != 0) {
    
    std::cout << "Tiempo: " << tiempo << std::endl;
    
    if (pos == procesos.size() && !procesosPendientes.empty() && procesoActual->getTerminado() == true) {
      if (completados + 1 == procesosPendientes.size()) {
        procesosPendientes.erase(procesosPendientes.begin());
      }
      procesoActual = procesosPendientes[0];
      //***
      procesosPendientes.erase(procesosPendientes.begin());
    }
    else if (pos < procesos.size() && procesoActual->getTerminado() == true && tiempo < procesos[pos+1]->getTiempoLlegada()) {
      
      //cambiar el procesoActual
      procesoActual = procesosPendientes[0];
      
      //***
      procesosPendientes.erase(procesosPendientes.begin());
      
      //informacion en consola
      std::cout << "Proceso actual: " << procesoActual->getProcesoID() << ", tiempo proceso: " << procesoActual->getTiempoProceso() << std::endl;
      
    }
    else if (pos < procesos.size() && procesoActual->getTerminado() == true && tiempo == procesos[pos+1]->getTiempoLlegada()) {
      
      //cambiar el procesoActual
      procesoActual = procesos[pos+1];
      
      //informacion en consola
      std::cout << "Proceso actual: " << procesoActual->getProcesoID() << ", tiempo proceso: " << procesoActual->getTiempoProceso() << std::endl;
      
      //incrementar la posicion
      pos++;
      
    }
    else if (pos < procesos.size() && tiempo == procesos[pos+1]->getTiempoLlegada() && procesos[pos+1]->getTiempoProceso() < procesoActual->getTiempoProceso()) {
      //mandar el proceso actual a la cola
      procesosPendientes.push_back(procesoActual);
      
      //ordenar ascendentemente los procesos en la cola por su tiempo de procesamiento
      ordenarProcesos(procesosPendientes, int(procesosPendientes.size()));
      
      std::cout << "- - -Procesos pendientes- - -" << std::endl;
      
      for (int i = 0; i < procesosPendientes.size(); i++) {
        std::cout << procesosPendientes[i]->getProcesoID() << ", ";
      }
      
      std::cout << std::endl;
      std::cout << "- - - - - - - - - - - - - - -" << std::endl;
      
      //cambiar el procesoActual
      procesoActual = procesos[pos+1];
      
      //informacion en consola
      std::cout << "Proceso actual: " << procesoActual->getProcesoID() << ", tiempo proceso: " << procesoActual->getTiempoProceso() << std::endl;
      
      //incrementar la posicion
      pos++;
    }
    else if (pos < procesos.size() && tiempo == procesos[pos+1]->getTiempoLlegada() && procesos[pos+1]->getTiempoProceso() > procesoActual->getTiempoProceso()) {
      
      procesosPendientes.push_back(procesos[pos+1]);
      
      //ordenar ascendentemente los procesos en la cola por su tiempo de procesamiento
      ordenarProcesos(procesosPendientes, int(procesosPendientes.size()));
      
      std::cout << "- - -Procesos pendientes- - -" << std::endl;
      
      for (int i = 0; i < procesosPendientes.size(); i++) {
        std::cout << procesosPendientes[i]->getProcesoID() << ", ";
      }
      
      std::cout << std::endl;
      std::cout << "- - - - - - - - - - - - - - -" << std::endl;
      
      pos++;
      
    }
    else if (pos < procesos.size() && tiempo == procesos[pos+1]->getTiempoLlegada() && procesos[pos+1]->getTiempoProceso() == procesoActual->getTiempoProceso()) {
      
      procesosPendientes.push_back(procesos[pos+1]);
      
      //ordenar ascendentemente los procesos en la cola por su tiempo de procesamiento
      ordenarProcesos(procesosPendientes, int(procesosPendientes.size()));
      
      std::cout << "- - -Procesos pendientes- - -" << std::endl;
      
      for (int i = 0; i < procesosPendientes.size(); i++) {
        std::cout << procesosPendientes[i]->getProcesoID() << ", ";
      }
      
      std::cout << std::endl;
      std::cout << "- - - - - - - - - - - - - - -" << std::endl;
      
      pos++;
      
    }
    
    //incrementar tiempo
    tiempo += incremento;
    if (!procesosPendientes.empty()) {
      for (int i = 0; i < procesosPendientes.size(); i++) {
        procesosPendientes[i]->setTiempoEspera(procesosPendientes[i]->getTiempoEspera() + incremento);
      }
    }
    
    std::cout << "Tiempo: " << tiempo << std::endl;
    
    //actualizar tiempo de procesamiento para el proceso actual
    procesoActual->setTiempoProceso(procesoActual->getTiempoProceso() - incremento);
    
    //informacion en consola
    std::cout << "Proceso actual: " << procesoActual->getProcesoID() << ", tiempo proceso: " << procesoActual->getTiempoProceso() << std::endl;
    
    if (procesoActual->getTiempoProceso() == 0) {
      procesoActual->setTerminado(true);
      completados--;
      std::cout << "***Se terminó el proceso: " << procesoActual->getProcesoID() << ". Falta(n) por completarse " << completados << " proceso(s)***" << std::endl;
    }
    
    //movimiento de lugar de esta condicion fue la corrección del bug :')
    if (pos+1 == procesos.size()) {
      pos++;
    }
    
  }//cierre del while
  
}//cierre de shortestJobFirst

void ManejoProcesos::ordenarProcesos(std::vector<Proceso*> &procesosPendientes, int tam)
{
  
  float tiempo;
  Proceso * index;
  
  for (int i=1; i < tam; i++) {
    tiempo = procesosPendientes[i]->getTiempoProceso();
    index = procesosPendientes[i];
    
    int j = i-1;
    
    while (j >= 0 && procesosPendientes[j]->getTiempoProceso() > tiempo) {
      procesosPendientes[j + 1] = procesosPendientes[j];
      j--;
    }
    
    procesosPendientes[j+1] = index;
  }
  
}

void ManejoProcesos::roundRobin(std::vector<Proceso*> procesos)
{
  //Valor del quantum
  float quantum = 0;
  
  std::ifstream c;
  c.open("/Users/Yoco/Desktop/procesos.txt");
  c >> quantum;
  c.close();
  
  //Valor del tiempo de ejecución del proceso actual y del tiempo actual
  float tiempoEjecucion = 0.0;
  float tiempoActual = quantum;
  
  //Variables para saber cuantos procesos ya se terminaron
  int terminados = 0;
  long int cantidadProcesos = procesos.size();
  
  std::string grafica = "";
  
  //Cola y lista de procesos
  std::vector<Proceso*> colaProcesos;
  std::vector<Proceso*> listaProcesos = procesos;
  
  //Mete los primeros procesos a la cola
  colaProcesos.push_back(listaProcesos.front());
  listaProcesos.erase(listaProcesos.begin());
  
  Proceso* temporal;
  
  for (int i = 0; i<listaProcesos.size(); i++)
  {
    listaProcesos[i]->setTiempoEspera(-listaProcesos[i]->getTiempoLlegada());
  }
  
  while (tiempoActual > listaProcesos[0]->getTiempoLlegada() && listaProcesos.size()>0)
  {
    colaProcesos.push_back(listaProcesos.front());
    listaProcesos.erase(listaProcesos.begin());
  }
  
  
  //Comienza el tiempo en 0
  tiempoActual = 0;
  
  //Ciclo que se ejecuta mientras no se hayan terminado todos los procesos
  while (cantidadProcesos != terminados)
  {
    //Se inicia el primer proceso
    std::cout << "Se está ejecutando el proceso: " << colaProcesos.front()->getProcesoID() << std::endl;
    
    //Checa si el proceso se termina en el tiempo del cuantum
    if (colaProcesos.front()->getTiempoProceso() < quantum) //Si si se termina asigna el tiempo que se tarda al tiempo de ejecución
    {
      tiempoEjecucion=colaProcesos.front()->getTiempoProceso();
    }
    else
    {
      tiempoEjecucion = quantum; //Si no le asigna el quatum
    }
    //Le resta el quantum a su tiempo de ejecución
    colaProcesos.front()->setTiempoProceso(colaProcesos.front()->getTiempoProceso()-quantum);
    grafica = grafica + "Tiempo inicia: " + std::to_string(tiempoActual) + "|" + colaProcesos.front()->getProcesoID() + "|";
    //Ajusta el tiempo actual
    tiempoActual = tiempoActual + tiempoEjecucion;
    grafica = grafica + "Tiempo termina: " + std::to_string(tiempoActual) + "|";
    
    //Mete los procesos que llegaron mientras se ejecutaba el proceso
    while (tiempoActual > listaProcesos[0]->getTiempoLlegada())
    {
      if (listaProcesos.size()>0)
      {
        colaProcesos.push_back(listaProcesos.front());
        listaProcesos.erase(listaProcesos.begin());
      }
      if (listaProcesos.size() == 0)
      {
        break;
      }
    }
    
    //Si el proceso se terminó lo termina y lo saca de la cola
    if (colaProcesos.front()->getTiempoProceso() <= 0)
    {
      std::cout << "Se terminó de ejecutar el proceso: " << colaProcesos.front()->getProcesoID() << std::endl;
      std::cout << "El tiempo de espera de este proceso fue de: " << colaProcesos.front()->getTiempoEspera() << std::endl;
      colaProcesos.front()->setTerminado(true);
      colaProcesos.erase(colaProcesos.begin());
      terminados++;
      //Aumenta el tiempo de espera de todos los que siguen en la cola
      for (int i = 0; i<colaProcesos.size(); i++)
      {
        colaProcesos[i]->setTiempoEspera(colaProcesos[i]->getTiempoEspera()+tiempoEjecucion);
      }
    }
    else
    {
      //Si no se terminó lo vuelve a poner en la cola y les aumenta el tiempo de ejecución
      temporal = colaProcesos.front();
      colaProcesos.erase(colaProcesos.begin());
      for (int i = 0; i<colaProcesos.size(); i++)
      {
        colaProcesos[i]->setTiempoEspera(colaProcesos[i]->getTiempoEspera()+tiempoEjecucion);
      }
      colaProcesos.push_back(temporal);
    }
    //resetea el tiempo de ejecución
    tiempoEjecucion = 0.0;
  }
  std::cout << "---------Gráfica en el tiempo ----------" << std::endl;
  std::cout << grafica <<std::endl;
  std::cout << "---------Tiempos de espera ----------" << std::endl;
  imprimirTiemposEsperaInd(procesos);
  std::cout << "---------Tiempo promedio ----------" << std::endl;
  imprimirTiempoPromedio(procesos);
}
