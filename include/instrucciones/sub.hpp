// Fichero que define la instruccion sub
#pragma once
#include "instruccion.hpp"

class sub : public instruccion {
  public:
    sub();
    ~sub();

    bool ejecutar(memoria&, cinta_escritura&, cinta_lectura&,
        std::tuple<int, int, std::string>,int&);
};


