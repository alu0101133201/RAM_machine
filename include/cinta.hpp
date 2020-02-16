//Fichero que define a la clase genérica cinta
#pragma once

#include <vector>
#include <fstream>
#include <iostream>

class cinta {
	protected:
		std::vector<int> celdas;
		int cabezal;

		void cargar(std::ifstream&);

	public:
		cinta();
		cinta(std::ifstream&);
		~cinta();

		void avanzar(void);
		int size(void);

		virtual std::ostream& write(std::ostream& os);
};
