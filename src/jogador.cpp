#include "../include/carta.hpp"
#include "../include/baralho.hpp"
#include "../include/jogador.hpp"

#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>

Jogador::Jogador(std::string nome, std::list<Carta> mao, int idDupla)
{
    _nome = nome;
    _mao = mao;
    _idDupla = idDupla;
}

void Jogador::pedirTruco()
{
    _pedindoTruco = true;
}

void Jogador::aceitarTruco()
{
    _aceitandoTruco = true;
}

bool Jogador::aumentarTruco()
{
    return true;
}

int Jogador::getPontos()
{
    return _pontos;
}

void Jogador::adicionaPontos(int pontos)
{
    _pontos += pontos;
}

std::string Jogador::getNome()
{
    return _nome;
}

Carta Jogador::jogarCarta(int indice)
{
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