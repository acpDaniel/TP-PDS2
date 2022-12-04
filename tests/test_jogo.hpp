//#include "catch.hpp"
#include "doctest.hpp"

#include "../include/carta.hpp"
#include "../include/baralho.hpp"
#include "../include/jogador.hpp"
#include "../include/bot.hpp"
#include "../include/humano.hpp"
#include "../include/rodada.hpp"
#include "../include/menu.hpp"
#include "../include/jogo.hpp"

#include <cstdint>
#include <cmath>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>

TEST_CASE("TESTANDO METODO QUE INICIALIZA O BARALHO COMPLETO E FORMA AS MAOS DE CADA JOGADOR")
{
    Jogo j1 = Jogo();
    // metodo inicializa as cartas e faz as maos de cada jogador
    j1.inicializaBaralho();
    CHECK_EQ(28, j1.baralhoDaQueda.getBaralhoSize());
    CHECK_EQ(3, j1.baralhoDaQueda.getMaoJogador0().size());
    CHECK_EQ(3, j1.baralhoDaQueda.getMaoJogador1().size());
    CHECK_EQ(3, j1.baralhoDaQueda.getMaoJogador2().size());
    CHECK_EQ(3, j1.baralhoDaQueda.getMaoJogador3().size());
}

TEST_CASE("TESTANDO VERIFICACAO DA ENTRADA NA CLASSE JOGO")
{
    Jogo j1 = Jogo();
    // se for entrada invalida retona 3
    CHECK_EQ(1, j1.verificachar(1));
    CHECK_EQ(2, j1.verificachar(2));
    CHECK_EQ(3, j1.verificachar(4));
    CHECK_EQ(3, j1.verificachar(5));
    CHECK_EQ(3, j1.verificachar(1000));
}

TEST_CASE("TESTANDO POLIMORFISMO")
{
    srand(1);
    Jogo j1 = Jogo();
    j1.inicializaBaralho();
    j1.usuario.setMao(j1.baralhoDaQueda.getMaoJogador0());
    CHECK_EQ("Rei de copas", j1.polimorfismoJogarCarta(j1.usuario, 1).getNome());

    j1.bot1.setMao(j1.baralhoDaQueda.getMaoJogador1());
    CHECK_EQ("5 de ouros", j1.polimorfismoJogarCarta(j1.bot1, 0).getNome());
}

TEST_CASE("TESTANDO PEDIDO TRUCO BOT1")
{
    srand(5);
    Jogo j1 = Jogo();
    // caso usuario recuse o truco cin = 2, a pontuaçao nao aumenta
    j1.checaPedidoTrucoBot1(true);
    CHECK_EQ(2, j1.rodadaAtual.getPontuacaoRodadaAtual());

    // caso usuario aceito o truco cin = 1, a pontuacao aumenta
    j1.checaPedidoTrucoBot1(true);
    CHECK_EQ(4, j1.rodadaAtual.getPontuacaoRodadaAtual());
}

TEST_CASE("TESTANDO PEDIDO TRUCO BOT2")
{
    srand(5);
    Jogo j1 = Jogo();
    // caso o outro bot nao aceite o truco, nao aumenta pontuacao
    j1.checaPedidoTrucoBot2();
    CHECK_EQ(2, j1.rodadaAtual.getPontuacaoRodadaAtual());

    srand(40040);
    Jogo j2 = Jogo();
    // caso o outro bot aceite o truco, aumenta a pontuacao
    j2.checaPedidoTrucoBot2();
    CHECK_EQ(4, j2.rodadaAtual.getPontuacaoRodadaAtual());
}

TEST_CASE("TESTANDO PEDIDO TRUCO BOT3")
{
    srand(5);
    Jogo j1 = Jogo();
    // caso usuario recuse o truco cin = 2, a pontuaçao nao aumenta
    j1.checaPedidoTrucoBot3(true);
    CHECK_EQ(2, j1.rodadaAtual.getPontuacaoRodadaAtual());

    // caso usuario aceite o truco cin = 1, a pontuacao aumenta
    j1.checaPedidoTrucoBot3(true);
    CHECK_EQ(4, j1.rodadaAtual.getPontuacaoRodadaAtual());
}

TEST_CASE("TESTANDO PEDIDOS TRUCO JOGADOR")
{
    SUBCASE("USUARIO PEDE TRUCO")
    {
        srand(5);
        Jogo j1 = Jogo();
        // caso usuario peça truco cin = 1 e bot nao aceita, nao aumenta pontuacao
        j1.checaPedidoTrucoJogador();
        CHECK_EQ(2, j1.rodadaAtual.getPontuacaoRodadaAtual());

        srand(40040);
        // caso usuario peça truco cin = 1 e bot aceita, aumenta pontuacao
        j1.checaPedidoTrucoJogador();
        CHECK_EQ(4, j1.rodadaAtual.getPontuacaoRodadaAtual());
    }
    SUBCASE("USUARIO NAO PEDE TRUCO")
    {
        srand(5);
        Jogo j1 = Jogo();
        // caso usuario nao peça truco cin = 2 nao aumenta pontuacao
        j1.checaPedidoTrucoJogador();
        CHECK_EQ(2, j1.rodadaAtual.getPontuacaoRodadaAtual());
    }
    SUBCASE("LANCAMENTO EXECOES ENTRADAS INVALIDAS")
    {
        srand(5);
        Jogo j1 = Jogo();
        // caso usuario digite uma entrada invalida, numero diferente de 1 e 2
        CHECK_THROWS(j1.checaPedidoTrucoJogador());
        // caso usuario digite uma entrada invalida, letra
        CHECK_THROWS(j1.checaPedidoTrucoJogador());
    }
}
