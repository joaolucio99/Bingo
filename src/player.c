#include "../lib/player.h"

    int compcart(int tam,int a[tam][tam],int b[tam][tam]){ 
        int i,j;
            for (i=0;i<tam;i++) {
                for (j=0;j<tam;j++) {
                    if (a[i][j]!=b[i][j]) return 0;
                }
            }
        return 1;               
    }

    void gerarallcarta(struct players b[],int a){
        int i,j;
            for(i=0;i<a;i++){
                    for(j=0;j<b[i].ncarta;j++){
                        b[i].carta[j]=gerarcarta();
                            while(j!=0 && compcart(5,b[i].carta[j].bingo,b[i].carta[j-1].bingo)!=0){ // verificando se as cartelas são iguais
                            b[i].carta[j]=gerarcarta();
                            }
                    }
                }
    }
    
    void removewinner(struct players player[],struct players winners[],int j,int *count){
        winners[*count]=player[j];
        player[j].out=2; 
        (*count)++;
        printf(ANSI_COLOR_GREEN"\n\n Parabens voce bingou!!!\n"ANSI_COLOR_RESET); 
    }

    void removeloser(struct players player[],struct players winners[],int j,int *count2,int nplayer){
        winners[nplayer-1-*count2]=player[j];
        player[j].out=1;
        (*count2)++;
        printf(ANSI_COLOR_RED"\n\n Voce perdeu!!!\n"ANSI_COLOR_RESET); 
    }

    int checkallplayers(struct players player[],int nplayer,int *lastplayer){
        int j,k=0;
            for(j=0;j<nplayer;j++){
               if(player[j].out!=0){
                    k++; 
               }
               if(player[j].out==0){
                    *lastplayer=j;
               }             
            }
        return k;     //RETORNA o numero de jogadores que ja sairam do jogo
    }

    void getplayerdata(struct players b[],int a){
        int i;
            for(i=0;i<a;i++){
                b[i].out=0;
                printf("Digite o nome jogador(a) %i:",i+1);
                clearget();
                fgets(b[i].name,50,stdin);
                delenter(b[i].name);
                printf("Digite o sexo: ");
                clearget();
                fgets(b[i].sex,20,stdin);
                delenter(b[i].sex);
                printf("Digite a idade: ");
                scanf("%d",&b[i].age); 
                printf("Digite o numero de cartelas que ira usar: ");
                scanf("%d",&b[i].ncarta);
                    if(b[i].ncarta<1 || b[i].ncarta>4){
                        do{
                            printf("\nO numero de cartelas permitidas e de no minimo 1 e maximo 4. Tente novamente.\n");
                            printf("\nDigite o numero de cartelas que ira usar: ");
                            scanf("%d",&b[i].ncarta);
                        } while(b[i].ncarta<1 || b[i].ncarta>4);
                    }
                clearter();
            }
    }