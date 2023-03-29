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

