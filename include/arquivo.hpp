#ifndef ARQUIVO_HPP
#define ARQUIVO_HPP

#include "../include/tpstring.hpp"

bool findName(std::string name);

bool passwordChecker(std::string name, std::string password);

void playerCreate(std::string name, std::string password);

std::string playerRegister();

#endif