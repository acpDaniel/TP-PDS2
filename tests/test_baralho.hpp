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

TEST_CASE("TESTANDO INICIALIZACAO DO BARALHO")
{
    SUBCASE("CASO POSITIVO")
    {
        Baralho b1 = Baralho();
        b1.inicializarBaralhoCompleto();
        CHECK_EQ(40, b1.getBaralhoSize());

        Baralho b2 = Baralho();
        b2.inicializarBaralhoCompleto();
        CHECK_EQ(40, b2.getBaralhoSize());

        Baralho b3 = Baralho();
        b3.inicializarBaralhoCompleto();
        CHECK_EQ(40, b3.getBaralhoSize());
    }

    SUBCASE("CASO NEGATIVO")
    {
        Baralho b1 = Baralho();
        b1.inicializarBaralhoCompleto();
        CHECK_EQ(39, b1.getBaralhoSize());

        Baralho b2 = Baralho();
        b2.inicializarBaralhoCompleto();
        CHECK_EQ(80, b2.getBaralhoSize());

        Baralho b3 = Baralho();
        b3.inicializarBaralhoCompleto();
        CHECK_EQ(2, b3.getBaralhoSize());
    }
}

TEST_CASE("TESTANDO DELETAR CARTA DO BARALHO")
{
    SUBCASE("CASO POSITIVO")
    {
        Baralho b1 = Baralho();
        b1.inicializarBaralhoCompleto();
        b1.deletarCartaBaralho(5);
        CHECK_EQ(39, b1.getBaralhoSize());

        Baralho b2 = Baralho();
        b2.inicializarBaralhoCompleto();
        b2.deletarCartaBaralho(7);
        b2.deletarCartaBaralho(8);
        CHECK_EQ(38, b2.getBaralhoSize());

        Baralho b3 = Baralho();
        b3.inicializarBaralhoCompleto();
        CHECK_NOTHROW(b3.deletarCartaBaralho(20));
    }

    SUBCASE("CASO NEGATIVO")
    {
        Baralho b1 = Baralho();
        b1.inicializarBaralhoCompleto();
        CHECK_NOTHROW(b1.deletarCartaBaralho(-5));

        Baralho b2 = Baralho();
        b2.inicializarBaralhoCompleto();
        CHECK_NOTHROW(b2.deletarCartaBaralho(41));

        Baralho b3 = Baralho();
        b3.inicializarBaralhoCompleto();
        b3.deletarCartaBaralho(5);
        CHECK_EQ(38, b2.getBaralhoSize());
    }
}

TEST_CASE("TESTANDO INICIALIZACAO MAO JOGADORES")
{
    SUBCASE("CASO POSITIVO")
    {
        Baralho b1 = Baralho();
        b1.inicializarBaralhoCompleto();
        b1.inicializarMaoJogadores();
        CHECK_EQ(28, b1.getBaralhoSize());
        CHECK_EQ(3, b1.getMaoJogador0().size());
        CHECK_EQ(3, b1.getMaoJogador1().size());
        CHECK_EQ(3, b1.getMaoJogador2().size());
        CHECK_EQ(3, b1.getMaoJogador3().size());

        Baralho b2 = Baralho();
        b2.inicializarBaralhoCompleto();
        b2.inicializarMaoJogadores();
        CHECK_EQ(28, b2.getBaralhoSize());
        CHECK_EQ(3, b2.getMaoJogador0().size());
        CHECK_EQ(3, b2.getMaoJogador1().size());
        CHECK_EQ(3, b2.getMaoJogador2().size());
        CHECK_EQ(3, b2.getMaoJogador3().size());
    }

    SUBCASE("CASO NEGATIVO")
    {
        Baralho b1 = Baralho();
        b1.inicializarBaralhoCompleto();
        b1.inicializarMaoJogadores();
        CHECK_EQ(40, b1.getBaralhoSize());

        Baralho b2 = Baralho();
        b2.inicializarBaralhoCompleto();
        b2.inicializarMaoJogadores();
        CHECK(b2.getMaoJogador0().size() != 3);
        CHECK(b2.getMaoJogador1().size() != 3);
        CHECK(b2.getMaoJogador2().size() != 3);
        CHECK(b2.getMaoJogador3().size() != 3);
    }
}

TEST_CASE("TESTANDO RESETAR BARALHO E MAO JOGADORES")
{
    SUBCASE("CASO POSITIVO")
    {
        Baralho b1 = Baralho();
        b1.inicializarBaralhoCompleto();
        b1.inicializarMaoJogadores();
        b1.resetarBaralhoEMaoJogadores();
        CHECK_EQ(0, b1.getBaralhoSize());
        CHECK_EQ(0, b1.getMaoJogador0().size());
        CHECK_EQ(0, b1.getMaoJogador1().size());
        CHECK_EQ(0, b1.getMaoJogador2().size());
        CHECK_EQ(0, b1.getMaoJogador3().size());
    }
    SUBCASE("CASO NEGATIVO")
    {
        Baralho b1 = Baralho();
        b1.inicializarBaralhoCompleto();
        b1.inicializarMaoJogadores();
        b1.resetarBaralhoEMaoJogadores();
        CHECK(b1.getBaralhoSize() != 0);
        CHECK(b1.getMaoJogador0().size() != 0);
        CHECK(b1.getMaoJogador1().size() != 0);
        CHECK(b1.getMaoJogador2().size() != 0);
        CHECK(b1.getMaoJogador3().size() != 0);
    }
}

TEST_CASE("TESTANDO SORTEAR INDICE CARTA")
{
    SUBCASE("CASO POSITIVO")
    {
        srand(1);
        Baralho b1 = Baralho();
        b1.inicializarBaralhoCompleto();
        CHECK_EQ(23, b1.sortearCarta());

        srand(2);
        CHECK_EQ(10, b1.sortearCarta());

        srand(3);
        CHECK_EQ(26, b1.sortearCarta());
    }
}