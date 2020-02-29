// Fichero que define la instruccion load
#pragma once
#include "instruccion.hpp"

class load : public instruccion {
  public:
    load();
    ~load();

    bool ejecutar(memoria&, cinta_escritura&, cinta_lectura&,
        std::tuple<int, int, std::string>,int&);
};

