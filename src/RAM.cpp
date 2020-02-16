//Fichero que implementa la clase máquina RAM

#include "RAM.hpp"

RAM::RAM(std::ifstream& f_prog, std::ifstream& f_cinta)
		: programa(f_prog),
			c_l(f_cinta) {}

RAM::~RAM() {}

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
