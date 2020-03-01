// Fichero que implementa la instruccion write_cinta
#define INMEDIATO 0
#define INDIRECTO 1
#define DIRECTO 2

#include "write.hpp"

write_cinta::write_cinta() {}

write_cinta::~write_cinta() {}

bool write_cinta::ejecutar(memoria &registros, cinta_escritura& c_e, cinta_lectura& c_l,
      std::tuple<int, int, std::string> data_instruccion, int& pc) {

  int direccionamiento = std::get<1>(data_instruccion); 
  std::string argumento_string = std::get<2>(data_instruccion);
  int argumento = std::atoi(argumento_string.c_str());
  
  if (direccionamiento == INMEDIATO) {
    c_e.escribir(argumento);
  }
  if (direccionamiento == DIRECTO) {
    c_e.escribir(registros.leer(argumento));
  }
  if (direccionamiento == INDIRECTO) {
    int dummy = registros.leer(argumento);
    c_e.escribir(registros.leer(dummy));
  }
  pc++;
  return true;
}  



