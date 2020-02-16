#include "cinta_escritura.hpp"

void cinta_escritura::escribir(int valor) {
	celdas.push_back(valor);
	cinta::avanzar();
}
