#include <iostream>
#include <vector>
#include <fstream>

#include "cinta.hpp"
#include "cinta_escritura.hpp"
#include "cinta_lectura.hpp"
#include "memoria.hpp"
#include "memoria_instruccion.hpp"
#include "juego_instrucciones.hpp"
#include "RAM.hpp"

int main(int argc, char** argv) {
  if (argc < 4) {
    std::cerr << "Argumentos insuficientes\n";
    return 1;
  }

  std::ifstream f_programa;
  std::ifstream f_cinta_lectura;
  std::ofstream f_cinta_escritura;

  f_programa.open(argv[1]);
  f_cinta_lectura.open(argv[2]);
  f_cinta_escritura.open(argv[3], std::ios::out | std::ios::trunc);

  if ((!f_programa.is_open()) || (!f_cinta_lectura.is_open())) {
    std::cerr << "Error abriendo ficheros\n";
    return 2;
  }



	try{
		RAM prueba(f_programa,f_cinta_lectura);
		prueba.write(std::cout);

	} catch (std::string e) {
		std::cerr << e;
	}
	
  return(0);
}
