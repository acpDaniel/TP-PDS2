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

std::string playerRegister() {

    system("cls");

    std::string name;
    std::cout << "REGISTRO\n\n";
    std::cout << "Crie um nick:\n";
    std::getline(std::cin, name);
    while(1) {
        if(strMaxTamChecker(name, MAXTAM_NAME)) {
            system("cls");
            std::cout << "REGISTRO\n\n";
            std::cout << "Nick com mais de " << MAXTAM_NAME << " caracteres, tente outro:\n";
            std::getline(std::cin, name);
        }

        else if(strMinTamChecker(name, MINTAM_NAME)) {
            system("cls");
            std::cout << "REGISTRO\n\n";
            std::cout << "Nick com menos de " << MINTAM_NAME << " caracteres, tente outro:\n";
            std::getline(std::cin, name);
        }

        else if(strSpaceChecker(name)) {
            system("cls");
            std::cout << "REGISTRO\n\n";
            std::cout << "Nick com espaco, tente outro:\n";
            std::getline(std::cin, name);
        }

        else if(findName(name)) {
            system("cls");
            std::cout << "REGISTRO\n\n";
            std::cout << "Nick ja utilizado, tente outro:\n";
            std::getline(std::cin, name);
        }

        else {
            break;
        }
    }

    std::string password;
    system("cls");
    std::cout << "REGISTRO\n\n";
    std::cout << "Nick: " << name << "\n";
    std::cout << "Crie uma senha:\n";
    std::getline(std::cin, password);
    while(1) {
        if(strMaxTamChecker(name, MAXTAM_PASSWORD)) {
            system("cls");
            std::cout << "REGISTRO\n\n";
            std::cout << "Nick: " << name << "\n";
            std::cout << "Senha com mais de " << MAXTAM_PASSWORD << " caracteres, tente outra:\n";
            std::getline(std::cin, password);
        }

        else if(strMinTamChecker(name, MINTAM_PASSWORD)) {
            system("cls");
            std::cout << "REGISTRO\n\n";
            std::cout << "Senha com menos de " << MINTAM_PASSWORD << " caracteres, tente outra:\n";
            std::getline(std::cin, name);
        }

        else if(strSpaceChecker(password)) {
            system("cls");
            std::cout << "REGISTRO\n\n";
            std::cout << "Nick: " << name << "\n";
            std::cout << "Senha com espaco, tente outra:\n";
            std::getline(std::cin, password);
        }

        else {
            break;
        }
    }
    playerCreate(name, password);
    system("cls");
    std::cout << "REGISTRO\n\n";
    std::cout << "Jogador registrado\n";
    system("pause");
    return name;
}

std::string playerLogin() {

    system("cls");

    std::string name;
    std::cout << "LOGIN\n\n";
    std::cout << "Digite o seu nick:\n";
    std::getline(std::cin, name);

    while(1) {
        if(strMaxTamChecker(name, MAXTAM_NAME)) {
            system("cls");
            std::cout << "LOGIN\n\n";
            std::cout << "Nick com mais de " << MAXTAM_NAME << ", tente outro:\n";
            std::getline(std::cin, name);
        }

        else if(strMinTamChecker(name, MAXTAM_NAME)) {
            system("cls");
            std::cout << "LOGIN\n\n";
            std::cout << "Nick com menos de " << MINTAM_NAME << " caracteres, tente outro:\n";
            std::getline(std::cin, name);
        }

        else if(strSpaceChecker(name)) {
            system("cls");
            std::cout << "LOGIN\n\n";
            std::cout << "Nick com espaco, tente outro:\n";
            std::getline(std::cin, name);
        }
        else if(!findName(name)) {
            system("cls");
            std::cout << "LOGIN\n\n";
            std::cout << "Nick nao encontrado, tente outro:\n";
            std::getline(std::cin, name);
        }
        else {
            break;
        }
    }

    system("cls");

    std::string password;
    std::cout << "LOGIN\n\n";
    std::cout << "Nick: " << name << "\n";
    std::cout << "Digite o sua senha:\n";
    std::getline(std::cin, password);

    std::ifstream base("base.txt", std::ios::in);
    while(1) {
        if(passwordChecker(name, password))
            break;
        else {
            system("cls");
            std::cout << "LOGIN\n\n";
            std::cout << "Nick: " << name << "\n";
            std::cout << "Senha incorreta, tente outra:\n";
            std::getline(std::cin, password);
        }
    }
    base.close();

    system("cls");
    std::cout << "LOGIN\n\n";
    std::cout << "Usuario " << name << " logado\n\n";
    system("pause");
    system("cls");

    return name;
}