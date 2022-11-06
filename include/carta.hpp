#ifndef CARTA_HPP
#define CARTA_HPP

#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>

class Carta
{
private:
    std::string _nome;
    int _peso;
    int _id;

public:
    Carta(std::string nome, int peso, int id);
    std::string getNome();
    int getPeso();
    int getId();
    void imprimeCarta();
};

#endif