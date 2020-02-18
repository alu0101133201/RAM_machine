//Fichero que implementa la clase memoria_instruccion

#include "memoria_instruccion.hpp"

memoria_instruccion::memoria_instruccion(std::ifstream& fichero) {
	std::string elemento_leido;

	std::getline(fichero,elemento_leido);
	while (fichero.good()) {
		if (elemento_leido == "") {
			std::getline(fichero,elemento_leido);
			continue;
		}
		std::string etiqueta;
		std::string instruccion_whitespaces;
		std::string instruccion;
		std::string argumento;
		int codigo_instruccion = -1;
		int direccionamiento_instruccion = -1;
		std::string argumento_instruccion;
		
		//Eliminación de comentarios
		elemento_leido = trim_derecha(elemento_leido);
		//---DIVISIÓN ENTRE ETIQUETA E INSTRUCCIÓN---
		if (elemento_leido.find(":") != std::string::npos) {
			std::pair<std::string,int> aux;
			
			etiqueta = elemento_leido.substr(0,elemento_leido.find(":"));
			aux.first = etiqueta;
			aux.second = mem.size();
			etiquetas.push_back(aux);
			instruccion_whitespaces = elemento_leido.substr(elemento_leido.find(":") + 2,
					elemento_leido.size());
		}
		else {
			instruccion_whitespaces = elemento_leido;	
		}		
		instruccion = trim(instruccion_whitespaces);	
		//---PROCESAMIENTO DEL CÓDIGO INSTRUCCIÓN
		if (instruccion.find(" ") != std::string::npos) {
			std::string aux = instruccion.substr(0,instruccion.find(" "));
			argumento = instruccion.substr(instruccion.find(" "), instruccion.length());
			codigo_instruccion =	juego_i.get_codigo(aux);
		}
		else {
			codigo_instruccion = juego_i.get_codigo(instruccion);
		}
		if (codigo_instruccion == -1) {
			std::cerr << "Hay instrucciones ilegales\n";
			throw "Instrucciones no permitidas";
		}
		//---PROCESAMIENTO DEL ARGUMENTO
		if (argumento.length() != 0) {
			if (argumento.find("=") != std::string::npos) {
				if (codigo_instruccion == juego_i.get_codigo("STORE")) {
					std::cerr << "Direccionamiento inválido (inmediato) con instrucción store\n";
					throw "Instrucciónes con direccionamientos erróneos";
				}
				argumento_instruccion = argumento.substr(2,argumento.length());
				direccionamiento_instruccion = 0;
			}
			else if (argumento.find("*") != std::string::npos) {
				argumento_instruccion = argumento.substr(2,argumento.length());
				direccionamiento_instruccion = 1;
			}
			else {
				direccionamiento_instruccion = 2;
				argumento_instruccion = argumento.substr(1,argumento.length());
			}
			//COMPROBACIÓN DE ARGUMENTO CORRESPONDIENTE A LA INSTRUCCIÓN
			if ((to_int(argumento_instruccion) == true) && 
					(juego_i.get_argumento(codigo_instruccion) != 2)) {
				std::cerr << "instrucciones con argumentos erróneos (expected etiqueta)\n";
				throw "Instrucciónes con argumentos erróneos";
			}
			if ((to_int(argumento_instruccion) == false) &&
		 		 (juego_i.get_argumento(codigo_instruccion) != 1)) {
				std::cerr << "instrucciones con argumentos erróneos (expected numero)\n";
	 			throw "Instrucciónes con argumentos erróneos";
			}
		}
		else { //caso sin argumento
			if (juego_i.get_argumento(codigo_instruccion) != 0) {
				std::cerr << "instrucciones sin argumento\n";
				throw "Instrucción sin argumento";
			}
		}
		auto tupla = std::make_tuple(codigo_instruccion, direccionamiento_instruccion,
				argumento_instruccion);		
		mem.push_back(tupla);	
		std::getline(fichero,elemento_leido);
	}	
}

memoria_instruccion::~memoria_instruccion() {}

std::ostream& memoria_instruccion::write(std::ostream& os) {
	int count = 0; 

	os << "\nnº  Código  Direcc.  Argumento  Etiqueta_asociada\n";

	for(int i = 0; i < mem.size(); i++) {
		os << i;
		if (i < 10) os << " ";
		os << std::setw(7) << std::get<0>(mem[i]) << std::setw(10) << std::get<1>(mem[i]) << 
				std::setw(7) << std::get<2>(mem[i]);
		if ((etiquetas.size() != 0) && (etiquetas[count].second == i))	{
			os << std::setw(15) << etiquetas[count].first;
			count++;
		}
			os << "\n";
	}
	return os;
}
