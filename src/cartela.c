#include "../lib/cartela.h"
 
    cartelas gerarcarta(){
        int i,k,aux;
        cartelas c;
        c.out=0;
            for(i=0;i<5;i++){ //preencher linha
                for(k=0;k<5;k++){ //preencher coluna
                    if(i==0){
                        c.bingo[i][k]=1+rand()%15; //15 sendo o intervalo entre os numeros que devem ser gerados
                            while(k!=0 && c.bingo[i][k]==c.bingo[i][k-1] || c.bingo[i][k]==c.bingo[i][k-2] || c.bingo[i][k]==c.bingo[i][k-3] || c.bingo[i][k]==c.bingo[i][k-4]){ // fazendo a verificação se os numeros gerados vao ser repitidos
                                c.bingo[i][k]=1+rand()%15;
                            }
                    } else if(i==1){
                        c.bingo[i][k]=16+rand()%15;
                            while(k!=0 && c.bingo[i][k]==c.bingo[i][k-1] || c.bingo[i][k]==c.bingo[i][k-2] || c.bingo[i][k]==c.bingo[i][k-3] || c.bingo[i][k]==c.bingo[i][k-4]){ // fazendo a verificação se os numeros gerados vao ser repitidos
                                c.bingo[i][k]=16+rand()%15;
                            }
                    } else if(i==2){
                        c.bingo[i][k]=31+rand()%15;
                            while(k!=0 && c.bingo[i][k]==c.bingo[i][k-1] || c.bingo[i][k]==c.bingo[i][k-2] || c.bingo[i][k]==c.bingo[i][k-3] || c.bingo[i][k]==c.bingo[i][k-4]){ // fazendo a verificação se os numeros gerados vao ser repitidos
                                c.bingo[i][k]=31+rand()%15;
                            }
                    } else if(i==3){
                        c.bingo[i][k]=46+rand()%15;
                            while(k!=0 && c.bingo[i][k]==c.bingo[i][k-1] || c.bingo[i][k]==c.bingo[i][k-2] || c.bingo[i][k]==c.bingo[i][k-3] || c.bingo[i][k]==c.bingo[i][k-4]){ // fazendo a verificação se os numeros gerados vao ser repitidos
                                c.bingo[i][k]=46+rand()%15;
                            }
                    } else if(i==4){
                        c.bingo[i][k]=61+rand()%15;
                            while(k!=0 && c.bingo[i][k]==c.bingo[i][k-1] || c.bingo[i][k]==c.bingo[i][k-2] || c.bingo[i][k]==c.bingo[i][k-3] || c.bingo[i][k]==c.bingo[i][k-4]){ // fazendo a verificação se os numeros gerados vao ser repitidos
                                c.bingo[i][k]=61+rand()%15;
                            }
                    }
                }
            }
            
            for(i=0;i<5;i++){ //ordenando os numeros em ordem crescente
                for(k=0;k<5;k++){
                    for(int j=k+1;j<5;j++){
                        if(c.bingo[i][k]>c.bingo[i][j]){
                            aux = c.bingo[i][k];
                            c.bingo[i][k] = c.bingo[i][j];
                            c.bingo[i][j] = aux;
                        }
                    }   
                }
            }
        return c;    
    }

    void printcarta(struct cartelas c,int *auxrock,int d){
        int i,j;
            printf("\nB= ");
                for(i=0;i<5;i++){
                    if(comprock(c,auxrock,0,d,i)==0){
                        printf(ANSI_COLOR_RED"\t%d"ANSI_COLOR_RESET,c.bingo[0][i]);
                    } else if(comprock(c,auxrock,0,d,i)==1){
                        printf("\t%d",c.bingo[0][i]);
                    }                    
                }    
            printf("\nI= ");
                for(i=0;i<5;i++){
                    if(comprock(c,auxrock,1,d,i)==0){
                        printf(ANSI_COLOR_RED"\t%d"ANSI_COLOR_RESET,c.bingo[1][i]);
                    } else if(comprock(c,auxrock,1,d,i)==1){
                        printf("\t%d",c.bingo[1][i]);
                    } 
                }    
            printf("\nN= ");
                for(j=0;j<4;j++){                
                        if(j==2){
                            if(comprock(c,auxrock,2,d,j)==0){
                                printf(ANSI_COLOR_RED"\t\t%d"ANSI_COLOR_RESET,c.bingo[2][j]);
                            } else if(comprock(c,auxrock,2,d,j)==1){
                                printf("\t\t%d",c.bingo[2][j]);
                            } 
                        } else{
                            if(comprock(c,auxrock,2,d,j)==0){
                                printf(ANSI_COLOR_RED"\t%d"ANSI_COLOR_RESET,c.bingo[2][j]);
                            } else if(comprock(c,auxrock,2,d,j)==1){
                                printf("\t%d",c.bingo[2][j]);
                            } 
                        }
                }
            printf("\nG= ");
                for(i=0;i<5;i++){
                    if(comprock(c,auxrock,3,d,i)==0){
                        printf(ANSI_COLOR_RED"\t%d"ANSI_COLOR_RESET,c.bingo[3][i]);
                    } else if(comprock(c,auxrock,3,d,i)==1){
                        printf("\t%d",c.bingo[3][i]);
                    } 
                }
            printf("\nO= ");
                for(i=0;i<5;i++){    
                    if(comprock(c,auxrock,4,d,i)==0){
                        printf(ANSI_COLOR_RED"\t%d"ANSI_COLOR_RESET,c.bingo[4][i]);
                    } else if(comprock(c,auxrock,4,d,i)==1){
                        printf("\t%d",c.bingo[4][i]);
                    }        
                }  
            printf("\n");   
    }

    int checkallcartas(struct players player[],int j){
        int k=0,l;
            for(l=0;l<player[j].ncarta;l++){
               if(player[j].carta[l].out==0){
                    k++; 
               }          
            }
        return k;
    }
    
    void printallcarta(struct players a[],int b,int *auxrock,int d){
        int i,j;
        for(i=0;i<b;i++){
            if(a[i].out!=0); //removendo jogador que bingou
            else{
                printf("\n-------------------------------------------");
                    printf("\nJogador(a) %i",i+1);
                    printf("\n-------------------------------------------");
                        for(j=0;j<a[i].ncarta;j++){
                            if(a[i].carta[j].out!=0); //cartela que nao bingou
                            else{
                            printf("\nCartela %i",j+1);
                            printf("\n-------------------------------------------");
                            printcarta(a[i].carta[j],auxrock,d);  
                            }
                        }
            }
        }  
    }