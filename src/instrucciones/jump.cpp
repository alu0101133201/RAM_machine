// Fichero que implementa la instruccion jump
#define INMEDIATO 0
#define INDIRECTO 1
#define DIRECTO 2

#include "jump.hpp"

jump::jump() {}

jump::~jump() {}

bool jump::ejecutar(memoria &registros, cinta_escritura& c_e, cinta_lectura& c_l,
      std::tuple<int, int, std::string> data_instruccion, int& pc) {

  int direccionamiento = std::get<1>(data_instruccion); 
  std::string argumento_string = std::get<2>(data_instruccion);
  int argumento = std::atoi(argumento_string.c_str());
  std::cout << "EN EL JUMP\n";
  
  if (direccionamiento == DIRECTO) {
    pc = argumento;
  }
  if ((direccionamiento == INDIRECTO) || (direccionamiento == INMEDIATO)) {
    throw "ERROR - Direccionamiento indirecto o inmediato en jump\n";
  }
  return true;
}  

