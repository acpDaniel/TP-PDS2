//#define CATCH_CONFIG_MAIN
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//#include "catch.hpp"
#include "doctest.hpp"

#include "test_carta.hpp"
#include "test_baralho.hpp"
#include "test_jogador.hpp"
#include "test_bot.hpp"
#include "test_humano.hpp"
#include "test_rodada.hpp"

TEST_CASE("TESTANDO ID JOGADOR MAIOR CARTA")
{
    // esse metodo sempre eh testado passando como parametro o pesos das cartas dos jogadores com id 0, 1 , 2 e 3 respectivamente
    Rodada b1 = Rodada();
    CHECK_EQ(0, b1.idJogadorMaiorCarta(14, 2, 1, 0));
    CHECK_EQ(1, b1.idJogadorMaiorCarta(5, 12, 1, 0));
    CHECK_EQ(2, b1.idJogadorMaiorCarta(3, 6, 9, 0));
    CHECK_EQ(3, b1.idJogadorMaiorCarta(4, 3, 7, 11));
    // se tiver dois com mesmo valor ele considera o primeiro que tacou a carta
    CHECK_EQ(2, b1.idJogadorMaiorCarta(4, 3, 11, 11));
    CHECK_EQ(0, b1.idJogadorMaiorCarta(14, 14, 2, 3));
}