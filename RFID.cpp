#include "RFID.hpp"

using namespace std;

/* Definindo o leitor de RFID */
MFRC522 mfrc522(SS_PIN, RST_PIN);

/**
* Autor: Alexandre Yuji Kajihara
* Descrição: implementações dos métodos que foram definidos como protótipos no arquivo Cards.hpp. Esses métodos estão relacionados as operações 
* que são realizadas pelo cartão e tag RFID.
* Data de criação: 28/02/2018
* Data de atualização: 28/02/2018
**/

void RFID :: initializeRFID(){
  /* Inicializa o RFID */
  mfrc522.PCD_Init();
}   

bool RFID :: isNewCardPresent(){
  return mfrc522.PICC_IsNewCardPresent();
}

bool RFID :: readCardSerial(){
  return mfrc522.PICC_ReadCardSerial();
}

String RFID :: getIdCard(){
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

/* Para declarar função em C++ é necessário por o nome da classe, que no caso é Cards */
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
