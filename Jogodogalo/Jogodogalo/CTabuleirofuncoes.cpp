#include "CTabuleiro.h"
#include <fstream>
/*
  1   |  2     | 3                0   |  1     | 2            
----------------------          ----------------------
  4   |  5     |  6               3   |  4     |  5
----------------------          ----------------------
  7   |  8     | 9                6   |  7     | 8 

*/
CTabuleiro::CTabuleiro(){
  for(int i=0;i<espacos;i++){
      tabuleiro[i]=' ';
  }
}

void CTabuleiro::mostrartabuleiro(){
  cout<<endl;
  cout<<" \t\t "<<tabuleiro[0]<<"  |  "<<tabuleiro[1]<<    
  "  |  "<<tabuleiro[2]<<" "<<endl; 
  cout<<"\t\t"<<"-------------------"<<endl;
  cout<<" \t\t "<<tabuleiro[3]<<"  |  "<<tabuleiro[4]<<    
  "  |  " <<tabuleiro[5]<<" "<<endl;
  cout<<"\t\t"<<"-------------------"<<endl;
  cout<<" \t\t "<< tabuleiro[6]<<"  |  "<<tabuleiro[7]<<   
  "  |  " <<tabuleiro[8]<<" "<<endl;
  cout<<endl;
}

 bool CTabuleiro::vencedor(){
   if((tabuleiro[0]==tabuleiro[1] && tabuleiro[1]==tabuleiro[2] &&         tabuleiro[0]!=' ')  || 
      (tabuleiro[3]==tabuleiro[4] && tabuleiro[4]==tabuleiro[5] &&  
       tabuleiro[3]!=' ')  ||    
      (tabuleiro[6]==tabuleiro[7] && tabuleiro[7]==tabuleiro[8]            && tabuleiro[6]!=' ') ){
        return true;}
     
  if((tabuleiro[0]==tabuleiro[3] && tabuleiro[3]==tabuleiro[6] && 
      tabuleiro[0]!=' ')  ||
    (tabuleiro[1]==tabuleiro[4] && tabuleiro[4]==tabuleiro[7] &&         tabuleiro[1]!=' ')   ||
    (tabuleiro[2]==tabuleiro[5] && tabuleiro[5]==tabuleiro[8] && 
     tabuleiro[2]!=' ') ){
          return true;}
       
  if((tabuleiro[0]==tabuleiro[4] && tabuleiro[4]==tabuleiro[8] &&         tabuleiro[0]!=' ')  ||
    (tabuleiro[2]==tabuleiro[4] && tabuleiro[4]==tabuleiro[6] &&         tabuleiro[2]!=' ') ){
          return true;}
  
      return false;
     }





bool CTabuleiro::acabarjogo(){
  if(vencedor()==true)
    return true;
  else
    return false;
}
CTabuleiro CTabuleiro::copiartabuleiro(){  // copia o tabuleiro
  CTabuleiro copia;
  for(int i=0;i < espacos; ++i){
    copia.tabuleiro[i] = tabuleiro [i];
  }
  return copia;
}
