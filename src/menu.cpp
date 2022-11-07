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
#include <fstream>

#define CLEAR "clear"

Menu::Menu()
{
    std::cout << "Bem vindo ao jogo de truco desenvolvido para a disciplina de PDS2" << std::endl;
}

void Menu::cadastroUsuario()
{
    std::cout << "Digite um nome de usuario para você se identificar no ranking do jogo (sem espaços): ";
    std::string nomeUsuario;
    std::cin >> nomeUsuario;
    _nomeUsuario = nomeUsuario;
}
void Menu::ranking()
{
    // aqui vai ser resposavel por ler o arquivo txt e exibir na tela o ranking
	
	std::ifstream in; 
    in.open("ranking.txt", std::ios::in); 

    char winner[100];
    char second[100];
    in.getline(winner, 100);
    in.getline(second, 100);
  
    std::cout<<"O primeiro colocado é: "<< winner << std::endl; 
    std::cout<<"O segundo colocado é: "<< second;
	
    //Precisa saber como o arquivo ranking vai ser escrito para adaptar esse trecho.
}

void Menu::limparTela()
{
    system(CLEAR);
}