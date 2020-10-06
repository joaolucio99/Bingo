#ifndef TOOLS
#define TOOLS
#define ANSI_COLOR_GREEN	"\e[0;32m" //definindo cores a partir tabela ANSI
#define ANSI_COLOR_RESET     "\x1b[0m"
#define ANSI_COLOR_RED     	"\x1b[31m"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "structs.h"
#include "player.h"
#include "gameround.h"

    int checkcolbingo(); // checar se a coluna indicada realmente bingou

    int checklinbingo(); // checar se a linha indicada realmente bingou

    void checkbingo();  // checar se o jogador bingou ou nao

    void clearter(); // limpar tela para user

    void delenter(); // excluir o enter captado pelo gets

    void clearget(); // excluir qualquer lixo de memoria antes gets

    void printwinners(); // printar o ranking dos jogadores

    void erroroption(); // loop para que rode até que a opção seja valida

    void gerardes(); //gerar um desenho escrito bingo

    void gerardes2(); //gerar um desenho escrito ranking

#endif