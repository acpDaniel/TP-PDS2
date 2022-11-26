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
    int _idJogador;
    int _idDupla;
    bool _pedindoTruco = false;
    bool _aceitandoTruco = false;

public:
    Jogador();
    Jogador(std::string nome, int idDupla, int idJogador);
    virtual bool pedirTruco();
    virtual bool aceitarTruco();
    int getPontos();
    void adicionaPontos(int pontos);
    std::string getNome();
    virtual Carta jogarCarta(int indice);
    void setMao(std::vector<Carta> mao);
};
#endif