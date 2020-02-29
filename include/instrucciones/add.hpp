// Fichero que define la instruccion add
#pragma once
#include "instruccion.hpp"

class add : public instruccion {
  public:
    add();
    ~add();

    bool ejecutar(memoria&, cinta_escritura&, cinta_lectura&,
        std::tuple<int, int, std::string>,int&);
};


