#include "CJogo.h"
#include <string>
#include <iostream>
#include <fstream>
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void CJogo::salvar_jogo(const string &nome_arquivo,CTabuleiro tabuleiro,int nivel,CUtilizador utilizador, int numerojogada){
  ofstream arquivo(nome_arquivo); //abre o arquivo para escrever
  if(arquivo.is_open()){
    for(int i=0;i<espacos;++i){
      if (tabuleiro.tabuleiro[i]==' '){
        arquivo <<'s'<<" ";
      }
      else{
      arquivo <<tabuleiro.tabuleiro[i]<<" ";
      }
    }
    arquivo << endl;
    arquivo<<nivel<<" ";
    arquivo<<numerojogada << " ";
    arquivo<<utilizador.nome_utilizador();
  arquivo.close();
  } else {

    cout<<"Jogo salvo com sucessso ! "<<nome_arquivo<<endl;
  cout <<"Erro ao abrir o arquivo"<<nome_arquivo<<"para salvar o jogo"<<endl;
  return;
  }
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void CJogo::carregar_jogo(const string &nome_arquivo, CTabuleiro &tabuleiro,int &nivel,CUtilizador &utilizador, int &numerojogada){
  ifstream arquivo(nome_arquivo); // Abrir o ficheiro para ler
  string linha_temporaria;
  if(arquivo.is_open()){
    getline(arquivo,linha_temporaria);
    int tamanho_linha=linha_temporaria.size();
    for (int i=0;i<9;i++){
      if (i<tamanho_linha){
          if(linha_temporaria[i]== 's'){
            tabuleiro.tabuleiro[i]=' ';
          }
      else{
            tabuleiro.tabuleiro[i]=linha_temporaria[i];
      }
     
      }else{
      tabuleiro.tabuleiro[i]=' ';}
    }
    arquivo>>nivel>>numerojogada;
    string nome_utilizador;
    arquivo >> nome_utilizador;
    
    utilizador.set_nome_utilizador(nome_utilizador);
    arquivo.close();
    cout<< "Jogo carregado com sucesso !"<<endl;
    tabuleiro.mostrartabuleiro();
    cout <<"Nivel de jogo carregado: "<< nivel<<endl;
    cout <<"numero de jogadas carregado: "<<numerojogada<<endl;
      cout <<"Nome do jogador carregado: "    
       <<utilizador.nome_utilizador()<<endl;}
      
   else{
    cout<<"Erro ao abrir o arquivo para carregar o jogo ! "<<endl;
    return;}
  
  }

//-----------------------------------------------------------------------------------------------------------------------------
void CJogo::salvar_jogo_mododificil(CTabuleiro &tab1,int &recompensa0,int &recompensa1){
  ofstream arquivo("dados.txt",ios::app); //abre o arquivo para escrever
  if(arquivo.is_open()){
    for(int i=0;i<espacos;++i){
      if (tab1.tabuleiro[i]==' '){
        arquivo <<'s';
      }
      else{
      arquivo <<tab1.tabuleiro[i];
      }
    }
    arquivo << endl;
    arquivo<<recompensa0<<" ";
    arquivo<< endl;
    arquivo<<recompensa1<<" ";
  arquivo.close();
  } else {
  return;
  }
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
bool CJogo::carregar_jogo_mododificil(CTabuleiro &tabuleiro1,CTabuleiro &tab,int &recompensa0,int &recompensa1){
  ifstream arquivo("dados.txt"); // Abrir o ficheiro para ler
  string linha_temporaria;
  bool jogo_encontrado=false;
  if(arquivo.is_open()){
    while(getline(arquivo,linha_temporaria)){
          CTabuleiro tabuleiro_temp;
      
              //Carrega o tabuleiro do arquivo
              for (int i=0;i<9;i++){
                if(i<linha_temporaria.size()){
                  if(linha_temporaria[i]== 's'){
                  tabuleiro_temp.tabuleiro[i]=' ';
                 } else {
                  tabuleiro_temp.tabuleiro[i]=linha_temporaria[i];
                }  
           
                }  
              }
              int recompensa0_temp=0,recompensa1_temp=0;
              arquivo>> recompensa0_temp;
              arquivo>>recompensa1_temp;
            if(comparar_jogos_mododificil(tab,tabuleiro_temp)){
              tabuleiro1=tabuleiro_temp;
              recompensa0=recompensa0_temp;
              recompensa1=recompensa1_temp;
              jogo_encontrado=true;
              break; //sai do loop apos encontrar o jogo desejado;
            }
      arquivo.ignore();
    }
    
          arquivo.close();
  }else{
      cout<<"Erro ao abrir o ficheiro."<<endl;
      
    }
    return jogo_encontrado;
}

 //---------------------------------------------------------------------------------------------------------------------------------------------------------

bool CJogo::comparar_jogos_mododificil(CTabuleiro &tabuleiro1,CTabuleiro &tabuleiro2){
  for (int i=0;i < espacos;i++){
     if (tabuleiro1.tabuleiro[i] != ' '){
       if (tabuleiro1.tabuleiro[i] != tabuleiro2.tabuleiro[i]){
         return false;
       }
     }
  }

      return true;
}
 
//------------------------------------------------------------------------------------------------------------------------

void CJogo::verificar_se_existe(CTabuleiro &tab1,int &recompensa0,int &recompensa1){
  ifstream arquivo("dados.txt"); // Abrir o ficheiro para ler
  string linha_temporaria;
  bool jogo_igual=false;
  if(arquivo.is_open()){
    while(getline(arquivo,linha_temporaria)){
          CTabuleiro tabuleiro_temp;

              //Carrega o tabuleiro do arquivo
              for (int i=0;i<9;i++){
                if(i<linha_temporaria.size()){
                  if(linha_temporaria[i]== 's'){
                  tabuleiro_temp.tabuleiro[i]=' ';
                 } else {
                  tabuleiro_temp.tabuleiro[i]=linha_temporaria[i];
                }  

                }  
              }
              int recompensa0_temp=0,recompensa1_temp=0;
              arquivo>> recompensa0_temp;
              arquivo>>recompensa1_temp;
            if(comparar_jogos_iguais(tab1,tabuleiro_temp)==true){
              jogo_igual=true;
              break; //sai do loop apos encontrar o jogo desejado;
            }else if (!comparar_jogos_iguais(tab1,tabuleiro_temp)){
               break;
            }
            arquivo.ignore();
              
    }
        arquivo.close();
  }else{
      cout<<"Erro ao abrir o ficheiro."<<endl;
      return;
  }
  if(!jogo_igual){
    salvar_jogo_mododificil(tab1,recompensa0,recompensa1);
  }
}


//------------------------------------------------------------------------------------------------------------------------

bool CJogo::comparar_jogos_iguais(CTabuleiro &tabuleiro1,CTabuleiro &tabuleiro2){
  for (int i=0;i < espacos;i++){
       if (tabuleiro1.tabuleiro[i] != tabuleiro2.tabuleiro[i]){
         return false;
       }
     
  }

      return true;
}


//------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------

void CJogo::verificar_se_existe2(CTabuleiro &tab1,int &recompensa0,int &recompensa1){
  ifstream arquivo("dados2.txt"); // Abrir o ficheiro para ler
  string linha_temporaria;
  bool jogo_igual=false;
  if(arquivo.is_open()){
    while(getline(arquivo,linha_temporaria)){
          CTabuleiro tabuleiro_temp;

              //Carrega o tabuleiro do arquivo
              for (int i=0;i<9;i++){
                if(i<linha_temporaria.size()){
                  if(linha_temporaria[i]== 's'){
                  tabuleiro_temp.tabuleiro[i]=' ';
                 } else {
                  tabuleiro_temp.tabuleiro[i]=linha_temporaria[i];
                }  

                }  
              }
              int recompensa0_temp=0,recompensa1_temp=0;
              arquivo>> recompensa0_temp;
              arquivo>>recompensa1_temp;
            if(comparar_jogos_iguais2(tab1,tabuleiro_temp)==true){
              jogo_igual=true;
              break; //sai do loop apos encontrar o jogo desejado;
            }else if (!comparar_jogos_iguais2(tab1,tabuleiro_temp)){
               break;
            }
            arquivo.ignore();

    }
        arquivo.close();
  }else{
      cout<<"Erro ao abrir o ficheiro."<<endl;
      return;
  }
  if(!jogo_igual){
    salvar_jogo_mododificil2(tab1,recompensa0,recompensa1);
  }
}


//------------------------------------------------------------------------------------------------------------------------

bool CJogo::comparar_jogos_iguais2(CTabuleiro &tabuleiro1,CTabuleiro &tabuleiro2){
  for (int i=0;i < espacos;i++){
       if (tabuleiro1.tabuleiro[i] != tabuleiro2.tabuleiro[i]){
         return false;
       }

  }

      return true;
}
//------------------------------------------------------------------------------------------------------------------------

void CJogo::salvar_jogo_mododificil2(CTabuleiro &tab1,int &recompensa0,int &recompensa1){
  ofstream arquivo("dados2.txt",ios::app); //abre o arquivo para escrever
  if(arquivo.is_open()){
    for(int i=0;i<espacos;++i){
      if (tab1.tabuleiro[i]==' '){
        arquivo <<'s';
      }
      else{
      arquivo <<tab1.tabuleiro[i];
      }
    }
    arquivo << endl;
    arquivo<<recompensa0<<" ";
    arquivo<< endl;
    arquivo<<recompensa1<<" ";
  arquivo.close();
  } else {
  return;
  }
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
bool CJogo::carregar_jogo_mododificil2(CTabuleiro &tabuleiro1,CTabuleiro &tab,int &recompensa0,int &recompensa1){
  ifstream arquivo("dados2.txt"); // Abrir o ficheiro para ler
  string linha_temporaria;
  bool jogo_encontrado=false;
  if(arquivo.is_open()){
    while(getline(arquivo,linha_temporaria)){
          CTabuleiro tabuleiro_temp;

              //Carrega o tabuleiro do arquivo
              for (int i=0;i<9;i++){
                if(i<linha_temporaria.size()){
                  if(linha_temporaria[i]== 's'){
                  tabuleiro_temp.tabuleiro[i]=' ';
                 } else {
                  tabuleiro_temp.tabuleiro[i]=linha_temporaria[i];
                }  

                }  
              }
              int recompensa0_temp=0,recompensa1_temp=0;
              arquivo>> recompensa0_temp;
              arquivo>>recompensa1_temp;
            if(comparar_jogos_mododificil2(tab,tabuleiro_temp)){
              tabuleiro1=tabuleiro_temp;
              recompensa0=recompensa0_temp;
              recompensa1=recompensa1_temp;
              jogo_encontrado=true;
              break; //sai do loop apos encontrar o jogo desejado;
            }
      arquivo.ignore();
    }

          arquivo.close();
  }else{
      cout<<"Erro ao abrir o ficheiro."<<endl;

    }
    return jogo_encontrado;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
bool CJogo::comparar_jogos_mododificil2(CTabuleiro &tabuleiro1,CTabuleiro &tabuleiro2){
  for (int i=0;i < espacos;i++){
     if (tabuleiro1.tabuleiro[i] != ' '){
       if (tabuleiro1.tabuleiro[i] != tabuleiro2.tabuleiro[i]){
         return false;
       }
     }
  }

      return true;
}