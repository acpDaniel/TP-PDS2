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
        Carta _cartaSelecionada1 = sortearCarta();
        _maoJogador1.push_back(_cartaSelecionada1);
        deletarCartaBaralho(_cartaSelecionada1);
    }

    for (int i = 0; i < 3; i++)
    {
        Carta _cartaSelecionada2 = sortearCarta();
        _maoJogador2.push_back(_cartaSelecionada2);
        deletarCartaBaralho(_cartaSelecionada2);
    }

    for (int i = 0; i < 3; i++)
    {
        Carta _cartaSelecionada3 = sortearCarta();
        _maoJogador3.push_back(_cartaSelecionada3);
        deletarCartaBaralho(_cartaSelecionada3);
    }

    for (int i = 0; i < 3; i++)
    {
        Carta _cartaSelecionada4 = sortearCarta();
        _maoJogador4.push_back(_cartaSelecionada4);
        deletarCartaBaralho(_cartaSelecionada4);
    }
}