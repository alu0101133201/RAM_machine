//Fichero que define la clase juego de instrucciones
#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <tuple>

class juego_instrucciones {
	private:
		std::vector<std::tuple <std::string,int,int> > tabla;

	public:
		juego_instrucciones();
		~juego_instrucciones();

		int get_codigo(std::string);
		std::string get_nombre(int);

		std::ostream& write(std::ostream&);
};
