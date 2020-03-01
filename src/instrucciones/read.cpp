// Fichero que implementa la instruccion read
#define INMEDIATO 0
#define INDIRECTO 1
#define DIRECTO 2

#include "read.hpp"

read::read() {}

read::~read() {}

bool read::ejecutar(memoria &registros, cinta_escritura& c_e, cinta_lectura& c_l,
      std::tuple<int, int, std::string> data_instruccion, int& pc) {
  std::cout << "EN EL READ\n";

  int direccionamiento = std::get<1>(data_instruccion); 
  std::string argumento_string = std::get<2>(data_instruccion);
  int argumento = std::atoi(argumento_string.c_str());
  
  if ((direccionamiento == INMEDIATO) || (direccionamiento == INDIRECTO)) {
    throw "READ con direccionamiento inmediato o indirecto - no permitido\n";
  }
  if (direccionamiento == DIRECTO) {
    registros.escribir(c_l.leer(), argumento);
  }
  pc++;
  return true;
}  


