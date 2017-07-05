/*
			
				Saidas.h

			
			Multi saidas utilizando 74HC595
			Disponibilidade de até 32 Portas de saidas (4 CIs)
			Sua numeração 0 a 31
			Eng. Lucas Santana
			
			Criação 02/07/2017
			
			Ultima Atualização:05/07/2017 
			
			The MIT License (MIT)
			Copyright (c) 2017 Lucas de Oliveira Santana
			the Software without restriction, including without limitation the rights to
			use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
			the Software.

*/


#ifndef Saidas_h
#define Saidas_h


#include "Arduino.h"

void confPinosOut(int Num_pinos,  int CLK, int latch, int Out);
void escreveSaida(int pino, int nivel);
int LeSaida (int pin);
int LePortSaida(int ports);

void escreveport(int PORTA, int Valores);

/* Para aumentar o numero de saidas, mude o numero do vetor saidas[x], e inicie com 0 todos*/
/* To increase the number of outputs, change the number of saidas [x], and start with 0 all */
char saidas [32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int Pino;
int _CLK1;
int _Latch1;
int _saida1;
int _Num_pinos;



#endif
void confPinosOut(int Num_pinos, int CLK, int latch, int Out)
{
	_CLK1 = CLK;
	_Latch1 = latch;
	_saida1 = Out;
	pinMode(_CLK1 , OUTPUT);
	pinMode(_Latch1 , OUTPUT);
	pinMode(_saida1 , OUTPUT);
	digitalWrite(_CLK1, LOW);
	digitalWrite(_Latch1, HIGH);

	_Num_pinos = Num_pinos;
}
void escreveSaida(int pino, int nivel)
{
  if(nivel)
  {
    saidas[pino]=1;
  }else
  {
    saidas[pino]=0;
  }
  digitalWrite(_Latch1, LOW);
  for (int cs = 0; cs < _Num_pinos; cs++)
  {
    digitalWrite(_saida1, saidas [cs]);
    digitalWrite(_CLK1, HIGH);
    delayMicroseconds(1);
    digitalWrite(_CLK1, LOW);
  }
  digitalWrite(_Latch1, HIGH);
}
int LeSaida (int pin)
{
	return (saidas[pin]);
}

int LePortSaida(int ports)
{
	ports = ports*8;
	int multv = 1;
	int retornarv = 0;
	
	for (int ahs = ports; ahs < (ports+8); ahs++)
	{
		retornarv = retornarv + ( saidas [ahs]*multv);
		multv = multv*2;
	}
	return (retornarv);
}

void escreveport(int PORTA, int Valores)
{
	PORTA = PORTA*8;
	for(int ash = PORTA; ash<(PORTA+8); ash++){
		saidas[ash] = Valores%2;
		Valores = Valores/2;
	}
	digitalWrite(_Latch1, LOW);
  for (int cs = 0; cs < _Num_pinos; cs++)
  {
    digitalWrite(_saida1, saidas [cs]);
    digitalWrite(_CLK1, HIGH);
    delayMicroseconds(1);
    digitalWrite(_CLK1, LOW);
  }
  digitalWrite(_Latch1, HIGH);
	
	
}
