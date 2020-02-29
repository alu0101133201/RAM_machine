// Fichero que define la clase base de instruccion. Es una clase abstracta
#pragma once

#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include "cinta_escritura.hpp"
#include "cinta_lectura.hpp"
#include "cinta_lectura.hpp"
#include "memoria.hpp"
#include "memoria_instruccion.hpp"


class instruccion {

  public: 
    instruccion();
    ~instruccion();

    virtual bool ejecutar(memoria&, cinta_escritura&, cinta_lectura&,
        std::tuple<int, int, std::string>) = 0;
};


