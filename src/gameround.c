#include "../lib/gameround.h"

    void gameround(struct players player[],struct players winners[],int j,int i,int *auxrocks,int teste,int nplayer,int *count,int *count2){
        for(j=0;j<nplayer;j++){
                if(player[j].out!=0);
                else{
                int opccart;
                printf("\n\n\n Jogador(a) %d qual opcao voce deseja?\n [1]Passar a vez [2]Bingo ",j+1);
                erroroption(&opccart,1,2);
                    switch(opccart){
                        case 1:
                            break;
                        case 2: ;
                        int ncartabingo,opcbingo,opccollin;
                            printf("\n\n Jogador(a) %d digita o número da cartela que bingou: ",j+1);
                                do{
                                scanf("%i",&ncartabingo);
                                    if(ncartabingo<1 || ncartabingo>player[j].ncarta || player[j].carta[ncartabingo-1].out!=0){
                                        printf("\n\nOpcao invalida tente novamente: ");
                                    }
                                } while(ncartabingo<1 || ncartabingo>player[j].ncarta || player[j].carta[ncartabingo-1].out!=0);
                            printf("\n Digite a opcao correspondente ao que bingou:\n [1]Coluna [2]Linha ");
                                erroroption(&opcbingo,1,2);
                                switch(opcbingo){
                                    case 1:
                                        printf("\n Digite o numero da coluna: ");
                                        erroroption(&opccollin,1,5);
                                        teste=checkcolbingo(player,j,ncartabingo,opccollin,auxrocks,i);
                                        checkbingo(player,winners,opccollin,teste,nplayer,ncartabingo,j,count,count2);     
                                        break;
                                    case 2:
                                        printf("\n Digite o numero da linha: ");
                                        erroroption(&opccollin,1,5);
                                        teste=checklinbingo(player,j,ncartabingo,opccollin,auxrocks,i);
                                        checkbingo(player,winners,opccollin,teste,nplayer,ncartabingo,j,count,count2);
                                        break;    
                                    default:
                                        break;      
                                }
                            break;
                        default:
                            break;  
                    }
                if(checkallcartas(player,j)==0){
                removeloser(player,winners,j,count2,nplayer); 
                } 
            }        
        }

    }

    void checkfinalround(struct players player[],struct players winners[],int nplayer,int *lastplayer,int count){
        if(checkallplayers(player,nplayer,lastplayer)==nplayer){ 
            clearter();
            gerardes2();
            printwinners(winners,nplayer);
            finalchoice();
        }
        if(checkallplayers(player,nplayer,lastplayer)==nplayer-1){   
            winners[count]=player[*lastplayer];
            clearter();
            gerardes2();
            printwinners(winners,nplayer);
            finalchoice();
        }
    }