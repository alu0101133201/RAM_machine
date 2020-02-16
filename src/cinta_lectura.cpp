//Fichero que implementa la clase cinta de cinta_escritura

#include "cinta_lectura.hpp"

cinta_lectura::cinta_lectura(std::ifstream& fichero)
     : cinta(fichero) {}

int cinta_lectura::leer(void) {
	int lectura = celdas[cabezal];
	cinta::avanzar();	
	return lectura;
}
