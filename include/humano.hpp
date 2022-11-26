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

class ErroEscolhaCartaInvalida : public std::exception
{
public:
    virtual const char *what() const noexcept
    {
        return "Numero para selecionar cartas invalido";
    }
};

class Humano : public Jogador
{
public:
    Humano();
    Humano(std::string nome, int idDupla, int idJogador);
    void imprimeCartasJogador();
    void msgSelecionarCartas();
    void checaIndice(int indice);
    Carta jogarCarta(int indice) override;
};

#endif
