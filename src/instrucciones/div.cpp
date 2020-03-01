// Fichero que implementa la instruccion division
#define INMEDIATO 0
#define INDIRECTO 1
#define DIRECTO 2

#include "div.hpp"

division::division() {}

division::~division() {}

bool division::ejecutar(memoria &registros, cinta_escritura& c_e, cinta_lectura& c_l,
      std::tuple<int, int, std::string> data_instruccion, int& pc) {

  int direccionamiento = std::get<1>(data_instruccion); 
  std::string argumento_string = std::get<2>(data_instruccion);
  int argumento = std::atoi(argumento_string.c_str());
  std::cout << "EN EL CON DIV con DIREC: "<<  direccionamiento << "\n";
  
  if (direccionamiento == INMEDIATO) {
    if (argumento == 0)
      throw "ERROR - División por 0\n";
    registros.escribir((registros.leer(0) / argumento), 0);
  }
  if (direccionamiento == INDIRECTO) {
    int dummy = registros.leer(argumento);
    int numeroADividir = registros.leer(dummy);
    if (numeroADividir == 0)
      throw "ERROR - División por 0\n";
    registros.escribir((registros.leer(0) / numeroADividir), 0);
  }
  if (direccionamiento == DIRECTO) {
    int dummy = registros.leer(argumento);
    if (dummy == 0)
      throw "ERROR - División por 0\n";
    registros.escribir((registros.leer(0) / dummy), 0);
  }
  pc++;
  return true;
}  
