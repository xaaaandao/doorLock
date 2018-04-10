#include "LED.hpp"

/**
* Autor: Alexandre Yuji Kajihara
* Descrição: implementações dos métodos que foram definidos como protótipos no arquivo Led.hpp. Esses métodos estão relacionados as operações 
* que são realizadas pelo LED.
* Data de criação: 02/03/2018
* Data de atualização: 02/03/2018
**/

/**
* O método initializeLED(void), basicamente inicializa o LED na porta que foi definida, que no nosso caso é a porta 7.
* @param void, não tem nenhum parâmetro.
* @return void, não retorna nada.
*/
void LED :: initializeLED(void){
	pinMode(LED_RED, OUTPUT);  	
  pinMode(LED_GREEN, OUTPUT);   
}

/**
* O método onLED(void), basicamente liga o LED na porta que foi definida, que no nosso caso é a porta 7.
* @param pinLed, que é um inteiro e recebe como parâmetro o valor do pino a qual o led está ligado no arduino.
* @return void, não retorna nada.
*/
void LED :: onLED(int pinLed){
	digitalWrite(pinLed, HIGH);
	delay(DELAYLED);
}

/**
* O método offLED(void), basicamente desliga o LED na porta que foi definida, que no nosso caso é a porta 7.
* @param pinLed, que é um inteiro e recebe como parâmetro o valor do pino a qual o led está ligado no arduino.
* @return void, não retorna nada.
*/
void LED :: offLED(int pinLed){
	digitalWrite(pinLed, LOW);
	delay(DELAYLED);
}

/**
* O método blinkLED(void), basicamente chama as funções de ligar e desligar o LED, para que o mesmo fique piscando.
* @param pinLed, que é um inteiro e recebe como parâmetro o valor do pino a qual o led está ligado no arduino.
* @return void, não retorna nada.
*/
void LED :: blinkLED(int pinLed){
  LED :: onLED(pinLed);
  LED :: offLED(pinLed);
}

/**
* O método countBlinkLED(int countBlink), basicamente chama a função de piscar o LED, baseado na quantidade de vezes que foi passado por parâmetro.
* @param valid, que é um booleano e recebe como parâmetro verdadeiro caso o cartão seja válido e caso contrário falso.
* @return void, não retorna nada.
*/
void LED :: countBlinkLED(bool valid){
  /* 4, porque o led indica que o cartão é inválido está na porta 4 */
  int pinLed = 4;
  for (int i = 0; i < BLINKLED; i++){
    /* 5, porque o led indica que o cartão válido e está na porta 4 */
    if(valid)
      pinLed = 5;
    LED :: blinkLED(pinLed);
  }
}

/**
* O método errorRFID(void), verifica se existe algum erro no RFID, caso exista retorna true e false caso não exista.
* @param countBlink, que é um inteiro com a quantidade de vezes que o LED irá piscar.
* @return true ou false, true quando existe algum erro no RFID e false quando não existe erro.
*/
bool LED :: errorRFID(void){
  /* Para acessar um enum de um classe */
  MFRC522::PCD_Register version = MFRC522::PCD_Register::VersionReg;
  MFRC522 mfrc522;
  byte v = mfrc522.PCD_ReadRegister(version);
  if ((v == 0x00) || (v == 0xFF))
    return true;
  return false;
}  
