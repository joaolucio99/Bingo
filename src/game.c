#include "../lib/game.h"

    void initscreen(){
        int opc;
            clearter();
            gerardes();
            printf("\n\n\t          1-JOGAR\n");
            printf("\t          2-INSTRUCOES\n");
            printf("\t          3-EXIT\n\n\n");
            printf("Digite a opção desejada: ");
            erroroption(&opc,1,3);
            switch(opc){
                case 1:
                    startgame();
                    break;
                case 2:
                    instruct();
                    break;
                case 3:
                    exit(0);
                default:
                    break;
            }
    }

    void instruct(){ 
        int opc;
            clearter();
            printf(ANSI_COLOR_GREEN"INSTRUÇOES DE JOGO\n\n\n"ANSI_COLOR_RESET);
            printf("° O numero minimo de jogadores sao 2 e o maximo sao 5.\n\n");
            printf("° Cada jogador pode usar de 1 a 4 cartelas. Sendo 1 o numero minimo e 4 o numero maximo.\n\n");
            printf("° A cada rodada será sorteada uma 'pedra', que sera um numero aleatorio que nao se repete.\n\n");
            printf("° A cada rodada as tabelas dos jogadores serao mostradas na tela, caso o jogador tenha o numero 'cantado' em sua tabela, este sera marcado na tabela.\n\n");
            printf("° O jogador que completar uma linha ou coluna pode digitar 'bingo' quando for marcar o ultimo numero 'cantado' em sua cartela.\n\n");
            printf("° Ganha o jogador que cantar bingo primeiro, o jogo so termina quando o penultimo cantar bingo.\n\n");
            printf("° Ao cantar bingo o jogador devera inserir a linha ou coluna e o numero da cartela que bingou.\n\n");
            printf("° Caso o jogador tenha mais de uma cartela e cante bingo o mesmo perde a cartela no qual cantou. Se tiver somente um cartela o mesmo sera desclassificado.\n\n");
            printf("° Se o jogador digitar a opcao errada de bingo o mesmo sera desclassificado por nao ter bingado, sem opção de segunda chance.\n\n");
            printf("° No final da partida ira aparecer o placar de todos jogadores.\n\n");
            printf(ANSI_COLOR_GREEN"\n\nDigite 1 e tecle enter para voltar ao menu: "ANSI_COLOR_RESET);
                do{
                scanf("%i",&opc);
                    if(opc!=1){
                        printf("\n\nOpcao invalida tente novamente: ");
                    }
                } while(opc!=1);
                switch(opc){
                    case 1:
                        initscreen();
                        break;
                    default:
                        initscreen();
                } 
    }

    void startgame(){
        int nplayer,i,j,*rocks,*auxrocks,teste,count=0,count2=0,lastplayer;
        rocks = (int*)malloc(sizeof(int)*76);
        auxrocks = (int*)malloc(sizeof(int)*76);
            clearter();
            printf("Quantos jogadores participara do bingo: ");
            scanf("%d",&nplayer);
                if(nplayer<=1 || nplayer>5){
                    do{
                        printf("\nO numero de jogadores e de no minimo 2 e maximo 5. Tente novamente.\n");
                        printf("\nQuantos jogadores participara do bingo: ");
                        scanf("%d",&nplayer);
                    } while(nplayer<=1 || nplayer>5);
                }
            players player[nplayer];
            players winners[nplayer];    
            clearter();
            getplayerdata(player,nplayer);
            gerarallcarta(player,nplayer); 
            generaterocks(rocks);
                for(i=1;i<76;i++){ 
                    int g=1+rand()%75;
                        while (i!=0 && g==rocks[g]) g=1+rand()%75;
                    rocks[g]=g;
                    auxrocks[i]=g;
                    printallcarta(player,nplayer,auxrocks,i);
                    printf("\n\n--------------------------------------------------------------------------------------");
                    printf("\n\nPedras sorteadas:"); 
                    printrock(i,auxrocks);
                    gameround(player,winners,j,i,auxrocks,teste,nplayer,&count,&count2);
                    checkfinalround(player,winners,nplayer,&lastplayer,count);
                    clearter();
                }            
    }

    void finalchoice(){
        int opc;
        printf(ANSI_COLOR_GREEN"\t         [1]MENU"ANSI_COLOR_RESET); 
        printf(ANSI_COLOR_RED"   [2]SAIR "ANSI_COLOR_RESET);
        erroroption(&opc,1,2);
        switch(opc){
                case 1:
                    initscreen();
                    break;
                case 2:
                    exit(0);
                default:
                    break;
            }    
    }