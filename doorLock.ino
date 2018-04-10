/* Biblioteca com operações relacionadas aos cartões */
#include "RFID.hpp"

/* Biblioteca com operações relacionadas ao LED */
#include "Led.hpp"

/* Biblioteca com operações relacionadas ao relé */
#include "Rele.hpp"

/* Biblioteca com operações relacionadas ao botão */
#include "Button.hpp"

/* Definindo o LED */
LED led; 
RFID rfid;
Rele rele;
Button button;

void setup(){
  rfid.initializeRFID();

  /* Inicializa o LED */
  led.initializeLED();

  /* Verifica se tem erro no RFID */
  while(led.errorRFID())
    led.blinkLED(LED_RED);

  rele.initializeRele();

  button.initializeButton();
}

void loop(){
  /* Fica lendo o botão */
  int buttonState = button.getValueButton();
  
  if(!rfid.isNewCardPresent())
    return;

  if (!rfid.readCardSerial())
    return;

  String id = rfid.getIdCard();
  bool validCard = false;
  
  /* Verifica se o id que foi passado por parâmetro é igual ao que está no vetor */
  if(rfid.cardIsValid(id) || buttonState == HIGH){

    /* Se tem energia libera porta */
    /* Se sim, libera a porta */
    /* Libero a tranca, espero 5 segundos e fecha depois */
    rele.turnOnRele();
    delay(TIMER_LOCK);           
    rele.turnOffRele();  

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
