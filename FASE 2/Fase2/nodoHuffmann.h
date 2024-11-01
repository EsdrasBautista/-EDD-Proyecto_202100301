#ifndef NODOHUFFMANN_H
#define NODOHUFFMANN_H

#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

class NodoHuffman{
public:
    char c;
    int n;
    NodoHuffman *sig;
    NodoHuffman *izq;
    NodoHuffman *der;

    NodoHuffman(char);
};



#endif // NODOHUFFMANN_H
