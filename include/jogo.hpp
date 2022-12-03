#ifndef JOGO_HPP
#define JOGO_HPP

#include "carta.hpp"
#include "baralho.hpp"
#include "jogador.hpp"
#include "humano.hpp"
#include "bot.hpp"
#include "rodada.hpp"
#include "menu.hpp"

#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>

class ErroNumeroInvalidoPedidoTruco : public std::exception
{
public:
    virtual const char *what() const noexcept
    {
        return "Entrada invalida, os numeros permitidos sao 1 ou 2";
    }
};

class Jogo
{
public:
    Menu menuJogo;
    Baralho baralhoDaQueda;
    Rodada rodadaAtual;
    Humano usuario;
    Bot bot1;
    Bot bot2;
    Bot bot3;

    Jogo();
    void inicializaBaralho();
    void sequenciaJogadasIniciandoUsuario();
    void sequenciaJogadasIniciandoBot1();
    void sequenciaJogadasIniciandoBot2();
    void sequenciaJogadasIniciandoBot3();
    void sequenciaJogadasMd3(int idMaior);
    void checaPedidoTrucoJogador();
    void checaPedidoTrucoBot1(int jaPediu);
    void checaPedidoTrucoBot2();
    void checaPedidoTrucoBot3(int jaPediu);
    int verificachar(int variavel);
    void procedimentosFinalRodada();

    Carta polimorfismoJogarCarta(Jogador &j, int indiceCartaEscolhida = 0);
};
#endif