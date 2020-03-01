// Fichero que define la instruccion division
#pragma once
#include "instruccion.hpp"

class division : public instruccion {
  public:
    division();
    ~division();

    bool ejecutar(memoria&, cinta_escritura&, cinta_lectura&,
        std::tuple<int, int, std::string>,int&);
};


