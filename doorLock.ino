/* Biblioteca relacionada ao serial */
#include <SPI.h>

/* Biblioteca relacionada ao leitor RFID */
#include <MFRC522.h>

/* Biblioteca com operações relacionadas aos cartões */
#include "Cards.hpp"

/* Biblioteca com operações relacionadas ao LED */
#include "Led.hpp"

/* Define relacionada ao RFID */
#define RST_PIN 9
#define SS_PIN 10
#define TIMER_READ_RFID 3000

/* Define relacionada a trava */
#define LOCK_PIN 2
#define TIMER_LOCK 5000

MFRC522 mfrc522(SS_PIN, RST_PIN);
Led led;  /* Variável global para poder invocar os métodos dessa classe */

/* Definindo relacionado a botão */
#define BUTTON_PIN 3

void setup(){
  Serial.begin(9600);
  while (!Serial);
  SPI.begin();
  
  /* Inicializa o RFID */
  mfrc522.PCD_Init();

  /* Inicializa o LED */
  led.initializeLED();

  /* Verifica se tem erro no RFID */
  while(led.errorRFID())
    //led.blinkLED();

  /* Inicializa o relé */
  pinMode(LOCK_PIN, OUTPUT);
}

void loop(){
  int buttonState = 0;
  
  /* Fica lendo o botão */
  buttonState = digitalRead(BUTTON_PIN);
  
  if (!mfrc522.PICC_IsNewCardPresent())
    return;

  if (!mfrc522.PICC_ReadCardSerial())
    return;

  /*
    Armazenar o ID do cartão em uma String
    https://www.filipeflop.com/blog/controle-acesso-leitor-rfid-arduino/
  */
  String id = "";
  for (byte i = 0; i < mfrc522.uid.size; i++){
     id.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     id.concat(String(mfrc522.uid.uidByte[i], HEX));
  }

  /* Cria uma variável para invocar o método que verifica se o id do cartão é válido */
  Cards cards;
  
  /* Coloco o id com letras maiuscúlas */
  id.toUpperCase();

  /* Removo o primeiro character do id que é uma espaço em branco */
  id = id.substring(1, id.length());

  /* Verifico se o cartão é válido */
  bool validCard = false;
  
  /* Verifica se o id que foi passado por parâmetro é igual ao que está no vetor */
  if(cards.cardIsValid(id) || buttonState == HIGH){

    /* Se tem energia libera porta */
    /* Se sim, libera a porta */
    /* Libero a tranca, espero 5 segundos e fecha depois */
    digitalWrite(LOCK_PIN, HIGH);
    delay(TIMER_LOCK);           
    digitalWrite(LOCK_PIN, LOW);

    validCard = true;
    led.countBlinkLED(validCard);
    
  } else {
    
    /* Se não tem energia fica fechado */
    /* Caso contrário, nega acesso a porta */
    led.countBlinkLED(validCard);
    
  } 

  /* Delay para não ficar lendo várias vezes */
  delay(TIMER_READ_RFID);
}
