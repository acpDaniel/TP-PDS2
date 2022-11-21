#ifndef MENU_HPP
#define MENU_HPP

#include "carta.hpp"
#include "baralho.hpp"
#include "jogador.hpp"
#include "humano.hpp"
#include "bot.hpp"
#include "rodada.hpp"
#include "arquivo.hpp"
#include "tpstring.hpp"

#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>

class Menu
{
public:
    std::string _nomeUsuario;
    Menu();
    void ranking();
    void cadastroUsuario();
    std::string loginUsuario();
    void Menu::uptadeRanking(std::string player, int win);
    void limparTela();
};
#endif