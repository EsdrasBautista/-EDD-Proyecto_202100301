#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "nodohuffmann.h"

class Huffman{
private:
    NodoHuffman *raiz;
    std::string codigos[256];

    void insertarCaracter(NodoHuffman*);
    void graficar(NodoHuffman*, std::ofstream&);
    void eliminar(NodoHuffman*);

public:
    Huffman();
    ~Huffman();

    void crearArbol(std::string);
    void crearCodigosHuffman(NodoHuffman*, std::string);
    void graficar();
    void imprimirCodigos();

    std::string comprimir(std::string);
    std::string descomprimir(std::string);

    NodoHuffman* getRaiz();
};

#endif // HUFFMAN_H
