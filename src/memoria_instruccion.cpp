//Fiohero que implementa la clase memoria_instruccion
#define INMEDIATO 0
#define INDIRECTO 1
#define DIRECTO 2
#define RECIBE_NUMERO 2
#define RECIBE_ETIQUETA 1
#define SIN_ARGUMENTO 0

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
			throw "Instrucciones no permitidas";
		}
		//---PROCESAMIENTO DEL ARGUMENTO
		if (argumento.length() != 0) {
			if (argumento.find("=") != std::string::npos) {
				if (codigo_instruccion == juego_i.get_codigo("STORE")) {
					throw "Direccionamiento inválido (inmediato) con instrucción store\n";
				}
				argumento_instruccion = argumento.substr(2,argumento.length());
				direccionamiento_instruccion = INMEDIATO;
			}
			else if (argumento.find("*") != std::string::npos) {
				argumento_instruccion = argumento.substr(2,argumento.length());
				direccionamiento_instruccion = INDIRECTO;
			}
      else {
        direccionamiento_instruccion = DIRECTO;
			  argumento_instruccion = argumento.substr(1, argumento.length());
			}
			//COMPROBACIÓN DE ARGUMENTO CORRESPONDIENTE A LA INSTRUCCIÓN
			if ((to_int(argumento_instruccion) == true) && 
					(juego_i.get_argumento(codigo_instruccion) != RECIBE_NUMERO)) {
				throw "instrucciones con argumentos erróneos (expected etiqueta)\n";
			}
			if ((to_int(argumento_instruccion) == false) &&
		 		 (juego_i.get_argumento(codigo_instruccion) != RECIBE_ETIQUETA)) {
				throw "instrucciones con argumentos erróneos (expected numero)\n";
			}
		}
		else { //caso sin argumento
			if (juego_i.get_argumento(codigo_instruccion) != SIN_ARGUMENTO) {
				throw "Instrucción sin argumento\n";
			}
		}
		auto tupla = std::make_tuple(codigo_instruccion, direccionamiento_instruccion,
				argumento_instruccion);		
		mem.push_back(tupla);	
		std::getline(fichero,elemento_leido);
	}	
  // Sustitución de las etiquetas por las posiciones de memoria correspondientes
  for (int i = 0; i < mem.size(); i++) {
    std::string arg = std::get<2>(mem[i]);
    if (!to_int(arg) && (arg.length() != 0)) {
      std::get<2>(mem[i]) = std::to_string(instruccion_etiqueta(arg));
    }
  }
}

memoria_instruccion::~memoria_instruccion() {}

int memoria_instruccion::instruccion_etiqueta(std::string etiqueta_buscar) {
  for (int i = 0; i < etiquetas.size(); i++) {
    if (etiquetas[i].first == etiqueta_buscar)
      return etiquetas[i].second;
  }
  std::cerr << etiqueta_buscar << " no existe\n";
  throw "Referencia a etiqueta no existente\n";
}


int memoria_instruccion::num_instrucciones(void){ 
  return mem.size();
}

std::tuple<int, int, std::string> memoria_instruccion::get_tupla(int posicion) {
  return mem[posicion]; }

std::ostream& memoria_instruccion::write(std::ostream& os) {
	int count = 0; 

	os << "\nnº  Código       Direcc.  Argumento  Etiqueta_asociada\n";

	for(int i = 0; i < mem.size(); i++) {
    int direccionamiento = std::get<1>(mem[i]);
		os << i;
		if (i < 10) os << " ";
		os << std::setw(7) << std::get<0>(mem[i]);
    switch(direccionamiento) {
      case 0:
        os << std::setw(15) << "INMEDIATO";
        break;
      case 1:
        os << std::setw(15) << "INDIRECTO";
        break;
      case 2:
        os << std::setw(15) << "DIRECTO";
        break;
      default:
        throw "Error inesperado. Default de switch que no debería ser accesible\n";
        break;
    }
    os << std::setw(7) << std::get<2>(mem[i]);
		if ((etiquetas.size() != 0) && (etiquetas[count].second == i))	{
			os << std::setw(15) << etiquetas[count].first;
			count++;
		}
			os << "\n";
	}
	return os;
}
