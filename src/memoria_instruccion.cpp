//Fichero que implementa la clase memoria_instruccion

#include "memoria_instruccion.hpp"

memoria_instruccion::memoria_instruccion(std::ifstream& fichero) {
	std::string elemento_leido;
	std::getline(fichero,elemento_leido);
	while (fichero.good()) {
	
		


		std::getline(fichero,elemento_leido);
	}	

}

memoria_instruccion::~memoria_instruccion() {}

std::ostream& memoria_instruccion::write(std::ostream& os) {
	for(int i = 0; i < mem.size(); i++) {
		os << i << ".- " << std::get<0>(mem[i]) << " - " << std::get<1>(mem[i]) << 
				" - " << std::get<2>(mem[i]) << "\n";
	}
	return os;
}
