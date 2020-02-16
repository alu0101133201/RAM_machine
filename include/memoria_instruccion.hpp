//Fichero que define la clase memoria_instrucción
#pragma once

#include <vector>
#include <tuple>
#include <iostream>
#include <fstream>
#include <string>

class memoria_instruccion {
	private:
		std::vector < std::tuple <int, int, int > > mem;

	public:
		memoria_instruccion(std::ifstream&);
		~memoria_instruccion();

		std::ostream& write(std::ostream&);	

};
