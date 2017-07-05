/* *****************************************************************************************************************
 *  Esse Exemplo demonsta o envio e valores a Portas de saidas com 74HC595.                                        *
 *  Será enviado as portas os valores crescentes, que serão escritos pela função                                   *
 *  escreveport(Porta, valor de 0 a 255).                                                                          *
 *******************************************************************************************************************
 *  This example demonstrates sending and values ​​to Output ports with 74HC595.                                     *
 *  The ports will be sent increasing values, which will be written by the function                                *
 *  escreveport(Port, value from 0 to 255).                                                                        *
 ******************************************************************************************************************* 
 *    Engenheiro Lucas de Oliveira Santana.                                                                        *
 *   04/07/2017                                                                                                    *
********************************************************************************************************************/


#include <Saidas.h>

int crescente =  0;
void setup() {
  
  confPinosOut(16, 2, 5, 6);
  
}

void loop() {
 escreveport(0, crescente);
 escreveport(1, crescente);
 if(crescente > 254)
 {crescente =0;}
 else{
 crescente++;
 }
 delay(300);
 
}
