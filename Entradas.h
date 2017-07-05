/*
			
				Entradas.h

			
			Multi I/O utilizando 74HC165
			Disponibilidade de portas de entradas sem valor definido, recomenda-se até 64 portas (8 CIs).
			Eng. Lucas Santana
			
			Criação 02/07/2017
			
			Ultima Atualização:05/07/2017 
			
			The MIT License (MIT)
			Copyright (c) 2017 Lucas de Oliveira Santana
			the Software without restriction, including without limitation the rights to
			use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
			the Software.

*/


#ifndef Entradas_h
#define Entradas_h


#include "Arduino.h"

void confPinosIn(int Num_pinos,  int CLK, int latch, int in);
int LeEntrada(int pin);
int PortEntrada(int port);

int _CLK;
int _Latch;
int _Entrada;
int _Num_pinos1;



#endif
void confPinosIn(int Num_pinos, int CLK, int latch, int in)
{
	_CLK = CLK;
	_Latch = latch;
	_Entrada = in;
	pinMode(_CLK , OUTPUT);
	pinMode(_Latch , OUTPUT);
	pinMode(_Entrada , INPUT);
	digitalWrite(_CLK, LOW);
	digitalWrite(_Latch, LOW);

	_Num_pinos1 = Num_pinos;
}

int LeEntrada(int pin)
{
	char dados[_Num_pinos1];
	
	digitalWrite(_Latch, HIGH);
	for (int ab = 0; ab < _Num_pinos1; ab++)
	{delayMicroseconds(1);

    dados[ab] = digitalRead(_Entrada);
    digitalWrite(_CLK, HIGH);
    delayMicroseconds(1);
    digitalWrite(_CLK, LOW);
	}
	digitalWrite(_Latch, LOW);
	if (dados[pin])
  {
    return (1);
  } else
  {
    return (0);
  }
	
}

int PortEntrada(int port)
{
	char dados[_Num_pinos1];
	int inicio;
	int retornar= 0;
	digitalWrite(_Latch, HIGH);
	for (int ab = 0; ab < _Num_pinos1; ab++)
	{delayMicroseconds(1);

    dados[ab] = digitalRead(_Entrada);
    digitalWrite(_CLK, HIGH);
    delayMicroseconds(1);
    digitalWrite(_CLK, LOW);
	}
	digitalWrite(_Latch, LOW);
	inicio = 8*port;
	int mult = 1;
	for (int ah = inicio; ah < (inicio+8); ah++)
	{
		retornar = retornar + (dados[ah]*mult);
		mult = mult*2;
	}
	return (retornar);
}