//Fichero que implementa la clase genérica cinta_lectura

#include "cinta.hpp"

cinta::cinta()
    : cabezal(-1) {} //Si no se inicializa por fichero se pone a -1 
										 //ya que no hay elementos

cinta::cinta(std::ifstream& fichero)
    : cabezal(0) { //Si se inicializa por fichero se pone a 0, 
								 	 //ya que en la posición 0 ya hay un elemento listo para leer
  cargar(fichero);
}

cinta::~cinta() {}

void cinta::avanzar(void) {
  cabezal++;
}

int cinta::size(void) {
	return celdas.size();
}

void cinta::cargar(std::ifstream& fichero) {
  int elemento_leido;
  fichero >> elemento_leido;
  while (fichero.good()) {
    celdas.push_back(elemento_leido);
    fichero >> elemento_leido;
  }
}

std::ostream& cinta::write(std::ostream& os) {
  if (celdas.size() != 0){
    for (int i = 0; i < celdas.size(); i++) {
			if (i == cabezal)	
				os << "\033[4m" << celdas[i] << "\033[0m ";
			else
      	os << celdas[i] << " ";
    }	
		os << "\n";
  }
  else
    os << "La cinta está vacía\n";
  return os;
}
