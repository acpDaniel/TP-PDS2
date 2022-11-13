#include "../include/carta.hpp"
#include "../include/baralho.hpp"
#include "../include/jogador.hpp"
#include "../include/bot.hpp"
#include "../include/humano.hpp"
#include "../include/rodada.hpp"
#include "../include/menu.hpp"
#include "../include/jogo.hpp"

/**DEBUG
#include "baralho.cpp"
#include "bot.cpp"
#include "carta.cpp"
#include "humano.cpp"
#include "jogador.cpp"
#include "menu.cpp"
#include "rodada.cpp"**/

#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <fstream>

// ---- METODOS DA CLASSE JOGO ----

Jogo::Jogo()
{
    menuJogo = Menu();
    baralhoDaQueda = Baralho();
    rodadaAtual = Rodada();
    usuario = Humano(menuJogo._nomeUsuario, 1, 0);
    bot1 = Bot("Bot1", 2, 1);
    bot2 = Bot("Bot2", 1, 2);
    bot3 = Bot("Bot3", 2, 3);
}

void Jogo::inicializaMenu()
{
    menuJogo.cadastroUsuario();
}

void Jogo::inicializaBaralho()
{

    baralhoDaQueda.inicializarBaralhoCompleto();
    baralhoDaQueda.inicializarMaoJogadores();
}

// void Jogo::inicializaJogadores()
// {
//     // constroi os jogadores atribuindo nome,id da dupla , id jogador
//     usuario = Humano(menuJogo._nomeUsuario, 1, 0);
//     bot1 = Bot("Bot1", 2, 1);
//     bot2 = Bot("Bot2", 1, 2);
//     bot3 = Bot("Bot3", 2, 3);
// }

// sequencia de jogadas iniciando com o usuario
void Jogo::sequenciaJogadasIniciandoUsuario()
{
    int indiceCartaEscolhida;
    checaPedidoTrucoJogador();
    std::cout << "Escolha a carta para jogar:" << std::endl;
    std::cout << "Digite 0 para escolher a primeira carta, 1 para escolher a segunda ou 2 para a terceira" << std::endl;
    // imprime as opcoes de carta do jogador
    usuario.imprimeCartasJogador();
    std::cin >> indiceCartaEscolhida; // ****** TEM QUE TRATAR OS ERROS POSSIVEIS DAQUI ******
    // insere na classe rodada a carta que foi escolhida pelo jogador, tira essa carta da mao do jogador
    Carta cartaSelecionadaUsuario = usuario.jogarCarta(indiceCartaEscolhida);
    rodadaAtual.inserirCartaDupla1(cartaSelecionadaUsuario);

    std::cout << std::endl;

    checaPedidoTrucoBot1();
    std::cout << "Bot1 (dupla adversaria) vai jogar..." << std::endl;
    Carta cartaSelecionadaBot1 = bot1.jogarCarta();
    rodadaAtual.inserirCartaDupla2(cartaSelecionadaBot1);

    std::cout << std::endl;

    checaPedidoTrucoBot2();
    std::cout << "Bot2 (minha dupla) vai jogar..." << std::endl;
    Carta cartaSelecionadaBot2 = bot2.jogarCarta();
    rodadaAtual.inserirCartaDupla1(cartaSelecionadaBot2);

    std::cout << std::endl;

    checaPedidoTrucoBot3();
    std::cout << "Bot3 (dupla adversaria) vai jogar..." << std::endl;
    Carta cartaSelecionadaBot3 = bot3.jogarCarta();
    rodadaAtual.inserirCartaDupla2(cartaSelecionadaBot3);

    rodadaAtual.setMaiorIdMd3(rodadaAtual.idJogadorMaiorCarta(cartaSelecionadaUsuario.getPeso(), cartaSelecionadaBot1.getPeso(), cartaSelecionadaBot2.getPeso(), cartaSelecionadaBot3.getPeso()));

    // checagem de qual dupla ganhou a queda
    rodadaAtual.checagemVitoriaParcial();
}

void Jogo::sequenciaJogadasIniciandoBot1()
{
    checaPedidoTrucoBot1();
    std::cout << "Bot1 (dupla adversaria) vai jogar..." << std::endl;
    Carta cartaSelecionadaBot1 = bot1.jogarCarta();
    rodadaAtual.inserirCartaDupla2(cartaSelecionadaBot1);

    std::cout << std::endl;

    checaPedidoTrucoBot2();
    std::cout << "Bot2 (minha dupla) vai jogar..." << std::endl;
    Carta cartaSelecionadaBot2 = bot2.jogarCarta();
    rodadaAtual.inserirCartaDupla1(cartaSelecionadaBot2);

    std::cout << std::endl;

    checaPedidoTrucoBot3();
    std::cout << "Bot3 (dupla adversaria) vai jogar..." << std::endl;
    Carta cartaSelecionadaBot3 = bot3.jogarCarta();
    rodadaAtual.inserirCartaDupla2(cartaSelecionadaBot3);

    std::cout << std::endl;

    int indiceCartaEscolhida;
    checaPedidoTrucoJogador();
    std::cout << "Escolha a carta para jogar:" << std::endl;
    std::cout << "Digite 0 para escolher a primeira carta, 1 para escolher a segunda ou 2 para a terceira" << std::endl;
    // imprime as opcoes de carta do jogador
    usuario.imprimeCartasJogador();
    std::cin >> indiceCartaEscolhida; // ****** TEM QUE TRATAR OS ERROS POSSIVEIS DAQUI ******
    // insere na classe rodada a carta que foi escolhida pelo jogador, tira essa carta da mao do jogador
    Carta cartaSelecionadaUsuario = usuario.jogarCarta(indiceCartaEscolhida);
    rodadaAtual.inserirCartaDupla1(cartaSelecionadaUsuario);

    rodadaAtual.setMaiorIdMd3(rodadaAtual.idJogadorMaiorCarta(cartaSelecionadaUsuario.getPeso(), cartaSelecionadaBot1.getPeso(), cartaSelecionadaBot2.getPeso(), cartaSelecionadaBot3.getPeso()));

    // checagem de qual dupla ganhou a queda
    rodadaAtual.checagemVitoriaParcial();
}

void Jogo::sequenciaJogadasIniciandoBot2()
{
    checaPedidoTrucoBot2();
    std::cout << "Bot2 (minha dupla) vai jogar..." << std::endl;
    Carta cartaSelecionadaBot2 = bot2.jogarCarta();
    rodadaAtual.inserirCartaDupla1(cartaSelecionadaBot2);

    std::cout << std::endl;

    checaPedidoTrucoBot3();
    std::cout << "Bot3 (dupla adversaria) vai jogar..." << std::endl;
    Carta cartaSelecionadaBot3 = bot3.jogarCarta();
    rodadaAtual.inserirCartaDupla2(cartaSelecionadaBot3);

    std::cout << std::endl;

    int indiceCartaEscolhida;
    checaPedidoTrucoJogador();
    std::cout << "Escolha a carta para jogar:" << std::endl;
    std::cout << "Digite 0 para escolher a primeira carta, 1 para escolher a segunda ou 2 para a terceira" << std::endl;
    // imprime as opcoes de carta do jogador
    usuario.imprimeCartasJogador();
    std::cin >> indiceCartaEscolhida; // ****** TEM QUE TRATAR OS ERROS POSSIVEIS DAQUI ******
    // insere na classe rodada a carta que foi escolhida pelo jogador, tira essa carta da mao do jogador
    Carta cartaSelecionadaUsuario = usuario.jogarCarta(indiceCartaEscolhida);
    rodadaAtual.inserirCartaDupla1(cartaSelecionadaUsuario);

    std::cout << std::endl;

    checaPedidoTrucoBot1();
    std::cout << "Bot1 (dupla adversaria) vai jogar..." << std::endl;
    Carta cartaSelecionadaBot1 = bot1.jogarCarta();
    rodadaAtual.inserirCartaDupla2(cartaSelecionadaBot1);

    rodadaAtual.setMaiorIdMd3(rodadaAtual.idJogadorMaiorCarta(cartaSelecionadaUsuario.getPeso(), cartaSelecionadaBot1.getPeso(), cartaSelecionadaBot2.getPeso(), cartaSelecionadaBot3.getPeso()));

    // checagem de qual dupla ganhou a queda
    rodadaAtual.checagemVitoriaParcial();
}

void Jogo::sequenciaJogadasIniciandoBot3()
{
    checaPedidoTrucoBot3();
    std::cout << "Bot3 (dupla adversaria) vai jogar..." << std::endl;
    Carta cartaSelecionadaBot3 = bot3.jogarCarta();
    rodadaAtual.inserirCartaDupla2(cartaSelecionadaBot3);

    std::cout << std::endl;

    int indiceCartaEscolhida;
    checaPedidoTrucoJogador();
    std::cout << "Escolha a carta para jogar:" << std::endl;
    std::cout << "Digite 0 para escolher a primeira carta, 1 para escolher a segunda ou 2 para a terceira" << std::endl;
    // imprime as opcoes de carta do jogador
    usuario.imprimeCartasJogador();
    std::cin >> indiceCartaEscolhida; // ****** TEM QUE TRATAR OS ERROS POSSIVEIS DAQUI ******
    // insere na classe rodada a carta que foi escolhida pelo jogador, tira essa carta da mao do jogador
    Carta cartaSelecionadaUsuario = usuario.jogarCarta(indiceCartaEscolhida);
    rodadaAtual.inserirCartaDupla1(cartaSelecionadaUsuario);

    std::cout << std::endl;

    checaPedidoTrucoBot1();
    std::cout << "Bot1 (minha dupla) vai jogar..." << std::endl;
    Carta cartaSelecionadaBot1 = bot1.jogarCarta();
    rodadaAtual.inserirCartaDupla2(cartaSelecionadaBot1);

    std::cout << std::endl;

    checaPedidoTrucoBot2();
    std::cout << "Bot2 (dupla adversaria) vai jogar..." << std::endl;
    Carta cartaSelecionadaBot2 = bot2.jogarCarta();
    rodadaAtual.inserirCartaDupla1(cartaSelecionadaBot2);

    rodadaAtual.setMaiorIdMd3(rodadaAtual.idJogadorMaiorCarta(cartaSelecionadaUsuario.getPeso(), cartaSelecionadaBot1.getPeso(), cartaSelecionadaBot2.getPeso(), cartaSelecionadaBot3.getPeso()));

    // checagem de qual dupla ganhou a queda
    rodadaAtual.checagemVitoriaParcial();
}

void Jogo::checaPedidoTrucoJogador()
{
    bool pedindoTruco;
    bool resposta;
    std::cout << "Se deseja pedir truco digite 1, se nao digite 0";
    std::cin >> pedindoTruco;
    if (pedindoTruco == true)
    {
        resposta = bot1.aceitarTruco();
        if (resposta == true)
        {
            rodadaAtual.aumentaPontuacaoRodadaAtual();
            std::cout << "Pedido de truco foi aceito" << std::endl;
        }
        else
        {
            std::cout << "Pedido de truco nao foi aceito" << std::endl;
        }
    }
}

void Jogo::checaPedidoTrucoBot1()
{
    bool pedindoTruco = bot1.pedirTruco();
    bool resposta;
    if (pedindoTruco == true)
    {
        std::cout << "Se deseja aceitar o truco digite 1, se nao digite 0";
        std::cin >> resposta;
        if (resposta == true)
        {
            rodadaAtual.aumentaPontuacaoRodadaAtual();
            std::cout << "Pedido de truco foi aceito" << std::endl;
        }
    }
}

void Jogo::checaPedidoTrucoBot2()
{
    bool pedindoTruco = bot2.pedirTruco();
    bool resposta;
    if (pedindoTruco == true)
    {
        resposta = bot1.aceitarTruco();
        if (resposta == true)
        {
            rodadaAtual.aumentaPontuacaoRodadaAtual();
            std::cout << "Pedido de truco foi aceito" << std::endl;
        }
    }
}

void Jogo::checaPedidoTrucoBot3()
{
    bool pedindoTruco = bot3.pedirTruco();
    bool resposta;
    if (pedindoTruco == true)
    {
        std::cout << "Se deseja aceitar o truco digite 1, se nao digite 0";
        std::cin >> resposta;
        if (resposta == true)
        {
            rodadaAtual.aumentaPontuacaoRodadaAtual();
            std::cout << "Pedido de truco foi aceito" << std::endl;
        }
    }
}

// procedimentos do final de uma rodada
void Jogo::procedimentosFinalRodada()
{
    // dar o ponto da md3 para quem ganhou ela, no caso so preenchi do usuario ou do bot1 (ja que sao pontos da dupla nao precisa preencher todo mundo)
    if (rodadaAtual.checagemDuplaVencedora() == 1)
    {
        usuario.adicionaPontos(rodadaAtual.getPontuacaoRodadaAtual());
    }
    else if (rodadaAtual.checagemDuplaVencedora() == 2)
    {
        bot1.adicionaPontos(rodadaAtual.getPontuacaoRodadaAtual());
    }
    // reseta o valor da md3 para 2
    rodadaAtual.resetPontuacaoRodadaAtual();
    // reseta as vitorias parciais pois vai ter nova md3
    rodadaAtual.resetVitoriasParciaisDuplas();
    // reseta o baralho adicionando novamente todas as cartas e prepara a mao de cada jogador
    baralhoDaQueda.resetarBaralhoEMaoJogadores();
    baralhoDaQueda.inicializarBaralhoCompleto();
    baralhoDaQueda.inicializarMaoJogadores();
}

// ---- FIM DOS METODOS DA CLASSE JOGO ----

//

//

// **** FUNCAO PRINCIPAL DO JOGO ****

void Jogo::novoJogo()
{
    // inicializa o menu do jogo e cadastra o usuario
    inicializaMenu();
    // se quiser visualizar o ranking digita 1, se quiser iniciar a partida digite 2
    int proxPasso;
    std::cout << "Se quiser visualizar o ranking digite 1, se quiser iniciar a partida digite 2: ";
    std::cin >> proxPasso;
    // se o usuario digitar um valor invalido vai repetir a msg
    while (proxPasso != 1 && proxPasso != 2)
    {
        std::cout << "Numero invalido! " << std::endl;
        std::cout << "Se quiser visualizar o ranking digite 1, se quiser iniciar a partida digite 2: ";
        std::cin >> proxPasso;
    }
    if (proxPasso == 1)
    {
        // menuJogo.ranking(); COMENTADO POR ENQT PQ PODE ESTAR ERRADA ********************************************************
        std::cout << "Se quiser iniciar a partida digite 2: ";
        std::cin >> proxPasso;
    }
    else
    {
        menuJogo.limparTela();
        std::cout << "O jogo ira iniciar!";
    }

    if (proxPasso == 2)
    {
        menuJogo.limparTela();
        std::cout << "O jogo ira iniciar!";

        // inicializa o baralho completo e prepara a mao de cada jogador
        inicializaBaralho();

        // // inicializa os jogadores
        // inicializaJogadores();

        menuJogo.limparTela();

        int quemIniciaJogandoRodada = 0;
        int idJogadorMaiorCarta;

        // while que controla a partida em si, ela so termina se uma das duplas fizer 12 pontos
        while (usuario.getPontos() < 12 && bot1.getPontos() < 12)
        {

            if (quemIniciaJogandoRodada == 0)
            {
                menuJogo.limparTela();
                std::cout << "Nova rodada esta iniciando..." << std::endl;
                // distribui as cartas pros jogadores
                usuario.setMao(baralhoDaQueda.getMaoJogador0());
                bot1.setMao(baralhoDaQueda.getMaoJogador1());
                bot2.setMao(baralhoDaQueda.getMaoJogador2());
                bot3.setMao(baralhoDaQueda.getMaoJogador3());

                sequenciaJogadasIniciandoUsuario();

                // fazer funcao na classe rodada para checar o id de quem tacou a maior carta
                idJogadorMaiorCarta = rodadaAtual.getMaiorIdMd3();

                // continua a rodada enquanto nenhuma dupla tiver ganhado a md3
                while (rodadaAtual.getVitoriasParciaisDupla1() != 2 && rodadaAtual.getVitoriasParciaisDupla2() != 2)
                {
                    // começar jogando agr quem tacou a maior carta
                    if (idJogadorMaiorCarta == 0)
                    {
                        std::cout << "-------- FIM DA QUEDA --------" << std::endl;
                        std::cout << std::endl;
                        std::cout << std::endl;
                        std::cout << "-------- Nova queda esta comecando --------" << std::endl;
                        // menuJogo.limparTela();
                        sequenciaJogadasIniciandoUsuario();

                        // fazer funcao na classe rodada para checar o id de quem tacou a maior carta
                        idJogadorMaiorCarta = rodadaAtual.getMaiorIdMd3();
                    }
                    else if (idJogadorMaiorCarta == 1)
                    {
                        std::cout << "-------- FIM DA QUEDA --------";
                        std::cout << std::endl;
                        std::cout << std::endl;
                        std::cout << "-------- Nova queda esta comecando --------" << std::endl;
                        // menuJogo.limparTela();
                        sequenciaJogadasIniciandoBot1();

                        // fazer funcao na classe rodada para checar o id de quem tacou a maior carta
                        idJogadorMaiorCarta = rodadaAtual.getMaiorIdMd3();
                    }
                    else if (idJogadorMaiorCarta == 2)
                    {
                        std::cout << "-------- FIM DA QUEDA --------";
                        std::cout << std::endl;
                        std::cout << std::endl;
                        std::cout << "-------- Nova queda esta comecando --------" << std::endl;
                        // menuJogo.limparTela();
                        sequenciaJogadasIniciandoBot2();

                        // fazer funcao na classe rodada para checar o id de quem tacou a maior carta
                        idJogadorMaiorCarta = rodadaAtual.getMaiorIdMd3();
                    }
                    else if (idJogadorMaiorCarta == 3)
                    {
                        std::cout << "-------- FIM DA QUEDA --------";
                        std::cout << std::endl;
                        std::cout << std::endl;
                        std::cout << "-------- Nova queda esta comecando --------" << std::endl;
                        // menuJogo.limparTela();
                        sequenciaJogadasIniciandoBot3();

                        // fazer funcao na classe rodada para checar o id de quem tacou a maior carta
                        idJogadorMaiorCarta = rodadaAtual.getMaiorIdMd3();
                    }
                }

                procedimentosFinalRodada();
                quemIniciaJogandoRodada = 1;
            }
            else if (quemIniciaJogandoRodada == 1)
            {
                menuJogo.limparTela();
                std::cout << "Nova rodada esta iniciando..." << std::endl;
                // aqui no inicio vamo ter que chamar as funcoes setMao de cada jogador para dar as cartas novas para eles
                usuario.setMao(baralhoDaQueda.getMaoJogador0());
                bot1.setMao(baralhoDaQueda.getMaoJogador1());
                bot2.setMao(baralhoDaQueda.getMaoJogador2());
                bot3.setMao(baralhoDaQueda.getMaoJogador3());

                sequenciaJogadasIniciandoBot1();

                // fazer funcao na classe rodada para checar o id de quem tacou a maior carta
                idJogadorMaiorCarta = rodadaAtual.getMaiorIdMd3();

                // continua a rodada enquanto nenhuma dupla tiver ganhado a md3
                while (rodadaAtual.getVitoriasParciaisDupla1() != 2 && rodadaAtual.getVitoriasParciaisDupla2() != 2)
                {
                    // começar jogando agr quem tacou a maior carta
                    if (idJogadorMaiorCarta == 0)
                    {
                        std::cout << "-------- FIM DA QUEDA --------" << std::endl;
                        std::cout << std::endl;
                        std::cout << std::endl;
                        std::cout << "-------- Nova queda esta comecando --------" << std::endl;
                        // menuJogo.limparTela();
                        sequenciaJogadasIniciandoUsuario();

                        // fazer funcao na classe rodada para checar o id de quem tacou a maior carta
                        idJogadorMaiorCarta = rodadaAtual.getMaiorIdMd3();
                    }
                    else if (idJogadorMaiorCarta == 1)
                    {
                        std::cout << "-------- FIM DA QUEDA --------" << std::endl;
                        std::cout << std::endl;
                        std::cout << std::endl;
                        std::cout << "-------- Nova queda esta comecando --------" << std::endl;
                        // menuJogo.limparTela();
                        sequenciaJogadasIniciandoBot1();

                        // fazer funcao na classe rodada para checar o id de quem tacou a maior carta
                        idJogadorMaiorCarta = rodadaAtual.getMaiorIdMd3();
                    }
                    else if (idJogadorMaiorCarta == 2)
                    {
                        std::cout << "-------- FIM DA QUEDA --------" << std::endl;
                        std::cout << std::endl;
                        std::cout << std::endl;
                        std::cout << "-------- Nova queda esta comecando --------" << std::endl;
                        // menuJogo.limparTela();
                        sequenciaJogadasIniciandoBot2();

                        // fazer funcao na classe rodada para checar o id de quem tacou a maior carta
                        idJogadorMaiorCarta = rodadaAtual.getMaiorIdMd3();
                    }
                    else if (idJogadorMaiorCarta == 3)
                    {
                        std::cout << "-------- FIM DA QUEDA --------" << std::endl;
                        std::cout << std::endl;
                        std::cout << std::endl;
                        std::cout << "-------- Nova queda esta comecando --------" << std::endl;
                        // menuJogo.limparTela();
                        sequenciaJogadasIniciandoBot3();

                        // fazer funcao na classe rodada para checar o id de quem tacou a maior carta
                        idJogadorMaiorCarta = rodadaAtual.getMaiorIdMd3();
                    }
                }

                procedimentosFinalRodada();
                quemIniciaJogandoRodada = 2;
            }
            else if (quemIniciaJogandoRodada == 2)
            {
                menuJogo.limparTela();
                std::cout << "Nova rodada esta iniciando..." << std::endl;
                // aqui no inicio vamo ter que chamar as funcoes setMao de cada jogador para dar as cartas novas para eles
                usuario.setMao(baralhoDaQueda.getMaoJogador0());
                bot1.setMao(baralhoDaQueda.getMaoJogador1());
                bot2.setMao(baralhoDaQueda.getMaoJogador2());
                bot3.setMao(baralhoDaQueda.getMaoJogador3());

                sequenciaJogadasIniciandoBot2();

                // fazer funcao na classe rodada para checar o id de quem tacou a maior carta
                idJogadorMaiorCarta = rodadaAtual.getMaiorIdMd3();

                // continua a rodada enquanto nenhuma dupla tiver ganhado a md3
                while (rodadaAtual.getVitoriasParciaisDupla1() != 2 && rodadaAtual.getVitoriasParciaisDupla2() != 2)
                {
                    // começar jogando agr quem tacou a maior carta
                    if (idJogadorMaiorCarta == 0)
                    {
                        std::cout << "-------- FIM DA QUEDA --------" << std::endl;
                        std::cout << std::endl;
                        std::cout << std::endl;
                        std::cout << "-------- Nova queda esta comecando --------" << std::endl;
                        // menuJogo.limparTela();
                        sequenciaJogadasIniciandoUsuario();

                        // fazer funcao na classe rodada para checar o id de quem tacou a maior carta
                        idJogadorMaiorCarta = rodadaAtual.getMaiorIdMd3();
                    }
                    else if (idJogadorMaiorCarta == 1)
                    {
                        std::cout << "-------- FIM DA QUEDA --------" << std::endl;
                        std::cout << std::endl;
                        std::cout << std::endl;
                        std::cout << "-------- Nova queda esta comecando --------" << std::endl;
                        // menuJogo.limparTela();
                        sequenciaJogadasIniciandoBot1();

                        // fazer funcao na classe rodada para checar o id de quem tacou a maior carta
                        idJogadorMaiorCarta = rodadaAtual.getMaiorIdMd3();
                    }
                    else if (idJogadorMaiorCarta == 2)
                    {
                        std::cout << "-------- FIM DA QUEDA --------" << std::endl;
                        std::cout << std::endl;
                        std::cout << std::endl;
                        std::cout << "-------- Nova queda esta comecando --------" << std::endl;
                        // menuJogo.limparTela();
                        sequenciaJogadasIniciandoBot2();

                        // fazer funcao na classe rodada para checar o id de quem tacou a maior carta
                        idJogadorMaiorCarta = rodadaAtual.getMaiorIdMd3();
                    }
                    else if (idJogadorMaiorCarta == 3)
                    {
                        std::cout << "-------- FIM DA QUEDA --------" << std::endl;
                        std::cout << std::endl;
                        std::cout << std::endl;
                        std::cout << "-------- Nova queda esta comecando --------" << std::endl;
                        // menuJogo.limparTela();
                        sequenciaJogadasIniciandoBot3();

                        // fazer funcao na classe rodada para checar o id de quem tacou a maior carta
                        idJogadorMaiorCarta = rodadaAtual.getMaiorIdMd3();
                    }
                }

                procedimentosFinalRodada();
                quemIniciaJogandoRodada = 3;
            }
            else if (quemIniciaJogandoRodada == 3)
            {
                menuJogo.limparTela();
                std::cout << "Nova rodada esta iniciando..." << std::endl;
                // aqui no inicio vamo ter que chamar as funcoes setMao de cada jogador para dar as cartas novas para eles
                usuario.setMao(baralhoDaQueda.getMaoJogador0());
                bot1.setMao(baralhoDaQueda.getMaoJogador1());
                bot2.setMao(baralhoDaQueda.getMaoJogador2());
                bot3.setMao(baralhoDaQueda.getMaoJogador3());

                sequenciaJogadasIniciandoBot3();

                // fazer funcao na classe rodada para checar o id de quem tacou a maior carta
                idJogadorMaiorCarta = rodadaAtual.getMaiorIdMd3();

                // continua a rodada enquanto nenhuma dupla tiver ganhado a md3
                while (rodadaAtual.getVitoriasParciaisDupla1() != 2 && rodadaAtual.getVitoriasParciaisDupla2() != 2)
                {
                    // começar jogando agr quem tacou a maior carta
                    if (idJogadorMaiorCarta == 0)
                    {
                        std::cout << "-------- FIM DA QUEDA --------" << std::endl;
                        std::cout << std::endl;
                        std::cout << std::endl;
                        std::cout << "-------- Nova queda esta comecando --------" << std::endl;
                        // menuJogo.limparTela();
                        sequenciaJogadasIniciandoUsuario();

                        // fazer funcao na classe rodada para checar o id de quem tacou a maior carta
                        idJogadorMaiorCarta = rodadaAtual.getMaiorIdMd3();
                    }
                    else if (idJogadorMaiorCarta == 1)
                    {
                        std::cout << "-------- FIM DA QUEDA --------" << std::endl;
                        std::cout << std::endl;
                        std::cout << std::endl;
                        std::cout << "-------- Nova queda esta comecando --------" << std::endl;
                        // menuJogo.limparTela();
                        sequenciaJogadasIniciandoBot1();

                        // fazer funcao na classe rodada para checar o id de quem tacou a maior carta
                        idJogadorMaiorCarta = rodadaAtual.getMaiorIdMd3();
                    }
                    else if (idJogadorMaiorCarta == 2)
                    {
                        std::cout << "-------- FIM DA QUEDA --------" << std::endl;
                        std::cout << std::endl;
                        std::cout << std::endl;
                        std::cout << "-------- Nova queda esta comecando --------" << std::endl;
                        // menuJogo.limparTela();
                        sequenciaJogadasIniciandoBot2();

                        // fazer funcao na classe rodada para checar o id de quem tacou a maior carta
                        idJogadorMaiorCarta = rodadaAtual.getMaiorIdMd3();
                    }
                    else if (idJogadorMaiorCarta == 3)
                    {
                        std::cout << "-------- FIM DA QUEDA --------" << std::endl;
                        std::cout << std::endl;
                        std::cout << std::endl;
                        std::cout << "-------- Nova queda esta comecando --------" << std::endl;
                        // menuJogo.limparTela();
                        sequenciaJogadasIniciandoBot3();

                        // fazer funcao na classe rodada para checar o id de quem tacou a maior carta
                        idJogadorMaiorCarta = rodadaAtual.getMaiorIdMd3();
                    }
                }

                procedimentosFinalRodada();

                quemIniciaJogandoRodada = 0;
            }
        }

        std::cout << usuario.getPontos() << std::endl;
        std::cout << bot1.getPontos();
        if (usuario.getPontos() >= 12)
        {
            std::cout << "usuario ganhou";
        }
        else if (bot1.getPontos() >= 12)
        {
            std::cout << "usuario perdeu";
        }
    }
}
