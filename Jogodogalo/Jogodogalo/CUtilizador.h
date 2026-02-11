#ifndef CUTILIZADOR_H
#define CUTILIZADOR_H
#include "CTabuleiro.h"
class CUtilizador{
  public:
    string utilizador;
    int vitorias;
    int empates;
    int derrotas;
    CUtilizador *proximo;
    CUtilizador();
    CUtilizador(CUtilizador &jogador);
    void pedir_nome_utilizador();
    void set_nome_utilizador(const string& novo_nome);
    string nome_utilizador();
    void guardar_estastisticas();
    void carregar_estatisticas();
    friend class CTopdez;
};
#endif