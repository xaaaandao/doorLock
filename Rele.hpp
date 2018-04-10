#ifndef RELE_H
#define RELE_H

/**
* Autor: Alexandre Yuji Kajihara
* Descrição: 
* Data de criação: 02/03/2018
* Data de atualização: 02/03/2018
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
    void initializeRele();
    void turnOnRele();
    void turnOffRele();
};

#endif /* RELE_H */
