// Fichero que define la instruccion write_cinta
#pragma once
#include "instruccion.hpp"

class write_cinta : public instruccion {
  public:
    write_cinta();
    ~write_cinta();

    bool ejecutar(memoria&, cinta_escritura&, cinta_lectura&,
        std::tuple<int, int, std::string>,int&);
};

