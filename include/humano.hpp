#ifndef HUMANO_HPP
#define HUMANO_HPP

#include "carta.hpp"
#include "baralho.hpp"
#include "jogador.hpp"
#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>

class Humano : public Jogador
{
public:
    Humano(std::string nome, std::vector<Carta> mao, int idDupla);
    bool pedirTruco();
    bool aceitarTruco(bool aceitarTruco);
    bool aumentarTruco(bool aumentarTruco);
    void imprimeCartasJogador();
    Carta jogarCarta(int indice);
};

#endif
