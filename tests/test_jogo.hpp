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
    CHECK_EQ(3, j1.baralhoDaQueda.getMaoJogador0Size());
    CHECK_EQ(3, j1.baralhoDaQueda.getMaoJogador1Size());
    CHECK_EQ(3, j1.baralhoDaQueda.getMaoJogador2Size());
    CHECK_EQ(3, j1.baralhoDaQueda.getMaoJogador3Size());
}

TEST_CASE("TESTANDO VERIFICACAO DA ENTRADA NA CLASSE JOGO")
{
    Jogo j1 = Jogo();
    CHECK_EQ(1, j1.verificachar(1));
    CHECK_EQ(2, j1.verificachar(2));
    CHECK_EQ(3, j1.verificachar(4));
    CHECK_EQ(3, j1.verificachar(5));
    CHECK_EQ(3, j1.verificachar(1000));
}
