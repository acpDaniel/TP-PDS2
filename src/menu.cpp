#include "../include/carta.hpp"
#include "../include/baralho.hpp"
#include "../include/jogador.hpp"
#include "../include/bot.hpp"
#include "../include/humano.hpp"
#include "../include/rodada.hpp"
#include "../include/menu.hpp"
#include "../include/tpstring.hpp"
#include "../include/arquivo.hpp"

#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <fstream>

#define CLEAR "clear"

Menu::Menu()
{
}

void Menu::cadastroUsuario()
{
    // função para cadastrar um usuário

    // Como o arquivo será escrito:
    // nome senha partidas vitorias "porcentagem de vitorias"
    // ------------------------------------------------------
    // name password games victorys pv

    system("cls");

    std::string name;
    std::cout << "REGISTRO\n\n";
    std::cout << "Crie um nick:\n";
    std::getline(std::cin, name);
    while(1) {
        if(strMaxTamChecker(name, MAXTAM_NAME)) {
            system("cls");
            std::cout << "REGISTRO\n\n";
            std::cout << "Nick com mais de " << MAXTAM_NAME << " caracteres, tente outro:\n";
            std::getline(std::cin, name);
        }

        else if(strMinTamChecker(name, MINTAM_NAME)) {
            system("cls");
            std::cout << "REGISTRO\n\n";
            std::cout << "Nick com menos de " << MINTAM_NAME << " caracteres, tente outro:\n";
            std::getline(std::cin, name);
        }

        else if(strSpaceChecker(name)) {
            system("cls");
            std::cout << "REGISTRO\n\n";
            std::cout << "Nick com espaco, tente outro:\n";
            std::getline(std::cin, name);
        }

        else if(findName(name)) {
            system("cls");
            std::cout << "REGISTRO\n\n";
            std::cout << "Nick ja utilizado, tente outro:\n";
            std::getline(std::cin, name);
        }

        else {
            break;
        }
    }

    std::string password;
    system("cls");
    std::cout << "REGISTRO\n\n";
    std::cout << "Nick: " << name << "\n";
    std::cout << "Crie uma senha:\n";
    std::getline(std::cin, password);
    while(1) {
        if(strMaxTamChecker(name, MAXTAM_PASSWORD)) {
            system("cls");
            std::cout << "REGISTRO\n\n";
            std::cout << "Nick: " << name << "\n";
            std::cout << "Senha com mais de " << MAXTAM_PASSWORD << " caracteres, tente outra:\n";
            std::getline(std::cin, password);
        }

        else if(strMinTamChecker(name, MINTAM_PASSWORD)) {
            system("cls");
            std::cout << "REGISTRO\n\n";
            std::cout << "Senha com menos de " << MINTAM_PASSWORD << " caracteres, tente outra:\n";
            std::getline(std::cin, name);
        }

        else if(strSpaceChecker(password)) {
            system("cls");
            std::cout << "REGISTRO\n\n";
            std::cout << "Nick: " << name << "\n";
            std::cout << "Senha com espaco, tente outra:\n";
            std::getline(std::cin, password);
        }

        else {
            break;
        }
    }
    playerCreate(name, password);
    system("cls");
    std::cout << "REGISTRO\n\n";
    std::cout << "Jogador registrado\n";
    system("pause");
}

void Menu::ranking()
{
    // função para imprimir ranking

    system("cls");
    
    std::set<float> p = pvs();
    float x[int(p.size())];
    int z = 0;

    for(auto i = p.begin(); i != p.end(); ++i) {
        x[z] = *i;
        z++;
    }

    for(int i = int(p.size()); i >= 0; i--) {
        std::set<std::string> n = nicks(x[i]);
        for(auto j = n.begin(); j != n.end(); ++j) {
            std::cout << p.size() - i << " - " << *j;
            std::string b = *j;
            for(int a = 0; a < 22 - b.size(); a++)
                std::cout << " ";
            std::cout << x[i] << "\n";
        }
    }

    std::ifstream base("base.txt");
    if(!base)
        std::cout << "Nao ha jogadores cadastrados, impossivel exibir ranking";
}

// função retorna o nome do usuario logado para depois do jogo conseguir realizar o ranking uptade
std::string Menu::loginUsuario()
{
    system("cls");

    std::string name;
    std::cout << "LOGIN\n\n";
    std::cout << "Digite o seu nick:\n";
    std::getline(std::cin, name);

    while(1) {
        if(strMaxTamChecker(name, MAXTAM_NAME)) {
            system("cls");
            std::cout << "LOGIN\n\n";
            std::cout << "Nick com mais de " << MAXTAM_NAME << ", tente outro:\n";
            std::getline(std::cin, name);
        }

        else if(strMinTamChecker(name, MAXTAM_NAME)) {
            system("cls");
            std::cout << "LOGIN\n\n";
            std::cout << "Nick com menos de " << MINTAM_NAME << " caracteres, tente outro:\n";
            std::getline(std::cin, name);
        }

        else if(strSpaceChecker(name)) {
            system("cls");
            std::cout << "LOGIN\n\n";
            std::cout << "Nick com espaco, tente outro:\n";
            std::getline(std::cin, name);
        }
        else if(!findName(name)) {
            system("cls");
            std::cout << "LOGIN\n\n";
            std::cout << "Nick nao encontrado, tente outro:\n";
            std::getline(std::cin, name);
        }
        else {
            break;
        }
    }

    system("cls");

    std::string password;
    std::cout << "LOGIN\n\n";
    std::cout << "Nick: " << name << "\n";
    std::cout << "Digite o sua senha:\n";
    std::getline(std::cin, password);

    std::ifstream base("base.txt", std::ios::in);
    while(1) {
        if(passwordChecker(name, password))
            break;
        else {
            system("cls");
            std::cout << "LOGIN\n\n";
            std::cout << "Nick: " << name << "\n";
            std::cout << "Senha incorreta, tente outra:\n";
            std::getline(std::cin, password);
        }
    }
    base.close();

    system("cls");
    std::cout << "LOGIN\n\n";
    std::cout << "Usuario " << name << " logado\n\n";
    system("pause");
    system("cls");

    return name;
}

// função para atualizar o ranking
void Menu::uptadeRanking(std::string player, int win) {
    std::string name;
    std::string password;
    float games;
    float victorys;
    float pv;

    std::ifstream base("base.txt", std::ios::in);
    std::ofstream aux("aux.txt", std::ios::out);

    while(base >> name >> password >> games >> victorys >> pv) {
        if(player == name) {
            games++;
            if(win)
                victorys++;
            pv = victorys / games;
        }
        aux << name << " " << password << " " << games << " "  << victorys << " "  << pv << "\n";
    }

    base.close();
    aux.close();

    remove("base.txt");
    rename("aux.txt", "base.txt");
}

void Menu::limparTela()
{
    system("cls");
}