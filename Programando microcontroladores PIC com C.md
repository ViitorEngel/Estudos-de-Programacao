|Registrador|Função|
|--|--|
|PORT|Responsável por armazeonar o valor de um pino I/O, seja ele saída ou entrada|
|TRIS|Determina se o pino I/O é saída ou entrada (0=saída e 1=entrada)|

Para acessar um registrador fazemos NOME_DO_REGbits.PINO = VALOR
ex:
```C
PORTBbits.RB0 = X; //Setando o PORT do pino RB0 como X
TRISCbits.TRISC3 = 0; //Setando o pino C3 como saída
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
```
