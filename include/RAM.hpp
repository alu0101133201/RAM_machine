//Fichero que define la clase maquina RAM
#pragma once

#include <iostream>
#include <fstream>
#include "cinta_escritura.hpp"
#include "cinta_lectura.hpp"
#include "cinta_lectura.hpp"
#include "memoria.hpp"
#include "memoria_instruccion.hpp"
#include "instruccion.hpp"
#include "load.hpp"
#include "store.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "read.hpp"
#include "write.hpp"
#include "jump.hpp"
#include "jgtz.hpp"
#include "jzero.hpp"
#include "halt.hpp"


class RAM {
	private:
		cinta_escritura c_e;
		cinta_lectura c_l;
		memoria_instruccion programa;
		memoria registros;

    int pc;   //program counter
	
	public:
		RAM(std::ifstream&, std::ifstream&);
		~RAM();

    void ejecutar_instruccion(instruccion*, bool&);
    void ejecutar_programa(int&);

    std::ostream& write_registros(std::ostream&);
		std::ostream& write(std::ostream&);
};
