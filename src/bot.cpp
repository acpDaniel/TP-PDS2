#include "../include/carta.hpp"
#include "../include/baralho.hpp"
#include "../include/jogador.hpp"
#include "../include/bot.hpp"

#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>

Bot::Bot(){};

Bot::Bot(std::string nome, int idDupla, int idJogador) : Jogador(nome, idDupla, idJogador){};

bool Bot::pedirTruco()
{
    // numero aleatorio de 1 a 10
    int numAleatorio = rand() % 10 + 1;
    // se o numeroAleatorio for maior igual a 7, vai pedir truco
    if (numAleatorio >= 7)
    {
        return 1;
    }
    else
        return 0;
}

bool Bot::aceitarTruco()
{
    // numero aleatorio de 1 a 10
    int numAleatorio = rand() % 10 + 1;
    // se o numeroAleatorio for maior igual a 7, vai aceitar o truco
    if (numAleatorio >= 7)
    {
        return 1;
    }
    else
        return 0;
}

bool Bot::aumentarTruco()
{
    // numero aleatorio de 1 a 10
    int numAleatorio = rand() % 10 + 1;
    // se o numeroAleatorio for maior igual a 9, vai aumentar o truco
    if (numAleatorio >= 9)
    {
        return 1;
    }
    else
        return 0;
}

Carta Bot::jogarCarta()
{
    // numero aleatorio entre 0 e o tamanho do vetor de cartas
    int random = rand();
    Carta &primeiraCarta = _mao[0];
    int numAleatorio = (random % _mao.size());
    // se o numAleatorio nao for 0, temos que diminuir 1 para ser a posiçao 0 ou 1 ou 2 do vetor de cartas
    if (numAleatorio != 0)
    {
        numAleatorio = numAleatorio - 1;
    }
    std::vector<Carta>::iterator it = _mao.begin();
    if (numAleatorio == 1)
    {
        ++it;
    }
    else if (numAleatorio == 2)
    {
        ++it;
        ++it;
    }
    Carta cartaSelecionada = *(it);
    _mao.erase(it);
    std::cout << "A carta selecionada foi " << cartaSelecionada.getNome() << std::endl;
    return cartaSelecionada;
}

// ainda sujeito a testes