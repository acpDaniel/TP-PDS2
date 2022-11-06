#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include "carta.hpp"
#include "baralho.hpp"
#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>

class Jogador
{
protected:
    std::string _nome;
    std::vector<Carta> _mao;
    int _pontos = 0;
    int _idDupla;
    bool _pedindoTruco = false;
    bool _aceitandoTruco = false;

public:
    // std::list<Carta> _mao;

    Jogador(std::string nome, std::vector<Carta> mao, int idDupla);
    void pedirTruco();
    void aceitarTruco();
    bool aumentarTruco();
    int getPontos();
    void adicionaPontos(int pontos);
    std::string getNome();
    Carta jogarCarta(int indice);
};
#endif