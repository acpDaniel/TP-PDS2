#include "../include/tpstring.hpp"

std::string strMaiuscula(std::string str) {
    char aux[str.size()];
    for(int i = 0; i < int(str.size()) + 1; i++) {
        aux[i] = toupper(str[i]);
    }
    return aux;
}