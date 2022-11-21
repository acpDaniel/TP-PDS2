#include "../include/arquivo.hpp"

bool findName(std::string name) {
    std::ifstream base("base.txt", std::ios::in);
    std::string auxname;
    while(base >> auxname) {
        if(strMaiuscula(auxname) == strMaiuscula(name))
            return 1;
    }
    base.close();
    return 0;
}