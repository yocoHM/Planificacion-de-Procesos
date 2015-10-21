/*
 * Clase ManejoArchivo (archivo .cpp)
 *
 * Clase que maneja las lecturas y escrituras de archivos.
 *
 * Autor: Moises Alencastre Miranda
 * Version: 1.0
 */
#include "ManejoArchivo.h"

/*
 Este método recibe como parámetros un string con el nombre del archivo .txt que tiene los datos y un int
 con la opción para saber si leer los datos para SJF o para Round Robin
 */
vector<Proceso*> ManejoArchivo::leer(string archivo) {
  
  //vector con los procesos leidos del archivo .txt
  vector<Proceso*> procesos;
  
  //id del proceso. e.g. "Proc1"
  char procesoID[10];
  //tiempo de llegada del proceso
  float tiempoLlegada;
  //tiempo que necesita el proceso para ser completado
  float tiempoProceso;
  
  //archivo .txt con los procesos
  ifstream procesosFile;
  procesosFile.open(archivo);
  
  cout << "El archivo a leer es: "<< archivo << endl;
  
  
  //ignorar el dato del "quantum" porque no se necesita
  procesosFile.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' );
  
  //leer y guardar los datos en variables independientes.
  while (procesosFile >> procesoID >> tiempoLlegada >> tiempoProceso) {
    
    //se crea un apuntador a un proceso temporal
    Proceso * procesoTemp = new Proceso(procesoID, tiempoLlegada, tiempoProceso, false, 0.0);
    //se guarda ese proceso en el vector de procesos leidos
    procesos.push_back(procesoTemp);
    
  }//cierre del while
  
  cout << endl;
  
  //se cierra el archivo de procesos
  procesosFile.close();
  
  
  return procesos;
}
