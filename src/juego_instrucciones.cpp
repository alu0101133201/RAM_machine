//Fichero que implementa la clase juego de instrucciones

#include "juego_instrucciones.hpp"

juego_instrucciones::juego_instrucciones() {

	auto aux = std::make_tuple("LOAD",0,2);
	tabla.push_back(aux);
	aux = std::make_tuple("STORE",1,2);
	tabla.push_back(aux);
	aux = std::make_tuple("ADD",2,2);
	tabla.push_back(aux);
	aux = std::make_tuple("SUB",3,2);
	tabla.push_back(aux);
	aux = std::make_tuple("MULT",4,2);
	tabla.push_back(aux);
	aux = std::make_tuple("DIV",5,2);
	tabla.push_back(aux);
	aux = std::make_tuple("READ",6,2);
	tabla.push_back(aux);
	aux = std::make_tuple("WRITE",7,2);
	tabla.push_back(aux);
	aux = std::make_tuple("JUMP",8,1);
	tabla.push_back(aux);
	aux = std::make_tuple("JGTZ",9,1);
	tabla.push_back(aux);
	aux = std::make_tuple("JZERO",10,1);
	tabla.push_back(aux);
	aux = std::make_tuple("HALT",11,0);
	tabla.push_back(aux);
}

juego_instrucciones::~juego_instrucciones() {}

int juego_instrucciones::get_codigo(std::string nombre) {
	for(auto& x: nombre)
		x = toupper(x);		//Convierto la cadena a mayúsculas por si ha sido suministrada en minus
	for (int i = 0; i < tabla.size(); i++) {
		if (std::get<0>(tabla[i]) == nombre)
			return std::get<1>(tabla[i]);;
	}	
	return -1;
}

std::string juego_instrucciones::get_nombre(int codigo) {
	for (int i = 0; i < tabla.size(); i++) {
		if (std::get<1>(tabla[i]) == codigo)
			return std::get<0>(tabla[i]);
	}	
		
	return "";
}

std::ostream& juego_instrucciones::write(std::ostream& os){
	for (int i = 0; i < tabla.size(); i++) {
		os << std::get<0>(tabla[i]) << " - " << std::get<1>(tabla[i]) << 
				" " << std::get<2>(tabla[i]) << "\n";
	}
	return os;
}

int juego_instrucciones::get_argumento(int codigo) {
	for (int i = 0; i < tabla.size(); i++) {
		if (std::get<1>(tabla[i]) == codigo)
			return std::get<2>(tabla[i]);;
	}
	return -1;
}

int juego_instrucciones::get_argumento(std::string nombre) {
	for (int i = 0; i < tabla.size(); i++) {
		if (std::get<0>(tabla[i]) == nombre)
			return std::get<2>(tabla[i]);;
	}
	return -1;
}




