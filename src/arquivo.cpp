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

bool passwordChecker(std::string name, std::string password) {
    std::string auxpassword;
    std::string auxname;
    float partidas;
    float vitorias;
    float pv;

    std::ifstream base("base.txt", std::ios::in);
    while(base >> auxname >> auxpassword >> partidas >> vitorias >> pv) {
        if(password == auxpassword && strMaiuscula(auxname) == strMaiuscula(name)) {
            base.close();
            return 1;
        }
    }
    base.close();
    return 0;
}

void playerCreate(std::string name, std::string password) {

    std::ifstream teste("base.txt");
    int aux = 0;
    if(teste) {
        aux = 1;
    }
    teste.close();

    std::ofstream base("base.txt", std::ios::app);
    if(aux == 1){
        base << "\n";
    }
    base << name << " " << password << " 0 0 0";
    base.close();
}

std::set<float> pvs() {
    std::string name;
    std::string password;
    float games;
    float victorys;
    float pv;

    std::set<float> s;

    std::ifstream base("base.txt", std::ios::in);

    while(base >> name >> password >> games >> victorys >> pv) {
        s.insert(pv);
    }
    base.close();

    return s;
}

std::set<std::string> nicks(float x) {
    std::ifstream base("base.txt", std::ios::in);
    std::string name;
    std::string password;
    float games;
    float victorys;
    float pv;

    std::set<std::string> s;

    while(base >> name >> password >> games >> victorys >> pv) {
        if(pv == x)
            s.insert(name);
    }
    base.close();

    return s;
}