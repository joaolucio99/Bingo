#ifndef STRUCTS
#define STRUCTS

    typedef struct cartelas{
        int bingo[5][5],out;
    }cartelas;

    typedef struct players{
        int age,ncarta,out;
        char name[50],sex[20];
        cartelas carta[4];
    }players;  

#endif    