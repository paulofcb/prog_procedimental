#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


void menu (void);

struct carta{
    char nome[15];
    int ataque;
};

int menu_mesa (int carta1, int carta2, int carta3, int carta4, int opcaox);

void jogar (void);
void ranking (void);
void sobre (void);
void sair (void);


int main (){
    

    
    menu();

    

    return 0;
}

void menu (void){
    int opcao = 0;

    for (;opcao < 1 || opcao > 4; ){
        printf ("menu  -  escolha uma opcao para prosseguir\n");
        printf ("jogar ----- 1\n");
        printf ("rankin ---- 2\n");
        printf ("sobre ----- 3\n");
        printf ("sair ------ 4\n");
        scanf ("%d", &opcao);
        switch (opcao){
            case 1:
                jogar();
            break;
            case 2:
                ranking();
            break;
            case 3:
                sobre();
            break;
            case 4:
                sair();
            break;
            default :
                printf ("digite um opcao valida\n");
                menu();
            break;
        }
    }
}

void jogar (void){
    
    struct carta baralho[40];
    struct carta mao1[3];
    struct carta mao2[3];
    struct carta carta_maquina;

    int i, j, k, l, m, n, p = 0;

    int tento1, tento2, rodada1, rodada2, rodada3, vencedor1, vencedor2, vencedor3, rod1_carta, rod2_carta;

    char rod1_carta_maquina[15], rod2_carta_maquina[15];

    int opcao, opcao_termino;

    int quem_joga_primeiro;

    strcpy(baralho[0].nome, "3 de paus"); baralho[0].ataque = 0;
    strcpy(baralho[1].nome, "2 de paus"); baralho[1].ataque = 1;
    strcpy(baralho[2].nome, "A de paus"); baralho[2].ataque = 2;
    strcpy(baralho[3].nome, "K de paus"); baralho[3].ataque = 3;
    strcpy(baralho[4].nome, "J de paus"); baralho[4].ataque = 4;
    strcpy(baralho[5].nome, "Q de paus"); baralho[5].ataque = 5;
    strcpy(baralho[6].nome, "7 de paus"); baralho[6].ataque = 6;
    strcpy(baralho[7].nome, "6 de paus"); baralho[7].ataque = 7;
    strcpy(baralho[8].nome, "5 de paus"); baralho[8].ataque = 8;
    strcpy(baralho[9].nome, "4 de paus (manilha)"); baralho[9].ataque = 13;
    strcpy(baralho[10].nome, "3 de copas"); baralho[10].ataque = 0;
    strcpy(baralho[11].nome, "2 de copas"); baralho[11].ataque = 1;
    strcpy(baralho[12].nome, "A de copas"); baralho[12].ataque = 2;
    strcpy(baralho[13].nome, "K de copas"); baralho[13].ataque = 3;
    strcpy(baralho[14].nome, "J de copas"); baralho[14].ataque = 4;
    strcpy(baralho[15].nome, "Q de copas"); baralho[15].ataque = 5;
    strcpy(baralho[16].nome, "7 de copas (manilha)"); baralho[16].ataque = 12;
    strcpy(baralho[17].nome, "6 de copas"); baralho[17].ataque = 7;
    strcpy(baralho[18].nome, "5 de copas"); baralho[18].ataque = 8;
    strcpy(baralho[19].nome, "4 de copas"); baralho[19].ataque = 9;
    strcpy(baralho[20].nome, "3 de espadas"); baralho[20].ataque = 0;
    strcpy(baralho[21].nome, "2 de espadas"); baralho[21].ataque = 1;
    strcpy(baralho[22].nome, "A de espadas (manilha)"); baralho[22].ataque = 11;
    strcpy(baralho[23].nome, "K de espadas"); baralho[23].ataque = 3;
    strcpy(baralho[24].nome, "J de espadas"); baralho[24].ataque = 4;
    strcpy(baralho[25].nome, "Q de espadas"); baralho[25].ataque = 5;
    strcpy(baralho[26].nome, "7 de espadas"); baralho[26].ataque = 6;
    strcpy(baralho[27].nome, "6 de espadas"); baralho[27].ataque = 7;
    strcpy(baralho[28].nome, "5 de espadas"); baralho[28].ataque = 8;
    strcpy(baralho[29].nome, "4 de espadas"); baralho[29].ataque = 9;
    strcpy(baralho[30].nome, "3 de ouros"); baralho[30].ataque = 0;
    strcpy(baralho[31].nome, "2 de ouros"); baralho[31].ataque = 1;
    strcpy(baralho[32].nome, "A de ouros"); baralho[32].ataque = 2;
    strcpy(baralho[33].nome, "K de ouros"); baralho[33].ataque = 3;
    strcpy(baralho[34].nome, "J de ouros"); baralho[34].ataque = 4;
    strcpy(baralho[35].nome, "Q de ouros"); baralho[35].ataque = 5;
    strcpy(baralho[36].nome, "7 de ouros (manilha)"); baralho[36].ataque = 10;
    strcpy(baralho[37].nome, "6 de ouros"); baralho[37].ataque = 7;
    strcpy(baralho[38].nome, "5 de ouros"); baralho[38].ataque = 8;
    strcpy(baralho[39].nome, "4 de ouros"); baralho[39].ataque = 9;

    for(tento1 = 0, tento2 = 0; tento1 < 12 && tento2 < 12; ){
        
        srand (time(NULL));
        for (j = 0; j < 3; j++){
            mao2[j] = baralho[rand() % 39];
            mao1[j] = baralho[rand() % 39];            
        }
        
        rodada1 = 3;
        rodada2 = 3;
        rodada3 = 3;

        if (p == 0){
            quem_joga_primeiro = 0;
            p++;
        }else{
            quem_joga_primeiro = 1;
            p--;
        }

        for(i = 0; i < 3; i++){

            if (rodada1 == 3){    
                vencedor1 = '-';
            }else{
                if (rodada1 == 1){ 
                    vencedor1 = 'H';
                }else{
                    if (rodada1 == 2){
                        vencedor1 = 'M';
                    }else{
                        vencedor1 = 'E';
                    }
                }
            }
            if (rodada2 == 3){    
                vencedor2 = '-';
            }else{
                if (rodada2 == 1){ 
                    vencedor2 = 'H';
                }else{
                    if (rodada2 == 2){
                        vencedor2 = 'M';
                    }else{
                        vencedor2 = 'E';
                    }
                }
            }
            if (rodada3 == 3){    
                vencedor3 = '-';
            }else{
                if (rodada3 == 1){ 
                    vencedor3 = 'H';
                }else{
                    if (rodada3 == 2){
                        vencedor3 = 'M';
                    }else{
                        vencedor3 = 'E';
                    }
                }
            }

            printf ("tentos: jogador-%d  maquina-%d \n", tento1, tento2);
    
            printf ("vancedor das rodadas: 1-%c   2-%c   3-%c \n", vencedor1, vencedor2, vencedor3);
            printf ("valor da mao atual: \n");

            printf ("qual carta jogar? \n");
            for (k = 0; k < 3; k++){
                printf ("carta %d: %s\n", k + 1, mao1[k].nome);
            }

            printf ("trucar? \n");

            if (quem_joga_primeiro == 1){             
                if (i == 0){
                    for(l = 0; l < 3; l++){
                        if (l == 0){
                            carta_maquina = mao2[l];
                            strcpy (rod1_carta_maquina, mao2[l].nome);
                        }else{
                            if (carta_maquina.ataque < mao2[l].ataque){
                                carta_maquina = mao2[l];
                                strcpy (rod1_carta_maquina, mao2[l].nome);
                            }
                        }
                    }
                    printf ("carta jogada pela maquina: %s\n", carta_maquina.nome);
                }else{
                    if (i == 1){
                        for(l = 0; l < 3; l++){
                            if (l == 0){
                                for(n = 0; ; n++){
                                    if (strcmp (mao2[n].nome, rod1_carta_maquina)){
                                        carta_maquina = mao2[n];
                                        strcpy (rod2_carta_maquina, mao2[l].nome);
                                        break;
                                    }    
                                }
                            }else{
                                if (carta_maquina.ataque < mao2[l].ataque && strcmp (mao2[l].nome, rod1_carta_maquina)){
                                    carta_maquina = mao2[l];
                                    strcpy (rod2_carta_maquina, mao2[l].nome);
                                }
                            }
                        }
                        printf ("carta jogada pela maquina: %s\n", carta_maquina.nome);
                    }else{
                        for(l = 0; ; l++){
                            if (strcmp (mao2[l].nome, rod1_carta_maquina) && strcmp (mao2[l].nome, rod2_carta_maquina)){
                                carta_maquina = mao2[l];
                                break;
                            }    
                        }
                        printf ("carta jogada pela maquina: %s\n", carta_maquina.nome);                        
                    }
                }    
            }

            if (i == 0){
                scanf ("%d", &opcao);
                for (;opcao < 1 || opcao > 4; ){
                    printf ("digite um valor valido:\n");
                    scanf ("%d", &opcao);
                }
                rod1_carta = opcao;
            }else{
                if (i == 1){
                    scanf ("%d", &opcao);
                    for (;opcao < 1 || opcao > 4 || opcao == rod1_carta; ){
                        printf ("digite um valor valido:\n");
                        scanf ("%d", &opcao);
                    }
                    rod2_carta = opcao;
                }else{
                    scanf ("%d", &opcao);
                    for (;opcao < 1 || opcao > 4 || opcao == rod1_carta || opcao == rod2_carta; ){
                        printf ("digite um valor valido:\n");
                        scanf ("%d", &opcao);
                    }
                }
            }                        

            if (i == 2){
                if (quem_joga_primeiro == 0){             
                    for(l = 0; ; l++){
                        if (strcmp (mao2[l].nome, rod1_carta_maquina) && strcmp (mao2[l].nome, rod2_carta_maquina)){
                            carta_maquina = mao2[l];
                            break;
                        }
                    }                                              
                }

                rodada3 = menu_mesa (mao1[0].ataque, mao1[1].ataque, mao1[2].ataque, carta_maquina.ataque, opcao);

                printf ("voce escolheu: %s\n", mao1[opcao - 1].nome);
                printf ("a maquina escolheu: %s\n", carta_maquina.nome);
                if (rodada3 == 1){ 
                    printf ("voce venceu\n");
                }else{
                    if (rodada3 == 2){
                        printf ("a maquina venceu\n");
                    }else{
                        printf ("empatou\n");
                    }
                }

                if (rodada1 == 1 && rodada2 == 2 && rodada3 == 2){
                    tento2++;
                }
                if (rodada1 == 1 && rodada2 == 2 && rodada3 == 1){
                    tento1++;
                }
                if (rodada1 == 2 && rodada2 == 1 && rodada3 == 1){
                    tento1++;
                }
                if (rodada1 == 2 && rodada2 == 1 && rodada3 == 2){
                    tento2++;
                }
                if (rodada1 == 0 && rodada2 == 0 && rodada3 == 2){
                    tento2++;
                }
                if (rodada1 == 0 && rodada2 == 0 && rodada3 == 1){
                    tento1++;
                }
            }

            if (i == 1){
                if (quem_joga_primeiro == 0){                                 
                    for(l = 0; l < 3; l++){
                        if (l == 0){
                            for(n = 0; ; n++){
                                if (strcmp (mao2[n].nome, rod1_carta_maquina)){
                                    carta_maquina = mao2[n]; 
                                    strcpy (rod2_carta_maquina, mao2[n].nome);
                                    break;
                                }    
                            }
                        }else{
                            if (carta_maquina.ataque < mao2[l].ataque && strcmp (mao2[l].nome, rod1_carta_maquina)){
                                carta_maquina = mao2[l];
                                strcpy (rod2_carta_maquina, mao2[l].nome);
                            }
                        }
                    }                        
                }    

                rodada2 = menu_mesa(mao1[0].ataque, mao1[1].ataque, mao1[2].ataque, carta_maquina.ataque, opcao);
                
                printf ("voce escolheu: %s\n", mao1[opcao - 1].nome);
                printf ("a maquina escolheu: %s\n", carta_maquina.nome);
                if (rodada2 == 1){ 
                    printf ("voce venceu\n");
                    quem_joga_primeiro = 0;;
                }else{
                    if (rodada2 == 2){
                        printf ("a maquina venceu\n");
                        quem_joga_primeiro = 1;
                    }else{
                        printf ("empatou\n");
                    }
                }

                if (rodada1 == 1 && rodada2 == 1){
                    i++;
                    tento1++;
                }
                if (rodada1 == 2 && rodada2 == 2){
                    i++;
                    tento2++;
                }
                if (rodada1 == 1 && rodada2 == 0){
                    i++;
                    tento1++;
                }
                if (rodada1 == 2 && rodada2 == 0){
                    i++;
                    tento2++;
                }
                if (rodada1 == 0 && rodada2 == 1){
                    i++;
                    tento1++;
                }
                if (rodada1 == 0 && rodada2 == 2){
                    i++;
                    tento2++;
                }
            }
            if (i == 0){

                if (quem_joga_primeiro == 0){
                    for(l = 0; l < 3; l++){
                        if (l == 0){
                            carta_maquina = mao2[l];
                            strcpy (rod1_carta_maquina, mao2[l].nome);
                        }else{
                            if (carta_maquina.ataque < mao2[l].ataque){
                                carta_maquina = mao2[l];
                                strcpy (rod1_carta_maquina, mao2[l].nome);
                            }
                        }
                    }
                }

                rodada1 = menu_mesa(mao1[0].ataque, mao1[1].ataque, mao1[2].ataque, carta_maquina.ataque, opcao);
                
                printf ("voce escolheu: %s\n", mao1[opcao - 1].nome);
                printf ("a maquina escolheu: %s\n", carta_maquina.nome);
                if (rodada1 == 1){ 
                    printf ("voce venceu\n\n");
                    quem_joga_primeiro = 0;
                }else{
                    if (rodada1 == 2){
                        printf ("a maquina venceu\n\n");
                        quem_joga_primeiro = 1;
                    }else{
                        printf ("empatou\n\n");
                    }
                }            
            }
        }
    }
    for (;!(opcao_termino == 1 || opcao_termino == 2); ){
    printf("1- jogar novamente\n");
    printf("2- ir para o menu\n");
    scanf ("%d", &opcao_termino);
    }
    if (opcao_termino == 1){
        jogar();
    }else{
        menu();
    }
}

void ranking (void){
    
}

void sobre (void){
    
}

void sair (void){
    exit(0);
}

int menu_mesa (int carta1, int carta2, int carta3, int carta4, int opcaox){

    switch (opcaox){
        case 1 :
            if (carta1 > carta4){
                return 1;
            }else{
                if (carta4 > carta1){
                    return 2;
                }else{
                    return 0;
                }
            }
                
        break;
        case 2 :
            if (carta2 > carta4){
                return 1;
            }else{
                if (carta4 > carta2){
                    return 2;
                }else{
                    return 0;
                }
            }
        break;
        case 3 :
            if (carta3 > carta4){
                return 1;
            }else{
                if (carta4 > carta3){
                    return 2;
                }else{
                    return 0;
                }
            }
        break;
        case 4 :
                //trucar
        break;
    }
}
