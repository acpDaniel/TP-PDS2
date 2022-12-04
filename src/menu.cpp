#include "../include/carta.hpp"
#include "../include/baralho.hpp"
#include "../include/jogador.hpp"
#include "../include/bot.hpp"
#include "../include/humano.hpp"
#include "../include/rodada.hpp"
#include "../include/menu.hpp"

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

#define CLEAR "clear"

Menu::Menu()
{
}

void Menu::cadastroUsuario()
{
    // função para cadastrar um usuário

    // Como o arquivo será escrito:
    // nome senha parti+das vitorias "porcentagem de vitorias"
    // ------------------------------------------------------
    // name password games victorys pv

    system("cls");

    std::string name;
    std::cout << "REGISTRO\n\n";
    std::cout << "Crie um nick:\n";
    std::getline(std::cin, name);

    while(1) {
        if(strMaxTamChecker(name, MAXTAM_NAME)) {
            std::cout << "\nNick com mais de " << MAXTAM_NAME << " caracteres, tente outro:";
        }

        else if(strMinTamChecker(name, MINTAM_NAME)) {
            std::cout << "\nNick com menos de " << MINTAM_NAME << " caracteres, tente outro:";
        }
        
        else if(strSpaceChecker(name)) {
            std::cout << "\nNick com espaco, tente outro:";
        }

        else if(findName(name)) {
            std::cout << "\nNick ja utilizado, tente outro:\n";
        }

        else {
            break;
        }
        std::cout << "\n";
        std::getline(std::cin, name);
    }

    std::string password;
    std::cout << "\n\n";
    std::cout << "Nick: " << name << "\n";
    std::cout << "Crie uma senha:\n";
    std::cin >> password;
    std::cout << "\n";

    while(1) {
        if(strMaxTamChecker(password, MAXTAM_PASSWORD)) {
            std::cout << "Nick: " << name << "\n";
            std::cout << "Senha com mais de " << MAXTAM_PASSWORD << " caracteres, tente outra:\n";
            std::getline(std::cin, password);
        }

        else if(strMinTamChecker(password, MINTAM_PASSWORD)) {
            std::cout << "Senha com menos de " << MINTAM_PASSWORD << " caracteres, tente outra:\n";
            std::getline(std::cin, password);
        }

        else if(strSpaceChecker(password)) {
            std::cout << "Nick: " << name << "\n";
            std::cout << "Senha com espaco, tente outra:\n";
            std::getline(std::cin, password);
        }

        else {
            break;
        }
    }
    playerCreate(name, password);
    std::cout << "\n";
    std::cout << "Jogador registrado\n\n";
    system("pause");
    system("cls");
}

void Menu::ranking()
{
    // função para imprimir ranking

    system("cls");
    
    std::ifstream base("base.txt");
    if(!base)
    {
        std::cout << "Nao ha jogadores cadastrados, impossivel exibir ranking";
    }

    else 
    {
        std::set<float> p = pvs();
        float x[int(p.size())];
        int z = 0;

        for(auto i = p.begin(); i != p.end(); ++i) {
            x[z] = *i;
            z++;
        }

        std::cout << "Pos.   Nick                  Pv\n";
        std::cout << "------------------------------------\n";
        for(int i = int(p.size()); i >= 0; i--) {
            std::set<std::string> n = nicks(x[i]);
            for(auto j = n.begin(); j != n.end(); ++j) {
                std::cout << " " << p.size() - i << "  -  " << *j;
                std::string b = *j;
                for(int a = 0; a < 22 - int(b.size()); a++)
                    std::cout << " ";
                std::cout << x[i] << "\n";
            }
        }
    }
    std::cout << "\n";
    system("pause");
    system("cls");
}

// função retorna o nome do usuario logado para depois do jogo conseguir realizar o ranking uptade
std::string Menu::loginUsuario()
{
    system("cls");

    std::string name;
    std::cout << "LOGIN\n\n";
    std::cout << "Digite o seu nick:\n";
    std::cin >> name;
    std::cout << "\n";

    while(1) {
        if(strMaxTamChecker(name, MAXTAM_NAME)) {
            std::cout << "Nick com mais de " << MAXTAM_NAME << ", tente outro:\n";
            std::getline(std::cin, name);
        }

        else if(strMinTamChecker(name, MINTAM_NAME)) {
            std::cout << "Nick com menos de " << MINTAM_NAME << " caracteres, tente outro:\n";
            std::getline(std::cin, name);
        }

        else if(strSpaceChecker(name)) {
            std::cout << "Nick com espaco, tente outro:\n";
            std::getline(std::cin, name);
        }

        else if(!findName(name)) {
            std::cout << "Nick nao encontrado, tente outro:\n";
            std::getline(std::cin, name);
        }

        else {
            break;
        }
    }

    system("cls");

    std::string password;
    std::cout << "LOGIN\n";
    std::cout << "Nick: " << name << "\n";
    std::cout << "Digite o sua senha:\n";
    std::cin >> password;
    std::cout << "\n";

    std::ifstream base("base.txt", std::ios::in);
    while(1) {
        if(passwordChecker(name, password))
            break;
        else {
            std::cout << "Nick: " << name << "\n";
            std::cout << "Senha incorreta, tente outra:\n";
            std::getline(std::cin, password);
        }
    }
    base.close();

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


// string
bool Menu::strMaxTamChecker(std::string str, int size)
{
    if (int(str.size()) > size)
        return 1;
    return 0;
}

bool Menu::strMinTamChecker(std::string str, int size)
{
    if (int(str.size()) < size)
        return 1;
    return 0;
}

bool Menu::strSpaceChecker(std::string str)
{
    for (int i = 0; i < int(str.size()); i++)
    {
        if (int(str[i]) == 32)
            return 1;
    }
    return 0;
}

//arquivo
bool Menu::findName(std::string name) {
    std::ifstream base("base.txt", std::ios::in);
    std::string auxname;
    while(base >> auxname) {
        if(auxname == name)
            return 1;
    }
    base.close();
    return 0;
}

bool Menu::passwordChecker(std::string name, std::string password) {
    std::string auxpassword;
    std::string auxname;
    float partidas;
    float vitorias;
    float pv;

    std::ifstream base("base.txt", std::ios::in);
    while(base >> auxname >> auxpassword >> partidas >> vitorias >> pv) {
        if(password == auxpassword && auxname == name) {
            base.close();
            return 1;
        }
    }
    base.close();
    return 0;
}

void Menu::playerCreate(std::string name, std::string password) {

    std::ifstream teste("base.txt");
    int aux = 0;
    if(teste) {
        aux = 1;
    }
    teste.close();

    std::ofstream base("base.txt", std::ios::app);
    if(aux == 1){
        base << "\n";
    }
    base << name << " " << password << " 0 0 0";
    base.close();
}

std::set<float> Menu::pvs() {
    std::string name;
    std::string password;
    float games;
    float victorys;
    float pv;

    std::set<float> s;

    std::ifstream base("base.txt", std::ios::in);

    while(base >> name >> password >> games >> victorys >> pv) {
        s.insert(pv);
    }
    base.close();

    return s;
}

std::set<std::string> Menu::nicks(float x) {
    std::ifstream base("base.txt", std::ios::in);
    std::string name;
    std::string password;
    float games;
    float victorys;
    float pv;

    std::set<std::string> s;

    while(base >> name >> password >> games >> victorys >> pv) {
        if(pv == x)
            s.insert(name);
    }
    base.close();

    return s;
}

///
void Menu::limparTela()
{
    system("cls");
}