//Fichero que definirá la clase memoria

#pragma once

#include <vector>
#include <iostream>

class memoria {
	private:
		std::vector<int> registros;
		
	public:
		memoria();
		~memoria();

		void escribir(int,int);
		int leer(int);

		std::ostream& write(std::ostream&);

};
