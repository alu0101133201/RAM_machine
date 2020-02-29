// Fichero que implementa la instruccion load
#include "load.hpp"

load::load() {}

load::~load() {}

bool load::ejecutar(memoria &registros, cinta_escritura& c_e, cinta_lectura& c_l,
    std::tuple<int, int, std::string> data_instruccion, int& pc) {

  std::cout << "Se está ejecutando el load!!\n";
  pc++; 
  return true;
}  
