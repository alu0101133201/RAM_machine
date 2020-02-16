IDIR = ../include
CC=g++
CFLAGS=-I$(IDIR) -std=c++11 -g

ODIR=../src

.PHONY: all

_OBJ = cinta_lectura.o cinta_escritura.o cinta.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


all: RAM


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
