// Fichero que define la instruccion jgtz
#pragma once
#include "instruccion.hpp"

class jgtz : public instruccion {
  public:
    jgtz();
    ~jgtz();

    bool ejecutar(memoria&, cinta_escritura&, cinta_lectura&,
        std::tuple<int, int, std::string>,int&);
};



