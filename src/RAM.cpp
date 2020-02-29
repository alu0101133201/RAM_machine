//Fichero que implementa la clase máquina RAM

#include "RAM.hpp"

RAM::RAM(std::ifstream& f_prog, std::ifstream& f_cinta)
		: programa(f_prog),
			c_l(f_cinta) {}

RAM::~RAM() {}

void RAM::ejecutar_instruccion(instruccion* instruccion_actual, bool& halt_flag) {
  instruccion_actual = new load;
  instruccion_actual -> ejecutar(registros, c_e, c_l, programa.get_tupla(pc)); 
  // if (halt pues halt_flag = true);
  delete instruccion_actual;
}

void RAM::ejecutar_programa() {
  instruccion* instruccion_actual;
  bool halt_flag = false;
  pc = 0;
  
  while(!halt_flag) {
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
