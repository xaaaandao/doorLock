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

/* Define relacionada a trava */
#define LOCK 2
#define TIMER_LOCK 5000

/* Definindo relacionado a botão */
#define BUTTON_PIN 3

MFRC522 mfrc522(SS_PIN, RST_PIN);
Led led;  /* Variável global para poder invocar os métodos dessa classe */

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
    led.blinkLED();

  /* Para o relé */
  pinMode(LOCK, OUTPUT);

  /* Inicializa o botão */
  pinMode(BUTTON_PIN, INPUT);
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
  
  /* Verifica se o id que foi passado por parâmetro é igual ao que está no vetor ou se o botão foi apertado */
  if(cards.cardIsValid(id) || buttonState == HIGH){

    /* Se tem energia libera porta */
    /* Se sim, libera a porta */
    Serial.print("É válido!!!\n");

    /* Libero a tranca, espero 5 segundos e fecha depois */
    digitalWrite(LOCK, HIGH);
    delay(TIMER_LOCK);           
    digitalWrite(LOCK, LOW);

    led.countBlinkLED(CARDVALID);
    
  } else {
    /* Se não tem energia fica fechado */
    /* Caso contrário, nega acesso a porta */
    Serial.print("Não é válido!!!\n");   

    led.countBlinkLED(CARDNOTVALID);

  } 

  /* Delay para não ficar lendo várias vezes */
  delay(3000);
}
