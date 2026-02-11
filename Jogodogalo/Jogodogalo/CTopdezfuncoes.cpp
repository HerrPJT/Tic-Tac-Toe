#include "CTopdez.h"
#include <fstream>
#include <cstdlib>
CTopdez::CTopdez(){
  cabeca=nullptr;
}

CTopdez::~CTopdez(){
    CUtilizador *atual, *proximo;
    atual=cabeca;
    while (atual != nullptr){
        proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }
}
void CTopdez::adicionarjogadoreordenar(CUtilizador jogador) {
  CUtilizador *novo = new CUtilizador;
  CUtilizador *atual, *anterior;
  novo->utilizador=jogador.utilizador; 
  novo->vitorias=jogador.vitorias;  
  novo->empates=jogador.empates;
  novo->derrotas=jogador.derrotas;
  novo->proximo = nullptr;
  if(cabeca == nullptr){ 
      cabeca = novo;
      return;
  }
  atual = cabeca;
  anterior = nullptr;
  if(atual->utilizador==novo->utilizador){
    atual->vitorias=novo->vitorias;  
    atual->empates=novo->empates;
    atual->derrotas=novo->derrotas;
    delete novo;
    return;}
  while ( (atual != nullptr) && (atual->vitorias < novo->vitorias) ){	// procura a posição 
      if(atual->utilizador==novo->utilizador){
          atual->vitorias=novo->vitorias;  
          atual->empates=novo->empates;
          atual->derrotas=novo->derrotas;
          delete novo;
          return;}
      anterior = atual;					// inserção
      atual = atual->proximo;
}
  if(anterior == nullptr)	
      cabeca = novo;	
  else 
      anterior->proximo = novo;
    
  novo->proximo = atual;  				    	
}
	

void CTopdez::mostrartopdez(){   
cout<<"//////////////////////////////////////////////////////////"<<endl;
     cout<<"Top10: "<<endl;
     CUtilizador *atual = cabeca;
     int i=1;
     while ((atual != nullptr) && (i<11)){
              cout<<i<<" - ";
              cout << atual->utilizador << ", "<<"Vitorias: "<<atual->vitorias<<", "<<"Empates: "<<atual->empates<< ", "<<"Derrotas: "<<atual->derrotas<<endl;
              atual = atual->proximo;
              i++;
          }  cout<<"//////////////////////////////////////////////////////////";
cout<<endl;
}


void CTopdez::salvartopdez(){
   ofstream file("topdez.txt",ios::app); //abre o arquivo para escrever
    if(file.is_open()){ 
      CUtilizador *atual = cabeca;
        if(cabeca == nullptr){
            file.close();
            cout<<"Não existe lista para guardar"<<endl;
            return;}
        else{
            while (atual != nullptr){
                file<<atual->utilizador<<" "<<atual->vitorias<<" "<<atual->empates<<" "<<atual->derrotas<<endl;
                atual = atual->proximo;
            }
            file.close();
        }
    }
    else {
    cout <<"Erro ao abrir o arquivo top10.txt para salvar o top 10"<<endl;
    cout<<endl;
    }
}


void CTopdez::carregartopdez(){
  ifstream file("topdez.txt"); // Abrir o ficheiro para ler
    if(file.is_open()){
      string nomeutilizador;
      int vitorias, empates, derrotas;
      while (file >> nomeutilizador >> vitorias >> empates >> derrotas){
              CUtilizador jogador;
              jogador.utilizador=nomeutilizador;
              jogador.vitorias=vitorias;
              jogador.empates=empates;
              jogador.derrotas=derrotas;
              adicionarjogadoreordenar(jogador);
            }
            file.close();
      } 
    else {
      cout<<"Erro ao abrir o arquivo top10.txt para carregar o top 10"<<endl;
      cout<<endl;
    }
}
