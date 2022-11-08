#ifndef RODADA_HPP
#define RODADA_HPP

#include "carta.hpp"
#include "baralho.hpp"
#include "jogador.hpp"
#include "humano.hpp"
#include "bot.hpp"

#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>

class Rodada
{
    std::vector<Carta> _cartasDupla1Mesa;
    int _vitoriasParciaisDupla1 = 0;
    std::vector<Carta> _cartasDupla2Mesa;
    int _vitoriasParciaisDupla2 = 0;
    int _pontuacaoRodadaAtual = 2;

public:
    void inserirCartaDupla1(Carta carta);
    void inserirCartaDupla2(Carta carta);
    int checagemDuplaVencedora();
    void checagemVitoriaParcial();
    void imprimeCartas();
};
#endif