//Fichero que implementa la clase máquina RAM

#include "RAM.hpp"

RAM::RAM(std::ifstream& f_prog, std::ifstream& f_cinta)
		: programa(f_prog),
			c_l(f_cinta) {}

RAM::~RAM() {}

void RAM::ejecutar_instruccion(instruccion* instruccion_actual, bool& halt_flag) {
  // Comprobamos que el pc es válido, por si el programador ha olvidado el HALT
  if (pc >= programa.num_instrucciones()) {
    throw "El programador ha omitido la instrucción HALT\n";
  }

  std::tuple<int, int, std::string> tupla_actual;
  tupla_actual = programa.get_tupla(pc);
  int code = std::get<0>(tupla_actual);
  
  switch (code) {
    case 0:
      instruccion_actual = new load;
      break;

    case 1:
      instruccion_actual = new store;
      break;

    default:
      throw "En el default. Caso teóricamente imposible\n"; 

  }

  halt_flag = instruccion_actual -> ejecutar(registros, c_e, c_l, tupla_actual, pc); 
  delete instruccion_actual;
}

void RAM::ejecutar_programa() {
  instruccion* instruccion_actual;
  bool halt_flag = true;
  pc = 0;
  
  while(halt_flag) {
    ejecutar_instruccion(instruccion_actual, halt_flag);
  }
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
