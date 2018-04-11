#include "Button.hpp"

/**
* Autor: Alexandre Yuji Kajihara
* Descrição: implementações dos métodos que foram definidos como protótipos no arquivo Button.hpp.
* Esses métodos estão relacionados as operações que são realizadas pelo botão.
* Data de criação: 10/04/2018
* Data de atualização: 11/04/2018
**/

/**
* O método initializeButton(void), basicamente inicializa o botão na porta que foi definida, que no nosso caso é a porta 3.
* @param void, não tem nenhum parâmetro.
* @return void, não retorna nada.
*/
void Button :: initializeButton(void){
  pinMode(BUTTON_PIN, INPUT);   
}

/**
* O método getValueButton(void), basicamente retorna o valor lido pelo botão.
* @param void, não tem nenhum parâmetro.
* @return digitalRead(BUTTON_PIN), que é um inteiro com o valor do botão.
*/
int Button :: getValueButton(void){
  return digitalRead(BUTTON_PIN);
}
