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

int main()
{
    srand(time(NULL));
    Jogo jogo;

    // inicializa o menu do jogo e cadastra o usuario
    jogo.inicializaMenu();
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
        jogo.menuJogo.limparTela();
        std::cout << "O jogo ira iniciar!";
    }

    if (proxPasso == 2)
    {
        jogo.menuJogo.limparTela();
        std::cout << "O jogo ira iniciar!";

        // inicializa o baralho completo e prepara a mao de cada jogador
        jogo.inicializaBaralho();

        // // inicializa os jogadores
        // inicializaJogadores();

        jogo.menuJogo.limparTela();

        int quemIniciaJogandoRodada = 0;
        int idJogadorMaiorCarta;

        // while que controla a partida em si, ela so termina se uma das duplas fizer 12 pontos
        while (jogo.usuario.getPontos() < 12 && jogo.bot1.getPontos() < 12)
        {

            if (quemIniciaJogandoRodada == 0)
            {
                jogo.menuJogo.limparTela();
                std::cout << "Nova rodada esta iniciando..." << std::endl;
                // distribui as cartas pros jogadores
                jogo.usuario.setMao(jogo.baralhoDaQueda.getMaoJogador0());
                jogo.bot1.setMao(jogo.baralhoDaQueda.getMaoJogador1());
                jogo.bot2.setMao(jogo.baralhoDaQueda.getMaoJogador2());
                jogo.bot3.setMao(jogo.baralhoDaQueda.getMaoJogador3());

                jogo.sequenciaJogadasIniciandoUsuario();

                // fazer funcao na classe rodada para checar o id de quem tacou a maior carta
                idJogadorMaiorCarta = jogo.rodadaAtual.getMaiorIdMd3();

                // continua a rodada enquanto nenhuma dupla tiver ganhado a md3
                while (jogo.rodadaAtual.getVitoriasParciaisDupla1() != 2 && jogo.rodadaAtual.getVitoriasParciaisDupla2() != 2)
                {
                    jogo.sequenciaJogadasMd3(idJogadorMaiorCarta);
                    // fazer funcao na classe rodada para checar o id de quem tacou a maior carta
                    idJogadorMaiorCarta = jogo.rodadaAtual.getMaiorIdMd3();
                }

                jogo.procedimentosFinalRodada();
                quemIniciaJogandoRodada = 1;
            }
            else if (quemIniciaJogandoRodada == 1)
            {
                jogo.menuJogo.limparTela();
                std::cout << "Nova rodada esta iniciando..." << std::endl;
                // aqui no inicio vamo ter que chamar as funcoes setMao de cada jogador para dar as cartas novas para eles
                jogo.usuario.setMao(jogo.baralhoDaQueda.getMaoJogador0());
                jogo.bot1.setMao(jogo.baralhoDaQueda.getMaoJogador1());
                jogo.bot2.setMao(jogo.baralhoDaQueda.getMaoJogador2());
                jogo.bot3.setMao(jogo.baralhoDaQueda.getMaoJogador3());

                jogo.sequenciaJogadasIniciandoBot1();

                // fazer funcao na classe rodada para checar o id de quem tacou a maior carta
                idJogadorMaiorCarta = jogo.rodadaAtual.getMaiorIdMd3();

                // continua a rodada enquanto nenhuma dupla tiver ganhado a md3
                while (jogo.rodadaAtual.getVitoriasParciaisDupla1() != 2 && jogo.rodadaAtual.getVitoriasParciaisDupla2() != 2)
                {
                    jogo.sequenciaJogadasMd3(idJogadorMaiorCarta);
                    // fazer funcao na classe rodada para checar o id de quem tacou a maior carta
                    idJogadorMaiorCarta = jogo.rodadaAtual.getMaiorIdMd3();
                }

                jogo.procedimentosFinalRodada();
                quemIniciaJogandoRodada = 2;
            }
            else if (quemIniciaJogandoRodada == 2)
            {
                jogo.menuJogo.limparTela();
                std::cout << "Nova rodada esta iniciando..." << std::endl;
                // aqui no inicio vamo ter que chamar as funcoes setMao de cada jogador para dar as cartas novas para eles
                jogo.usuario.setMao(jogo.baralhoDaQueda.getMaoJogador0());
                jogo.bot1.setMao(jogo.baralhoDaQueda.getMaoJogador1());
                jogo.bot2.setMao(jogo.baralhoDaQueda.getMaoJogador2());
                jogo.bot3.setMao(jogo.baralhoDaQueda.getMaoJogador3());

                jogo.sequenciaJogadasIniciandoBot2();

                // fazer funcao na classe rodada para checar o id de quem tacou a maior carta
                idJogadorMaiorCarta = jogo.rodadaAtual.getMaiorIdMd3();

                // continua a rodada enquanto nenhuma dupla tiver ganhado a md3
                while (jogo.rodadaAtual.getVitoriasParciaisDupla1() != 2 && jogo.rodadaAtual.getVitoriasParciaisDupla2() != 2)
                {
                    jogo.sequenciaJogadasMd3(idJogadorMaiorCarta);
                    // fazer funcao na classe rodada para checar o id de quem tacou a maior carta
                    idJogadorMaiorCarta = jogo.rodadaAtual.getMaiorIdMd3();
                }

                jogo.procedimentosFinalRodada();
                quemIniciaJogandoRodada = 3;
            }
            else if (quemIniciaJogandoRodada == 3)
            {
                jogo.menuJogo.limparTela();
                std::cout << "Nova rodada esta iniciando..." << std::endl;
                // aqui no inicio vamo ter que chamar as funcoes setMao de cada jogador para dar as cartas novas para eles
                jogo.usuario.setMao(jogo.baralhoDaQueda.getMaoJogador0());
                jogo.bot1.setMao(jogo.baralhoDaQueda.getMaoJogador1());
                jogo.bot2.setMao(jogo.baralhoDaQueda.getMaoJogador2());
                jogo.bot3.setMao(jogo.baralhoDaQueda.getMaoJogador3());

                jogo.sequenciaJogadasIniciandoBot3();

                // fazer funcao na classe rodada para checar o id de quem tacou a maior carta
                idJogadorMaiorCarta = jogo.rodadaAtual.getMaiorIdMd3();

                // continua a rodada enquanto nenhuma dupla tiver ganhado a md3
                while (jogo.rodadaAtual.getVitoriasParciaisDupla1() != 2 && jogo.rodadaAtual.getVitoriasParciaisDupla2() != 2)
                {
                    jogo.sequenciaJogadasMd3(idJogadorMaiorCarta);
                    // fazer funcao na classe rodada para checar o id de quem tacou a maior carta
                    idJogadorMaiorCarta = jogo.rodadaAtual.getMaiorIdMd3();
                }

                jogo.procedimentosFinalRodada();

                quemIniciaJogandoRodada = 0;
            }
        }

        std::cout << jogo.usuario.getPontos() << std::endl;
        std::cout << jogo.bot1.getPontos();
        if (jogo.usuario.getPontos() >= 12)
        {
            std::cout << "usuario ganhou";
        }
        else if (jogo.bot1.getPontos() >= 12)
        {
            std::cout << "usuario perdeu";
        }
    }
}