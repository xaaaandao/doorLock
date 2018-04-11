#include "Rele.hpp"

using namespace std;

/**
* Autor: Alexandre Yuji Kajihara
* Descrição: implementações dos métodos que foram definidos como protótipos no arquivo Rele.hpp.
* Esses métodos estão relacionados as operações que são realizadas pelo Rele.
* Data de criação: 10/04/2018
* Data de atualização: 11/04/2018
**/

/**
* O método initializeRele(void), basicamente inicializa o Rele na porta que foi definida, que no nosso caso é a porta 2.
* @param void, não tem nenhum parâmetro.
* @return void, não retorna nada.
*/
void Rele :: initializeRele(void){
  /* Inicializa o relé */
  pinMode(LOCK_PIN, OUTPUT);
}   

/**
* O método turnOnRele(void), ativa o relé, para poder passar energia para fechadura eletrônica.
* @param void, não tem nenhum parâmetro.
* @return void, não retorna nada.
*/
void Rele :: turnOnRele(void){
  digitalWrite(LOCK_PIN, HIGH);
}   

/**
* O método turnOffRele(void), desativa o relé, e assim não passa energia para a fechadura eletrônica.
* @param void, não tem nenhum parâmetro.
* @return void, não retorna nada.
*/
void Rele :: turnOffRele(void){
  digitalWrite(LOCK_PIN, LOW);
}   

