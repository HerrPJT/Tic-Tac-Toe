#include "CTabuleiro.h"
#include "CJogo.h"
#include "CUtilizador.h"
#include <cstdlib>
int menu_inicial(){
  int opcao;
  cout<<"1-Iniciar Jogo"<<endl;
  cout<<"2-Carregar Jogo existente"<<endl;
  cout<<"3-Mostrar top 10"<<endl;
  cout<<"0-Sair"<<endl;
  cout<<"Escolha uma opcao: ";
  do{
  cin>>opcao;
  cout<<endl;}
  while(opcao>3 || opcao<0);
  return opcao;
}
//-----------------------------------------------
int menu_modos_funcionamento(){
    int opcaofuncionamento;
    cout<<"Escolha um modo de funcionamento"<<endl;
    cout<<"1-Utilizador vs Computador"<<endl;
    cout<<"2-Utilizador vs Utilizador"<<endl;
    cout<<"3-Computador vs Computador"<<endl;
    cout<<"Escolha uma opcao: ";
    do{
    cin>>opcaofuncionamento;
    cout<<endl;}
    while(opcaofuncionamento>3 || opcaofuncionamento<1);
    return opcaofuncionamento;
  }
//-----------------------------------------
void sair_menu(CTabuleiro tabuleiro,int nivel,CUtilizador utilizador, int numerojogada){
  int opcao_sair;
  cout<<"Deseja salvar o jogo antes de sair?"<<endl;
  cout<<"1-Sim,salvar e sair"<<endl;
  cout<<endl;
  cout<<"2-Não,sair sem salvar"<<endl;
  cout<<"Escolha uma opção: ";
  cin >> opcao_sair;
  if (opcao_sair ==1 ){
      CJogo jogo;
     string nome_arquivo_jogo;
    cout<< "Introduza o nome do arquivo para salvar o jogo: ";
      cin >> nome_arquivo_jogo;
jogo.salvar_jogo(nome_arquivo_jogo,tabuleiro,nivel,utilizador,numerojogada);
      cout<<"Saindo do programa"<<endl;
  } else if (opcao_sair ==2){
      cout<<"Saindo do programa sem salvar"<<endl;
      exit(0);
  } else {
      cout<<"Opção Inválida ! Saindo do progrma sem salvar"<<endl;
      exit(0);
    }
}

//---------------------------------------------------------
void carregarjogo(CJogo &jogo,CTabuleiro &tabuleiro,int &nivel, CUtilizador &utilizador, int &numerojogada){
  string nome_arquivo;
  cout<<"Digite o nome do arquivo para carregar o jogo: ";
  cin >> nome_arquivo;
  cout <<"Nome do arquivo fornecido " << nome_arquivo <<endl;
  jogo.carregar_jogo(nome_arquivo,tabuleiro,nivel,utilizador,numerojogada); 
}
//---------------------------------------------------------
int escolherturno(){
  int turnoaescolher;
  cout<<"Escolha quem comeca"<<endl;
  cout<<"1-Computador"<<endl<<"2-Utilizador"<<endl<<"3-Aleatorio: "    <<endl<<"Numero: ";
  do{
  cin>>turnoaescolher;
  cout<<endl;}
  while(turnoaescolher<1 || turnoaescolher>3);
  if(turnoaescolher>0 && turnoaescolher<3){
    return turnoaescolher;}
  if(turnoaescolher==3){
    turnoaescolher=rand() % 2 + 1;
    return turnoaescolher;
  }
  return -1;
}
int escolherturnoutilizadores(){
  int turnoaescolher;
  cout<<"Escolha quem comeca"<<endl;
  cout<<"1-Utilizador1"<<endl<<"2-Utilizador2"<<endl<<"3-Aleatorio: "    <<endl<<"Numero: ";
  do{
  cin>>turnoaescolher;
  cout<<endl;}
  while(turnoaescolher<1 || turnoaescolher>3);
  if(turnoaescolher>0 && turnoaescolher<3){
    return turnoaescolher;}
  if(turnoaescolher==3){
    turnoaescolher=rand() % 2 + 1;
    return turnoaescolher;
  }
  return -1;
}
int escolherturnocomputadores(){
  int turnoaescolher;
  cout<<"Escolha quem comeca"<<endl;
  cout<<"1-Computador1"<<endl<<"2-Computador2"<<endl<<"3-Aleatorio: "    <<endl<<"Numero: ";
  do{
  cin>>turnoaescolher;
  cout<<endl;}
  while(turnoaescolher<1 || turnoaescolher>3);
  if(turnoaescolher>0 && turnoaescolher<3){
    return turnoaescolher;}
  if(turnoaescolher==3){
    turnoaescolher=rand() % 2 + 1;
    return turnoaescolher;
  }
  return -1;
}
//--------------------------------------------------------
int escolherdificuldade(){
  int nivel;
  cout<<"Escolha uma dificuldade: "<<endl;
  cout<<"1-Elementar"<<endl<<"2-Facil"<<endl<<"3-Medio"<<endl<<"4-Dificil"<<endl<<"Numero: ";
  do{
  cin>>nivel;
  cout<<endl;}
  while(nivel<1 || nivel>4);
  return nivel;
}
//-----------------------------------------------------
void Instrucoes(){
  cout<<endl<<endl;
  cout<<"Insira o numero do quadrado onde quer colocar"<<endl;
  cout<<" 1   |  2     |  3  "<<endl<<"----------------------"    
  <<endl<<  " 4   |  5     |  6  "<<endl<<"----------------------" 
  <<endl<<" 7   |  8     | 9"<<endl<<endl<<endl;
}
//------------------------------------------------------ 
//-------------------------------------------------------------
void utilizadorjoga(CTabuleiro &tab,int n,CJogo jogo,int nivel,CUtilizador utilizador, int numerojogada){
    cout<<endl;
    cout<<"Jogada do utilizador: ";
    cout<<endl;
    do{
      do{cout<<"Escolha um quadrado: ";
          cin>>n;
          cout<<endl;}
       while((n<0 || n>9));}
    while(n!=0 && tab.posicao_disponivel(n)==false);
    if(n==0){
      sair_menu(tab,nivel,utilizador,numerojogada);
      return;
    }
    else{
    tab.tabuleiro[n-1]='X';}
}
void jogadas_de_utilizadores(CTabuleiro &tab,int n,CJogo jogo,CUtilizador utilizador1,CUtilizador utilizador2 , int numerojogada,int turnoajogar){
  cout<<endl;
  cout<<"Jogada do utilizador: ";
  cout<<endl;
  do{
    do{cout<<"Escolha um quadrado: ";
        cin>>n;
        cout<<endl;}
     while((n<0 || n>9));}
  while(n!=0 && tab.posicao_disponivel(n)==false);
    if(turnoajogar==turnoutilizador)
      tab.tabuleiro[n-1]='X';
    else{
      tab.tabuleiro[n-1]='0';}
    
}
//-------------------------------------------------
//-------------------------------------------------
//-------------------------------------------------
void mostrartabuleirosanteriores(CTabuleiro *tabuleiros,int nj){
  for(int i=0;i<nj;i++){
    tabuleiros[i].mostrartabuleiro();
  }
}
//------------------------------------------------------------
void mostrarestatisticas(CUtilizador utilizador){
  cout<<utilizador.vitorias<<" V / "
    <<utilizador.empates<<" E / "
    <<utilizador.derrotas<<" D "<<endl;
}
//-------------------------------------------------------
void mostrarjogador(int jogador,CUtilizador utilizador){
    if(jogador==1){
      cout<<"Jogador: Computador"<<"\t\t";
      return;
    }
    if(jogador==2){
      cout<<"Jogador: "<<utilizador.utilizador<<":"<<"\t";
      mostrarestatisticas(utilizador);
    }
}
//------------------------------------------------------
void mostrarnivel(int nivel,int jogador,CUtilizador utilizador){
    if(nivel==1){
      cout<<"Modo: Elementar"<<"\t\t";
      mostrarjogador(jogador, utilizador);
    }
    if(nivel==2){
      cout<<"Modo: Facil"<<"\t\t";
      mostrarjogador(jogador,utilizador);
    }
    if(nivel==3){
      cout<<"Modo: Medio"<<"\t\t";
      mostrarjogador(jogador,utilizador);}
    if(nivel==4){
      cout<<"Modo: Dificil"<<"\t\t";
      mostrarjogador(jogador, utilizador);
    }
}                 

void mostrarjogoentreutilizadores(int jogador,CUtilizador utilizador1,CUtilizador utilizador2){
  if(jogador==1){
    cout<<"Jogador: "<<utilizador1.utilizador<<"\t";
    mostrarestatisticas(utilizador1);
  }
  if(jogador==2){
    cout<<"Jogador: "<<utilizador2.utilizador<<"\t";
    mostrarestatisticas(utilizador2);
  }
}