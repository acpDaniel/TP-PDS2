#include "../include/carta.hpp"

#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>

Carta::Carta(std::string nome, int peso, int id)
{
    _nome = nome;
    _peso = peso;
    _id = id;
}

std::string Carta::getNome()
{
    return _nome;
}

int Carta::getPeso()
{
    return _peso;
}

int Carta::getId()
{
    return _id;
    _id = 2;
}

void Carta::setId(int num)
{
    _id = num;
}

void Carta::imprimeCarta()
{
    std::cout << "A carta selecionada e o(a) " << _nome << std::endl;
}

// CARTAS FUNCIONANDO

/** DEBUG
    int main(){

    Carta SeteCopas("Sete de Copas", 1, 1);
    Carta Zap("Quatro de Paus", 0, 0);
    Carta Aspadilhas("As de Espadas", 2, 2);
    Carta SeteOuros("Sete de Ouros", 3, 3);

    std::cout << SeteCopas.getId() << std::endl;
    std::cout << Zap.getNome() << std::endl;
    std::cout << Aspadilhas.getId() << std::endl;
    SeteOuros.imprimeCarta();

    return 0;
}**/