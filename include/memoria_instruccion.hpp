//Fichero que define la clase memoria_instrucción
#pragma once

#include <vector>
#include <tuple>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include "juego_instrucciones.hpp"

int to_int(std::string cadena);
std::string trim(std::string cadena);
std::string trim_derecha(std::string cadena);

class memoria_instruccion {
	private:
		std::vector < std::tuple <int, int, std::string > > mem;
		std::vector < std::pair <std::string, int > > etiquetas;
		juego_instrucciones juego_i;

	public:
		memoria_instruccion(std::ifstream&);
		~memoria_instruccion();

		std::ostream& write(std::ostream&);	

};
