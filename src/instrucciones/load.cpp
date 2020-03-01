// Fichero que implementa la instruccion load
#define INMEDIATO 0
#define INDIRECTO 1
#define DIRECTO 2

#include "load.hpp"

load::load() {}

load::~load() {}

bool load::ejecutar(memoria &registros, cinta_escritura& c_e, cinta_lectura& c_l,
      std::tuple<int, int, std::string> data_instruccion, int& pc) {
  int direccionamiento = std::get<1>(data_instruccion); 
  std::string argumento_string = std::get<2>(data_instruccion);
  int argumento = std::atoi(argumento_string.c_str());
  
  if (direccionamiento == INMEDIATO) {
    registros.escribir(argumento, 0);
  }
  if (direccionamiento == INDIRECTO) {
    int dummy = registros.leer(argumento);
    registros.escribir(registros.leer(dummy), 0);
  }
  if (direccionamiento == DIRECTO) {
    registros.escribir(registros.leer(argumento), 0);
  }
  pc++;
  return true;
}  
