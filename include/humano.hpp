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
    bool pedirTruco();
    bool aceitarTruco(bool aceitarTruco);
    bool aumentarTruco(bool aumentarTruco);
    Carta jogarCarta(int indice);
};

#endif