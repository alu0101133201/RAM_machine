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

#define LOAD 0
#define STORE 1
#define ADD 2
#define SUB 3
#define MULT 4
#define DIV 5
#define READ 6
#define WRITE 7
#define JUMP 8
#define JGTZ 9
#define JZERO 10
#define HALT 11


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

    std::ostream& desensamblador(std::ostream&);

    std::ostream& write_registros(std::ostream&);
    std::ostream& write_cinta_e(std::ostream&);
    std::ostream& write_cinta_l(std::ostream&);
		std::ostream& write(std::ostream&);
};
