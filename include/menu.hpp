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
#include <set>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <cctype>
#include <stdlib.h>

#define MAXTAM_NAME 20
#define MINTAM_NAME 3
#define MAXTAM_PASSWORD 15
#define MINTAM_PASSWORD 4

class Menu
{
public:
    std::string _nomeUsuario;
    Menu();
    void cadastroUsuario();
    void ranking();
    std::string loginUsuario();
    void uptadeRanking(std::string player, int win);
    void limparTela();

    //Strings
    bool strMaxTamChecker(std::string str, int size);
    bool strMinTamChecker(std::string str, int size);
    bool strSpaceChecker(std::string str);

    // Arquivo
    bool findName(std::string name);
    bool passwordChecker(std::string name, std::string password);
    void playerCreate(std::string name, std::string password);
    std::set<float> pvs();
    std::set<std::string> nicks(float x);
};
#endif