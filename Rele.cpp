#include "Rele.hpp"

using namespace std;

/**
* Autor: Alexandre Yuji Kajihara
* Descrição: 
* Data de criação: 28/02/2018
* Data de atualização: 28/02/2018
**/

void Rele :: initializeRele(){
  /* Inicializa o relé */
  pinMode(LOCK_PIN, OUTPUT);
}   

void Rele :: turnOnRele(){
  digitalWrite(LOCK_PIN, HIGH);
}   

void Rele :: turnOffRele(){
  digitalWrite(LOCK_PIN, LOW);
}   

