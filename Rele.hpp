#ifndef RELE_H
#define RELE_H

/**
* Autor: Alexandre Yuji Kajihara
* Descrição: definição de alguns valores necessários para se utilizar o relé,
* a inclusão de biblioteca, para poder utilizar o pinMode, etc. e os protótipos dos métodos.
* Data de criação: 10/04/2018
* Data de atualização: 11/04/2018
**/

/* 
  Arduino sketches não suporta nenhuma biblioteca padrão do C++, então usar Arduino.h 
  https://stackoverflow.com/questions/10612385/strings-in-c-class-file-for-arduino-not-compiling
*/
#include <Arduino.h>

/* Define relacionada a trava */
#define LOCK_PIN 2
#define TIMER_LOCK 5000

class Rele{
	public:
    /* Protótipo dos métodos */
    void initializeRele(void);
    void turnOnRele(void);
    void turnOffRele(void);
};

#endif /* RELE_H */
