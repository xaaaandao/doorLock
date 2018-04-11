/* Biblioteca com operações relacionadas aos cartões */
#include "RFID.hpp"

/* Biblioteca com operações relacionadas ao LED */
#include "Led.hpp"

/* Biblioteca com operações relacionadas ao relé */
#include "Rele.hpp"

/* Biblioteca com operações relacionadas ao botão */
#include "Button.hpp"

/* Definindo as variáveis globais para evitar, de declarar várias vezes */
LED led; 
RFID rfid;
Rele rele;
Button button;

void setup(){
  /* Inicializa o RFID */
  rfid.initializeRFID();

  /* Inicializa o LED */
  led.initializeLED();

  /* Verifica se tem erro no RFID */
  while(rfid.errorRFID())
    led.blinkLED(LED_RED);

  /* Inicializa o relé */
  rele.initializeRele();

  /* Inicializa o botão */
  button.initializeButton();
}

void loop(){
  /* Fica lendo o botão */
  int buttonState = button.getValueButton();

  /* Verifica se não é novo cartão presente */
  if(!rfid.isNewCardPresent())
    return;

  /* Verifica se está lendo o cartão serial */
  if (!rfid.readCardSerial())
    return;

  /* Pega o ID do cartão RFID */
  String id = rfid.getIdCard();
  bool validCard = false;
  
  /* Verifica se o id que foi passado por parâmetro é igual ao que está no vetor ou se o botão foi presionado */
  if(rfid.cardIsValid(id) || buttonState == HIGH){

    /* Se é válido libera a porta */
    /* Ativo o relé, espero 5 segundos e depois desativo o relé */
    rele.turnOnRele();
    delay(TIMER_LOCK);           
    rele.turnOffRele();  
    
    /* Pisca o LED sinalizando que o cartão é válido */
    validCard = true;
    led.countBlinkLED(validCard);
    
  } else {
    
    /* Se não é válido, pisca o LED para mostrar que o cartão é inválido */
    led.countBlinkLED(validCard);
    
  } 

  /* Delay para não ficar lendo várias vezes */
  delay(TIMER_READ_RFID);
}
