// Fichero que implementa la instruccion jgtz
#define INMEDIATO 0
#define INDIRECTO 1
#define DIRECTO 2

#include "jgtz.hpp"

jgtz::jgtz() {}

jgtz::~jgtz() {}

bool jgtz::ejecutar(memoria &registros, cinta_escritura& c_e, cinta_lectura& c_l,
      std::tuple<int, int, std::string> data_instruccion, int& pc) {

  int direccionamiento = std::get<1>(data_instruccion); 
  std::string argumento_string = std::get<2>(data_instruccion);
  int argumento = std::atoi(argumento_string.c_str());
  std::cout << "EN EL JUMP\n";
  
  if (direccionamiento == DIRECTO) {
    if (registros.leer(0) > 0)
      pc = argumento;
    else
      pc++;
  }
  if ((direccionamiento == INDIRECTO) || (direccionamiento == INMEDIATO)) {
    throw "ERROR - Direccionamiento indirecto o inmediato en jgtz\n";
  }
  return true;
}  


