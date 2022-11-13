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

class Jogo
{
    Menu menuJogo;
    Baralho baralhoDaQueda;
    Rodada rodadaAtual;
    Humano usuario;
    Bot bot1;
    Bot bot2;
    Bot bot3;

public:
    Jogo();
    void novoJogo();
    void inicializaMenu();
    void inicializaBaralho();
    void inicializaJogadores();
    void sequenciaJogadasIniciandoUsuario();
    void sequenciaJogadasIniciandoBot1();
    void sequenciaJogadasIniciandoBot2();
    void sequenciaJogadasIniciandoBot3();
    void checaPedidoTrucoJogador();
    void checaPedidoTrucoBot1();
    void checaPedidoTrucoBot2();
    void checaPedidoTrucoBot3();
    void procedimentosFinalRodada();
};
#endif