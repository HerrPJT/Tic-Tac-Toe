#include "CComputador.h"
#include "funcoesauxiliares.h"

void Jogarjogodogalo(CUtilizador utilizador,int nivel,int numerojogadas,int turnoaescolher, CTabuleiro tabuleironormal){
  CTabuleiro conjuntotabuleiros[9];
  CComputador computador;
  CJogo jogo;
  int quadrado=0;
  int recompensas_derrota=0;
  int recompensas_vitoria=0;
  for(;numerojogadas<espacos &&               
    tabuleironormal.acabarjogo()==false;numerojogadas++){
     if(turnoaescolher==turnoutilizador){
            cout<<"Numero da jogada: "<<numerojogadas<<"\t\t";
            mostrarnivel(nivel,turnoutilizador,utilizador);
         utilizadorjoga(tabuleironormal,quadrado,jogo,nivel,
              utilizador,numerojogadas);
    mostrartabuleirosanteriores(conjuntotabuleiros,numerojogadas);
              tabuleironormal.mostrartabuleiro();            conjuntotabuleiros[numerojogadas]=tabuleironormal.copiartabuleiro();
              turnoaescolher=turnocomputador;}

//--------------------------------------------------
    else if(turnoaescolher==turnocomputador){
        cout<<"Numero da jogada: "<<numerojogadas<<"\t\t";
        mostrarnivel(nivel,turnocomputador,utilizador);
      computador.introduzirDificuldade(tabuleironormal,nivel);
      mostrartabuleirosanteriores(conjuntotabuleiros,numerojogadas);
        tabuleironormal.mostrartabuleiro();
conjuntotabuleiros[numerojogadas]=tabuleironormal.copiartabuleiro();
        turnoaescolher=turnoutilizador;}
}
//-----------------------------------------------------------    
  if(tabuleironormal.acabarjogo()==true){
    if(turnoaescolher==turnocomputador){
        cout<<"O vencedor e o utilizador";
        cout<<endl<<endl<<endl;
        recompensas_vitoria=0;
        recompensas_derrota=1;
        jogo.verificar_se_existe(tabuleironormal,recompensas_vitoria,recompensas_derrota);
        utilizador.vitorias++;}
    
    if(turnoaescolher==turnoutilizador){
        cout<<"O vencedor e o computador";
        cout<<endl<<endl<<endl;
        recompensas_vitoria=1;
        recompensas_derrota=0;
        jogo.verificar_se_existe(tabuleironormal,recompensas_vitoria,recompensas_derrota);
        utilizador.derrotas++;}
}
  if(numerojogadas==espacos && tabuleironormal.acabarjogo()!=true){ 
      cout<<"Empate";
      cout<<endl<<endl<<endl;
      utilizador.empates++;}

  utilizador.guardar_estastisticas();
}
//----------------------------------------------------------
//----------------------------------------------------------
//----------------------------------------------------------
void jogoutilizadores(CUtilizador utilizador1,CUtilizador utilizador2,int nivel,int numerojogadas,int turnoaescolher, CTabuleiro tabuleironormal){
    CJogo jogo;
    CTabuleiro conjuntotabuleiros[9];
    int quadrado=0;
    for(;numerojogadas<espacos &&               
      tabuleironormal.acabarjogo()==false;numerojogadas++){
       if(turnoaescolher==turnoutilizador){
              cout<<"Numero da jogada: "<<numerojogadas<<"\t\t";
         mostrarjogoentreutilizadores(turnoaescolher, utilizador1,utilizador2);
              jogadas_de_utilizadores(tabuleironormal, quadrado,jogo,utilizador1, utilizador2 ,numerojogadas,turnoaescolher);
  mostrartabuleirosanteriores(conjuntotabuleiros,numerojogadas);
         tabuleironormal.mostrartabuleiro();            conjuntotabuleiros[numerojogadas]=tabuleironormal.copiartabuleiro();
              turnoaescolher=turnocomputador;}

  //--------------------------------------------------
      else if(turnoaescolher==turnocomputador){
          cout<<"Numero da jogada: "<<numerojogadas<<"\t\t";
        mostrarjogoentreutilizadores(turnoaescolher, utilizador1,utilizador2);
        jogadas_de_utilizadores(tabuleironormal, quadrado,jogo,utilizador1, utilizador2 ,numerojogadas,turnoaescolher);
mostrartabuleirosanteriores(conjuntotabuleiros,numerojogadas);
        tabuleironormal.mostrartabuleiro();            conjuntotabuleiros[numerojogadas]=tabuleironormal.copiartabuleiro();
          turnoaescolher=turnoutilizador;}
  }
  //-----------------------------------------------------------    
    if(tabuleironormal.acabarjogo()==true){
      if(turnoaescolher==turnocomputador){
          cout<<"O vencedor e o utilizador 1";
          cout<<endl<<endl<<endl;
          utilizador1.vitorias++;}

      if(turnoaescolher==turnoutilizador){
          cout<<"O vencedor e o utilizador 2";
          cout<<endl<<endl<<endl;
          utilizador1.derrotas++;}
  }
    if(numerojogadas==espacos && tabuleironormal.acabarjogo()!=true){ 
        cout<<"Empate";
        cout<<endl<<endl<<endl;
        utilizador1.empates++;}

    utilizador1.guardar_estastisticas();
    utilizador2.guardar_estastisticas();
  }
//---------------------------------------------------------
//---------------------------------------------------------
//---------------------------------------------------------
void jogocomputadores(int nivel1,int nivel2,int numerojogadas,int turnoaescolher, CTabuleiro tabuleironormal){
  CComputador computador1;
  CComputador computador2;
  CTabuleiro conjuntotabuleiros[9];
    for(;numerojogadas<espacos &&               
      tabuleironormal.acabarjogo()==false;numerojogadas++){
       if(turnoaescolher==turnoutilizador){
          cout<<"Numero da jogada: "<<numerojogadas<<"\t\t";
   computador1.introduzirDificuldade(tabuleironormal,nivel1);
mostrartabuleirosanteriores(conjuntotabuleiros,numerojogadas);
         tabuleironormal.mostrartabuleiro();            conjuntotabuleiros[numerojogadas]=tabuleironormal.copiartabuleiro();
              turnoaescolher=turnocomputador;}

      else if(turnoaescolher==turnocomputador){
          cout<<"Numero da jogada: "<<numerojogadas<<"\t\t";
   computador2.introduzirDificuldade2(tabuleironormal,nivel2);
mostrartabuleirosanteriores(conjuntotabuleiros,numerojogadas);
        tabuleironormal.mostrartabuleiro();            conjuntotabuleiros[numerojogadas]=tabuleironormal.copiartabuleiro();
          turnoaescolher=turnoutilizador;}
    }
    if(tabuleironormal.acabarjogo()==true){
      if(turnoaescolher==turnocomputador){
          cout<<"O vencedor e o computador 1";
          cout<<endl<<endl<<endl;}
      if(turnoaescolher==turnoutilizador){
          cout<<"O vencedor e o computador 2";
          cout<<endl<<endl<<endl;}
    } 
    if(numerojogadas==espacos &&   
       tabuleironormal.acabarjogo()!=true){ 
        cout<<"Empate";
        cout<<endl<<endl<<endl;}
}
