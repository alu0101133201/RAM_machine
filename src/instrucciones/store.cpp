// Fichero que implementa la instruccion load
#define INMEDIATO 0
#define INDIRECTO 1
#define DIRECTO 2

#include "store.hpp"

store::store() {}

store::~store() {}

bool store::ejecutar(memoria &registros, cinta_escritura& c_e, cinta_lectura& c_l,
      std::tuple<int, int, std::string> data_instruccion, int& pc) {
  std::cout << "EN EL STORE\n";

  int direccionamiento = std::get<1>(data_instruccion); 
  std::string argumento_string = std::get<2>(data_instruccion);
  int argumento = std::atoi(argumento_string.c_str());
  
  if (direccionamiento == INDIRECTO) {
    int dummy = registros.leer(argumento);
    registros.escribir(registros.leer(0), dummy);
  }
  if (direccionamiento == DIRECTO) {
    registros.escribir(registros.leer(0), argumento);
  }
  pc++;
  return true;
}  

