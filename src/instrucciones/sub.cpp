// Fichero que implementa la instruccion sub
#define INMEDIATO 0
#define INDIRECTO 1
#define DIRECTO 2

#include "sub.hpp"

sub::sub() {}

sub::~sub() {}

bool sub::ejecutar(memoria &registros, cinta_escritura& c_e, cinta_lectura& c_l,
      std::tuple<int, int, std::string> data_instruccion, int& pc) {

  int direccionamiento = std::get<1>(data_instruccion); 
  std::string argumento_string = std::get<2>(data_instruccion);
  int argumento = std::atoi(argumento_string.c_str());
  std::cout << "EN EL CON SUB con DIREC: "<<  direccionamiento << "\n";
  
  if (direccionamiento == INMEDIATO) {
    registros.escribir((registros.leer(0) - argumento), 0);
  }
  if (direccionamiento == INDIRECTO) {
    int dummy = registros.leer(argumento);
    int numeroASumar = registros.leer(dummy);
    registros.escribir((registros.leer(0) - numeroASumar), 0);
  }
  if (direccionamiento == DIRECTO) {
    int dummy = registros.leer(argumento);
    registros.escribir((registros.leer(0) - dummy), 0);
  }
  pc++;
  return true;
}  


