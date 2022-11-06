#include "../include/carta.hpp"
#include "../include/baralho.hpp"
#include "../include/jogador.hpp"
#include "../include/bot.hpp"
#include "../include/humano.hpp"
#include "../include/rodada.hpp"

#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>

void Rodada::inserirCartaDupla1(Carta carta)
{
    _cartasDupla1Mesa.push_back(carta);
}

void Rodada::inserirCartaDupla2(Carta carta)
{
    _cartasDupla2Mesa.push_back(carta);
}

// checagem de vitoria de cada queda da md3 que compoe a rodada
void Rodada::checagemVitoriaParcial()
{
    int pesoMaiorCartaDupla1 = _cartasDupla1Mesa[0].getPeso();
    if (_cartasDupla1Mesa[1].getPeso() > pesoMaiorCartaDupla1)
    {
        pesoMaiorCartaDupla1 = _cartasDupla1Mesa[1].getPeso();
    }

    int pesoMaiorCartaDupla2 = _cartasDupla2Mesa[0].getPeso();
    if (_cartasDupla2Mesa[1].getPeso() > pesoMaiorCartaDupla2)
    {
        pesoMaiorCartaDupla2 = _cartasDupla2Mesa[1].getPeso();
    }

    if (pesoMaiorCartaDupla1 > pesoMaiorCartaDupla2)
    {
        _vitoriasParciaisDupla1 = _vitoriasParciaisDupla1 + 1;
    }
    else
        _vitoriasParciaisDupla2 = _vitoriasParciaisDupla2 + 1;

    _cartasDupla1Mesa.clear();
    _cartasDupla2Mesa.clear();
}

// checagem de vitoria da rodada
int Rodada::checagemDuplaVencedora()
{
    if (_vitoriasParciaisDupla1 == 2)
    {
        return 1;
    }
    else if (_vitoriasParciaisDupla2 == 2)
    {
        return 2;
    }
}

void Rodada::imprimeCartas()
{
    std::cout << "Cartas da dupla 1 :";
    for (int i = 0; i < _cartasDupla1Mesa.size(); i++)
    {
        std::cout << _cartasDupla1Mesa[i].getNome() << " ";
    }
    std::cout << '\n';
    std::cout << "Cartas da dupla 2 :";
    for (int i = 0; i < _cartasDupla2Mesa.size(); i++)
    {
        std::cout << _cartasDupla2Mesa[i].getNome() << " ";
    }
}