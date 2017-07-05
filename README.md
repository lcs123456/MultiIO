# MultiIO
O arquivo Saida.h conta com as funções descritas abaixo,
Para usar basta informar como informações solicitadas, cada uma explicada abaixo:

Void confPinosOut (int NUMERO_DE_SAIDAS, int CLOCK, int LATCH, int DADOS_PARA_O_CI)
- Primeira função usada em Configuração, deve-se informar:
- O NUMERO_DE_SAIDAS, com valor maximo de 32 (0-31);
- RELÓGIO, conexão ao relógio (SHCP do 74hc595).
- LATCH, ssaida de latch (STCp do 74HC595).
- DADOS_PARA_O_CI, saida de dados (DS do 74HC595).
- A função não retorna nada.
 
Vazio escreveSaida (int pino, int nivel);
- Função trabalha igual a digitalEscreva, informe qual é seu estado.
********* A saida (Q7 ou D7) do primeiro CI é um valor 0 **************
- A função não retorna nada.

Int LeSaida (pino int);
- Informa o valor de qualquer saida.
- Função retorna uma int de valor 0 ou 1.

Int LePortSaida (portas int);
- Devolve o valor decimal de cada IC.
********** O primeiro CI tem valor 0. **********
- Retorna um int de 0 ~ 255.

Vazio escreveport (int PORTA, int Valores);
- Semelhante a função LePortSaida, porem, escreve um valor na porta de 0 a 255.
- A função não retorna nada.


O arquivo Entrada.h conta com as funções descritas abaixo,
Para usar basta informar como informações solicitadas, cada uma explicada abaixo:

Void confPinosIn (int NUMERO_DE_ENTRADAS, int CLOCK, int LATCH, int DADOS_DO_CI);
- Primeira função usada em Configuração, deve-se informar:
- O NUMERO_DE_ENTRADAS, sem valor maximo, recomenda-se até 64 entradas.
- RELÓGIO, conexão ao relógio (CLK do 74hc165).
- LATCH, ssaida de latch (SH / LD do 74HC165).
- DADOS_DO_CI, entrada de dados (SO do 74HC165).
- A função não retorna nada.

Int LeEntrada (pino int);
- Função trabalhada igual a digitalRead, retornando o estado da entrada.
********* A saida (Q7 ou D7) do primeiro CI é um valor 0 **************
- Função retorna int com 0 ou 1.

Int PortEntrada (int port);
- Devolve o valor decimal de cada IC.
********** O primeiro CI tem valor 0. **********
- Retorna um int de 0 ~ 255.




***************************Inglês********************** ********************************
O arquivo Saida.h possui as seguintes funções descritas abaixo,
Para usar, basta inserir as informações solicitadas, cada uma delas explicada abaixo:

Void confPinosOut (int NUMBER_ID, int CLOCK, int LATCH, int DATA_PART_O_CI)
- Primeira função usada na Configuração, você deve informar:
- THE NUMBER_DE_SAIDAS, com valor máximo de 32 (0-31);
- RELÓGIO, conexão ao relógio (SHCP de 74hc595).
- LATCH, ensaio de trava (STCp de 74HC595).
- DATA_PARA_O_CI, saída de dados (DS de 74HC595).
- A função não retorna nada.
 
Void writesAid (int pin, int level);
- Função funciona da mesma forma que digitalWrite, informe qual saída e seu estado.
********* A saída (Q7 ou D7) da primeira CI é um valor de 0 **************
- A função não retorna nada.

Int LeSaida (pino int);
- Informa o valor de qualquer saída.
- A função retorna um int de valor 0 ou 1.

Int LePortSaida (portas int);
- Retorna o valor decimal de cada CI.
********** O primeiro CI tem um valor de 0. **********
- Retorna um int de 0 ~ 255.

Void writesport (int PORT, int values);
- Semelhante à função LePortSaida, no entanto, ele escreve um valor na porta de 0 a 255.
- A função não retorna nada.


O arquivo Input.h possui as seguintes funções descritas abaixo,
Para usar, basta inserir as informações solicitadas, cada uma delas explicada abaixo:

Void confPinosIn (int NUMBER_INTERNATES, int CLOCK, int LATCH, int CID_DATA);
- Primeira função usada na Configuração, você deve informar:
- THE NUMBER_DE_ENTRADAS, sem valor máximo, são recomendadas até 64 entradas.
- RELÓGIO, conexão do relógio (CLK de 74hc165).
- LATCH, ensaio de trinco (SH / LD de 74HC165).
- CI_DATA, entrada de dados (74HC165 OS).
- A função não retorna nada.

Int Le Input (pino int);
- A função funciona da mesma forma que o digitalRead, retornando o estado da entrada.
********* A saída (Q7 ou D7) da primeira CI é um valor de 0 **************
- A função retorna int com 0 ou 1.

Int PortEntry (int port);
- Retorna o valor decimal de cada CI.
********** O primeiro CI tem um valor de 0. **********
- Retorna um int de 0 ~ 255.
