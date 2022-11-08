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
    // DEBUG std::vector<Carta> _baralho;
    int sortearCarta();
    void inicializarBaralhoCompleto();
    void inserirCartaBaralho(Carta carta);
    void deletarCartaBaralho(int indice);
    void inicializarMaoJogadores();
    void resetarBaralhoEMaoJogadores();
    std::vector<Carta> getMaoJogador1();
    std::vector<Carta> getMaoJogador2();
    std::vector<Carta> getMaoJogador3();
    std::vector<Carta> getMaoJogador4();
};

#endif