#include "Jogar_jogogalo.h"
#include "CTopdez.h"
//---------------------------
int main() {
  CTopdez ranking;
  CJogo jogo;
  CUtilizador utilizador;
  int nivel=0;
  int opcao;
  int numerojogos=0;
  int numerojogadas;
  do{
      opcao=menu_inicial();
  //----------------------------------------------------------
    if(opcao==1){
        CTabuleiro tabuleiro;
        int opcaofuncionamento;
        numerojogadas=0;
        CUtilizador utilizador2;
        opcaofuncionamento=menu_modos_funcionamento();
        if(opcaofuncionamento==1){
          int turnoaescolher;
          int guardarturnoescolhido;
          Instrucoes();
          utilizador.pedir_nome_utilizador();
          utilizador.carregar_estatisticas();
          nivel=escolherdificuldade();
            if(numerojogos==0){
              turnoaescolher=escolherturno();
              guardarturnoescolhido=turnoaescolher;}
            if(numerojogos!=0){
              if(guardarturnoescolhido==turnocomputador){
                turnoaescolher=turnoutilizador;
                guardarturnoescolhido=turnoaescolher;}
              if(guardarturnoescolhido==turnoutilizador){
                turnoaescolher=turnocomputador;
                guardarturnoescolhido=turnoaescolher;}}      
         Jogarjogodogalo(utilizador,nivel,numerojogadas, 
         turnoaescolher,tabuleiro);
          numerojogos++;
          ranking.carregartopdez();
          ranking.adicionarjogadoreordenar(utilizador);
          ranking.salvartopdez();  
      }
        if(opcaofuncionamento==2){
      int turnoaescolher;
      int guardarturnoescolhido;
      Instrucoes();
      utilizador.pedir_nome_utilizador();
      utilizador.carregar_estatisticas();
      utilizador2.pedir_nome_utilizador();
      utilizador2.carregar_estatisticas();
      if(numerojogos==0){
        turnoaescolher=escolherturnoutilizadores();
        guardarturnoescolhido=turnoaescolher;}
      if(numerojogos!=0){
        if(guardarturnoescolhido==turnocomputador){
          turnoaescolher=turnoutilizador;
          guardarturnoescolhido=turnoaescolher;}
        if(guardarturnoescolhido==turnoutilizador){
          turnoaescolher=turnocomputador;
          guardarturnoescolhido=turnoaescolher;}}
      int numerojogadas=0;
      int nivel=0;
      jogoutilizadores(utilizador,utilizador2, numerojogadas,nivel,turnoaescolher,tabuleiro);
    }
        if(opcaofuncionamento==3){
            int turnoaescolher;
            int guardarturnoescolhido;
            int nivel1;
            int nivel2;
            nivel1=escolherdificuldade();
            nivel2=escolherdificuldade();
            int numerojogadas=0;
            if(numerojogos==0){
              turnoaescolher=escolherturnocomputadores();
              guardarturnoescolhido=turnoaescolher;}
            if(numerojogos!=0){
              if(guardarturnoescolhido==turnocomputador){
                turnoaescolher=turnoutilizador;
                guardarturnoescolhido=turnoaescolher;}
              if(guardarturnoescolhido==turnoutilizador){
                turnoaescolher=turnocomputador;
                guardarturnoescolhido=turnoaescolher;}}
            jogocomputadores(nivel1, nivel2, numerojogadas, turnoaescolher, tabuleiro);
          }
    }
  //-----------------------------------------------------------
    if(opcao==2){
        CTabuleiro tabuleiro;
        int numerojogadas;
        carregarjogo(jogo,tabuleiro,nivel,utilizador, numerojogadas);
        utilizador.nome_utilizador();
        utilizador.carregar_estatisticas();
        int turnoescolhido=2;
        Jogarjogodogalo(utilizador,nivel,numerojogadas, 
        turnoescolhido,tabuleiro);
        ranking.carregartopdez();
        ranking.adicionarjogadoreordenar(utilizador);
        ranking.salvartopdez();
      }
  //----------------------------------------------------------
      if(opcao==3){
        ranking.carregartopdez();
        ranking.mostrartopdez();
      }
     if(opcao==0){
       cout<<"A sair do jogo";
       return 0;}
  } while(opcao!=0);
}
  