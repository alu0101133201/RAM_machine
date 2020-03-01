// Fichero que define la instruccion jzero
#pragma once
#include "instruccion.hpp"

class jzero : public instruccion {
  public:
    jzero();
    ~jzero();

    bool ejecutar(memoria&, cinta_escritura&, cinta_lectura&,
        std::tuple<int, int, std::string>,int&);
};


