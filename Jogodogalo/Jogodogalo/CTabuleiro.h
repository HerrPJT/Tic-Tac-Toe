#ifndef CTABULEIRO_H
#define CTABULEIRO_H

#include <iostream>
using namespace std;
//--------------
const int espacos=9;
const int turnocomputador=1;
const int turnoutilizador=2;
//--------------
class CTabuleiro{
  public:
    char tabuleiro[espacos];
    CTabuleiro();
    void mostrartabuleiro();
    bool vencedor();
    bool acabarjogo();
    bool posicao_disponivel(int n);
    bool cheio();
    char quemganhou();
    void resetartabuleiro();
    CTabuleiro copiartabuleiro();
    friend class CUtilizador;
    friend class CComputador;
    friend class CJogo;
};


#endif