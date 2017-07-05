/*******************************************************************************************************************
     Exemplo para leitura das entradas digitais multiplexadas por 74HC165 e Escrita para Saida em 74HC595.         *
     Será impresso na serial o valor da saida e o equivalente a sua porta (8 bits) em decimal.                     *
     Utilizando 16 entradas, porem o programa permite até 32768 entradas (Limitado pela memoria do processador).   *
     Utilizando 16 Saidas, disponivel um total de 32 (4 CIs), se necessario um numero superior deve-se editar o    *
    arquivos Saidas.h, instruções no arquivo.                                                                      *
     Recomenda-se o uso de até 64 entradas (8 CIs 74HC165).                                                        *
     Segue Junto com exemplo um Arquivo do Proteus para demonstação.                                               *
********************************************************************************************************************
      Example for reading digital inputs multiplexed by 74HC165 and Writing to Output on 74HC595.                  *
      The value of the output and the equivalent of its port (8 bits) in decimal will be printed on the serial.    *
      Using 16 inputs, however the program allows up to 32768 entries (Limited by processor memory).               *
      Using 16 outputs, a total of 32 (4 ICs) is available, if necessary a higher number one should edit the       *
     files, instructions in the file.                                                                              *
      It is recommended to use up to 64 inputs (8 ICs 74HC165).                                                    *
      Follow along with an example Proteus File for demonstration.                                                 *
********************************************************************************************************************
 *    Engenheiro Lucas de Oliveira Santana.                                                                        *
 *   04/07/2017                                                                                                    *
********************************************************************************************************************/

#include <Entradas.h>
#include <Saidas.h>


unsigned long TEMPO = 0;

void setup() {

  /*********************************************************************************************************************
       Utiliza-se essa Função para configurações deve-se colocar as seguintes informações:                             *
       confPinosOut(Numero de Saidas, Saida Conectada ao Clock, Saida do Latch(SH/LD), Entrada do CI).                 *
       O Clock pode ser compartilhado entre o CI de entradas e saidas.                                                 *
       Pelo Proteus o Latch pode ser compartilhado tambem, mas não foram realizados testes reais sobre.                *
  **********************************************************************************************************************
       Use this function to configure the following information:                                                       *
       ConfPinosOut (Number of Outputs, Output Connected to Clock, Latch Output (SH / LD), CI Output).                 *
       The Clock can be shared between the IC of inputs and outputs.                                                   *
       For Proteus Latch can be shared as well, but no actual tests have been performed.                               *
  **********************************************************************************************************************/
  confPinosOut(16, 2, 5, 6);

  confPinosIn(16, 2, 3, 4);    // Configura entradas Multiplexada.

  Serial.begin(9600);
}

void loop() {

  for (int i = 0; i < 16; i++) {
    if (LeEntrada(i)) {
 /***********************************************************************************************************************     
  *      A função escreveSaida, se comporta igual a DigitalWrite, utilizando-se dos mesmos parametros,                  *
  *      com observação ao fato que os valores são relacionados aos CIs.                                                * 
  ***********************************************************************************************************************
  *      The function writeSaida, behaves the same as DigitalWrite, using the same parameters,                          *
  *      With observation to the fact that the values are related to the ICs.                                           *
  *************************************************** *******************************************************************/
      escreveSaida(i, HIGH);  
    } else
    {
      escreveSaida(i, LOW);
    }
  }
  if (millis() - TEMPO > 5000) {
    Serial.println("       Saidas");
    for (int i = 0; i < 16; i++) {
      Serial.print("Saida ");
      Serial.print(i);
 /***********************************************************************************************************************     
  *      A função LeSaida, se comporta igual a DigitalRead, porem, só le as saidas dos CIs.                             *                                 * 
  ***********************************************************************************************************************
  *      The LeSaida function behaves the same as DigitalRead, but only the outputs of the ICs.                         *
  ***********************************************************************************************************************/
      if (LeSaida(i)) {
        Serial.println(" Nivel Alto");
      } else
      {
        Serial.println(" Nivel Baixo");
      }
    }
    Serial.println("Valor Port 0");
/*******************************************************************************************
     Função LePortSaida(Num da porta) retorna um valor decimal                             *
     de 8 bits para cada CI Individual.                                                    *
     IMPORTANTE: O Numero de Portas deve ser sempre menor que                              *
     o numero dos CIs, Valores diferentes geram valores sem qualquer referencia.           *
     Primeiro CI tem Valor "0".                                                            *
********************************************************************************************
      Function LePortSaida (Port Num) returns a decimal value                              *
      8 bits for each Individual CI.                                                       *
      IMPORTANT: The number of doors must always be less than                              *
      The number of CIs, different values generate values without any reference.           *
      First IC has Value "0".                                                              *                                                            
********************************************************************************************/
    Serial.println(LePortSaida(0));
    Serial.println("Valor Port 1");
    Serial.println(LePortSaida(1));    
    TEMPO = millis();
  }
}
