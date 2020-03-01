// Fichero que implementa la instruccion halt
#define INMEDIATO 0
#define INDIRECTO 1
#define DIRECTO 2

#include "halt.hpp"

halt::halt() {}

halt::~halt() {}

bool halt::ejecutar(memoria &registros, cinta_escritura& c_e, cinta_lectura& c_l,
      std::tuple<int, int, std::string> data_instruccion, int& pc) {
  std::cout << "EN EL HALT\n";

  return false;
}  


