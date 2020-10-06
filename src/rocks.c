#include "../lib/rocks.h"

    int comprock(struct cartelas c,int *auxrock,int k,int i,int x){
            int j;
                    for(j=1;j<i+1;j++){
                        if(c.bingo[k][x]==auxrock[j]) return 0;
                    }
        return 1;    
        }

    void printrock(int i,int *aux){
        int k;
            for(k=1;k<i+1;k++){
                printf(ANSI_COLOR_GREEN " %d " ANSI_COLOR_RESET,aux[k]);
            }
    }    

    void generaterocks(int *a){
        int i;
            for(i=1;i<76;i++){ //gerando as pedras sorteadas
                a[i]=0;
            } 
    }        