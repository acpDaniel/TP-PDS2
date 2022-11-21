#ifndef ARQUIVO_HPP
#define ARQUIVO_HPP

#include "../include/tpstring.hpp"

bool findName(std::string name);

bool passwordChecker(std::string name, std::string password);

void playerCreate(std::string name, std::string password);

std::string playerRegister();

std::string playerLogin();

void uptadeRanking(std::string player, int win);

std::set<float> pvs();

std::set<std::string> nicks(float x);

#endif