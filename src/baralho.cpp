#include "../include/carta.hpp"
#include "../include/baralho.hpp"

#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>

int Baralho::sortearCarta()
{
    int indiceCarta = rand() % _baralho.size();
    return indiceCarta;
}

void Baralho::inserirCartaBaralho(Carta carta)
{
    _baralho.push_back(carta);
}

void Baralho::deletarCartaBaralho(int indice)
{
    auto it = _baralho.begin();
    for (int i = 0; i < indice; i++)
    {
        ++it;
    }
    _baralho.erase(it);
}

void Baralho::inicializarMaoJogadores()
{
    for (int i = 0; i < 3; i++)
    {
        Carta _cartaSelecionada1 = _baralho[sortearCarta()];
        _maoJogador1.push_back(_cartaSelecionada1);
        deletarCartaBaralho(_cartaSelecionada1.getId());
    }

    for (int i = 0; i < 3; i++)
    {
        Carta _cartaSelecionada2 = _baralho[sortearCarta()];
        _maoJogador2.push_back(_cartaSelecionada2);
        deletarCartaBaralho(_cartaSelecionada2.getId());
    }

    for (int i = 0; i < 3; i++)
    {
        Carta _cartaSelecionada3 = _baralho[sortearCarta()];
        _maoJogador3.push_back(_cartaSelecionada3);
        deletarCartaBaralho(_cartaSelecionada3.getId());
    }

    for (int i = 0; i < 3; i++)
    {
        Carta _cartaSelecionada4 = _baralho[sortearCarta()];
        _maoJogador4.push_back(_cartaSelecionada4);
        deletarCartaBaralho(_cartaSelecionada4.getId());
    }
}
