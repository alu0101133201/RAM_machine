//Fichero que define la clase maquina RAM
#pragma once

#include <iostream>
#include <fstream>
#include "cinta_escritura.hpp"
#include "cinta_lectura.hpp"
#include "cinta_lectura.hpp"
#include "memoria.hpp"
#include "memoria_instruccion.hpp"

class RAM {
	private:
		cinta_escritura c_e;
		cinta_lectura c_l;
		memoria_instruccion programa;
		memoria registros;
	
	public:
		RAM(std::ifstream&, std::ifstream&);
		~RAM();

		std::ostream& write(std::ostream&);
};
