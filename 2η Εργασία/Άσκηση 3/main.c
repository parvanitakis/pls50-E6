#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SCORE 10
#define MIN_SCORE 0
#define WIN_POINT 2
#define LOSE_POINT -1

int i;
int j;
int x;

int nextPlayer=0;

typedef struct player {
    char name[17];
    char id;
    short int score;
} player;

player p[2];

typedef struct card {
    char colour;
    char shape;
    int number;
    char texture;
    int checked;
} card;

card trapoula[4][3];
card fullTrapoula[9][9];

void init_random();
int random_number(int min, int max);

void new_game();
void getNextCard();
void full_trapoula();
void epiloges_paikti();
void vathmologia();

int main()
{
    x=0;
    char choice;
    srand(time(NULL));
    new_game();

    for (i=0; i<3; i++){
        for (j=0; j<4; j++){
            trapoula[i][j].colour = '\0';
            trapoula[i][j].shape = '\0';
            trapoula[i][j].number = '\0';
            trapoula[i][j].texture = '\0';
        }
    }

    printf("Kalws irthate sto paixnidi SET! Kali epityxia!\n");
    printf("Gia na kanete SET prepei na dialexete 3 kartes opou kathena apo ta\n");
    printf("xaraktiristika tous na einai eite idio eite diaforetiko apo ola ta alla\n");
    printf("Diagwnizontai oi paixtes:\n%s, %s kai %s\n", p['a'].name, p['g'].name, p['p'].name);
    printf("Epilekste twra i pieste to miden gia na termatisete to paixnidi!!\n\n");
        getNextCard();
    do{
        printf("\nEisagete to anagnwristiko sas gia na paiksete.\n");

        scanf(" %c", &choice);
        if (choice == '0'){
            vathmologia();
            exit(0);
        }
        if ((choice == 'a')||(choice =='g')||(choice == 'p')) {
            epiloges_paikti(choice);
        }
        else if (choice !=('a'&&'g'&&'p')){
            printf("De vrethike SET. Neo moirasma!\n");
            getNextCard();
        }

    }while (choice != '0');

    return 0;
}

void new_game(){

    p['a'].id = 'a';
    p['g'].id = 'g';
    p['p'].id = 'p';

    strcpy(p['a'].name, "Marina Andreou");
    strcpy(p['g'].name, "Kostas Grammenos");
    strcpy(p['p'].name, "Maria Perdika");

    p['a'].score = (int)0;
    p['g'].score = (int)0;
    p['p'].score = (int)0;

    return;
}

int random_number(int min, int max){
    max -= min;
    return (rand() % max) + min;
}

void getNextCard(){
    int z;
    int i;
    int j;

    full_trapoula();

    int checkMonadiko[81];      //voithitikos pinakas gia elegxo an yparxoun 2 idies kartes
    for (i=0; i<81; i++){
        checkMonadiko[i] = 0;
    }

    for (i=0; i<3; i++){
        for (j=0; j<4; j++){
            z = random_number(0, 81);
            while (checkMonadiko[z] > 0){   //apeftheias elegxos gia dipli timi kai epanalipsi checked
                z = random_number(0, 81);
            }
            checkMonadiko[z] +=1;
            trapoula[i][j].checked = z;
            trapoula[i][j].colour = fullTrapoula[z/9][z%9].colour;
            trapoula[i][j].shape = fullTrapoula[z/9][z%9].shape;
            trapoula[i][j].number = fullTrapoula[z/9][z%9].number;
            trapoula[i][j].texture = fullTrapoula[z/9][z%9].texture;
            printf("[%c,%c,%d,%c] ", trapoula[i][j].colour, trapoula[i][j].shape, trapoula[i][j].number, trapoula[i][j].texture);
        }
        printf("\n");
    }
    return;
}

void full_trapoula(){

    char colour[3] = "rgb";
    char shape[3] = "ctr";
    int number[3] = {1,2,3};
    char texture[3] = "bhe";

    //dimiougria pinaka 81 diaforetikwn syndyasmwn
    for (i=0; i<9; i++){
        for (j=0; j<9; j++){
            fullTrapoula[i][j].checked = (i*9)+j;
            if (i<3){  // i<3
                fullTrapoula[i][j].colour = colour[0];
            }
            else if (i<6){ //i<6
            fullTrapoula[i][j].colour = colour[1];
            }
            else {  //if i<9
                fullTrapoula[i][j].colour = colour[2];
            }
            if ((i%3)==0){
                fullTrapoula[i][j].shape = shape[0];
            }
            else if ((i%3)==1){
                fullTrapoula[i][j].shape = shape[1];
            }
            else {  //if i%3==2
                fullTrapoula[i][j].shape = shape[2];
            }
            if (j<3){
            fullTrapoula[i][j].number = number[0];
            }
            else if (j<6){
                fullTrapoula[i][j].number = number[1];
            }
            else {  //if j<9
                fullTrapoula[i][j].number = number[2];
            }
            if ((j%3)==0){
                fullTrapoula[i][j].texture = texture[0];
            }
            else if ((j%3)==1){
                fullTrapoula[i][j].texture = texture[1];
            }
            else {  //if (j%3==2)
                fullTrapoula[i][j].texture = texture[2];
            }
        }
    }
    return;
}

void epiloges_paikti(choice){
    int a1;
    int a2;
    int b1;
    int b2;
    int c1;
    int c2;

    printf("Paizei o paiktis %s\n", p[choice].name);
    printf("Epilekste seira kai stili tis prwtis kartas!(me ena keno)\n");
    do{
        scanf(" %d %d", &a1, &a2);
        if ((a1-1<0) || (a1-1>3) || (a2-1<0) || (a2-1>4)){
            printf("Epilexte seira apo 1 ws 3 kai stili apo 1 ws 4\n");
            continue;
        }
    } while ((a1-1<0) || (a1-1>3) || (a2-1<0) || (a2-1>4));

    printf("Epilekse seira kai stili tis defteris kartas!(me ena keno)\n");
    do{
        scanf(" %d %d", &b1, &b2);
        if ((b1-1<0) || (b1-1>3) || (b2-1<0) || (b2-1>4)){
            printf("Epilexte seira apo 1 ws 3 kai stili apo 1 ws 4\n");
            continue;
        }
        if((a1==b1)&&(a2==b2)){
            printf("De mporeite na epileksete tin idia karta!!\n");
        }
        continue;
    } while ((b1-1<0) || (b1-1>3) || (b2-1<0) || (b2-1>4) || ((a1==b1)&&(a2==b2)));

    printf("Epilekse seira kai stili tis tritis kartas!(me ena keno)\n");
    do{
        scanf(" %d %d", &c1, &c2);
        if ((c1-1<0) || (c1-1>3) || (c2-1<0) || (c2-1>4)){
            printf("Epilexte seira apo 1 ws 3 kai stili apo 1 ws 4\n");
            continue;
        }
        if (((c1==a1)&&(c2==a2))||((c1==b1)&&(c2==b2))){
            printf("De mporeite na epileksete tin idia karta!!\n");
            continue;
        }
    } while ((c1-1<0) || (c1-1>3) || (c2-1<0) || (c2-1>4) || ((c1==a1)&&(c2==a2))||((c1==b1)&&(c2==b2)));

    if ((((trapoula[a1-1][a2-1].colour == trapoula[b1-1][b2-1].colour) && //xrwma
        (trapoula[b1-1][b2-1].colour == trapoula[c1-1][c2-1].colour)) ||
        ((trapoula[a1-1][a2-1].colour != trapoula[b1-1][b2-1].colour) && //ola idia i ola diaforetika
        (trapoula[b1-1][b2-1].colour != trapoula[c1-1][c2-1].colour) &&
        (trapoula[a1-1][a2-1].colour != trapoula[c1-1][c2-1].colour)))&&
        (((trapoula[a1-1][a2-1].shape == trapoula[b1-1][b2-1].shape) && //deftero stoixeio
        (trapoula[b1-1][b2-1].shape == trapoula[c1-1][c2-1].shape)) ||//sxima
        ((trapoula[a1-1][a2-1].shape != trapoula[b1-1][b2-1].shape) &&//ola idia i ola diaforetika
        (trapoula[b1-1][b2-1].shape != trapoula[c1-1][c2-1].shape) &&
        (trapoula[a1-1][a2-1].shape != trapoula[c1-1][c2-1].shape))) &&//trito stoixeio
        (((trapoula[a1-1][a2-1].number == trapoula[b1-1][b2-1].number) && //arithmos
        (trapoula[b1-1][b2-1].number == trapoula[c1-1][c2-1].number)) || //ola idia i ola diaforetika
        ((trapoula[a1-1][a2-1].number != trapoula[b1-1][b2-1].number) &&
        (trapoula[b1-1][b2-1].number != trapoula[c1-1][c2-1].number) &&
        (trapoula[a1-1][a2-1].number != trapoula[c1-1][c2-1].number))) &&        //tetarto stoixeio
        (((trapoula[a1-1][a2-1].texture == trapoula[b1-1][b2-1].texture) &&
        (trapoula[b1-1][b2-1].texture == trapoula[c1-1][c2-1].texture)) || //ola idia i ola diaforetika
        ((trapoula[a1-1][a2-1].texture != trapoula[b1-1][b2-1].texture) &&
        (trapoula[b1-1][b2-1].texture != trapoula[c1-1][c2-1].texture) &&
        (trapoula[a1-1][a2-1].texture != trapoula[c1-1][c2-1].texture))))
    {

        printf("O paiktis %s ekane SET kai kerdizei 2 vathmous!\n", p[choice].name);
        if (p[choice].score > 7){
            p[choice].score = 10;
            printf("O paiktis %s sygkentrwse prwtos 10 vathmous kai einai o nikitis\n", p[choice].name);
            vathmologia();
            exit(0);
        }
        else {
            p[choice].score += 2;
            nextPlayer = 0;
            getNextCard();
        }
    }
    else {
        printf("Lathos epilogi\n");
        p[choice].score -= 1;
        if (p[choice].score == 0){
            p[choice].score = 0;
        }
        if (nextPlayer<2){
            printf("O paiktis %s xanei ena vathmo kai de mporei na ksanapaiksei se auto to gyro\n", p[choice].name);
            printf("Epomenos paixtis...\n");
            nextPlayer +=1;
        }
        else {
            printf("Kanenas paixtis de vrike ti swsti apantisi\nNeo moirasma!\n\n");
            nextPlayer = 0;
            getNextCard();
        }
    }
    return;
}

void vathmologia(){

    if (p['a'].score < 0){
        p['a'].score = (int)0;
    }
    if (p['g'].score < 0){
        p['g'].score = (int)0;
    }
    if (p['p'].score < 0){
        p['p'].score = (int)0;
    }

    printf("\nTeliki vathmologia paiktwn:\n");
    printf("Onoma Paikti,\t vathmologia\n");
    if ((p['a'].score == p['g'].score) && (p['g'].score==p['p'].score)){
        printf("%3s,\t %2d\n", p['a'].name, p['a'].score);
        printf("%3s,%2d\n", p['g'].name, p['g'].score);
        printf("%3s,\t %2d\n", p['p'].name, p['p'].score);
        printf("To paixnidi teleiwse xwris nikiti! Oloi oi paiktes exoun tin idia vathmologia!\n");
    }

    else if (p['a'].score > p['g'].score){
        if (p['g'].score == p['p'].score){
            printf("%3s,\t %2d,\t nikitis!!!\n", p['a'].name, p['a'].score);
            printf("Isovathmia sti defteri thesi!!\n");
            printf("%3s,\t %2d\n", p['g'].name, p['g'].score);
            printf("%3s,\t %2d\n", p['p'].name, p['p'].score);
        }
        else if (p['g'].score > p['p'].score){
            printf("%3s,\t %2d,\t nikitis!!!\n", p['a'].name, p['a'].score);
            printf("%3s,\t %2d,\t defteros!!\n", p['g'].name, p['g'].score);
            printf("%3s,\t %2d,\t tritos!!\n", p['p'].name, p['p'].score);
        }
        else {
            if (p['a'].score > p['p'].score){
                printf("%3s,\t %2d,\t nikitis!!!\n", p['a'].name, p['a'].score);
                printf("%3s,\t %2d,\t defteros!!\n", p['p'].name, p['p'].score);
                printf("%3s,\t %2d,\t tritos!!\n", p['g'].name, p['g'].score);
            }
            else {
                printf("%3s,\t %2d,\t nikitis!!!\n", p['p'].name, p['p'].score);
                printf("%3s,\t %2d,\t defteros!!\n", p['a'].name, p['a'].score);
                printf("%3s,\t %2d,\t tritos!!\n", p['g'].name, p['g'].score);
            }
        }
    }
    else if (p['a'].score < p['g'].score){
        if (p['a'].score == p['p'].score){
            printf("%3s,\t %2d,\t nikitis!!!\n", p['g'].name, p['g'].score);
            printf("Isovathmia sti defteri thesi!!\n");
            printf("%3s,\t %2d\n", p['a'].name, p['a'].score);
            printf("%3s,\t %2d\n", p['p'].name, p['p'].score);
        }
        else if (p['a'].score > p['p'].score){
            printf("%3s,\t %2d,\t nikitis!!!\n", p['g'].name, p['g'].score);
            printf("%3s,\t %2d,\t defteros!!\n", p['a'].name, p['a'].score);
            printf("%3s,\t %2d,\t tritos!!\n", p['p'].name, p['p'].score);
        }
        else{
            if (p['g'].score > p['p'].score){
                printf("%3s,\t %2d,\t nikitis!!!\n", p['g'].name, p['g'].score);
                printf("%3s,\t %2d,\t defteros!!\n", p['p'].name, p['p'].score);
                printf("%3s,\t %2d,\t tritos!!\n", p['a'].name, p['a'].score);
            }
            else {
                printf("%3s,\t %2d,\t nikitis!!!\n", p['p'].name, p['p'].score);
                printf("%3s,\t %2d,\t defteros!!\n", p['g'].name, p['g'].score);
                printf("%3s,\t %2d,\t tritos!!\n", p['a'].name, p['a'].score);
            }
        }
    }
    else {
        printf("%3s,\t %2d,\t nikitis!!!\n", p['p'].name, p['p'].score);
            printf("Isovathmia sti defteri thesi!!\n");
            printf("%3s,\t %2d\n", p['a'].name, p['a'].score);
            printf("%3s,\t %2d\n", p['g'].name, p['g'].score);
    }
    printf("Game Over!\n");

    return;
}
