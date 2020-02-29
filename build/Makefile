IDIR = ../include
IDIRI = ../include/instrucciones
CC=g++
CFLAGS=-I$(IDIR) -I$(IDIRI) -std=c++11 -g

ODIR=../src
ODIRI=../src/instrucciones

.PHONY: all

_OBJ = load.o instruccion.o RAM.o juego_instrucciones.o memoria_instruccion.o memoria.o cinta_lectura.o cinta_escritura.o cinta.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


all: RAM

$(ODIR)/instruccion.o: $(ODIRI)/instruccion.cpp $(IDIRI)/instruccion.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/load.o: $(ODIRI)/load.cpp $(IDIRI)/load.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/RAM.o: $(ODIR)/RAM.cpp $(IDIR)/RAM.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/juego_instrucciones.o: $(ODIR)/juego_instrucciones.cpp $(IDIR)/juego_instrucciones.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/memoria_instruccion.o: $(ODIR)/memoria_instruccion.cpp $(IDIR)/memoria_instruccion.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/memoria.o: $(ODIR)/memoria.cpp $(IDIR)/memoria.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/cinta.o: $(ODIR)/cinta.cpp $(IDIR)/cinta.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/cinta_escritura.o: $(ODIR)/cinta_escritura.cpp $(IDIR)/cinta_escritura.hpp $(IDIR)/cinta.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/cinta_lectura.o: $(ODIR)/cinta_lectura.cpp $(IDIR)/cinta_lectura.hpp $(IDIR)/cinta.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/main.o: $(ODIR)/main.cpp $(IDIR)/cinta_escritura.hpp $(IDIR)/cinta_lectura.hpp
	$(CC) -c -o $@ $< $(CFLAGS)


RAM: $(OBJ)
	$(CC)  -o $@ $^ $(CFLAGS)




.PHONY: clean

clean:
	rm -f $(ODIR)/*.o ./P1
