//Fichero que define la clase memoria_instrucción
#pragma once

#include <vector>
#include <tuple>
#include <iostream>
#include <fstream>
#include <string>

#include "juego_instrucciones.hpp"

class memoria_instruccion {
	private:
		std::vector < std::tuple <int, int, std::string > > mem;
		juego_instrucciones juego_i;

	public:
		memoria_instruccion(std::ifstream&);
		~memoria_instruccion();

		std::ostream& write(std::ostream&);	

};
