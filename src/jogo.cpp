#include "../include/carta.hpp"
#include "../include/baralho.hpp"
#include "../include/jogador.hpp"
#include "../include/bot.hpp"
#include "../include/humano.hpp"
#include "../include/rodada.hpp"
#include "../include/menu.hpp"
#include "../include/jogo.hpp"

#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>

void Jogo::novoJogo()
{
    Menu menuJogo;
    menuJogo.cadastroUsuario();
    int proxPasso;
    std::cout << "Se quiser visualizar o ranking digite 1, se quiser iniciar a partida digite 2: ";
    std::cin >> proxPasso;
    while (proxPasso != 1 || proxPasso != 2)
    {
        std::cout << "Numero invalido! " << std::endl;
        std::cout << "Se quiser visualizar o ranking digite 1, se quiser iniciar a partida digite 2: ";
        std::cin >> proxPasso;
    }
    if (proxPasso == 1)
    {
        menuJogo.ranking();
    }

    menuJogo.limparTela();
    std::cout << "O jogo irá iniciar!";

    Baralho baralhoDaQueda;
    baralhoDaQueda.inicializarBaralhoCompleto();
    baralhoDaQueda.inicializarMaoJogadores();

    Humano usuario = Humano(menuJogo._nomeUsuario, baralhoDaQueda.getMaoJogador1(), 1);
    Bot bot1 = Bot("Bot1", baralhoDaQueda.getMaoJogador2(), 1);
    Bot bot2 = Bot("Bot2", baralhoDaQueda.getMaoJogador3(), 2);
    Bot bot3 = Bot("Bot3", baralhoDaQueda.getMaoJogador4(), 2);
}