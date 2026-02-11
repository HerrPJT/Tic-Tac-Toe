#ifndef CCOMPUTADOR_H
#define CCOMPUTADOR_H
#include "CTabuleiro.h"
#include "CJogo.h"

class CComputador{
private:
int nivelDificuldade;
public:
  void introduzirDificuldade(CTabuleiro &tab,int nivel);
  void modoelementar(CTabuleiro &tab);
  void modofacil(CTabuleiro &tab);
  void modomedio(CTabuleiro &tab);
  void mododificil(CTabuleiro &tab);
  void fazer_jogada(CTabuleiro &tab,int n);
  void introduzirDificuldade2(CTabuleiro &tab,int nivel);
  void fazer_jogada2(CTabuleiro &tab,int n);
  void modoelementar2(CTabuleiro &tab);
  void modofacil2(CTabuleiro &tab);
  void modomedio2(CTabuleiro &tab);
  void mododificil2(CTabuleiro &tab);
};

    
#endif