// Fichero que define la instruccion jump
#pragma once
#include "instruccion.hpp"

class jump : public instruccion {
  public:
    jump();
    ~jump();

    bool ejecutar(memoria&, cinta_escritura&, cinta_lectura&,
        std::tuple<int, int, std::string>,int&);
};


