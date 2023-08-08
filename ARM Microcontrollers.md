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
  
