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
    std::vector<Carta> _baralho;
    std::vector<Carta> _maoJogador1;
    std::vector<Carta> _maoJogador2;
    std::vector<Carta> _maoJogador3;
    std::vector<Carta> _maoJogador4;

public:
    int sortearCarta();
    void inserirCartaBaralho(Carta carta);
    void deletarCartaBaralho(int indice);
    void inicializarMaoJogadores();
};

#endif