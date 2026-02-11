#include "CTabuleiro.h"
#include "CComputador.h"
#include <cstdlib> //para rand
#include <ctime> // para o tempo
/*
  1   |  2     | 3                0   |  1     | 2            
----------------------          ----------------------
  4   |  5     |  6               3   |  4     |  5
----------------------          ----------------------
  7   |  8     | 9                6   |  7     | 8 

*/

//-----------------------------------------------------------------------------------------------------------------Modo Elemetar

int gerar_jogada_aleatoria(int excluir){
  srand(time(NULL));
  int aleatorio;
  do{
  aleatorio=rand() % 9 +1;
}while(aleatorio==excluir);
  return aleatorio;
}


void CComputador::introduzirDificuldade(CTabuleiro &tab,int nivel){
  nivelDificuldade = nivel;
  if(nivelDificuldade==1){
        modoelementar(tab);
      }
  else if (nivelDificuldade==2){
        modofacil(tab);
      }
  else if (nivelDificuldade==3){
        modomedio(tab);
      }
  else if(nivelDificuldade==4){
        mododificil(tab);
      }
  }

void CComputador::fazer_jogada(CTabuleiro &tab,int n){
  cout<<endl;
  cout<<endl;
  tab.tabuleiro[n-1]='0';
};


bool CTabuleiro::posicao_disponivel(int n){
  if (tabuleiro[n-1] == ' ')
    return true;
  else
    return false;
}


void CComputador::modoelementar(CTabuleiro &tab){
  int n = gerar_jogada_aleatoria(0);
  while(!tab.posicao_disponivel(n)){
    n = gerar_jogada_aleatoria(0);
  }
  fazer_jogada(tab,n);
}


//----------------------------------------------------------------------------------------------------------------------Modo Facil


void CComputador::modofacil(CTabuleiro &tab){
CTabuleiro copia= tab.copiartabuleiro();
  for (int i=0;i < espacos;++i){
    if(copia.tabuleiro[i]== ' '){
      copia.tabuleiro[i]='0';
    }
    if(copia.vencedor()){  //se verificar true na copia na vitoria                           ele faz a jogada no verdadeiro tabuleiro
      fazer_jogada(tab,i+1);
      return;                     
    }
    else{     //se não se verificar vitoria ele elimina na copia 
  copia.tabuleiro[i]=' ';   
    }
  }
  int n = gerar_jogada_aleatoria(0); // se não der vitoria ele faz                                         uma jogada aleatoria
  while(!tab.posicao_disponivel(n)){      
    n=gerar_jogada_aleatoria(0);
  }
fazer_jogada(tab,n);
}




//-----------------------------------------------------------------------------------------------------------------------Modo Médio




void CComputador::modomedio(CTabuleiro &tab){
  CJogo jogo;
  CTabuleiro copia= tab.copiartabuleiro();
    for (int i=0;i<espacos;++i){
      if(copia.tabuleiro[i]== ' '){
        copia.tabuleiro[i]='0';        // ele faz a jogada 0 na copia
      
        if(copia.vencedor()){           //se verificar true na copia na vitoria ele faz a jogada no verdadeiro tabuleiro
        fazer_jogada(tab,i+1);
        return;                     
        }
        else{                          //se não se verificar vitoria ele elimina na copia 
             copia.tabuleiro[i]=' ';   
        }
      }  
        
      
    }
  
  for (int i=0;i<espacos;++i){
    if(copia.tabuleiro[i]== ' '){
      copia.tabuleiro[i]='X';          // ele faz a jogada X na copia
    
      if(copia.vencedor()){           //se verificar true na copia na vitoria em que ele jogou X ele faz a jogada 0 no verdadeiro tabuleiro
      fazer_jogada(tab,i+1);
      return;                     
      }
      else{                          //se não se verificar vitoria ele elimina na copia 
  copia.tabuleiro[i]=' ';   
      }
    }
    
  }
    int n = gerar_jogada_aleatoria(0);        // se não der vitoria nem conseguir cortar ele faz uma jogada aleatoria
    while(!tab.posicao_disponivel(n)){      
      n=gerar_jogada_aleatoria(0);
    }
  fazer_jogada(tab,n);
  }
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void CComputador::mododificil(CTabuleiro &tab){
  CJogo jogo;
  int recompensa_vitoria=0;
  int recompensa_derrota=0;
  CTabuleiro copia= tab.copiartabuleiro();
  int jogada=0;
  bool movimento_disponivel=false;
  bool jogo_encontrado;
  int jogada_tab=0;

  for(int i=0;i<espacos;++i){
    if(copia.tabuleiro[i]==' '){
      movimento_disponivel=true;
      break;
    }
  }
    if(!movimento_disponivel){
      return;
    }
  for (int i=0;i<espacos;++i){
    if(copia.tabuleiro[i]== ' '){
      copia.tabuleiro[i]='0';
      if(copia.vencedor()){
        fazer_jogada(tab,i+1);
        return;
      }
      else{
        copia.tabuleiro[i]=' ';
      }
    }
  }
  for (int i=0;i<espacos;++i){
    if(copia.tabuleiro[i]== ' '){
      copia.tabuleiro[i]='X';
      if(copia.vencedor()){
        fazer_jogada(tab,i+1);
        return;
      }
      else{
        copia.tabuleiro[i]=' ';
      }
    }
  }
CTabuleiro tabuleiroteste;
jogada=0;  jogo_encontrado=jogo.carregar_jogo_mododificil(tabuleiroteste,tab,recompensa_vitoria,recompensa_derrota);
if(jogo_encontrado==true){
  for(int i =0;i<espacos;++i){
    while(jogada==0){
      if(copia.tabuleiro[i]== ' ' && tabuleiroteste.tabuleiro[i]== '0'){
            if (recompensa_vitoria == 1 && recompensa_derrota == 0){
            jogada_tab = i + 1;
            jogada = 1;
            } else if (recompensa_vitoria == 0 && recompensa_derrota == 1){
            copia.tabuleiro[i] = tabuleiroteste.tabuleiro[i];
            int j = gerar_jogada_aleatoria(i);
            jogada_tab = j ;
            jogada = 1;
  
          }
      }
      break;
    }
    fazer_jogada(tab,jogada_tab);
    
  }
  return;
}
    int n=gerar_jogada_aleatoria(0);
    while(!tab.posicao_disponivel(n)){
      n=gerar_jogada_aleatoria(0);
    }
    fazer_jogada(tab,n);
  }

//----------------------------------------------------
//-----------------------------------------------------
//-----------------------------------------------------
//---------------------------------------------------
//---------------------------------------------------
//---------------------------------------------------
//------------------------------------------------------

void CComputador::introduzirDificuldade2(CTabuleiro &tab,int nivel){
  nivelDificuldade = nivel;
  if(nivelDificuldade==1){
        modoelementar2(tab);
      }
  else if (nivelDificuldade==2){
        modofacil2(tab);
      }
  else if (nivelDificuldade==3){
        modomedio2(tab);
      }
  else if(nivelDificuldade==4){
        mododificil2(tab);
      }
  }

void CComputador::fazer_jogada2(CTabuleiro &tab,int n){
  cout<<endl;
  cout<<endl;
  tab.tabuleiro[n-1]='X';
};




void CComputador::modoelementar2(CTabuleiro &tab){
  int n = gerar_jogada_aleatoria(0);
  while(!tab.posicao_disponivel(n)){
    n = gerar_jogada_aleatoria(0);
  }
  fazer_jogada(tab,n);
}


//----------------------------------------------------------------------------------------------------------------------Modo Facil


void CComputador::modofacil2(CTabuleiro &tab){
CTabuleiro copia= tab.copiartabuleiro();
  for (int i=0;i < espacos;++i){
    if(copia.tabuleiro[i]== ' '){
      copia.tabuleiro[i]='X';
    }
    if(copia.vencedor()){  //se verificar true na copia na vitoria                           ele faz a jogada no verdadeiro tabuleiro
      fazer_jogada(tab,i+1);
      return;                     
    }
    else{     //se não se verificar vitoria ele elimina na copia 
  copia.tabuleiro[i]=' ';   
    }
  }
  int n = gerar_jogada_aleatoria(0); // se não der vitoria ele faz                                         uma jogada aleatoria
  while(!tab.posicao_disponivel(n)){      
    n=gerar_jogada_aleatoria(0);
  }
fazer_jogada(tab,n);
}




//-----------------------------------------------------------------------------------------------------------------------Modo Médio




void CComputador::modomedio2(CTabuleiro &tab){
  CJogo jogo;
  CTabuleiro copia= tab.copiartabuleiro();
    for (int i=0;i<espacos;++i){
      if(copia.tabuleiro[i]== ' '){
        copia.tabuleiro[i]='X';        // ele faz a jogada 0 na copia

        if(copia.vencedor()){           //se verificar true na copia na vitoria ele faz a jogada no verdadeiro tabuleiro
        fazer_jogada2(tab,i+1);
        return;                     
        }
        else{                          //se não se verificar vitoria ele elimina na copia 
             copia.tabuleiro[i]=' ';   
        }
      }  


    }

  for (int i=0;i<espacos;++i){
    if(copia.tabuleiro[i]== ' '){
      copia.tabuleiro[i]='0';          // ele faz a jogada X na copia

      if(copia.vencedor()){           //se verificar true na copia na vitoria em que ele jogou X ele faz a jogada 0 no verdadeiro tabuleiro
      fazer_jogada2(tab,i+1);
      return;                     
      }
      else{                          //se não se verificar vitoria ele elimina na copia 
  copia.tabuleiro[i]=' ';   
      }
    }

  }
    int n = gerar_jogada_aleatoria(0);        // se não der vitoria nem conseguir cortar ele faz uma jogada aleatoria
    while(!tab.posicao_disponivel(n)){      
      n=gerar_jogada_aleatoria(0);
    }
  fazer_jogada2(tab,n);
  }
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void CComputador::mododificil2(CTabuleiro &tab){
  CJogo jogo;
  int recompensa_vitoria=0;
  int recompensa_derrota=0;
  CTabuleiro copia= tab.copiartabuleiro();
  int jogada=0;
  bool movimento_disponivel=false;
  bool jogo_encontrado;
  int jogada_tab=0;

  for(int i=0;i<espacos;++i){
    if(copia.tabuleiro[i]==' '){
      movimento_disponivel=true;
      break;
    }
  }
    if(!movimento_disponivel){
      return;
    }
  for (int i=0;i<espacos;++i){
    if(copia.tabuleiro[i]== ' '){
      copia.tabuleiro[i]='X';
      if(copia.vencedor()){
        fazer_jogada2(tab,i+1);
        return;
      }
      else{
        copia.tabuleiro[i]=' ';
      }
    }
  }
  for (int i=0;i<espacos;++i){
    if(copia.tabuleiro[i]== ' '){
      copia.tabuleiro[i]='0';
      if(copia.vencedor()){
        fazer_jogada2(tab,i+1);
        return;
      }
      else{
        copia.tabuleiro[i]=' ';
      }
    }
  }
CTabuleiro tabuleiroteste;
jogada=0;  jogo_encontrado=jogo.carregar_jogo_mododificil(tabuleiroteste,tab,recompensa_vitoria,recompensa_derrota);
if(jogo_encontrado==true){
  for(int i =0;i<espacos;++i){
    while(jogada==0){
      if(copia.tabuleiro[i]== ' ' && tabuleiroteste.tabuleiro[i]== '0'){
            if (recompensa_vitoria == 1 && recompensa_derrota == 0){
            jogada_tab = i + 1;
            jogada = 1;
            } else if (recompensa_vitoria == 0 && recompensa_derrota == 1){
            copia.tabuleiro[i] = tabuleiroteste.tabuleiro[i];
            int j = gerar_jogada_aleatoria(i);
            jogada_tab = j ;
            jogada = 1;

          }
      }
      break;
    }
    fazer_jogada2(tab,jogada_tab);

  }
  return;
}
    int n=gerar_jogada_aleatoria(0);
    while(!tab.posicao_disponivel(n)){
      n=gerar_jogada_aleatoria(0);
    }
    fazer_jogada(tab,n);
  }