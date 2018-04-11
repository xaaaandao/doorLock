#ifndef BUTTON_H
#define BUTTON_H

/**
* Autor: Alexandre Yuji Kajihara
* Descrição: definição de alguns valores necessários para se utilizar o botão,
* a inclusão de biblioteca, para poder utilizar o pinMode, etc. e os protótipos dos métodos.
* Data de criação: 10/04/2018
* Data de atualização: 11/04/2018
**/

/* Biblioteca necessária para utilizar os métodos pinMode(), digitalRead() */
#include <Arduino.h>

/* Definindo valores relacionado ao botão */
#define BUTTON_PIN 3

class Button{
	public:
    /* Protótipo dos métodos */
    void initializeButton(void);
    int getValueButton(void);
};

#endif /* BUTTOn_H */
