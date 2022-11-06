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
}

void Carta::imprimeCarta()
{
    std::cout << "A carta selecionada é o(a) " << _nome << std::endl;
}