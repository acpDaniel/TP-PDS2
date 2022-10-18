#include "../include/carta.hpp"
#include "../include/baralho.hpp"

#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>

Carta Baralho::sortearCarta()
{
    // checar se essa funçao funciona
    srand(time(NULL));
    int numSorteio = rand() % 40;
    int i = 0;
    for (std::list<Carta>::iterator it = _baralho.begin(); i <= numSorteio; ++it)
    {
        if (i == numSorteio)
        {
            return *it;
        }
        i++;
    }
}

void Baralho::inserirCartaBaralho(Carta carta)
{
    _baralho.push_back(carta);
}

void Baralho::deletarCartaBaralho(Carta carta)
{
    _baralho.remove(carta); // checar esse remove dps
}

void Baralho::inicializarMaoJogadores()
{
    for (int i = 0; i < 3; i++)
    {
        Carta _cartaSelecionada = sortearCarta();
        _maoJogador1.push_back(_cartaSelecionada);
        deletarCartaBaralho(_cartaSelecionada);
    }

    for (int i = 0; i < 3; i++)
    {
        Carta _cartaSelecionada = sortearCarta();
        _maoJogador2.push_back(_cartaSelecionada);
        deletarCartaBaralho(_cartaSelecionada);
    }

    for (int i = 0; i < 3; i++)
    {
        Carta _cartaSelecionada = sortearCarta();
        _maoJogador3.push_back(_cartaSelecionada);
        deletarCartaBaralho(_cartaSelecionada);
    }

    for (int i = 0; i < 3; i++)
    {
        Carta _cartaSelecionada = sortearCarta();
        _maoJogador4.push_back(_cartaSelecionada);
        deletarCartaBaralho(_cartaSelecionada);
    }
}