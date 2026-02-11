#ifndef CTOPDEZ_H
#define CTOPDEZ_H
#include "CUtilizador.h"
class CTopdez{
  protected:
    CUtilizador *cabeca;
  public:
    CTopdez();
    ~CTopdez();
    void adicionarjogadoreordenar(CUtilizador jogador);
    void mostrartopdez();
    void salvartopdez();
    void carregartopdez();
};
#endif