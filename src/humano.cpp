#include "../include/carta.hpp"
#include "../include/baralho.hpp"
#include "../include/jogador.hpp"
#include "../include/humano.hpp"
/** DEBUG
#include "jogador.cpp"
#include "baralho.cpp"*/

#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>

Humano::Humano(){};

Humano::Humano(std::string nome, int idDupla, int idJogador) : Jogador(nome, idDupla, idJogador)
{
}

bool Humano::pedirTruco()
{
    _pedindoTruco = true;
    return 1;
}

bool Humano::aceitarTruco(bool aceitarTruco)
{
    if (aceitarTruco == true)
    {
        return 1;
    }
    else
        return 0;
}

bool Humano::aumentarTruco(bool aumentarTruco)
{
    if (aumentarTruco == true)
    {
        return 1;
    }
    else
        return 0;
}

void Humano::imprimeCartasJogador()
{
    std::cout << "Cartas disponiveis para escolha:" << std::endl;
    for (int i = 0; i < _mao.size(); i++)
    {
        std::cout << _mao[i].getNome() << " -peso:" << _mao[i].getPeso() << ", ";
    }
}

Carta Humano::jogarCarta(int indice)
{
    // logica para selecionar uma das 3 cartas, ja que o iterator begin retorna o endereço para primeira posicao
    std::vector<Carta>::iterator it = _mao.begin();
    if (indice == 1)
    {
        ++it;
    }
    else if (indice == 2)
    {
        ++it;
        ++it;
    }
    Carta cartaSelecionada = *(it);
    _mao.erase(it);
    return cartaSelecionada;
}

/** DEBUG
int main(){
    Carta SeteCopas("Sete de Copas", 1, 1);
    Carta Zap("Quatro de Paus", 0, 0);
    Carta Aspadilhas("As de Espadas", 2, 2);
    Carta SeteOuros("Sete de Ouros", 3, 3);

    Baralho baralhoteste;

    baralhoteste.inserirCartaBaralho(Zap);
    baralhoteste.inserirCartaBaralho(SeteCopas);
    baralhoteste.inserirCartaBaralho(Aspadilhas);
    baralhoteste.inserirCartaBaralho(SeteOuros);


    Jogador teste1("Syrus", baralhoteste._baralho, 1);
    Humano::Jogador teste2("Danilo", baralhoteste._baralho, 2);

    std::cout << teste1._aceitandoTruco << std::endl;
    teste1.aceitarTruco();
    std::cout << teste1._aceitandoTruco << std::endl;
    std::cout << teste1.getPontos() << std::endl;
    teste1.adicionaPontos(2);
    std::cout << teste1.getPontos() << std::endl;
    std::cout << teste1.aumentarTruco() << std::endl;
    std::cout << teste1._pedindoTruco << std::endl;
    teste1.pedirTruco();
    std::cout << teste1._pedindoTruco << std::endl;
    std::cout << teste1.getNome() << std::endl;
    std::cout << teste1._mao.size() << std::endl;
    teste1.jogarCarta(1);
    std::cout << teste1._mao.size() << std::endl;

    std::cout << "Humano" << std::endl << std::endl;

    /**std::cout << teste2._aceitandoTruco << std::endl;
    std::cout << teste2.aceitarTruco(true) << std::endl;
    std::cout << teste2._aceitandoTruco << std::endl;
    std::cout << teste2.getPontos() << std::endl;
    teste2.adicionaPontos(2);
    std::cout << teste2.getPontos() << std::endl;
    std::cout << teste2.aumentarTruco(true) << std::endl;
    std::cout << teste2._pedindoTruco << std::endl;
    teste2.pedirTruco();
    std::cout << teste2._pedindoTruco << std::endl;
    std::cout << teste2.getNome() << std::endl;
    std::cout << teste2._mao.size() << std::endl;
    teste2.jogarCarta(1);
    std::cout << teste2._mao.size() << std::endl;

    return 0;

}**/