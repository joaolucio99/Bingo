#include "../lib/tools.h"

    int checkcolbingo(struct players player[],int j,int ncartabingo,int opccollin,int *auxrock,int i){
        int l,m=0;
            for(l=0;l<5;l++){
                for(int k=1;k<i+1;k++){
                    if(opccollin-1>2 && l==2){
                        if(player[j].carta[ncartabingo-1].bingo[l][opccollin-2]==auxrock[k]) m++;
                    } else{
                        if(player[j].carta[ncartabingo-1].bingo[l][opccollin-1]==auxrock[k]) m++;
                    }
                }  
            }
        return m;    
    }

    int checklinbingo(struct players player[],int j,int ncartabingo,int opccollin,int *auxrock,int i){
        int l,m=0;
            for(l=0;l<5;l++){
                for(int k=1;k<i+1;k++){
                    if(opccollin-1==2 && l==2){
                        if(player[j].carta[ncartabingo-1].bingo[opccollin-2][l]==auxrock[k]) m++;
                    } else{
                        if(player[j].carta[ncartabingo-1].bingo[opccollin-1][l]==auxrock[k]) m++;
                    }
                }  
            }
        return m;    
    }

    void checkbingo(struct players player[],struct players winners[],int opccollin,int teste,int nplayer,int ncartabingo,int j,int *count,int *count2){
        if(opccollin-1!=2){ //bingou
            if(teste==5) {
                removewinner(player,winners,j,count);                                                   
            } else{ //nao bingou
                if(player[j].ncarta!=1){ //removendo carta
                    player[j].carta[ncartabingo-1].out=1;
                } else {  
                    removeloser(player,winners,j,count2,nplayer);                                          
                }
            }
            } else if(opccollin-1==2){ //bingou
                if(teste>3) {
                    removewinner(player,winners,j,count);                                                       
                } else{ //nao bingou
                    if(player[j].ncarta!=1){ //removendo carta
                        player[j].carta[ncartabingo-1].out=1;
                    } else { 
                        removeloser(player,winners,j,count2,nplayer);  
                    }
                }
            }
    }

    void clearter(){ 
        system ("cls"); //windows
        system ("clear"); //linux
    }

    void delenter(char a[]){ 
        int b=strlen(a);
        a[b-1]='\0';
    }

    void clearget(){ 
        setbuf(stdin,NULL);
    }

    void printwinners(struct players winners[],int nplayer){
        printf("\n\n");
            for(int y=0;y<nplayer;y++){
                printf("\t  %iº Posição - %s - %i anos - %s\n\n",y+1,winners[y].name,winners[y].age,winners[y].sex);
            }
        printf("\n\n");
    }

    void erroroption(int *opc,int a,int b){
        do{
            scanf("%i",&(*opc));
                if(*opc<a || *opc>b){
                    printf("\n\nOpcao invalida tente novamente: ");
                }
            } while(*opc<a || *opc>b);
    }

    void gerardes(){ 
        printf(ANSI_COLOR_GREEN"\n\n    ██████╗ ██╗███╗   ██╗ ██████╗  ██████╗ \n"ANSI_COLOR_RESET); 
        printf(ANSI_COLOR_GREEN"    ██╔══██╗██║████╗  ██║██╔════╝ ██╔═══██╗\n"ANSI_COLOR_RESET);
        printf(ANSI_COLOR_GREEN"    ██████╔╝██║██╔██╗ ██║██║  ███╗██║   ██║\n"ANSI_COLOR_RESET);
        printf(ANSI_COLOR_GREEN"    ██╔══██╗██║██║╚██╗██║██║   ██║██║   ██║\n"ANSI_COLOR_RESET);
        printf(ANSI_COLOR_GREEN"    ██████╔╝██║██║ ╚████║╚██████╔╝╚██████╔╝\n"ANSI_COLOR_RESET);
        printf(ANSI_COLOR_GREEN"    ╚═════╝ ╚═╝╚═╝  ╚═══╝ ╚═════╝  ╚═════╝ \n"ANSI_COLOR_RESET);
    }

    void gerardes2(){
        printf(ANSI_COLOR_GREEN"\n\n██████   █████  ███    ██ ██   ██ ██ ███    ██  ██████  \n"ANSI_COLOR_RESET);
        printf(ANSI_COLOR_GREEN"██   ██ ██   ██ ████   ██ ██  ██  ██ ████   ██ ██       \n"ANSI_COLOR_RESET);
        printf(ANSI_COLOR_GREEN"██████  ███████ ██ ██  ██ █████   ██ ██ ██  ██ ██   ███ \n"ANSI_COLOR_RESET);
        printf(ANSI_COLOR_GREEN"██   ██ ██   ██ ██  ██ ██ ██  ██  ██ ██  ██ ██ ██    ██ \n"ANSI_COLOR_RESET);
        printf(ANSI_COLOR_GREEN"██   ██ ██   ██ ██   ████ ██   ██ ██ ██   ████  ██████  \n"ANSI_COLOR_RESET);
    }