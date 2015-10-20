#include <iostream>
#include <queue>


void roundRobin(std::queue<float> v);

int main()
{
  std::queue<float> procesos;
  procesos.push(10);
  procesos.push(4);
  procesos.push(6);
  procesos.push(5);

  roundRobin(procesos);

  return 0;
}

void roundRobin(std::queue<float> v)
{
  float quantum = 1;
  int procesoActual;
  int tiempoRestanteDelProcesoActual;

  while(!v.empty())
  {
    procesoActual = v.front();
    tiempoRestanteDelProcesoActual = procesoActual - quantum;
    if(tiempoRestanteDelProcesoActual <= 0)
    {
      v.pop();
    }
    else
    {
      v.push(tiempoRestanteDelProcesoActual);
      v.pop();
    }
  }
}
