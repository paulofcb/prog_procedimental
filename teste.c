#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


void menu (void);               //struct que define o tipo carta, com um nome e um ataque para cada carta

struct carta{
    char nome[25];
    int ataque;
};

int comparar_cartas (int carta1, int carta2, int carta3, int carta4, int opcaox);               //recebe que opcao o jogador escolheu e retorna o vencedor da jogada ou truca o jogo

void jogar (void);              //funcoes que compoem o menu inicial do truco

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
    
    struct carta baralho[40];               //vetor que armazena o baralho de cartas

    struct carta mao1[3];               //vetor que armazena as cartas que o jogador tem na mao

    struct carta mao2[3];               //vetor que armazena as cartas que a maquina tem na mao

    struct carta carta_maquina;             //variavel que armazena a carta que a maquina escolhe naquela determinada rodada

    int i, j, k, l, n, o = 0;                //variaveis usadas em loops

    int tento1, tento2;             //variaveis que armazenam os tentos do jogador, tento1, e da maquina, tento2

    int rodada1, rodada2, rodada3;              //variaveis que armazenam os vencedores de cada rodada para a decisao de quem ganha os pontos

    int vencedor1, vencedor2, vencedor3;                //variaveis que armazenam os vencedores de cada rodada para mostrar o resultado ao jogador

    int rod1_carta, rod2_carta;             //variaveis que armazenam as cartas jogadas pelo jogador para evitar repetiçao

    char rod1_carta_maquina[25], rod2_carta_maquina[25];                //variaveis que armazenam as cartas jogadas pela mquina para evitar repetiçao

    int opcao, opcao_termino;               //variaveis que armazenam a opcao escolhida pelo jogador nos menus

    int quem_joga_primeiro;             //variavel que define quem deve dar a primeira carta em cada rodada

    int valor_rodada;               //variavel que define o valor de cada rodada, alterada pelo truco

    FILE *p;

    char *q;

    char ranking_s[200];

    char eof_teste[50];

    char nome_player[50];

    strcpy(baralho[0].nome, "3 de paus"); baralho[0].ataque = 9;                //definindo o vetor de cartas, este sera o baralho utilizado, ele é estatico e cada carta tem um nome e um ataque
    strcpy(baralho[1].nome, "2 de paus"); baralho[1].ataque = 8;                //o nome eh usado para comparar duas cartas e o ataque para definir quem tem maior poder
    strcpy(baralho[2].nome, "A de paus"); baralho[2].ataque = 7;
    strcpy(baralho[3].nome, "K de paus"); baralho[3].ataque = 6;
    strcpy(baralho[4].nome, "J de paus"); baralho[4].ataque = 5;
    strcpy(baralho[5].nome, "Q de paus"); baralho[5].ataque = 4;
    strcpy(baralho[6].nome, "7 de paus"); baralho[6].ataque = 3;
    strcpy(baralho[7].nome, "6 de paus"); baralho[7].ataque = 2;
    strcpy(baralho[8].nome, "5 de paus"); baralho[8].ataque = 1;
    strcpy(baralho[9].nome, "4 de paus (manilha)"); baralho[9].ataque = 13;
    strcpy(baralho[10].nome, "3 de copas"); baralho[10].ataque = 9;
    strcpy(baralho[11].nome, "2 de copas"); baralho[11].ataque = 8;
    strcpy(baralho[12].nome, "A de copas"); baralho[12].ataque = 7;
    strcpy(baralho[13].nome, "K de copas"); baralho[13].ataque = 6;
    strcpy(baralho[14].nome, "J de copas"); baralho[14].ataque = 5;
    strcpy(baralho[15].nome, "Q de copas"); baralho[15].ataque = 4;
    strcpy(baralho[16].nome, "7 de copas (manilha)"); baralho[16].ataque = 12;
    strcpy(baralho[17].nome, "6 de copas"); baralho[17].ataque = 2;
    strcpy(baralho[18].nome, "5 de copas"); baralho[18].ataque = 1;
    strcpy(baralho[19].nome, "4 de copas"); baralho[19].ataque = 0;
    strcpy(baralho[20].nome, "3 de espadas"); baralho[20].ataque = 9;
    strcpy(baralho[21].nome, "2 de espadas"); baralho[21].ataque = 8;
    strcpy(baralho[22].nome, "A de espadas (manilha)"); baralho[22].ataque = 11;
    strcpy(baralho[23].nome, "K de espadas"); baralho[23].ataque = 6;
    strcpy(baralho[24].nome, "J de espadas"); baralho[24].ataque = 5;
    strcpy(baralho[25].nome, "Q de espadas"); baralho[25].ataque = 4;
    strcpy(baralho[26].nome, "7 de espadas"); baralho[26].ataque = 3;
    strcpy(baralho[27].nome, "6 de espadas"); baralho[27].ataque = 2;
    strcpy(baralho[28].nome, "5 de espadas"); baralho[28].ataque = 1;
    strcpy(baralho[29].nome, "4 de espadas"); baralho[29].ataque = 0;
    strcpy(baralho[30].nome, "3 de ouros"); baralho[30].ataque = 9;
    strcpy(baralho[31].nome, "2 de ouros"); baralho[31].ataque = 8;
    strcpy(baralho[32].nome, "A de ouros"); baralho[32].ataque = 7;
    strcpy(baralho[33].nome, "K de ouros"); baralho[33].ataque = 6;
    strcpy(baralho[34].nome, "J de ouros"); baralho[34].ataque = 5;
    strcpy(baralho[35].nome, "Q de ouros"); baralho[35].ataque = 4;
    strcpy(baralho[36].nome, "7 de ouros (manilha)"); baralho[36].ataque = 10;
    strcpy(baralho[37].nome, "6 de ouros"); baralho[37].ataque = 2;
    strcpy(baralho[38].nome, "5 de ouros"); baralho[38].ataque = 1;
    strcpy(baralho[39].nome, "4 de ouros"); baralho[39].ataque = 0;

    fflush (stdin);
    printf ("digite o seu nome: \n");
    fgets (nome_player, 50, stdin);
    nome_player[strlen(nome_player) - 1] = '\0';
    p = fopen ("ranking.txt", "r");
    if (p != NULL){
        for ( ; !feof(p); ){
            if (fgets (eof_teste, 50, p)){
                strcat (ranking_s, eof_teste);
            }
        }
    }else{
        ranking_s[0] = '\0';
    }
    fclose (p);

    for (tento1 = 0, tento2 = 0; tento1 < 12 && tento2 < 12; ){             //for em que o jogo de truco acontece, a cada vez que um ciclo eh completo o valor dos tentos dos jogadores eh aumentado
        
            for (j = 0; j < 3; ){               //for que distribue as cartas para a maquina e o jogador, nao deixa que a mesma carta seja distribuida mais de uma vez
                srand (time(NULL));
                mao1[j] = baralho[rand() % 39];
                mao2[j] = baralho[rand() % 39];
                if (j == 0){
                    if (strcmp (mao1[j].nome, mao2[j].nome)){
                        j++;
                    }
                }else{
                    if (j == 1){
                        if (strcmp (mao1[j].nome, mao1[j - 1].nome) && strcmp (mao1[j].nome, mao2[j].nome) && strcmp (mao1[j].nome, mao2[j - 1].nome)){
                            if (strcmp (mao2[j].nome, mao2[j - 1].nome) || strcmp (mao2[j].nome, mao1[j - 1].nome)){
                                j++;
                            }
                        }                                                                                                               
                    }else{
                        if (strcmp (mao1[j].nome, mao1[j - 1].nome) && strcmp (mao1[j].nome, mao1[j - 2].nome) && strcmp (mao1[j].nome, mao2[j - 2].nome)){
                            if (strcmp (mao2[j].nome, mao2[j - 1].nome) && strcmp (mao2[j].nome, mao2[j - 2].nome) && strcmp (mao2[j].nome, mao1[j - 2].nome)){
                                if (strcmp (mao2[j].nome, mao1[j - 1].nome) && strcmp (mao1[j].nome, mao2[j - 1].nome) && strcmp (mao2[j].nome, mao1[j].nome)){
                                    j++;
                                }
                            }
                        }        
                    }
                }           
            }
        
        rodada1 = 3;                //a cada vez que uma rodada comeca as variaveis rodada1, rodada2, rodada3 e valor_rodada devem
        rodada2 = 3;                //ter seu valor resetado para mostrar ao jogador que uma nova rodada foi iniciada e valor da rodada ser redefinido
        rodada3 = 3;                
        valor_rodada = 1;

        if (p == 0){                //if para definir que vai dar a primeira carta, de forma alternanda, dependendo do valor da variavel quem_joga_primeiro
            quem_joga_primeiro = 0;
            o++;
        }else{
            quem_joga_primeiro = 1;
            o--;
        }

        for(i = 0; i < 3; i++){             //for em que as rodadas acontecem, a cada execuçao ocorre uma comparacao entrre as cartas jogadas pela maquina e pelo jogador
                                            
            if (rodada1 == 3){              //if para modifica o valor das variaveis vencedor1, vencedor2 e vencedor3 de acordo com o resultado de cada jogada
                vencedor1 = '-';            //de forma a mostrar '-' para uma rodada que ainda nao aconteceu, 'h' o jogador venceu, 'm' a maquina venceu e 'e' empate
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
                                                                                                            //sequencia de prints que compoe o menu pelo qual o jogador se oriente durante as rodadas
            printf ("tentos: jogador-%d  maquina-%d \n", tento1, tento2);                                       //mostra os tentos do jogador e da maquina
            printf ("vencedor das rodadas: 1-%c   2-%c   3-%c \n", vencedor1, vencedor2, vencedor3);                //mostra o resultado de cada jogada, empate, vitoria do jogador, vitoria da maquina ou a rodada ainda nao aconteceu
            printf ("qual carta jogar? \n");                                                                    
            for (k = 0; k < 3; k++){                                                                            //for mostra as cartas da mao do jogador
                printf ("opcao %d: jogar carta - %s\n", k + 1, mao1[k].nome);
            }
            printf ("opcao 4: trucar\n");

            if (quem_joga_primeiro == 1){             //if que, caso a maquina deva dar a primeira carta na rodada, escolhe a carta da maquina e mostra ao jogador antes que ela escolha qual carya deve jogar
                if (i == 0){
                    for(l = 0; l < 3; l++){
                        if (l == 0){                                                  //caso seja a primeira rodada, semepre escolhe-se a carta mais forte da mao que ainda nao foi jogada
                            carta_maquina = mao2[l];                                  //primeiro se escolhe a primeira carta da mao e depois a compara com as outras para verificar se ja foi jogada ou se eh a mais forte delas
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
                                if (carta_maquina.ataque > mao2[l].ataque && strcmp (mao2[l].nome, rod1_carta_maquina)){
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

            if (i == 0){                                        //if que coleta qual opcao o jogaodr escolheu entre trucar, jogar a carta 1, 2 ou 3
                scanf ("%d", &opcao);                           //alem de verificar se a carta ja foi jogada 
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

            if (i == 2){                                    //if define o que deve ser feito caso o jogo esteja na rodada 3
                if (quem_joga_primeiro == 0){             //if escolhe a carta que a maquina ira jogar 
                    for(l = 0; ; l++){
                        if (strcmp (mao2[l].nome, rod1_carta_maquina) && strcmp (mao2[l].nome, rod2_carta_maquina)){
                            carta_maquina = mao2[l];
                            break;
                        }
                    }                                              
                }

                rodada3 = comparar_cartas (mao1[0].ataque, mao1[1].ataque, mao1[2].ataque, carta_maquina.ataque, opcao);                //rodada3 recebe um valor diferente da funao comparar_cartas de acordo com cada situaçao:
                                                                                                                                        //o jagador vece a rodada, a maquina vence a rodada, o jogador pede truco
                if (rodada3 == 4){              //if define o que acontece se o jogador pede truco
                    valor_rodada = 3;               //alterando valor da rodada por causa do truco
                    scanf ("%d", &opcao);
                    for (;opcao < 1 || opcao > 3 || opcao == rod1_carta || opcao == rod2_carta; ){              //lendo a decisao que o jogador vai tomar depois de trucar
                        printf ("digite um valor valido:\n");
                        scanf ("%d", &opcao);
                    }
                    rodada3 = comparar_cartas (mao1[0].ataque, mao1[1].ataque, mao1[2].ataque, carta_maquina.ataque, opcao);
                }

                printf ("voce escolheu: %s\n", mao1[opcao - 1].nome);               //mostrando o resultado da rodada
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

                if (rodada1 == 1 && rodada2 == 2 && rodada3 == 2){              //modificando os tentos do jogador e da maquina dependendo de quem ganhou cada rodada
                    tento2 += valor_rodada;
                }else{
                    if (rodada1 == 1 && rodada2 == 2 && rodada3 == 1){
                        tento1 += valor_rodada;
                    }else{
                        if (rodada1 == 2 && rodada2 == 1 && rodada3 == 1){
                            tento1 += valor_rodada;
                        }else{
                            if (rodada1 == 2 && rodada2 == 1 && rodada3 == 2){
                                tento2 += valor_rodada;
                            }else{
                                if (rodada1 == 1 && rodada2 == 2 && rodada3 == 0){
                                    tento1 += valor_rodada;
                                }else{
                                    if (rodada1 == 2 && rodada2 == 1 && rodada3 == 0){
                                        tento2 += valor_rodada;
                                    }else{
                                        if (rodada1 == 0 && rodada2 == 0 && rodada3 == 2){
                                            tento2 += valor_rodada;
                                        }else{
                                            if (rodada1 == 0 && rodada2 == 0 && rodada3 == 1){
                                                tento1 += valor_rodada;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }                            
            }

            if (i == 1){                //if define o que deve ser feito caso o jogo esteja na rodada 2
                if (quem_joga_primeiro == 0){               //if escolhe a carta que a maquina ira jogar
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
                            if (carta_maquina.ataque > mao2[l].ataque && strcmp (mao2[l].nome, rod1_carta_maquina) && carta_maquina.ataque > mao1[opcao - 1].ataque){
                                carta_maquina = mao2[l];
                                strcpy (rod2_carta_maquina, mao2[l].nome);
                            }
                        }
                    }                        
                }    

                rodada2 = comparar_cartas(mao1[0].ataque, mao1[1].ataque, mao1[2].ataque, carta_maquina.ataque, opcao);                 //rodada2 recebe um valor diferente da funao comparar_cartas de acordo com cada situaçao:
                                                                                                                                        //o jagador vece a rodada, a maquina vence a rodada, o jogador pede truco
                if (rodada2 == 4){                       //if define o que acontece se o jogador pede truco
                    valor_rodada = 3;                    //alterando valor da rodada por causa do truco
                    scanf ("%d", &opcao);
                    for (;opcao < 1 || opcao > 3 || opcao == rod1_carta; ){                    //lendo a decisao que o jogador vai tomar depois de trucar
                        printf ("digite um valor valido:\n");
                        scanf ("%d", &opcao);
                    }
                    rod2_carta = opcao;
                    rodada2 = comparar_cartas(mao1[0].ataque, mao1[1].ataque, mao1[2].ataque, carta_maquina.ataque, opcao);
                }
                
                printf ("voce escolheu: %s\n", mao1[opcao - 1].nome);                   //mostrando o resultado da rodada
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

                if (rodada1 == 1 && rodada2 == 1){                  //modificando os tentos do jogador e da maquina dependendo de quem ganhou cada rodada
                    i++;
                    tento1 += valor_rodada;
                }else{
                    if (rodada1 == 2 && rodada2 == 2){
                        i++;
                        tento2 += valor_rodada;
                    }else{
                        if (rodada1 == 1 && rodada2 == 0){
                            i++;
                            tento1 += valor_rodada;
                        }else{
                            if (rodada1 == 2 && rodada2 == 0){
                                i++;
                                tento2 += valor_rodada;
                            }else{
                                if (rodada1 == 0 && rodada2 == 1){
                                    i++;
                                    tento1 += valor_rodada;
                                }else{
                                    if (rodada1 == 0 && rodada2 == 2){
                                        i++;
                                        tento2 += valor_rodada;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (i == 0){                //if define o que deve ser feito caso o jogo esteja na rodada 1

                if (quem_joga_primeiro == 0){               //if escolhe a carta que a maquina ira jogar
                    for(l = 0; l < 3; l++){
                        if (l == 0){
                            carta_maquina = mao2[l];
                            strcpy (rod1_carta_maquina, mao2[l].nome);
                        }else{
                            if (carta_maquina.ataque > mao2[l].ataque && carta_maquina.ataque > mao1[opcao - 1].ataque){
                                carta_maquina = mao2[l];
                                strcpy (rod1_carta_maquina, mao2[l].nome);
                            }
                        }
                    }
                }

                rodada1 = comparar_cartas (mao1[0].ataque, mao1[1].ataque, mao1[2].ataque, carta_maquina.ataque, opcao);                    //rodada2 recebe um valor diferente da funao comparar_cartas de acordo com cada situaçao:
                                                                                                                                            //o jagador vece a rodada, a maquina vence a rodada, o jogador pede truco
                if (rodada1 == 4){              //if define o que acontece se o jogador pede truco
                    valor_rodada = 3;           //alterando valor da rodada por causa do truco
                    scanf ("%d", &opcao);
                    for (;opcao < 1 || opcao > 3; ){                //lendo a decisao que o jogador vai tomar depois de trucar
                        printf ("digite um valor valido:\n");
                        scanf ("%d", &opcao);
                    }
                    rod1_carta = opcao;
                    rodada1 = comparar_cartas (mao1[0].ataque, mao1[1].ataque, mao1[2].ataque, carta_maquina.ataque, opcao);
                }

                
                printf ("voce escolheu: %s\n", mao1[opcao - 1].nome);               //mostrando o resultado da rodada
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

    if (tento1 >= 12){
        printf ("parabens, voce ganhou !!\n");
        printf ("volte ao menu para verificar o ranking ou jogue mais uma pertida\n");
    }else{ 
        printf ("que pena, voce perdeu\n");
        printf ("volte ao menu para verificar o ranking ou jogue mais uma pertida\n");
    }
    p = fopen ("ranking.txt", "w");
    q = strstr (ranking_s, nome_player);
    if (q != NULL){
        for (i = 0, k = 0; k != 1 ; i++){
            if (q[i] == ','){
                if (tento1 >= 12){
                    q[i + 1] += 1;
                }else{
                    q[i + 3] += 1;
                }
                k = 1;
            }
        }
    }else{
        if (tento1 >= 12){
            strcat (nome_player, ",1,0\n");
        }else{
            strcat (nome_player, ",0,1\n");
        }
        strcat (ranking_s, nome_player);
    }
    fprintf(p, "%s", ranking_s);
    fclose (p);

    for (;!(opcao_termino == 1 || opcao_termino == 2); ){               //for que deixa o jogador escolher se ira jogar mais uma partida ou valtara para o menu depois de terminar um jogo
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

    FILE *p;

    char ranking_s[200];

    char eof_teste[50];

    p = fopen ("ranking.txt", "r");
    if (p != NULL){
        for ( ; !feof(p); ){
            if (fgets (eof_teste, 50, p)){
                strcat (ranking_s, eof_teste);
            }
        }
        printf ("%s", ranking_s);
    }else{
        printf ("nao existe um ranking no momento\n");
    }
    fclose (p);
    menu();
}

void sobre (void){
    printf ("integrantes do grupo: Paulo Fernando Correa Brandao\n");  
    printf ("grande parte do codigo foi feito apenas com estruturas de repeticao e structs\n");
    printf ("versao atual do programa: 1.7\n");
    printf ("1.0- apenas 6 cartas existiam, a mao sempre tinha as mesmas cartas, um teste dos sistemas mais basios do programa\n");
    printf ("1.1- introducao de todas as cartas e do baralho aleatorio, maquina joga as cartas na ordem que recebeu\n");
    printf ("1.2- introducao do sistema de tentos, sistema de rodadas, rodadas alternadas e interface para o jogador\n");
    printf ("1.3- nao eh mais possivel escolher a mesma carta duas vezes, ou receber cartas repetidas na mao, alem de outras correcoes de problemas\n");
    printf ("1.4- introducao de uma maquina inteligente, ate certo ponto\n");
    printf ("1.5- introducao do sistema de truco\n");
    printf ("1.6- introducao do sistema de ranking\n");
    printf ("1.7- otimizacao\n");

    menu();
}

void sair (void){
    exit(0);
}

int comparar_cartas (int carta1, int carta2, int carta3, int carta4, int opcaox){                   //recebe que opcao o jogador escolheu e retorna o vencedor da jogada ou truca o jogo
                                                                                                    //retorna valores diferentes para vitorias da maquina e do jogador, empates e pedidos de truco
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
            printf ("a maquina aceitou\n");
            printf ("agora esta rodada vale 3 tentos!\n");
            printf ("escolha uma carta: \n");
            return 4;
        break;
    }
}
