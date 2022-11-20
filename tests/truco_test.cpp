#define CATCH_CONFIG_MAIN
#include "catch.hpp"

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

// FUNCOES CLASSE CARTA
TEST_CASE("TESTANDO CARTA GET NOME")
{
    Carta c1("Zap", 14, 39);
    Carta c2("4 de ouros", 1, 0);
    Carta c3("5 de paus", 2, 3);
    Carta c4("6 de paus", 3, 7);
    Carta c5("3 de paus", 10, 32);
    CHECK(c1.getNome() == "Zap");
    CHECK(c2.getNome() == "4 de ouros");
    CHECK(c3.getNome() == "5 de paus");
    CHECK(c4.getNome() == "6 de paus");
    CHECK(c5.getNome() == "3 de paus");
}