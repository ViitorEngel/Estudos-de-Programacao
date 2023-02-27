
# Curso: https://youtu.be/XKHEtdqhLK8

# Print in terminal

```Python
print ("mensagem")
```

- Não precisa de ";" 😜

# Variáveis

NÃO PRECISA DECLARAR O TIPO DE VARIÁVEL 😍

## String

```Python
string = "string"
```

Podemos combinar strings com variáveis num print, exemplo:
```Python
name = "Vitao"
print ("Salve, "+name)
```

Se quisermos, podemos printar o tipo de variávei com a função type(), que retonar o tipo de uma variável:
```Python
print(type(name))
```

Podemos juntar duas variáveis do tipo string numa só:
```Python
primeiro_nome = "Vitor"
sobrenome = "Barros"
nome_completo = primeiro_nome + " " + sobrenome
```
Veja que tivemos que adicionar um espaço nesta junção, senão as strings iriam ficar coladas

## Int

```Python
idade = 19
```

Se quisermos, podemos agregar idade em +1 de duas maneiras:
```Python
idade = idade + 1
idade += 1
```

Mas e se quisermos transfomar uma int numa string? Como fazemos esta conversão?
```Python
print ("Sua idade é: " + str(idade))
```

## Float

```Python
altura = 190.6
```

Fazer a conversão de float para string pode é igual a como se faz numa int

```Python
print (Sua altura é: +str(altura) + "cm")
```

## Boolean

```Python
human = False
```

# Multiple assignment

Podemos declarar diversas variáveis numa só linha de código:
```Python
name, age, attractive = "Bro", 21, True

ou ainda:

Bon_Esponja = Patrique = Sandy = Lula_Molusco = 30
```

# String Methods

```Python
name = "bro"
print (len(name)) #printa o tamanho da string
print (name.find("B")) #printa o primeiro índice aonde temos o caractere B
print (name.capitalize()) #irá deixar a letra indicada pelo índice em maiúsculo, se não indicarmos o índice, será a primeira letra
print (name.upper()) #irá printar a string toda em letra maiuscula
print (name.lower()) #irá printar a string toda em letra minúscula
print (name.isdigit()) #irá printar se a string é somente um dígito 
print (name.isalpha()) #irá printar se a string contém apenas letras do alfabeto (exlui espaço)
print (name.count("o")) #irá printar quantas vezes a string "o" aparece na string
print (name.replace("o", "a")) #irá printar a string substituindo o por a
print (name*3) #printa a string 3 vezes
```

# Type cast

Type cast consiste em converter uma variável de um tipo para outro tipo

Convertemos com a seguinte sintaxe:
```Python
x = 1
y = 2.0
z = "3"

y = int(y) # aqui convertemos de string para int
x = float(x) #convertemos de int para float
y = str(y) #aqui covnertemos de float para string

```

# User Input

Fazemos com a função inptut:
```Python
input("Qual é o seu nome? ")

caso queiramos igualar a uma variável

nome = input("Qual é o seu nome? ")
```

Observe que o formato que será entregue será de string, então caso queira realizar alguma operação, irá se fazer necessário utilizar as ferramentas descritas em Type Cast, por exemplo:
```Python
age = int(input("Qual a sua idade? "))
print("Você tem "+str(age)+" anos de idade.")
```

# Math Functions

```Python
import math

pi = 3.14
x, y, z = 1, 2, 3

print (round(pi)) #printa pi arredondado
print (math.ceil(pi)) #printa pi arredondado para cima
print (math.floor(pi)) #printa pi arredondado para baixo
print (abs(pi)) #printa a distância entre pi e zero
print (pow(pi,2)) #printa pi^2
print (math.sqrt(pi)) #printa a raiz quadrada de pi
print (max(x,y,z)) #printa o maior valor entre estas variáveis
print (min(x,y,z)) #printa o menor valor entre estas variáveis
```

# String Slicing

Usando os índices:
```Python
name = "Bro Code"

primeira_letra = name[0] #irá adicionar B à variável primeira_letra, já que é esta a letra no índice 0
primeiro_nome = name[0:3] #irá adicionar Bro à variável primeiro_nome
primeiro_nome = name [:3] #exatamente igual a anterior, se não colocar um valor de começo, ele irá entender que é 0
segundo_nome = name[4:] #irá igualar a viariável segundo nome a tudo que vem depois do índice 4 de name
nome_zoado = name [0:8:2] #irá igualar à name, mas dando passos de 2 em 2, então seria BoCd
nome_zoado = name [0:8:3] #igual a anterior, mas dando passos de 3 em 3
nome_invertido = [::-1] #irá inverter o nome, pois irá do começo ao final de name, mas dando passos de -1 em -1
```

Outro método é com a função slice, que funciona a partir dos índices, de modo muito semelhante ao anterior:
```Python
website = "http://google.com"

slice = slice(7,-4) #iremos adicionar à variável slice o termo google
```
Observe que utilizamos -4 como o índice de parada, isto acontece porque estamos contando de trás para frente, então queremos que ele pare no índice 4, mas contado a partir do final da string

# If Else

```Python
age = int(input("Qula a sua idade? "))

if age == 100:
	print("Você é um centenário!") #TOME CUIDADO COM A INDENTAÇÃO
elif age >= 18: #se a idade for maior ou igual a 18
	print("Você é adulto!") 
elif age < 0: #outro teste antes do else
	print("Você ainda não nasceu!") 
else: #senão
	print("Você é uma criança!")
```
Preste atenção na ordem das comparações, quando uma for verdadeira, o programa irá pular as outras

# Operadores lógicos

É ridiculamente fácil, a operação AND é literalmente "and", OR é literalmente "or" e NOT é "not", exemplo:
```Python
temp = int (input("Qual a temperatura do quarto? "))

if temp >= 0 and temp <= 30:
	print("A tempera está agradável hoje!")
elif temp < 0 or temp > 30:	
	print("A temperatura está desagradável hoje...")

PARA O USO DA NOT:

if not(x==2):
	print("x é diferente de 2!")
```

# While

```Python
while 1==1: #1 sempre será igual a 1, temos um loop infinito
	print("LOOP INFINITO!")

OUTRO EXEMPLO:

name = " "
while len(name) == 0: #enquanto o tamanho de nome for 0, ou seja, o usuário não inserir um nome, ele irá ficar perguntando
	name = input("DIZ TEU NOME: ")
print ("Salve, "+name)	
```

# For

```Python
for i in range(10): #fizemos um contador de 0 a 9 :)
	print(1)

for i in range(50,100): #fizemos um contador de 50 a 99 :)
	print(i)

for i in range(50,100,2): #conta de 50 a 99, mas de 2 em 2
	print(i)

for i in "Bro Code": #iremos printar cada letra de "Bro Code", uma após a outra
	print(i)

for i in range (10,0,-1): #vai contar de trás pra frente, porque estamos dando passos negativos
	print(i)
```

# Nested Loops

Um loop dentro de outro, onde o de dentro vai terminar todas as suas iterações antes de terminar uma iteração do de fora

EXEMPLO:
```Python
#Código que irá desenhar na tela um conjunto de linhas e colunas definidos pelo usuário

colunas = int(input("Quantas colunas: ")) #pergunta o numero de linhas e colunas
linhas = int(input("Quantas linhas: "))  
  
for i in range (0,linhas):  
    for j in range (0,colunas):  
        print("@", end="")
    print()
```
Observe que colocamos end="" no print. Temos que fazer isso porque por padrão, ao final de um print, o programa irá para uma nova linha. Podemos definir end como alguma outra coisa, e e o programa irá printar esta outra coisa quando chegar ao final da linha ao invés de printar o comando para ir para a próxima. Neste caso, utilizamos aspas sem nada dentro porque simplesmente não queremos printar nada. Depois, printamos um print vazio, que tem a função de simplesmente ir para a próxima linha.

# Loop control statements

break -> pula para fora do loop

continue -> pula a próxima iteração do loop

pass -> faz nada, serve somenta para não deixar uma sentença vazia (um if, por exemplo) se por algum motivo não queiramos colocar nada dentro dele

# Listas

Guarda vários valores dentro de uma única variável.
```Python
food = ["Pizza","hamburger","hotdog","espaguete"]

print(food[0]) #printamos pizza
print(food[1]) #printamos hamburger

food [0] = "sushi" #substituimos pizza por sushi

for x in food: #printamos todos os elementos de food
	print(x)

food.append("sorvete") #adicionamos sorvete ao final da lista
food.remove("hotdog") #remove hotdog da lista
food.pop() #remove o último elemento da lista
food.insert(0,"bolo") #insere bolo no índice 0
food.sort() #coloca a lista em ordem alfabética
food.clear() #remove tudo da lista
```

# Listas 2D

Basicamente uma lista de listas

```Python
bebidas = ["café","coca","chá"]
jantar = ["pizza","espaguete","hotdog"]
sobremesa = ["bolo","sorvete"]

comida = [bebidas, jantar, sobremesa]

print (comida) #printa todas as listas
print (comida[0]) #vai printar só a primeira lista da lista
print (comida[0][0]) #vai printar só o primeiro elemento da primeira lista da lista
```

# Tuples

Coleções ordenadas e estáticas (não tem como alterar)

```Python
estudante = ("Cleber", 21, "homem")

print (estudante.count.("Cleber")) #printa quantas vezes Cleber aparece
print (estudante.idex("homem")) #printa o índice em que temos homem

for x in estudante: #printa todos os elementos de estudante
	print(x)

if "Cleber" in estudante: #verifica se temos algum elemento "Cleber" na tuple
	print ("Clebão chegou!")
```

# Sets

Coleção desordenada, sem índices, que não considera valores duplicados

```Python
utensilios = {"garfo","colher","faca"}
pratos = {"tigela","prato","copo"}

for x in utensilios: #iremos printar todos os elementos, mas como não temos índice, serão printados em ordem aleatória
	print(x)

utensilios.add("guardanapo") #adiciona guardanapo ao set
utensilios.remove("garfo") #remove garfo do set
utensilios.clear() #remove tudo do set
utensilios.update(pratos) #adiciona tudo que tem em pratos a utensilios

mesa = utensilios.union(pratos) #cria um novo set que é a união de utensilios e pratos

utensilios.difference(pratos) #retorna os valores que utensilios tem que pratos não
utensilios.intersection(pratos) #retorna os valores que os sets tem em comum
```

# Dicionários

Uma coleção, desordenada, alterável de pares duplos de "keys:values". Nos permite acessar um valor rapidamente.

```Python
Capitais = {"USA":"Washington DC",
		   "India":"Nova Delhi",
		   "China":"Pequim",
			"Russia":"Moscou"}

print(capitais["Russia"]) #vai printar o valor da key Russia, que é Moscou
print(capitais.keys()) #vai printar todas as keys
print(capitais.values()) #vai printar todos os valores
print(capitais.items()) #vai printar tudo

for key, value in capitais.items():
	print(key, value) #tbm vai printar tudo

capitais.update({"Alemanha":"Berlim"}) #adicionamos um elemento ao dicionário
capitais.update({"USA":"Las Vegas"}) #alteramos a capital de USA para Las Vegas
capitais.pop("China") #remove a key e o valor china
capitais.clear() #deleta tudo do dicionário
```

# Index Operator

index operator [] = dá o acesso a um elemento de uma sequencia (str, list, tuple)

Neste caso, a contagem realmente começa no 1, e não no zero
```Python
name = "bro code"

if (name[0].islower()): #verifica se a primeira letra da string é minuscula
	name = name.capitalize() #se for, botamos em maiuscula

primeiro_nome = name[0:3].upper() #criamos uma variável que irá pegar os 3 primeiros valores e botar todos em maiusculo
ultimo_caractere = name[-1] #pegamos o ultimo caractere, porque estamos utilizando um índice negativo
```

# Funções

Um pedaço de código que só é executado quando é chamado, muito útil pra não ficar repetindo blocos de código

```Python

def hello(): #criamos uma função chamada hello que printa hello
	print("hello")

hello() #chamamos a função hello

def hello2(nome): #criamos uma função que printa hello e o nome, com argumentos
	print("hello, "+nome)

hello2("Jeremias") #chamamos a função hello 2, que irá printar hello Jeremias
```

Podemos colocar quantos argumentos queremos numa função, basta que quando a chamarmos coloquemos os argumentos na ordem correta dentro dos parênteses

# Return Statement

É utilizado para retornar o valor do chamador da função

```Python
def multiply (x,y)
	return x * y

print(multiply (6,8)) #printa a multiplicação de 6 e 8, já que por causa do "return", a função retorna esta multiplicação
```

# Keyword arguments

Consiste numa maneira de passar argumentos para uma função fora de ordem, indicando a qual variável da função esses valores devem ser atribuidos, exemplo:
```Python
def hello (primeiro, segundo, final):  
   print ("Salve "+primeiro+" "+segundo+" "+final)  
  
hello (final="Barros",primeiro="Vitor",segundo="Engel")
```

# Neste function calls

Call de funções dentro de outras funções, exemplo:
```Python
print(round(abs(float(input("Diga um número: ")))))
```
Obseve que estamos chamando uma função nos argumentos de outras funções, e o valor retornado pela função será então o argumento

# Variable Scope

Variávels globais e locais, igual no C

# Args parameters

Parâmetros que irão colocar todos os argumentos numa tuple. Muito útil quando queremos passar muitos valores para dentro de uma função, exemplo:
```Python
def soma(*args): 
	sum = 0
	for i in args:
		sum += i
	return sum

print (soma(1,2,3,4,5,6))
```
Veja que ele está pegando todos os argumentos e criando uma tuple chamada args, e então fazendo a soma de todos os valores dentro de um for, e retornando o valor para ser printado

# Kwargs

Extremamente parecido com args, a diferença é que aqui podemos utilizar keyword arguments, já que estamos criando dicionários exemplo:
```Python
def ola (**kwargs):
	print("Olá, "+kwarg["first"]+" "+kwargs["last"])

print(ola(first="Vitor", meio="Engel", last="Barros"))
```
Estamos criando um dicionário chamado kwargs, que será o argumento da função, com seus elementos sendo declarados quando chamamos a função ola.

# String Format

Método opcional que dá mais controle ao mostrar a output
```Python
SINTAXE:
str.format(argumentos)
```

Por exemplo, teremos a mesma output com estes dois formatos:
```Python
animal = "vaca"
item = "lua"

print ("A "+animal+" pulou sobre a "+item)
print ("A {} pulou sobre a {}".format(animal,item))

#entretanto, podemos brincar com os indices, por padrão, eles estão desta forma:
print ("A {0} pulou sobre a {1}".format(animal,item))
#mas podemos inverter:
print ("A {1} pulou sobre a {0}".format(animal,item))
#neste caso, iremos printar "A lua pulou sobre a vaca"
#podemos inclusive repetir indices:
print ("A {1} pulou sobre a {1}".format(animal,item))
#A lua pulou sobre a lua
```

Podemos ainda fazer pares de keywords:
```Python
print ("A {animal} pulou sobre a {objeto}".format(animal="vaca",objeto="lua"))
```

Também podemos utilizar isto para adicionar padding numa string:
```Python
name = "Bro"
print ("Hello, my name is {:10}. Nice to meet you".format(name)) #adiciona padding de 10 com o texto a direita
print ("Hello, my name is {:<10}. Nice to meet you".format(name)) #adiciona padding de 10 com o texto a direita
print ("Hello, my name is {:>10}. Nice to meet you".format(name)) #adiciona padding de 10 com o texto a esquerda
print ("Hello, my name is {:^10}. Nice to meet you".format(name)) #adiciona padding de 10 com o texto centralizado
```
Veja a output:
```Terminal
Hello, my name is Bro       . Nice to meet you
Hello, my name is Bro       . Nice to meet you
Hello, my name is        Bro. Nice to meet you
Hello, my name is    Bro    . Nice to meet you
```

Também podemos formartar numeros, exemplo:
```Python
numero = 3.14159
numero2 = 1000
print("O numero Pi é {:.3f}".format(numero)) #iremos printar pi com somente 3 casas decimais, usamos o "f" porque temos um float
print("O numero é {:,}".format(numero2)) #vai adicionar virgula ao numero
print("O numero é {:b}".format(numero2)) #vai exibir o numero em binario
print("O numero é {:X}".format(numero2)) #vai exibir o numero em hexadecimal
print("O numero é {:E}".format(numero2)) #vai exibir o numero em notação cientifica
```

# Numeros aleatorios

Temos que improtar a biblioteca random
```Python
import random

x = random.randint(1,6) #geramos uma int aleatória entre 1 e 6 e atribuimos a x
y = random.random() #geramos uma float aleatória entre 0 e 1

#podemos pegar um valor aleatório de uma lista com .choice, exemplo:
lista = ["Pedra", "Papel", "Tesoura"]
z = random.choice(lista)

#podemos também embaralhar uma lista, por exemplo, caso queiramos embaralhar um baralho:
cards = [1,2,3,4,5,6,7,8,9,"J","Q","k","A"]
random.shuffle(cards)

print (x)
print (y)
print (z)
print (cards)
```

# Exception handling

Uma exceção é um evendo detectado durante a execução que interrompe o fluxo do programa, por exemplo:
```Python
resultado = 5/0
print (resultado)
#teremos uma exceção, porque não podemos dividir um numero por zero
```

Podemos lidar com isso com a operação "try", que irá testar o código para verificar se não temos nenhuma exceção. Se tivermos, podemos lidar com ela usando "except nome_da_exeção", exemplo:
```Python
try:  
   numerador = int(input("Diga um numero para ser dividido: "))  
   denominador = int(input("Diga um numero para dividir: "))  
   result = numerador/denominador  
   #iremos testar esse código, quais exeções podem acontecer? O usuário pode digitar algo que não seja um número, ou pode tentar dividir por zero, então:  
   
except ZeroDivisionError: #se ele tentar dividir por zero  
   print ("Não dá pra dividir por zero...")  
   
except ValueError: #se ele colocar algo que não seja um numero  
   print ("Só dá pra dividir numeros! ")  
   
except Exception as e: #Se tiver qualquer outra exceção  
   #além disso, colocamos o "as e", para atribuir a e o tipo de exceção, e então printamos e, para sabermos exatamente qual a exceção que tivemos   print (e)  
   print("Deu ruim")  
   
else: #se não tivermos nenhuma exceção:  
   print("O resultado é {}".format(result))  
   
finally: #algo que irá acontecer sempre, independente de ter tido exceção ou não  
   print("Isto sempre irá aparecer!")
```

# Detectar, ler e escrever em arquivos

Comece importanto a biblioteca os
Exemplo de código com aplicação prática das funções (é necessário criar um arquivo de texto chamado teste na área de trabalho caso queira testar):
```Python
import os

path = "C:\\Users\\User\\Desktop\\teste.txt" #criamos uma variávei com o diretório do arquivo, é necessário colocar duas contra barras porque é assim que dizemos que temos uma quando colocamos numa string 

if os.path.exists(path): #verifica se o diretório existe
    print("O diretório existe")
    
    if os.path.isfile(path): #verifica se o diretório final é um arquivo
        print("O diretório é um arquivo")
    elif os.path.isdir(path): #verifica se o diretório é um diretório (pasta)
        print("O diretório é um diretório")
        
else:
    print("O diretório não existe")
```

Para ler, é muito fácil:
```Python
#Usamos a função open para abrir o arquivo e atribuimos o que tem nela à variável file
with open ("C:\\Users\\User\Desktop\\arquivo\\arquivo.txt") as file:

#utilizamos a função read para ler o que temos na variável file, então printamos
    print (file.read()) 
```
Observe que temos o "with". Ele é utilizado sempre que o bloco que estamos escrevendo envolva recursos que precisem ser fechados, neste caso, fechamos o arquivo de texto. Ele fecha automáticamente, se utilizarmos ele, precisamos fechar manualmente.

Observe que não precisamos colocar todo o diretório, somente o arquivo, se ele estiver na mesma pasta que o arquivo .py

Para escrever, também é muito fácil. Junto à função open, temos outro parâmetro:
	r: read (é o padrão, se não declarar, será este)
	w: write (sobrescreve o que temos no arquivo)
	a: append (adiciona informação ao arquivo)

Por exemplo:
```Python
#Observe que agora estamos abrindo o arquivo no modo de escrita
with open ("C:\\Users\\User\Desktop\\arquivo\\arquivo.txt", "w") as file:
    #sobrescrevemos o conteúdo do arquivo com esta string utilizando a função write
    file.write("Eu estou escrevendo!\nQue bacana!") 
```

No modo append:
```Python
with open ("C:\\Users\\User\Desktop\\arquivo\\arquivo.txt", "a") as file:
    file.write("\nAdicionando texto sem sobrescrever!")
```

# Copy files

Importamos o módulo shutil

Teremos três funções:
- copyfile() = copia o conteúdo de um arquivo
- copy() = copyfile() + permission mode + destino pode ser um diretório
- copy2() = copy() + copia metadados

```Python
import shutil  

shutil.copy("arquivo.txt","copiaarquivo.txt") #copiamos o arquivo arquivo.txt para copiaarquivo.txt, se não houver o copiaarquivo.txt, ele será criado
```


# Move Files

```Python
import os

#criamos as variáveis que irão armazenar os diretórios
source = "arquivo.txt"
destination = "C:\\Users\\User\\Desktop\\arquivo2\\arquivo.txt"

#verificamos se já existe um arquivo no destino
if os.path.exists(destination):
    print ("Já tem um arquivo ai...")

else:
    #se não houver, utilizamos o os.replace para mover o arquivo
    os.replace(source,destination)
    print(source+" foi movido")
```

# Delete files

```Python
import os

#me recuso a comentar isto daqui, se você não entende o que essa linha de código faz, você é burro
os.remove("arquivo.txt")
```

Entretanto, este comando apenas deleta arquivos, não diretórios. Para deletar diretórios use os.rmdir().

Caso queiramos deletar uma pasta com arquivos dentro, precisaremos importar o módulo shutil, e entãousar o comando shutil.rmtree(). Isso irá deletar o diretório especificado e tudo que tem dentro dele

# Módulos

Módulos são pedaços de código em outros arquivos, utilizado para programação modular.

Para criar um módulo, basta criar outro arquivo .py e escrever as funções que quisermos, então importamos ele no outro arquivo e usamos o módulo normalmente.

Ex, criando um módulo, supondo que o seu arquivo se chame messages.py
```Python
def hello()
	print ("Hello!")

def bye()
	print ("Bye!")
```
Importando o módulo e utilizando-o:
```Python
import messages

messages.hello()
messages.bye()
```
Observe que ambos os arquivos devem estar na mesma pasta

Caso queiramos verificar todos os modulos padrões que existem, basta rodar um programa com :
```Python
help("modules")
```

# Programação orientada a objeto (POO)

Precisei de outro vídeo pra entender: https://youtu.be/QY0Kdg83orY
É um paradigma de desenvolvimento, que bate de frente com a programação procedural.
Representamos objetos do mundo real no código, onde aglutinamos estados e comportamentos
Temos 4 pilares:
	- Herança: capacidade de um objeto ser idealizado com base em outro objeto
		- Possuem atributos e métodos
	- Polimorfismo: a capacidade de um objeto passar por outro em determinadas situações, consiste na alteração de um método da classe original
	- Encapsulamento: a capacidade de esconder detalhes do objeto, permitindo a exibição de só o que pode ser realmente publicamente editado
	- Abstração: é capacidade de representar o objeto de uma forma abstrata, é como a criação de um template ou super-classe, não podemos criar um objeto a partr dela, mas somente a partir de suas classes filhas

Exemplo de criação de classes, objetos e aplicação:
```Python
#Criando a classe carro. É comum a convenção de que classes começam com letras maiusculas
class Car:
   #aqui criamos os atributos da classe, que são basicamente funções. Utilizamos o   método __init__ que funciona como o "constructor" da classe. Isso significa, que quando formos criar um objeto a partir desta classe, é com este método que conseguimos determinar seus atributos.
    def __init__(self, make, model, year, color):
        self.make = make
        self.model = model
        self.year = year
        self.color = color

    #adicionando métodos a classe, que nada mais são do que funções. Utilizamos o self para indicar que o método se refere a classe em questão.
    def drive (self):
        print ("This car is driving")
    def stop (self):
        print ("The car stopped")

#aqui estamos criando dois objetos de carros a partir da classe criada
car_1 = Car("Chevy","Corvette",2021,"blue")
car_2 = Car("Ford","Mustang",2022,"red")

#aqui, estamos printando o fabricante (um atributo) do objeto car_1
print(car_1.make)

#aqui, estamos chamando os métodos dos objetos
car_1.drive()
car_1.stop()
```

Observe que ainda podemos criar uma variável dentro da classe, mas fora do constructor. Neste caso, este terá um valor "padrão", que não precisará ser declarado na criação do objeto, mas que todos os objetos terão. Poderemos editar esta variável para cada objeto com:
objeto.variável = valor
Porém, podemos também mudar o valor da viarável diretamente na classe, com:
classe.variável = valor
Observe que nesta última situação, todos os objetos serão alterados.

# Hierarquia

Basicamente, a criação de uma classe com base em outra classe, com certas características da classe mãe

```Python
#criando a classe mãe
class Animal:
    #se você é um animal, você começa vivo, então determinamos true como padrão para alive, que é uma variável
    alive = True
    #criamos métodos comer e dormir
    def eats(self):
        print("Este animal está comendo")
    def sleep(self):
        print("Este animal está dormindo")

#criamos classes filhas, que terão todas as variáveis, métodos e atributos que a mãe, mais as variáveis, métodos e atributos que determinarmos para ela.
#sendo assim, se mudarmos o método "sleep" na classe animal, iremos mudar este método para todas as outras classes
class Coelho(Animal):
    def run(self):
        print("O coelho está correndo")
class Peixe(Animal):
    def nadar(self):
        print("O peixe está nadando")
class Falcao(Animal):
    def voar(self):
        print("O falcao está voando")
```

Podemos ainda criar uma classe filha da filha, que terá todas as caracterísitcas a classe mãe e "avó", bem como as suas. 

Podemos ainda criar uma classe que tenha duas mães, separando por vírgula. Imagine que um coelho cruzou com um falcão (ignore a biologia por hora), e assim, teremos um falelho:
```Python
class Falelho (Falcao, Coelho)
	def voar_pulando(self):
		pass
```
Observe que está classe será neta da classe Animal, e filha das classes Coelho e Falcão, terá todas as qualidades das classes Coelho e Falcão, bem como da classe Animal.

Além disso, existe uma coisa chamada "method overriding". Se reescrevermos um método na classe filha com a mesma signature da classe mãe, podemos alterar o conteúdo do método para aquela classe filha.

# Method Chaining

Usado para chamar diversos métodos em sequência
Exemplo, imagine um objeto chamado carro, que advém de uma classe com 4 métodos:
```Python
#Jeito estúpido de chamar a todos:
car.ligar()
car.dirigir()
car.para()
car.desligar()

#Jeito massa de chamar todos:
car.ligar().dirigir().para().desligar()

#ou ainda:
car.ligar()\
	.dirigir()\
	.para()\
	.desligar()
```
Perceba entretanto, que estamos chamando cada método como atributo um do outro. Para que isto funcione, cada método deve então retornar o atributo "self", com "return self", para indicar que o atributo é ele mesmo. Devemos fazer esta alteração direto na declaração do método na classe.

# Super function

Utilizado para acessar metodos da classe pai de uma classe, pelo retorno de um proxy temporário da classe que pode ser utilizado para chamar métodos da classe superior.

É utilizado quando queremos criar classes que estendam as funcionalidades da classe pai, por exemplo:
Temos uma classe square:
```python
class Square:
    def __init__(self, side):
        self.side = side

    def area(self):
        return self.side * self.side
```
Square tem o atributo side e um método para calcular a área
Vamos criar agora uma classe filha de quare chamada cube, e com a ajuda da função super vamos implementar o método surface_area sem termos que reescrever o método para calcular a área:
```python
class Cube(Square):
    def __init__(self, side):
      super().__init__(side)
      
    def surface_area(self):
        # Using super to access area()
        face_area = super().area()
        return face_area * 6
```
 Para resumir, super() retorna um objeto temporário da classe pai que nos permite chamar um método dela.
 Texto traduzido e copiado de: https://www.scaler.com/topics/super-in-python/

# Abstract Class

Imagine que temos diversas classes, uma pai, e todas as outras filhas. Queremos que a classe pai seja somente um template, e que não seja possível de criar um objeto a partir dela. Para isso, a transformamos numa classe abstrata.

```Python
from abc import ABC, abstractmethod #importando o método

#criando a classe pai que será abstrata. Veja que temos que colocar ABC como parâmetro da classe e colocar @abstractmethod no começo. Assim, não conseguiremos declarar objetos desta classe.
class Abstrata(ABC):
	@abstractmethod
	def metodo(self):
		pass

#classe filha, que funciona normalmente
class Filha(Abstrata):
	def metodo(self):
		pass
	def metodo_filha(self):
		pass
```
Observe que ao implementer isto, devemos reescrever todos os métodos da função pai na função filha, senão teremos erro.

# Walrus Operator

Como Python é uma linguagem não tipada, a gente pode criar, atribuir e usar uma variável direto dentro de uma expressão, desde que utilizando o Walrus:
```Python
#CÓDIGO ERRADO:
print (valor=5)
#output:
#TypeError: 'valor' is an invalid keyword argument for print()

#CÓDIGO CORRETO:
print (valor:=5)
#output:
#5
```

Isso é extremamente útil para reduzir linhas de código

# Funções para variáveis:

Podemos armazenar o endereço de uma função numa variável, e então utilizar a variável como a função.
```Python
def oi(): #define a função
	print("Oi")

ola = oi #salva o endereço numa variável

ola() #kabum variável vira função
```

# Higher Order Functions

Funções que aceitam outras funções como argumento ou então retornam outras funções

Exemplo do useo de uma função como argumento:
```Python
def gritar(text): #Criamos uma função que tem como argumento algum texto
	return text.upper() #iremos retornar o texto todo em maiúsculo

def hello(func): #criamos uma função que tem como argumento alguma função
	text = func ("hello") #aplicamos a função do argumento em "hello" e atribuimos a text
	print (text) #printamos text

hello(gritar) #chamamos a função hello e usamos como argumento a função gritar

#output:
#HELLO
```

Exemplo de uma função retornando outra função:
```Python
def divisor(x):
	def dividend(y):
		return y/x
	return dividend	

divide = divisor(2)
print(divide(10))

#output:
#5.0
```
Começamos passando 2 para a função do divisor, porém ainda não chamamos a função dividend, então, simplesmente retornamos o seu valor de memória (por causa do return dividend), que é atribuido a variável divide. Ao printarmos a variável divide, estamos chamando, portanto a função dividend, que irá realizar a operação y/x, e então printar o resultado.

# Lambda functions

Funções escritas numa linha de código usando a keyword lambda. Aceitam qualquer quantidade de argumentos, mas tem somente uma expressão. Imagine que se trata de um atalho, e são úteis quando necessárias por um curto período de tempo, descartáveis.

```Python
#função padrão:
def double(x):
	return x*2

print (double(5))

#função lambda
double = lambda x: x * 2

print(double(5))

#outro exemplo de função lambda
multiply = lambda x, y: x * y

print(multiply(2,5))
```

# Sort

Podemos usar o sort method (que só funciona com listas)
```Python
food = ["Pizza","hamburger","hotdog","espaguete"]
food.sort() #coloca em ordem alfabética
food.sort(reverse=True) #ordem alfabética, mas ao contrário
```

Caso queiramos utilizar uma tuple, por exemplo, devemos usar uma função:
```Python
food = ("Pizza","hamburger","hotdog","espaguete")
sorted_food = sorted(food)
```
Observe que apesar de estarmos utilizando uma tuple como argumento, ele irá retornar uma lista. 

# Map

Aplica uma função para todos os itens de um iterable

Ex de aplicação:
```Python
store = [("shirt",20), #criamos o catálogo de uma loja
		("socks",8),
		("shoes",90),
		("jacket",100),]

usd_eur = lambda data: (data[0],data[1]*0.82) #criamos uma função que converte de dolar para euro

store_eur = list(map(usd_eur, store)) #criamos uma outra lista (declaração pelo list) e aplicamos o map, que irá aplicar para cada uma das tuples dentro da lista a função usd_eur

for i in store_eur: #printamos o catálogo da loja com os preços atualizados
	print(i)
```

# Filter function

Filtra um conjunto de iterables, retornando somente aqueles que passam numa função

Exemplo de código:
```Python
amigos = [("Clebao", 19), #lista de amigos
         ("Pedrao", 15),
         ("Julhao", 17),
         ("Lucao", 21),]
  
pode_beber = lambda data: data[1]>=18 #cria uma função que verifica quem pode beber

colegas_de_bar = list(filter(pode_beber,amigos)) #crio uma outra lista, onde aplico a função filter, que irá filtrar com base na função pode_beber na lista amigos. Igualo esta lista a "colegas de bar"

for i in colegas_de_bar: #Printo quem são meus colegas de bar
    print(i)
```

# Reduce 

Aplica uma função a um iterable e o reduz a um valr cumulativo, performando a função nos dois primeiros elementos e repetindo até somente sobrar um valor

```Python
import functools #importamos a biblioteca que contém a função reduce

#criamos uma lista com todas as letras de salve
letras = ["S","A","L","V","E"]

#criamos uma função que recebe dois argumentos (pois a função reduce irá passar 2 elementos, sendo sempre os dois primeiros elementos do iterble) e que realiza a concatenação deles
juncao = lambda letra1, letra2: letra1 + letra2

#aplicamos a função reduce para criar a palavra salve
salve = functools.reduce(juncao,letras)

#salve
print(salve)
```

# List Comprehensions

Uma forma de criar uma lista com menos sintaxe, de forma mais legível.

Exemplo de código:
```Python
#SINTAXE:
#list = [expressação para o item no terable]

#criando um programa que gera os quadrados dos numeros entre 1 e 10, com sintaxe normal:
squares = []
for i in range(1,11):
    squares.append(i*i)
print (squares)

#mesmo programa, mas com list comprehension:
squares_=[i * i for i in range(1,11)]
print(squares)

#outro código, desta vez checando quais alunos passaram de ano
notas = [100,90,80,70,60,50,40,30,20,10,0]
passaram = [i if i>=60 else "FAILED" for i in notas]
print(passaram)
```

# Dictionary comprehensions

Mesma coisa que os lists comprehensions, mas com dicionários
```Python
#SINTAXE
#dicionário = {key: expression for (key,value) in iterable}
#dicionário = {key: expression for (key,value) in iterable if conditional}

#exemplo da primeira "fórmula"
cidades_em_F = {"SP":100,"RJ":110,"POA":80}
cidades_em_C = {key: round((value-32)*5/9) for (key,value) in cidades_em_F.items()}
print(cidades_em_C)
```

# Zip function

Cria um elemento Zip com elementos pareados de dois elementos de dois iterables em uma tuple pra cada elementos:

```Python
#zip(iterables)
usernames = ["Dude", "Bro", "Mister"]
senhas = ("senha", "abc123", "guest")
users = zip(usernames,senhas)
for i in users:
    print(i)
```

# if __name__ == '__main__':

Quando importamos um módulo para dentro de um arquivo, todo o módulo sendo chamado é executado, exceto aquilo que está dentro de:
```Python
if __name__ == '__main__':
```
Assim, quando estivermos programando um módulo, podemos testar o módulo a parte, rodando somente o módulo, programando oteste dentro desta condição, sem precisar rodar todo o script.

A variável __name__ é uma variável definida automaticamente pelo python no momento em que executamos um código. Quando executamos o arquivo diretamente, a variável irá igualar a __main__, e portanto, o que está dentro desta condição, roda. Desta forma, tudo que está dentro deste if só irá rodar caso lacenmos o arquivo em questão diretamente,

# Modulo time

Funções massas do módulo time
```Python
import time  

print(time.ctime(0)) #converte o tempo a partir da epoch para uma string legível
print(time.time()) #printa o tempo em segundos desde o epoch (com base no relógio do pc)
print(time.ctime(time.time()))#utilizamos ambos, conseguimos pegar a data atual
print(time.localtime())#cria um objeto de tempo com o tempo atual
print(time.gmtime())#tempo no meridiano de gremwich (objeto de tempo)
```

# Threading

thread = flow of execution
Com multithreading, conseguimos fazer o programa rodar diferentes partes de si ao mesmo tempo, somente uma thread irá rodar por vez, mas rodam em "turnos". Rodar duas threads ao mesmo paralelamente se chama multiprocessing.

existem dois tipos de tasks, primariamente:

cpu bound: passam a maior parte do tempo esperando por eventos internos (CPU intentese work), utilizamos multiprocessing

io bound: ficam a maior parte do tempo esperando por eventos externos (user input), use multithreading

Exemplo de código:
```Python
#importando as bibliotecas importantes
import threading
import time
  
print(threading.active_count()) #exibe quantas threads estão rodando
print(threading.enumerate())#exibe quais threads estão rodando

#definindo funções. Observe que a função sleep interrompe o flow do código
def comerpao():
    time.sleep(3)
    print("Comemos pão")

def tomarcafe():
    time.sleep(3)
    print("Bebemos café")

def estudar():
    time.sleep(3)
    print("Estudamos")

#aqui, estaremos interrompendo a execução do código três vezes por 3 segundos, então o código irá demorar 9 segundos para ser concluido. Isto porque temos somente uma thread cuidando destas 3 funções
comerpao()
tomarcafe()
estudar()

#criando uma thread para cuidar só da função comerpao
x = threading.Thread(target=comerpao, args=())
x.start()
#criando threads para os outros bgls
y = threading.Thread(target=tomarcafe, args=())
y.start()
z = threading.Thread(target=estudar, args=())
z.start()
#Agora, todo o programa demorou 3 segundos, pq temos diferentes flows rodando ao mesmo tempo.
```

Temos também daemon threads, que rodam no background e não são importantes para rodar o programa. O program anão irá esperar estas threads serem concluidas antes de fechar.

```Python
#importando as bibliotecas importantes
import threading
import time

def timer():
    print()
    count = 0
    while True:
        time.sleep(1)
        count += 1
        print("logado por {}s".format(count))

#declaramos esta thread como uma daemon, isso significa que quando main thread terminar, está será terminada automaticamente. Se não fizéssemos isto, o código iria ficar rodando para sempre.
tempo = threading.Thread(target=timer, daemon=True)
tempo.start()

answer = input("Deseja sair?")
```

# Multiprocessing

Rodar tarefas em paralelo em diferentes cores da cpu

```Python
#importando a porra toda
from multiprocessing import Process, cpu_count
import time
#criando uma função que conta
def counter(num):
    count=0
    while count<num:
        count+=1

def main(): #função mains, explicada mais tarde
    #criando diferentes tasks
    a = Process(target=counter, args=(25000000,))
    b = Process(target=counter, args=(25000000,))
    c = Process(target=counter, args=(25000000,))
    d = Process(target=counter, args=(25000000,))
    #iniciando diferentes tasks
    a.start()
    b.start()
    c.start()
    d.start()
    #impedindo que o programa não seja terminado antes de todos as tasks forem concluidas
    a.join()
    b.join()
    c.join()
    d.join()

    #Observe que não adianta ficar colocando mais tasks ao mesmo tempo do que o número de cores que o processador tem. No meu caso, como é um FX6300, um sixcore, pouco adianta iniciar 7 tasks, por exemplo. O código vai funcionar, mas não vai ser no tempo ótimo.
if __name__ == '__main__': #precisamos fazer isso porque senão quando iniciarmos outros processos eles iriam iniciar outros processos que iriam iniciar outros processos e iria ser radical
    main()
```

# GUI

BORA CRIAR INTERFACE GRÁFICA

```Python
from tkinter import * 

window = Tk() #instantiate an instance of a window  

window.title("Minha primeira GUI")#altera o nome da janela

icon = PhotoImage(file="shrek.png")#converte de png para photoimage, o tipo de arquivo que conseguimos setar como icone. Observe que a imagem deve estar na mesma pasta que o script

window.iconphoto(True, icon)#setamos o icone da janela

window.geometry("1000x500")#seta o tamanho da janela

window.config(background="#eb4034")#seta a cor de fundo para um hex value

window.mainloop()#exibe a janela
```

Agora, podemos colocar labels. Labels são áreas onde podemos colocar elementos, por exemplo:
```Python
from tkinter import *

window = Tk() #instantiate an instance of a window 

label = Label(window,text="Hello World")#inicia a label na window "window", e colocamos um texto, "Hello World"
label.place(x=0,y=0) #exibe a label nas coordenadas determinadas
#label.pack() outra forma de exibir a label, neste caso, sempre será no meio para cima

window.mainloop()#exibe a janela
```
Brincando um pouco mais:
```Python
from tkinter import *

window = Tk() #instantiate an instance of a window

emoji = PhotoImage(file='emoji.png') #fazemos a conversão da imagem que vamos colocar na label

label = Label(window,text="Hello World",
                    font=('Arial',40,'bold'),
                    fg='#fcba03',
                    bg='black',
                    relief=RAISED,
                    bd=10,
                    padx=20,
                    pady=20,
                    image=emoji,
                    compound='top')
#inicia a label na window "window", e colocamos um texto, "Hello World", mudamos a fonte, a sua cor (fg) e a cor da label (bg). Colocamos borda com relief e setamos a sua espessura (bd). Adicionamos padding com padx e pady. Colocamos uma imagem com image e dizemos que queremos ela acima do texto com compound='top'

label.pack() #exibe a label
window.mainloop()#exibe a janela
```

Também podemos colocar botões na gui:
```Python
from tkinter import *

def click(): #função de callback do botão
    print("Você apertou o botão!")

window = Tk() #instantiate an instance of a window

emoji = PhotoImage(file='emoji.png') #fazemos a conversão da imagem que vamos colocar na label

botao = Button(window, #criamos um botão
                text="Clique-me", #texto do botão
                command=click, #definimos qual função será o callback do botão
                font=("Streetwear",30), #colocamos uma fonte no botão
                fg="white", #setamos o foreground e o background, observe que temos que definir os ativos tbm, quando o botão é pressionado
                bg="black",
                activebackground="black",
                activeforeground="white",
                state=ACTIVE, #queremos que o botão esteja ativo, ou seja, possa ser pressionado
                image=emoji, #colocamos uma imagem no botão
                compound='bottom') #a imagem ficará embaixo do texto
botao.pack() #exibimos o botão

window.mainloop()#exibe a janela
```

Pegando info do usuário:
```Python
from tkinter import *

window = Tk() #instantiate an instance of a window
texto = Entry(window, #criamos uma entry box

            font=("Arial",50))
texto.pack() #colocamos a entry box na tela

username = texto.get() #pegamos a informação da entrybox e associamos ela a username  

window.mainloop()#exibe a janela
```
Observe que coisas como a foreground color, background color, state, compound e afim continuam válidas, mas aqui temos uma nova, a "show", que deve ser igualada  ao caractere que irá substituir no texto.

Além desses, temos muitos outros elementos que podemos adicionar, como checkboxes, listboxes, sliders, radio buttons, canvas, menubars,

Uma das funcionalidades mais legais é o filedialog, que abre uma janela para procurarmos o arquivo, e retorna o diretório do arquivo selecionado:
```Python
from tkinter import *
from tkinter import filedialog

filepath = filedialog.askopenfilename()
print (filepath)
```
Neste simples código, poderemos escolher o arquivo e printaremos o seu diretório.
Podemos usar isto tanto para buscar arquivos quanto salvar arquivos. 

Além disso, podemos criar um "frame", e colocar diversos gidgets agrupados dentro dele. Assim, quando quisermos mudar algo de posição na tela, ao invés de mover todos os elementos, podemos mover somente o frame.

Também podemos criar novas janelas, com auxílio do comando "TopLevel()", que funciona exatamente igual ao comando "Tk()". A principal diferença entretanto é que o Tk() gera uma janela totalmente independetente, enquanto "TopLevel()" cria uma janela ligada associada a outra janela. Quando fechamos a janela a qual a janela associada está ligada, a janela secundária fecha tabém.

Podemos adicionar TABs a uma janela também, iremos precisar importar o submódulo tkk, do tkinter. Então criamos um Notebook, e adicionamos frames a este notebook.

**IMPORTANTE**
Uma maneira de colocar tudo na tela de maneira organizada é substituir a função "pack()" pela função "grid(row=,column=)". Imagine que a janela se comporta como uma planilha de excel, com esta função, podemos dizer onde cada widget deve ficar explicitamente.

Outra coisa interessante é uma progress bar, que adicionamos com ProgressBarr(janela, orient=, lenght=), e alteramos o quão cheia está a barra com nome_da_barra['value']+=valor. Podemos ainda, colocar a porcentagem juntamente com algum outro texto.

Podemos também criar um canva com Canvas(janela,height,width), e lá podemos colocar polígonos, linhas, retângulos, arcos, etc... (ex: canvas.create_line(0,0,500,500,fill="blue",width=5), criamos uma linha que vai de 0/0 a 500/500 (os pontos que determinam o começo e o final da linha), ela será azul e de 5 pixels de espessura)

Podemos ainda bindar um evento do teclado a uma janela ou widget com a função bind.
ex:
```Python
def doSomething(event):
	print("you did something")
	
window.bind("<Return>",doSomething)
```
Aqui, ao pressionarmos enter, iremos chamar a função doSomething, que irá printar "you did something" no terminal. Também podemos utilizar os botões do mouse:
	- Button-1: botão esquerdo
	- Button-2: botão do scroll
	- Button-3:  botão direito
Podemos ainda pegar a posição do evento com event.x e event.y
Podemos ainda utilizar no lugar dos botões Enter, Leave, Motion, que determinam, respectivamente, quando o mouse entrou num widget, saiu, ou se simplesmente está em movimento.

Para realizar estes conceitos, foram realizados alguns exercícios demonstrados durante o curso, e estão nesta mesma pasta, como o drag and drop e move keys. Entretanto, ainda é possivel fazermos muitas coisas, como criar animações, por exemplo.

# Envio de email

```Python
sender = "sender@gmail.com"
receiver = "receiver@gmail.com"
password = "password"
subject = "Python email test"
body = "Email..."

#header
message = f"""From: {sender}
To: {receiver}
Subject: {Subject}\n
"""

server = smtplib.SMTP("smtp.gmail.com", 587)
server.starttls()

server.login(sender, password)
print("Logged in")
server.sendmail(sender, receiver, message)
print("Email has been sent")
```

# Comandos legais do PIP
help: pip
check: pip --version
update: pip install --upgrade pip
installed packages: pip list
check outdated packages: pip list --outdated
update a package: pip install "package name" --upgrade
install a package: pip install "package name"

# Converting .py to .exe
No terminal, na pasta onde temos o arquivo:
pyinstaller -F -w -i icon.ico clock.py

Aqui estamos convertendo o clock.py. Observe que estamos colocando um ícone (que deve estar em formato .ico). Se não quiser colocar um ícone ao programa, apenas remova o -i e o nome do ícone.