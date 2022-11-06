#ifndef MENU_HPP
#define MENU_HPP

#include "carta.hpp"
#include "baralho.hpp"
#include "jogador.hpp"
#include "humano.hpp"
#include "bot.hpp"
#include "rodada.hpp"

#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>

class Menu
{
    std::string _nomeUsuario;

public:
    Menu();
    void ranking();
    void cadastroUsuario();
    void limparTela();
};
#endif