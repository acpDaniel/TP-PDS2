#include "../include/tpstring.hpp"

std::string strMaiuscula(std::string str)
{
    char aux[str.size()];
    for (int i = 0; i < int(str.size()) + 1; i++)
    {
        aux[i] = toupper(str[i]);
    }
    return aux;
}

bool strMaxTamChecker(std::string str, int size)
{
    if (int(str.size()) > size)
        return 1;
    return 0;
}

bool strMinTamChecker(std::string str, int size)
{
    if (int(str.size()) < size)
        return 1;
    return 0;
}

bool strSpaceChecker(std::string str)
{
    for (int i = 0; i < int(str.size()); i++)
    {
        if (int(str[i]) == 32)
            return 1;
    }
    return 0;
}