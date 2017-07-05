/*******************************************************************************************************************
     Exemplo para leitura das entradas digitais multiplexadas por 74HC165.                                         *
     Será impresso na serial a entrada e seu determinado valor.                                                    *
     Utilizado 16 entradas, porem o programa permite até 32768 entradas (Limitado pela memoria do processador).    *
     Recomenda-se o uso de até 64 entradas (8 CIs 74HC165).                                                        *     
     Segue Junto com exemplo um Arquivo do Proteus para demonstação.                                               *                 
********************************************************************************************************************     
     Example for reading digital inputs multiplexed by 74HC165.                                                    *
     The input and its value will be printed on the serial.                                                        *
     Used 16 inputs, but the program allows up to 32768 entries (Limited by processor memory).                     *
     It is recommended to use up to 64 inputs (8 ICs 74HC165).                                                     *
     Follow along with an example Proteus File for demonstration.                                                  * 
********************************************************************************************************************     
     Engenheiro Lucas de Oliveira Santana.                                                                         *
     04/07/2017                                                                                                    *
********************************************************************************************************************/
#include <Entradas.h>         // Inclue BiBlioteca de Entradas Multiplexadas para 74HC165.

void setup() {
  
/*******************************************************************************************************************
   Utiliza-se essa Função para configurações deve-se colocar as seguintes informações:                             *
   confPinosIn(Numero de Entradas, Saida Conectada ao Clock, Saida do Latch(SH/LD), Saida do CI).                  *
********************************************************************************************************************
   Use this function to configure the following information:                                                       *
   ConfPinosIn (Number of Inputs, Output Connected to Clock, Latch Output (SH / LD), CI Output).                   *
********************************************************************************************************************/
  confPinosIn(16, 2, 3, 4);

  Serial.begin(9600); // Configura Serial.

}

void loop() {

  Serial.print("Entradas");
  for (int ad = 0; ad < 16; ad++)
  {
    Serial.println();
    Serial.print(ad);
    if (LeEntrada(ad))        // Função LeEntrada(Numero da entrada). // Le Input Function (Input Number).
    {
      Serial.print("  Nivel Alto (1)");
    } else
    {
      Serial.print("  Nivel Baixo (0)");
    }
  }
  Serial.println();
  Serial.println("Imprime Porta 0");
/*******************************************************************************************
     Função PortEntrada(Num da porta) retorna um valor decimal                             *
     de 8 bits para cada CI Individual.                                                    *
     IMPORTANTE: O Numero de Portas deve ser sempre menor que                              *
     o numero dos CIs, Valores diferentes geram valores sem qualquer referencia.           *
     Primeiro CI tem Valor "0".                                                            *
********************************************************************************************
      Function PortEntry (Port Num) returns a decimal value                                *
      8 bits for each Individual CI.                                                       *
      IMPORTANT: The number of doors must always be less than                              *
      The number of CIs, different values generate values without any reference.           *
      First CI has Value "0".                                                              *
********************************************************************************************/
  Serial.println(PortEntrada(0));
  Serial.println("Imprime Porta 1");
  Serial.println(PortEntrada(1));
  delay(5000);
}
