//Fichero que implementará la clase memoria

#include "memoria.hpp"

memoria::memoria() {}

memoria::~memoria() {}

void memoria::escribir(int valor, int registro) {
/*	if (registro == 0) {
		throw "Intento de escribir en el acumulador";
	} */
	if (registros.size() < (registro + 1)) {
		registros.resize(registro + 1);
	}
	registros[registro] = valor;
}

int memoria::leer(int registro) {
	if ((registros.size() + 1) < registro) {
		return (-1);
	}
	else {
		return registros[registro];
	}
}

std::ostream& memoria::write(std::ostream& os) {
	if (registros.size() == 0)
		os << "Memoria vacía\n";
	else {
		os << " _ \n";
		for (int i = 0; i < registros.size(); i++) {
			os << "|" << registros[i] << "|\n";
		}
	}
	return os;
}
