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
    // std::list<Carta> _mao;
    /** DEBUG std::vector<Carta> _mao;
    int _idDupla;
    bool _pedindoTruco = false;
    bool _aceitandoTruco = false;**/
    Jogador(std::string nome, int idDupla, int idJogador);
    void pedirTruco();
    void aceitarTruco();
    bool aumentarTruco();
    int getPontos();
    int getIdJogador();
    void adicionaPontos(int pontos);
    std::string getNome();
    Carta jogarCarta(int indice);
    void setMao(std::vector<Carta> mao);
};
#endif