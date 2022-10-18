#ifndef BARALHO_HPP
#define BARALHO_HPP

#include "carta.hpp"
#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>

class Baralho
{
private:
    std::list<Carta> _baralho;
    std::list<Carta> _maoJogador1;
    std::list<Carta> _maoJogador2;
    std::list<Carta> _maoJogador3;
    std::list<Carta> _maoJogador4;

public:
    Carta sortearCarta();
    void inserirCartaBaralho(Carta carta);
    void deletarCartaBaralho(Carta carta);
    void inicializarMaoJogadores();
};

#endif