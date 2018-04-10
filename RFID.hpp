#ifndef CARDS_H
#define CARDS_H

/**
* Autor: Alexandre Yuji Kajihara
* Descrição: biblioteca relacionadas as operações dos cartões RFID, com os protótipos dos métodos que estão no arquivo Cards.cpp.
* Além disso, contém a inclusão de outras bibliotecas, como o Arduino.h que permite utilizar variáveis do tipo String.
* Já a biblioteca, WString.h permite utilizar operações para manipular as Strings, como comparar duas strings, transformar as letras
* minúscula em maiúscula, pegar uma substring dentro de uma string e o tamanho da string.
* Data de criação: 28/02/2018
* Data de atualização: 28/02/2018
**/

/* 
	Arduino sketches não suporta nenhuma biblioteca padrão do C++, então usar Arduino.h 
	https://stackoverflow.com/questions/10612385/strings-in-c-class-file-for-arduino-not-compiling
*/
#include <Arduino.h>

/*
	Para poder utilizar o método compareTo(), toUpperCase(), substring() e length() é necessário adicionar a biblioteca abaixo
	http://forum.arduino.cc/index.php?topic=294419.0
*/
#include <WString.h>

/* Biblioteca relacionada ao leitor RFID */
#include <MFRC522.h>

/* Define relacionada ao RFID */
#define RST_PIN 9
#define SS_PIN 10
#define TIMER_READ_RFID 3000

class RFID{
	public:
    /* Protótipo dos métodos */
    void initializeRFID();
    bool isNewCardPresent();
    bool readCardSerial();
    String getIdCard();
		bool cardIsValid(String currentCardId);
};

#endif /* CARDS_H */
