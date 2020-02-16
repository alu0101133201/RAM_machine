//Fichero que implementa la clase máquina RAM

#include "RAM.hpp"

RAM::RAM(std::ifstream& f_prog, std::ifstream& f_cinta, std::ofstream& f_out)
		: programa(f_prog),
			c_l(f_cinta),
			salida(f_out) {}

RAM::~RAM() {}

std::ostream& RAM::write(std::ostream& os) {
	os << "CINTA ESCRITURA ";
	c_e.write(os) << "\n"; 
	os << "CINTA LECTURA ";
  c_l.write(os) << "\n"; 
	os << "REGISTROS ";
	registros.write(os) << "\n";
	os << "PROGRAMA ";
	programa.write(os);
	

	return os;
}
