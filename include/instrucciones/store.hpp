// Fichero que define la instruccion store
#pragma once
#include "instruccion.hpp"

class store : public instruccion {
  public:
    store();
    ~store();

    bool ejecutar(memoria&, cinta_escritura&, cinta_lectura&,
        std::tuple<int, int, std::string>,int&);
};


