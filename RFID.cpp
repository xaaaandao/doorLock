#include "RFID.hpp"

using namespace std;

/* Definindo o leitor de RFID */
MFRC522 mfrc522(SS_PIN, RST_PIN);

/**
* Autor: Alexandre Yuji Kajihara
* Descrição: implementações dos métodos que foram definidos como protótipos no arquivo RFID.hpp.
* Esses métodos estão relacionados as operações que são realizadas pelo cartão, as tags e o leitor de RFID.
* Data de criação: 10/04/2018
* Data de atualização: 11/04/2018
**/

/**
* O método initializeRFID(void), basicamente inicializa o leitor de RFID na porta que foi definida.
* @param void, não tem nenhum parâmetro.
* @return void, não retorna nada.
*/
void RFID :: initializeRFID(void){
  /* Inicializa o RFID */
  mfrc522.PCD_Init();
}   

/**
* O método isNewCardPresent(void), basicamente verifica se é ou não um novo cartão presente.
* @param void, não tem nenhum parâmetro.
* @return mfrc522.PICC_IsNewCardPresent(), que é true caso seja um novo cartão presente ou false se não for um novo cartão.
*/
bool RFID :: isNewCardPresent(void){
  return mfrc522.PICC_IsNewCardPresent();
}

/**
* O método readCardSerial(void), basicamente verifica se está ou não lendo um cartão serial.
* @param void, não tem nenhum parâmetro.
* @return mfrc522.readCardSerial(), que é true caso esteja lendo um cartão na serial ou false caso não esteja lendo um cartão.
*/
bool RFID :: readCardSerial(void){
  return mfrc522.PICC_ReadCardSerial();
}

/**
* O método getIdCard(void), retorna em uma string o ID do cartão que foi lido pelo leitor de RFID.
* @param void, não tem nenhum parâmetro.
* @return id, que é uma string com o ID do cartão.
*/
String RFID :: getIdCard(void){
  /*
    Armazenar o ID do cartão em uma String
    https://www.filipeflop.com/blog/controle-acesso-leitor-rfid-arduino/
  */
  String id = "";
  for (byte i = 0; i < mfrc522.uid.size; i++){
     id.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     id.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
 
  /* Coloco o id com letras maiuscúlas */
  id.toUpperCase();

  /* Removo o primeiro character do id que é uma espaço em branco */
  id = id.substring(1, id.length());

  return id;
}

/**
* O método cardIsValid(String currentCardId) recebe uma string, e conteúdo dela é o id do cartão ou da tag.
* Com esse parâmetro, verificamos se o id do cartão é um dos id que está presente no vetor de id do cartão e das tag's.
* Se for um desses retorna verdade, caso contrário retorna falso.
* @param currentCardId, é uma string com o id que está sendo lido pelo leitor de RFID, e verificado se é um id válido ou não.
* @return true ou false, true quando o id recebido por parâmetro é válido e false quando id não é válido.
*/

/* Para declarar função em C++ é necessário por o nome da classe, que no caso é RFID */
bool RFID :: cardIsValid(String currentCardId){
	/* Todos os id's dos cartões */
  String allCardId[] = {};/* Substituir pelo ID do cartão */
  
	/* Percorro o vetor com todos os id's dos cartões */
	for(String cardId : allCardId){
		/* Se for zero significa que o id que está sendo lido é igual ao que está no vetor, então retorna verdade */
		if(cardId.compareTo(currentCardId) == 0)
			return true;
	}

  /* Caso não encontre o id no vetor, retorna falso */
	return false;
}		

/**
* O método errorRFID(void), verifica se existe algum erro no RFID, caso exista retorna true e false caso não exista.
* @param countBlink, que é um inteiro com a quantidade de vezes que o LED irá piscar.
* @return true ou false, true quando existe algum erro no RFID e false quando não existe erro.
*/
bool RFID :: errorRFID(void){
  /* Para acessar um enum de um classe */
  MFRC522::PCD_Register version = MFRC522::PCD_Register::VersionReg;
  MFRC522 mfrc522;
  byte v = mfrc522.PCD_ReadRegister(version);
  if ((v == 0x00) || (v == 0xFF))
    return true;
  return false;
}  
