#ifndef BUTTON_H
#define BUTTON_H

/**
* Autor: Alexandre Yuji Kajihara
* Descrição: 
* Data de criação: 02/03/2018
* Data de atualização: 02/03/2018
**/

#include <Arduino.h>

/* Definindo relacionado a botão */
#define BUTTON_PIN 3

class Button{
	public:
    /* Protótipo dos métodos */
    void initializeButton(void);
    int getValueButton(void);
};

#endif /* BUTTOn_H */
