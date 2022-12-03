#ifndef BOT_HPP
#define BOT_HPP

#include "carta.hpp"
#include "baralho.hpp"
#include "jogador.hpp"
#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>

class Bot : public Jogador
{
public:
    Bot();
    Bot(std::string nome, int idDupla, int idJogador);
    bool pedirTruco() override;
    bool aceitarTruco() override;
    Carta jogarCarta(int numAleatorio);
};

#endif
