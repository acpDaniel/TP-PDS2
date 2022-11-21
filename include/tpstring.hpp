#ifndef TPSTRING_HPP
#define TPSTRING_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <set>
#include <vector>

#define MAXTAM_NAME 20
#define MINTAM_NAME 3

#define MAXTAM_PASSWORD 15
#define MINTAM_PASSWORD 4

std::string strMaiuscula(std::string str);

bool strMaxTamChecker(std::string str, int size);

bool strMinTamChecker(std::string str, int size);

bool strSpaceChecker(std::string str);

#endif