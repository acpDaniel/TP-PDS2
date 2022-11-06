#include "../include/carta.hpp"
#include "../include/baralho.hpp"
#include "../include/jogador.hpp"
#include "../include/humano.hpp"

#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>

bool Humano::pedirTruco()
{
    _pedindoTruco = true;
    return 1;
}

bool Humano::aceitarTruco(bool aceitarTruco)
{
    if (aceitarTruco == true)
    {
        return 1;
    }
    else
        return 0;
}

bool Humano::aumentarTruco(bool aumentarTruco)
{
    if (aumentarTruco == true)
    {
        return 1;
    }
    else
        return 0;
}

Carta Humano::jogarCarta(int indice)
{
    // logica para selecionar uma das 3 cartas, ja que o iterator begin retorna o endereço para primeira posicao
    std::list<Carta>::iterator it = _mao.begin();
    if (indice == 1)
    {
        ++it;
    }
    else if (indice == 2)
    {
        ++it;
        ++it;
    }
    Carta cartaSelecionada = *(it);
    _mao.erase(it);
    return cartaSelecionada;
}