#ifndef PLAYER
#define PLAYER
#include "tools.h"
#include "cartela.h"

    int compcart(); //comparar cartelas
    
    void getplayerdata(); // pegar infos sobre jogadores

    void gerarallcarta(); // gerar todas cartelas dos jogadores

    int checkallplayers(); // verificar quantos jogadores ja saiu do jogo

    void removewinner(); // remover o vencedor

    void removeloser(); // remover o perdedor

#endif