#include "../include/tpstring.hpp"

std::string strMaiuscula(std::string str) {
    char aux[str.size()];
    for(int i = 0; i < int(str.size()) + 1; i++) {
        aux[i] = toupper(str[i]);
    }
    return aux;
}

bool strMaxTamChecker(std::string str, int size) {
    if(int(str.size()) >= size)
        return 1;
    return 0;
}