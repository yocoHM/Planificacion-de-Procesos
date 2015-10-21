//
//  main.cpp
//  Planificacion De Procesos
//
//  Created by Yoco Hernández on 17/10/15.
//  Copyright © 2015 Yoco. All rights reserved.
//

#include "ManejoArchivo.h"
#include "ManejoProcesos.h"


void desplegarMenu(ManejoArchivo file);

int main(int argc, const char * argv[]) {
  
  //instancia para manejar el archivo .txt
  ManejoArchivo file = ManejoArchivo();
  
  //se llama a la función para mostrar el menú mandando como parámetro al objeto que va a manejar el archivo .txt
  desplegarMenu(file);
  
  
  return 0;
}

//función para mostrar el menú del programa
void desplegarMenu(ManejoArchivo file) {
  
  //instancia que se encarga de manejar los procesos
  ManejoProcesos admProcesos = ManejoProcesos();
  //vector de procesos obtenidos del archivo .txt
  vector<Proceso*> procesos;
  
  cout << "- - - - -Simulación de algoritmos de planificación de procesos- - - - -" << endl;
  
  //elección del usuario para la planificación de procesos
  int op = 0;
  
  while (op != 3) {
    //menú impreso en consola
    cout << "1. Shortest Job First" << endl;
    cout << "2. Round Robin" << endl;
    cout << "3. Salir" << endl;
    cin >> op;
    
    switch (op) {
        //opción 1 es para seleccionar SJF Apropiativo
      case 1:
        cout << "\n- - - - -SJF Apropiativo- - - - -" << endl;
        //se lee el archivo .txt con los procesos para SJF Apropiativo y se guardan los procesos leídos en el vector procesos
        procesos = file.leer("/Users/Yoco/Desktop/procesos8.txt");
        admProcesos.shortestJobFirst(procesos);
        cout << "\n- - - - -Tiempos de espera individuales- - - - -" << endl;
        admProcesos.imprimirTiemposEsperaInd(procesos);
        cout << "\n- - - - -Tiempo promedio de espera total- - - - -" << endl;
        admProcesos.imprimirTiempoPromedio(procesos);
        cout << endl;
        break;
        
        //opcion 2 es para seleccionar Round Robin
      case 2:
        cout << "\n- - - - -Round Robin- - - - -" << endl;
        //se lee el archivo .txt con los procesos para Round Robin y se guardan los procesos leídos en el vector procesos
        procesos = file.leer("/Users/Yoco/Desktop/procesos8.txt");
        admProcesos.roundRobin(procesos);
        cout << endl;
        break;
        
        //opcion 3 es salir del programa
      case 3:
        cout << "\nHas salido del programa" << endl;
        break;
        
      default:
        cout << "\nOpción inválida" << endl;
        break;
    }//cierre del switch
    
  }//cierre del while
  
  //se libera la memoria del vector de apuntadores a procesos
  admProcesos.borrarProcesos(procesos);
  
  
}
