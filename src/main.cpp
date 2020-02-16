#include <iostream>
#include <fstream>

#include "cinta.hpp"
#include "cinta_escritura.hpp"
#include "cinta_lectura.hpp"

int main(int argc, char** argv) {
  if (argc < 4) {
    std::cerr << "Argumentos insuficientes\n";
    return 1;
  }

  std::ifstream f_programa;
  std::ifstream f_cinta_lectura;
  std::ifstream f_cinta_escritura;
  f_programa.open(argv[1]);
  f_cinta_lectura.open(argv[2]);
  f_cinta_escritura.open(argv[3]);

  if ((!f_programa.is_open()) || (!f_cinta_lectura.is_open()) ||
      (!f_cinta_escritura.is_open())) {
    std::cerr << "Error abriendo ficheros\n";
    return 2;
  }
	
	cinta_escritura prueba;
	cinta_lectura prueba2(f_cinta_lectura);
	prueba2.cinta::write(std::cout);

	prueba.escribir(3);
	prueba.escribir(3);
	prueba.escribir(3);
	prueba.escribir(3);
	prueba.cinta::write(std::cout);

  return(0);
}
