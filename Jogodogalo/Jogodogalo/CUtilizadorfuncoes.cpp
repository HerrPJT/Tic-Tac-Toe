#include "CTabuleiro.h"
#include "CUtilizador.h"
#include "fstream"//manipulacao de arquivos
/*
  1   |  2     | 3                0   |  1     | 2            
----------------------          ----------------------
  4   |  5     |  6               3   |  4     |  5
----------------------          ----------------------
  7   |  8     | 9                6   |  7     | 8 

*/
CUtilizador::CUtilizador(){
  utilizador=" ";
  vitorias=0;
  empates=0;
  derrotas=0;
}
CUtilizador::CUtilizador(CUtilizador &jogador){
  utilizador=jogador.utilizador;
  vitorias=jogador.vitorias;
  empates=jogador.empates;
  derrotas=jogador.derrotas;
}
void CUtilizador:: set_nome_utilizador(const string& novo_nome){
  utilizador=novo_nome;
}
void CUtilizador::pedir_nome_utilizador(){
  cout<<"Insira o seu nome: ";
  string nome;
  cin>>nome;
  utilizador=nome;
}
string CUtilizador::nome_utilizador(){
  return utilizador;
}

void CUtilizador::guardar_estastisticas(){
  ofstream file(utilizador + "estatisticas.txt");
   if(file.is_open()){
    file<<vitorias<<endl;
    file<<empates<<endl;
    file<<derrotas;
    file.close();}
   else{
      cout<<"Erro ao abrir o arquivo de estatisticas ! "<<endl;
   }
}
void CUtilizador::carregar_estatisticas(){
  ifstream file(utilizador + "estatisticas.txt");
  if(file.is_open()){
  file>>vitorias;
  file>>empates;              
  file>>derrotas;
  file.close();}
  else{
     cout<<"Erro ao abrir o arquivo de estatisticas! "<<endl;}
}
