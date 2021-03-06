// Fichero que implementa la instruccion mult
#define INMEDIATO 0
#define INDIRECTO 1
#define DIRECTO 2

#include "mult.hpp"

mult::mult() {}

mult::~mult() {}

bool mult::ejecutar(memoria &registros, cinta_escritura& c_e, cinta_lectura& c_l,
      std::tuple<int, int, std::string> data_instruccion, int& pc) {

  int direccionamiento = std::get<1>(data_instruccion); 
  std::string argumento_string = std::get<2>(data_instruccion);
  int argumento = std::atoi(argumento_string.c_str());
  
  if (direccionamiento == INMEDIATO) {
    registros.escribir((registros.leer(0) * argumento), 0);
  }
  if (direccionamiento == INDIRECTO) {
    int dummy = registros.leer(argumento);
    int numeroASumar = registros.leer(dummy);
    registros.escribir((registros.leer(0) * numeroASumar), 0);
  }
  if (direccionamiento == DIRECTO) {
    int dummy = registros.leer(argumento);
    registros.escribir((registros.leer(0) * dummy), 0);
  }
  pc++;
  return true;
}  

