# Fontes:
https://deepbluembedded.com/pic-programming-tutorials/
# Início
Nunca esqueça do define que determina a frequência do micro:
```C
#define _XTAL_FREQ 4000000
```
Neste caso estamos utilizando 4MHz, mas pode ser outro valor

Também sempre cuide dos configurations bits (fuses) em Window>Target Memory Views>Configuration bits.
Depois de gerar os defines, os cole no main.c ou no header de configuração. Os significados dos bits são:
- Fosc1 e Fosc2: Oscillator selection bus. De acordo com a cofiguração destes bits, determinamos a origem do clock da MCU:
	- 11: RC -> Usando ckts RC pra gerar o clock
	- 10: HS -> Cristais >= 4MHz
	- 01: XT -> Cristais Oscialdores / ressonadores cerâmicos <=4MHz
	- 00: LP -> Cristais Low Power (baixo consumo) até 400Khz
- WDTEN: Watchdog enable bit
- PWRTEN: Ativa o Power-Up Timer, que nos dá um time-out de 72ms ao iniciarmos o micro. Isto serve para que esperemos a fonte atingir o seu nível correto de tensão antes da MCU começar a operar. Em projeto simples, pouca diferença se nota.
- BOREN: Brown-Out Reset. Quando ativo, se VDD cair abaixo de VBOR (4V, + ou -) por um período de tempo maior que TBOR (cerca de 100us), toda MCU será reiniciada até VDD voltar a ficar acima de VBOR, dando um time-out de 72ms.
- LVP: Low-Voltage In-Circuit Serial Programmin. Alterna entre os modos de programação de alta/baixa tensão. Se estiver for igual a 0, será o modo High-Voltage (cerca de 13V), valor padrão para os PICkit.
- CPD: Data EEPROM Memory Code Protection. Determina se a memória EEPROM poderá ser acessada e lida. Quando se faz um produto, normalmente este fica ativo.
- WRT: Flash Program Memory Write Enable. Dois bits que determinam uma page do programa para proteger, se deixada como padrão, não protegerá nada.
- DEBUG: In-Circuit Debugger Mode. Se estiver usando uma ferramente de debuggin por hardware, pode deixar ativo, senão, deixa em OFF.
- CP: Flash Program Memory Code Protection. Se deixado em OFF, permite que o programa em código de máquina (literalmente o firmware em .hex) seja extraído do micro. Quando se faz um produto, normalmente se deixa isto LIGADO, pra ninguém simplesmente sair copiando o código.

Temos todos os Fuses explicados, dito isto, nos tutoriais que estarei seguindo, a configuração será a seguinte:
```C
// CONFIG
#pragma config FOSC = XT    // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF   // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON   // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = ON   // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF    // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit
                            // (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF    // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF    // Flash Program Memory Write Enable bits
                            // (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF     // Flash Program Memory Code Protection bit (Code protection off)
```

# I/O
==SEMPRE VEJA NA DOCUMENTAÇÃO AS CORRENTES MÁXIMAS SUPORTADAS PELOS PINOS==, mas no geral, é 25mA
|Registrador|Função|
|--|--|
|PORT|Responsável por armazeonar o valor de um pino I/O, seja ele saída ou entrada|
|TRIS|Determina se o pino I/O é saída ou entrada (0=saída e 1=entrada)|

Para acessar um registrador fazemos NOME_DO_REGbits.PINO = VALOR
ex:
```C
PORTBbits.RB0 = X; //Setando o PORT do pino RB0 como X
TRISCbits.TRISC3 = 0; //Setando o pino C3 como saída

ou ainda
TRISB0 = 0; //Setando o pino B0 como saída
```

Se quisermos, podemos setar o byte inteiro:
```C
TRISC = 0b01010101
PORTB = 0b00000001
```

Exemplo de código de leitura de um pino:
```C
int pino_rb0;
TRISBbits.TRISB0 = 1;
pino_rb0 = PORTBbits.RB0;

ou

int pino_rb0;
TRISB0 = 1;
pino_rb0 = RB0;
```

Podemos fazer o interfaceamento de displays 7seg usando as gpios, utilizando uma porta inteira para controlar um display. Basta decidir se vamos utilizar alinhamento para a direita ou esquerda (já que o display tem 7 segmentos, mas temos 8 bits) e montar tudo.
Se for alinhado para a direita, podemos utilizar o seguinte site para gerar o valor hexadecimal correspondente ao número, bastanto aplicar este valor ao PORT da saída para termos o valor.
https://deepbluembedded.com/seven-segment-display-generator/
Ex de código de minuteira (PIC16F877A):
```C
#include <xc.h>
#include "config.h"
int vals [11] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x3F}; 
void main(void) {
    TRISB=0;
    TRISC=0;
    PORTB=0x3F;
    PORTC=0x3F;
    while(1){
        for(int i=0;i<6;i++){
            PORTC=vals[i];
            for (int j=1;j<11;j++){
                __delay_ms(1000);
                PORTB=vals[j];
            }
        }
    }
    return;
}
```

# Interrupt

Viver só de polling é complicado. Às vezes, precisamos de uma interrupt.

Antes de mais nada, temos que entender que o CI que estamos usando (PIC16F877A) não possuí interrupts vetorizadas, então, quando temos alguma interrupt, ele não faz ideia de onde veio, só sabe que veio.

O esquemático do ckt de interrupts é o seguinte (pode variar de CI para CI, então procura no datasheet do que tu for usar):
![[Interrupt_Circuitry_PIC16F.png]]
Apesar de estar confuso, vou explicar com um exemplo. Imagine que queremos configurar uma interrupt vinda do Timer1, para configurar:
- Setamos o bit TMR1IE (Timer1 interrupt enable)
- Setamos o bit PEIE (Peripheral interrupt enable)
- Setamos o bit GIE (Global interrupt enable)
Desta forma, teremos uma interrupt na CPU quando o TMR1IF (também conhecido como flag do timer1) for acionado.
Observe para alguns periféricos não precisamos acionar o PEIE.

Detalhe, nunca esqueça de limpar a flag quando der alguma interrupt.
O ISR (Interrupt Service Routine) deve serguir um passo a passo tipo:
- Verifica a origem de interrupt (por meio da flag)
- Faz o trabalho
- Limpa a flag

Por exemplo, vamos configurar uma interrupt do ADC para quando uma conversão é concluida e pra quando temos uma overflow no timer1:
```C
ADIE = 1;
TMR1IE = 1;
PEIE = 1;
GIE = 1;

void __interrupt() ISR(void){
	if(TMR1IF==1){
		//Faz a magia
		TMR1IF=0; //limpa a flag
	}
	if(ADIF==1){
	//Faz a magia
	ADIF=0; //limpa a flag
	}
}
```

Muitas vezes, o sistema vai receber um monte de interrupts, então é crucial QUE ELAS SEJAM RÁPIDAS. Nunca use delays dentro de uma ISR.

# Timers
Podem funfar tanto como timers quanto como meros contadores
No modelo utilizado (PIC16F877A), temos 3 timers, com os seguintes esquemáticos (de novo, deixa de ser preguiçoso e pesquisa no detasheet do CI que tu for usar):

![[Timers Schmt.png]]

## Timer 0:
- 8 bits
- Radable/writable
- 3 bit prescaler
- Internal or external clock select
- Edge select for eternal clock
- Controlado pelo SRF OPTION_REG
	- bit 2-0: Prescaler Rate Select Bits
	- bit 3: PSA (Prescaler assignemt bit)
		- 1 assigned to WDT
		- 0 assigned to Timer0 module
	- bit 4: T0SE (Source Edge Select bit)
		- 1 incrementa na descida
		- 0 incrementa na subida
	- 5 T0CS (Clock Source Select bit)
		- 1 transition on T0CKl pin
		- CLKO (internal instruction cycle clocl)
	- 6 INTEDG
	- 7 ~RBPU
## Timer 1:
- 16 bit core
- Radeble/writable
- 2 bit prescaler
- Internal or external clk 
- Edge selct for external clock
- SRF T1CON:
	- 0 TMR1ON
		- 1 enables timer1
		- 0 stops timer1
	- 1 TMR1CS clock source select bit
		- 1 external clock
		- 0 internal clock
	- 2 T1SYNC External clock input sync
		- 1 não sincroniza
		- 0 sincroniza
	- 3 T1OSCEN oscillator enable control bit
		- 1 oscillator enabled
		- oscillator shut-off
	- 4-5 prescaler
	- 6-7 unimplemented

## Timer 2
- 8 bit
- Reable/writable
- 2 bit prescaler
- 4 bit postscaler
- internal/external clock
- edge select for external clock
- T2CON SRF:
	- 0-1 prescaler select bits
	- 2 TMR2ON On bit
		- 1 is on
		- 0 is off
	- 3-6 postscale select bits
	- 7 uninmplemented

## Geral
No final das contas, cada microcontrolador vai ter seus contadores configurados de formas diferentes, vai ler o datasheet. Neste caso, o TIMER0 compartilha o PS com o WDT, e o TIMER2 é usado para PWM por ter aquele comparador massa.

Observe que caso você queira usar interrupts (e provavelmente vai querer, já que delays são horríveis), terá de ativar o GIE e o PEIE. Veja também quais os bits de flag e quais os de Interrupt ENABLE (para o timer 1, por exemplo, será TMR1IE e TMR1IF).

ex de código que irá gerar um intervalo de tempo entre 2 eventos (sim, eu só copiei do site mesmo):
```C
# include "config.h"
# include <stdint.h>

uint8_t C = 0;  // Global Counter To Count The Number Of Overflow Interrupts

void main(){
	// -- [[ Configure Timer1 To Operate In Timer Mode  ]] --
	// Clear The Timer1 Register. To start counting from 0
	TMR1 = 0;
	// Choose the local clock source (timer mode)
	TMR1CS = 0;
	// Choose the desired prescaler ratio (1:1)
	T1CKPS0 = 0;
	T1CKPS1 = 0;

	TMR1IE = 1;  // Timer1 Interrupt Enable Bit
	TMR1IF = 0;  // Clear The Interrupt Flag Bit
	PEIE = 1;    // Peripherals Interrupts Enable Bit
	GIE = 1;     // Global Interrupts Enable Bit

	// Put Your Fist Event Here
	-->FAÇA OS PARANAUÊS AQUI<--
	// Switch ON Timer1 Module!
	TMR1ON = 1;
	while(1){
	//Só na base da interrupt hahaha
	}
}

void interrupt ISR ()
{
   // Check The Flag Bit
   if (TMR1IF)
   {
      C++;
      if(C==VALOR PRO TEMPO QUE A GENTE QUER)
      {
        // Put Your Second Event Here
         -->FAÇA OS SEGUNDOS PARANAUES AQUI<--
        // Clear The Global Counter
        C = 0;
      }
      TMR1IF = 0; // Clear The Flag Bit
   }
}
```
Veja que para calcular o tempo usamos a equação:
$$ (4 * Prescaler * (65536 - TMR1) * X) / FOSC $$
Sendo que 65535 é pq o contador é de 16bits, TMR1 é o valor inicial do timer1, X=C é a quantidade de overflows a serem consideradas e FOSC é a frequência do clock interno

Observe que podemos ter alguns problemas aqui. Podemos querer exatamente 2 segundos, mas quando calculamos o valor de X, chegamos num valor quebrado, o que não faz o menor sentido, e irá gerar erros. Como concertamos isto? ==Preloading==.

Vamos considerar que o sistema roda a 4MHz num timer de 16bit, prescaler 1:1 e queremos Tout=2s. Assumindo que TMR1=0 (começa do começo) e calculando para x, teremos X=30,52 overflows (nonsense).

Observe porém, que 0,52 overflow equivale a 0,034 segundos (0,52 * 0,06553), sendo assim, basta substituir Tout por 0,034 na equação e resolver para TMR1, que será de 34002. Agora, basta carregar este valor para o TMR1 (o nome do registrador é literalmente TMR1, mamão com açúcar) no começo do código, antes de começar a contage, e na interrupt, sempre que tivermos uma overflow.