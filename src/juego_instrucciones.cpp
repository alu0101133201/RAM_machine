//Fichero que implementa la clase juego de instrucciones

#include "juego_instrucciones.hpp"

juego_instrucciones::juego_instrucciones() {
	tabla.resize(12);

	std::pair<std::string,int> aux;
	aux.first = "LOAD"; aux.second = 0;
	tabla[0] = aux;
	aux.first = "STORE"; aux.second = 1;
	tabla[1] = aux;
	aux.first = "ADD"; aux.second = 2;
	tabla[2] = aux;
	aux.first = "SUB"; aux.second = 3;
	tabla[3] = aux;
	aux.first = "MULT"; aux.second = 4;
	tabla[4] = aux;
	aux.first = "DIV"; aux.second = 5;
	tabla[5] = aux;
	aux.first = "READ"; aux.second = 6;
	tabla[6] = aux;
	aux.first = "WRITE"; aux.second = 7;
	tabla[7] = aux;
	aux.first = "JUMP"; aux.second = 8;
	tabla[8] = aux;
	aux.first = "JGTZ"; aux.second = 9;
	tabla[9] = aux;
	aux.first = "JZERO"; aux.second = 10;
	tabla[10] = aux;
	aux.first = "HALT"; aux.second = 11;
	tabla[11] = aux;
}

juego_instrucciones::~juego_instrucciones() {}

int juego_instrucciones::get_codigo(std::string nombre) {
	for(auto& x: nombre)
		x = toupper(x);		//Convierto la cadena a mayúsculas por si ha sido suministrada en minus
	for (int i = 0; i < tabla.size(); i++) {
		if (tabla[i].first == nombre)
			return tabla[i].second;
	}	
	return -1;
}

std::string juego_instrucciones::get_nombre(int codigo) {
	for (int i = 0; i < tabla.size(); i++) {
		if (tabla[i].second == codigo)
			return tabla[i].first;
	}	
		
	return "";
}

std::ostream& juego_instrucciones::write(std::ostream& os){
	for (int i = 0; i < tabla.size(); i++) {
		os << tabla[i].first << " - " << tabla[i].second << "\n";
	}
	return os;
}
