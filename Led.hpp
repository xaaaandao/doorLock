#ifndef LED_H
#define LED_H

/**
* Autor: Alexandre Yuji Kajihara
* Descrição: biblioteca relacionada as operações do LED, com os protótipos dos métodos que estão no arquivo Led.cpp.
* Além disso, contém a inclusão de outras bibliotecas, como o Arduino.h que permite utilizar variáveis do tipo byte, e também o método de delay().
* Já a biblioteca, MFRC522.h permite utilizar descobrir se a alguem erro no RFID, através de o valor de um enum que está presente nessa classe.
* Data de criação: 02/03/2018
* Data de atualização: 02/03/2018
**/

#define LED_RED 5         /* LED que está na porta 5 */
#define LED_GREEN 4         /* LED que está na porta 4 */
#define DELAYLED 100       /* Tempo de delay do LED */
#define BLINKLED 2         /* Pisca o LED */

/* Biblioteca para uso da variável byte, delay() */
#include <Arduino.h>

/* Biblioteca para ter acesso ao enum da classe MFRC522 */
#include <MFRC522.h>

class Led{
	public:
    /* Protótipo dos métodos */
		void initializeLED(void);
    void onLED(int);
    void offLED(int);
    void blinkLED(int);
    void countBlinkLED(bool);
		bool errorRFID(void);
};

#endif /* LED_H */
