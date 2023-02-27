
#importa a biblioteca random
import random

dnv = "s" #define o valor de "dnv", utilizado pra saber se o jogador quer jogar de novo

while dnv == "s":

    #pega a informação do usuário
    user = input("Diga-me jogador, qual a  sua jogada? 'pedra', 'papel, ou 'tesoura'? ")
    if (user != "pedra") and (user != "papel") and (user != "tesoura"):
        print("Insira uma jogada válida!")
    else:
        #determina a jogada do pc com base nos valores de uma lista
        opcoes_pc = ["pedra", "papel", "tesoura"]
        pc = opcoes_pc[random.randint(0,2)]

        #determina quem venceu
        if user==pc:
            print ("Você escolheu {}, e o computador escolheu {}. Vocês empataram!".format(user, pc))
        elif (user == "papel" and pc == "pedra") or (user == "tesoura" and pc == "papel") or (user == "pedra" and pc == "tesoura"):
            print ("Você escolheu {}, e o computador escolheu {}. Você venceu!".format(user, pc))
        else:
            print ("Você escolheu {}, e o computador escolheu {}. Você perdeu!".format(user, pc))

    #pergunta se o jogador quer jogar novamente
    dnv = input("Deseja jogar de novo? Se sim, digite 's': ")



