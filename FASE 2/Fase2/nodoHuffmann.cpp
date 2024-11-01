#include "./nodoHuffmann.h"

NodoHuffman::NodoHuffman(char c){
    this->c = c;
    n = 1;
    sig = nullptr;
    izq = nullptr;
    der = nullptr;
}
