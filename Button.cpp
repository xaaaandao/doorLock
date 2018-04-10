#include "Button.hpp"

/**
* Autor: Alexandre Yuji Kajihara
* Descrição: implementações dos métodos que foram definidos como protótipos no arquivo Led.hpp. Esses métodos estão relacionados as operações 
* que são realizadas pelo LED.
* Data de criação: 02/03/2018
* Data de atualização: 02/03/2018
**/

void Button :: initializeButton(void){
  pinMode(BUTTON_PIN, INPUT);   
}

int Button :: getValueButton(void){
  return digitalRead(BUTTON_PIN);
}
