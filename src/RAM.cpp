//Fichero que implementa la clase máquina RAM
#define INMEDIATO 0
#define INDIRECTO 1
#define DIRECTO 2
#define RECIBE_NUMERO 2
#define RECIBE_ETIQUETA 1
#define SIN_ARGUMENTO 0

#include "RAM.hpp"

RAM::RAM(std::ifstream& f_prog, std::ifstream& f_cinta)
		: programa(f_prog),
			c_l(f_cinta),
      pc(0) {}

RAM::~RAM() {}

void RAM::ejecutar_instruccion(instruccion* instruccion_actual, bool& halt_flag) {
  // Comprobamos que el pc es válido, por si el programador ha olvidado el HALT
  if (pc >= programa.num_instrucciones()) {
    halt_flag = false;
    return;
  }

  std::tuple<int, int, std::string> tupla_actual;
  tupla_actual = programa.get_tupla(pc);
  int code = std::get<0>(tupla_actual);
  
  switch (code) {
    case LOAD:
      instruccion_actual = new load;
      break;

    case STORE:
      instruccion_actual = new store;
      break;

    case ADD:
      instruccion_actual = new add;
      break;

    case SUB:
      instruccion_actual = new sub;
      break;

    case MULT:
      instruccion_actual = new mult;
      break;

    case DIV:
      instruccion_actual = new division;
      break;

    case READ:
      instruccion_actual = new read;
      break;

    case WRITE:
      instruccion_actual = new write_cinta;
      break;

    case JUMP:
      instruccion_actual = new jump;
      break;
      
    case JGTZ:
      instruccion_actual = new jgtz;
      break;
      
    case JZERO:
      instruccion_actual = new jzero;
      break;
      
    case HALT:
      instruccion_actual = new halt;
      break;

    default:
      throw "En el default. Caso teóricamente imposible\n"; 

  }

  halt_flag = instruccion_actual -> ejecutar(registros, c_e, c_l, tupla_actual, pc); 
  delete instruccion_actual;
}

void RAM::ejecutar_programa(int& contador_instrucciones) {
  instruccion* instruccion_actual;
  bool halt_flag = true;
  
  while(halt_flag) {
    ejecutar_instruccion(instruccion_actual, halt_flag);
    contador_instrucciones++;
  }
}

std::ostream& RAM::desensamblador(std::ostream& os) {
  for (int i = 0; i < programa.num_instrucciones(); i++) {

    auto tupla_actual = programa.get_tupla(i);
    int direccionamiento = std::get<1>(tupla_actual);
    int codigo = std::get<0>(tupla_actual);
    std::string argumento = std::get<2>(tupla_actual);

    //programa.etiqueta_asociada devuelve "" si no hay ninguna eitqueta en la inst.
    if (programa.etiqueta_asociada(i) != "") {
      std::cout << programa.etiqueta_asociada(i) << " : ";
    }
    else {
      std::cout << "\t";
    }
    std::cout << programa.juego_i.get_nombre(codigo) << " ";
    switch(direccionamiento) {
      case(INMEDIATO):
        std::cout << "=";
        break;
      case(INDIRECTO):
        std::cout << "*";
      default:
        break;
    }
    if (programa.juego_i.get_argumento(codigo) == RECIBE_NUMERO)
      std::cout << argumento << "\n";
    if (programa.juego_i.get_argumento(codigo) == RECIBE_ETIQUETA){
      std::cout << programa.etiqueta_asociada(std::atoi(argumento.c_str()));  
      std::cout << "\n";

    }
    if (programa.juego_i.get_argumento(codigo) == SIN_ARGUMENTO)
      std::cout << "\n";
  }
  return os;
}

std::ostream& RAM::write_registros(std::ostream& os) {
	os << "\n---REGISTROS---\n";
	registros.write(os) << "\n";
  return os;
}

std::ostream& RAM::write_cinta_e(std::ostream& os) {
	os << "\n---CINTA DE ESCRITURA---\n";
	c_e.write(os) << "\n";
  return os;
}

std::ostream& RAM::write_cinta_l(std::ostream& os) {
	os << "\n---CINTA DE LECTURA--\n";
	c_l.write(os) << "\n";
  return os;
}

std::ostream& RAM::write(std::ostream& os) {
	os << "---CINTA ESCRITURA---\n";
	c_e.write(os) << "\n"; 
	os << "---CINTA LECTURA---\n";
  c_l.write(os) << "\n"; 
	os << "---REGISTROS---\n";
	registros.write(os) << "\n";
	os << "---PROGRAMA---\n";
	programa.write(os);

	return os;
}
