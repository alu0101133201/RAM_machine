//Fichero que implementa la clase memoria_instruccion

#include "memoria_instruccion.hpp"

memoria_instruccion::memoria_instruccion(std::ifstream& fichero) {
	std::string elemento_leido;

	std::getline(fichero,elemento_leido);
	while (fichero.good()) {
		std::string etiqueta;
		std::string instruccion;
		std::string argumento;
		int codigo_instruccion = -1;
		int direccionamiento_instruccion = -1;
		std::string argumento_instruccion;


		std::string lol;
		//---DIVISIÓN ENTRE ETIQUETA E INSTRUCCIÓN---
		if (elemento_leido.find(":") != std::string::npos) {
			etiqueta = elemento_leido.substr(0,elemento_leido.find(":"));
			instruccion = elemento_leido.substr(elemento_leido.find(":") + 2,
					elemento_leido.size());
		}
		else {
			instruccion = elemento_leido;	
		}		
		//---PROCESAMIENTO DEL CÓDIGO INSTRUCCIÓN
		if (instruccion.find(" ") != std::string::npos) {
			std::string aux = instruccion.substr(0,instruccion.find(" "));
			argumento = instruccion.substr(instruccion.find(" "), instruccion.length());
			codigo_instruccion =	juego_i.get_codigo(aux);
		}
		else {
			codigo_instruccion = juego_i.get_codigo(instruccion);
		}
		if (codigo_instruccion == -1)
			throw "Instrucciones no permitidas";
		//---PROCESAMIENTO DEL ARGUMENTO
		if (argumento.length() != 0) {
			if (argumento.find("=") != std::string::npos) {
				argumento_instruccion = argumento.substr(2,argumento.length());
				direccionamiento_instruccion = 0;
			}
			else if (argumento.find("*") != std::string::npos) {
				argumento_instruccion = argumento.substr(2,argumento.length());
				lol = argumento.substr(2,argumento.length());
				direccionamiento_instruccion = 1;
			}
			else {
				direccionamiento_instruccion = 2;
				argumento_instruccion = argumento.substr(1,argumento.length());
			}
		}
		auto tupla = std::make_tuple(codigo_instruccion, direccionamiento_instruccion, argumento_instruccion);		
		mem.push_back(tupla);	
		
		std::getline(fichero,elemento_leido);
	}	

}

memoria_instruccion::~memoria_instruccion() {}

std::ostream& memoria_instruccion::write(std::ostream& os) {
	for(int i = 0; i < mem.size(); i++) {
		os << i << ".- (" << std::get<0>(mem[i]) << " - " << std::get<1>(mem[i]) << 
				" - " << std::get<2>(mem[i]) << ")\n";
	}
	return os;
}
