#ifndef CJOGO_H
#define CJOGO_H
#include "CTabuleiro.h"
#include "CUtilizador.h"
class CJogo{
  private:
  CTabuleiro tabuleiro;
 public:
  void carregar_jogo(const string &nome_arquivo, CTabuleiro &tabuleiro,int &nivel,CUtilizador &utilizador, int &numerojogada); 
  void salvar_jogo(const string &nome_arquivo,CTabuleiro tabuleiro,int nivel,CUtilizador utilizador, int numerojogada);
  void salvar_jogo_mododificil(CTabuleiro &tabuleiro,int &recompensa0,int &recompensa1);
  bool carregar_jogo_mododificil(CTabuleiro &tab1,CTabuleiro &tab,int &recompensa0,int &recompensa1);
  void salvar_jogo_mododificil2(CTabuleiro &tabuleiro,int &recompensa0,int &recompensa1);
  bool carregar_jogo_mododificil2(CTabuleiro &tab1,CTabuleiro &tab,int &recompensa0,int &recompensa1);
  void verificar_se_existe2(CTabuleiro &tab1,int &recompensa0,int &recompensa1);
  bool comparar_jogos_mododificil(CTabuleiro &tabuleiro1,CTabuleiro &tabuleiro2);
  bool comparar_jogos_iguais(CTabuleiro &tabuleiro1,CTabuleiro &tabuleiro2);
  void verificar_se_existe(CTabuleiro &tab1,int &recompensa0,int &recompensa1);
  bool comparar_jogos_mododificil2(CTabuleiro &tabuleiro1,CTabuleiro &tabuleiro2);
  bool comparar_jogos_iguais2(CTabuleiro &tabuleiro1,CTabuleiro &tabuleiro2);
};

#endif