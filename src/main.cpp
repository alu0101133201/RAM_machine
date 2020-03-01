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
#include "instruccion.hpp"
#include "load.hpp"

int to_int (std::string cadena) {
	std::string::iterator it = cadena.begin();
	if (std::isdigit(*it) || (*it == '-')) {
		++it;
		while (it != cadena.end() && (std::isdigit(*it))) ++it;
	}
	return (!cadena.empty() && it == cadena.end());
}

// Función que elimina los whitespaces de la izquierda
std::string trim(std::string cadena) {
	const std::string whitespaces(" \t");
	const auto primer_no_blanco = cadena.find_first_not_of(whitespaces);
	if (primer_no_blanco == std::string::npos)
		return "";
	return cadena.substr(primer_no_blanco,cadena.length());
}

// Función que elimina los whitespaces de la derecha
std::string trim_derecha(std::string cadena) {
	const std::string pto_coma(";");
	const std::string whitespaces(" \t");
	std::string cadena_sin_comentario;
	std::string cadena_acotada;
	const auto comentario = cadena.find_first_of(pto_coma);

	if (comentario != std::string::npos)
		cadena_sin_comentario = cadena.substr(0,comentario - 1);
	else
		cadena_sin_comentario = cadena;

	const auto ultimo_no_blanco = cadena_sin_comentario.find_last_not_of(whitespaces);
	if (ultimo_no_blanco == std::string::npos)
		return cadena_sin_comentario;
	return cadena_sin_comentario.substr(0,ultimo_no_blanco + 1);
}


int main(int argc, char** argv) {
  if (argc < 4) {
    std::cerr << "Argumentos insuficientes\n";
    std::cerr << "./RAM <programa> <cinta_lectura> <cinta_escritura>\n";
    return 1;
  }

  std::ifstream f_programa;
  std::ifstream f_cinta_lectura;
  std::ofstream f_cinta_escritura;
  bool debug_mode;

  f_programa.open(argv[1]);
  f_cinta_lectura.open(argv[2]);
  f_cinta_escritura.open(argv[3], std::ios::out | std::ios::trunc);

  if ((argc > 4) && (std::string(argv[4]) == "debug")) {
    debug_mode = true;
  }

  if ((!f_programa.is_open()) || (!f_cinta_lectura.is_open())) {
    std::cerr << "Error abriendo ficheros\n";
    return 2;
  }
	try{
		RAM prueba(f_programa,f_cinta_lectura);
    if (debug_mode) {
      char opcion;
      bool end_flag = true;
      do {
        std::cout << "> ";
        std::cin >> opcion;
        switch (opcion) {
          case('x'):
            break;
          case('r'):
            prueba.write_registros(std::cout);
            break;
          case('t'):
            if (end_flag) {
              instruccion* instruccion_actual;
              prueba.ejecutar_instruccion(instruccion_actual,end_flag);

            }
            break;
          case('e'):
            {
            int count = 0;
            prueba.ejecutar_programa(count);
            std::cout << "Ejecutadas: " << count << " instrucciones\n";
            break;
            }
          case('s'):
            prueba.desensamblador(std::cout);
            break;
          case('i'):
            prueba.write_cinta_l(std::cout);
            break;
          case('o'):
            prueba.write_cinta_e(std::cout);
            break;
          case('h'):
            std::cout << "\n---MENÚ RAM ---\n";
            std::cout << "r: Ver los registros\n";
            std::cout << "t: Traza\n";
            std::cout << "e: Ejecutar\n";
            std::cout << "s: Desensamblador\n";
            std::cout << "i: Ver cinta de entrada\n";
            std::cout << "o: Ver cinta de salida\n";
            std::cout << "h: Ayuda\n";
            std::cout << "x: Salir\n";
            break;
          default:
            std::cout << "Opción no permitida" << std::endl;
            break;
        }
      } while(opcion != 'x');
    }
    else {
      int contador = 0;
      prueba.ejecutar_programa(contador);
      std::cout << "Se han ejecutado " << contador << " instrucciones\n";
    }
			
	} catch (const char* e) {
		std::cerr << e;
	}
	
  return(0);
}
