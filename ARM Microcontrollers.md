# Anotações focadas nos micros STM32
# SWO / SWD / ITM
- Serial Wire Output, Nas placas de desenvolvimento, temos este pino ligado no debugger (os da linha M0 não o tem) via SWD
- Dentro do micros podemos ter as unidades ITM (Instrumentation Trace Macrocell Unit), permite realizar comunicações sobre os processos do programa serialmente, conectados ao SWO, que se conecta ao SWD
- Temos então o SWD, Debug Serial Wire, um protocolo de debug que utiliza dois pinos para ser realizada à qual está conectado o SWO e o ITM.
  - Um dos pinos é o SWCLK, que é o clock, o outro, o SWDIO, uma linha de dados bidirecional
  - Com o SWD, podemos programar a FLASH, acessar regiões da memória, adicionar breakpoints e parar/rodar a CPU
  - Podemos até mesmo utilizar o printf() para enviar mensagens via este serial com o SWO
    - Na realidade o printf() irá chamar uma função de nível ainda mais baixo de acordo com o micro específico que está sendo utilizado 
  
- Mais tradicional e antiga é o protocolo de debug JTAG, porem, ele precisa de mais pinos

- Observe que sempre que for utilizar o SWD com o Debugger na IDE, você deve habilitar a função nas configurações de debugging.
  
# Opções de Debug
Não vou ficar falando sobre breakpoints, ver SRFS e afins, vou focar em coisas novas
### Call Stacks
Por exemplo
```C
void (*jump_addr) (void);
jump_addr = (void*)0x645634534;
jump_addr();
```
O que fazemos um ponteiro de função na primeira linha, iniciamos a função na segunda no endereço especificado e chamamos a função na terceira linha. Observe porém, que não temos nenhuma instrução naquele endereço, é somente um endereço aleatório. Isso irá causar uma instruction fault.
Iremos ver na janela de debug um:
```C
<signal gander called>() at 0xendereco
```
Basta ver então onde parou o ponteiro do programa para descobrirmos onde está o erro.

### Watchpoints
Te permite criar uma expressão que observa um endereço, parando o progrma toda vez que ele for alterado. Útil para descobrir o que está acontecendo com variáveis que ficam mudando magicamente.

# MCU Bus Interfaces
Dentro do uC temos diferentes barramentos(bus), cada carregando um determinado tipo de informação.
No geral, pelo menos para os ARM, temos
I-BUS: Instruction Bus
D-BUS: Data Bus
S-BUS: System Bus (carrega tanto dados quanto instruções)

- No geral, cada um destes barramentos está conectado à sua parte correspondente na flash (exceto o system bus). Se um dado que deveria estar num endereço referente a um barramento específico não estiver nele, então ele não conseguirá ser acessado pelo protocolo que realiza a leitura/gravação do barramento na flash.
- Existe diversos protocolos, mas os mais vistos são os AHB e o APB.
- O AHB funciona com frequências de clocks mais altos e é mais comum em barramentos que necessitem de muita informação, já o APB é mais lento e utilizado para conjuntos menores de periféricos onde velocidade é menos crítica.
- HCLK é a frequência do AHB
- PCLK é a frequência do clock do APB

- Observe que todos os barramentos eventualmente atingem a bus matrix. Ela funciona como o guarda de trânsito num cruzamento super movimentado e é responsável por fazer o controle do fluxo das informações:
  ![Captura de tela 2023-08-08 163729](https://github.com/ViitorEngel/Estudos-de-Programacao/assets/124899227/5d813ccd-e76c-47be-8c8d-dca106e37164)
  Entender seu funcionamento é bem simples, basta olhar seu diagrama e você entende exatamente quem conversa com quem:

  ![image](https://github.com/ViitorEngel/Estudos-de-Programacao/assets/124899227/dda61202-9a7e-43ae-ae42-3724da801a62)

# Clocks
Por padrão, o clock da MCU será o RC HSI (High Freq Internal Osc RC).
As configurações do clock são normalmente feitas pelos registradores do RCC
