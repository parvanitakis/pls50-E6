#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_ZERO 48   //I ASCII timi gia to miden. Gia metatropi char stoixeiwn symvoloseiras se int
                        //afou px to char 1 einai to 49 se ASCII an afairesoume 48 ginetai 1 (dld int)
char pinakida[7];
int theseis;    //arithmos thesewn lewforeiou pou diavazei apo arxeio
int i;          //thesi leoforeiou
int j;          //thesi pinaka tilefwnou
int sumkenes;
int sumkratimenes;

char tempLastName[40] = ""; //proswrini apothikefsi onomatwn
char tempName[40]="";       //proswrini apothikefsi onomatwn
unsigned int tempSeatNo;    //proswrini apothikefsi thesis lewforeiou
char tempTel[11];            //proswrini apothikefsi tilefwnou
char epivevaiwsi;

typedef struct passenger {  //domi passenger me 3 metavlites
    char fullname[40];
    unsigned short tel[10];
    unsigned int seatNo;
} passenger;

passenger bus[53];

void readFile();
void kenesTheseis();
void kratisiThesis();
void anazitisiMeOnoma();
void anazitisiMeTilefwno();
void akyrwsiThesis();
void kratimenesTheseis();
void writefile();

int main()
{
    int choice;

    readFile();
    printf("To leoforeio exei pinakida: %s", pinakida);
    printf(" kai diathetei %d theseis\n\n", theseis);

    do {
        printf("\nEpilekste ena apo ta parakatw: Epilekste\n");
        printf("1 gia emfanisi tou sinolou kenwn thesewn kai ton arithmwn me afksousa seira\n");
        printf("2 gia kratisi thesis me sigkekrimeno arithmo gia epivati tis epilogis sas\n");
        printf("3 gia na anazitisete me tilefwno i onom/mo epivati an mia thesi einai kratimeni\n");
        printf("4 gia na akirwsete mia kratimeni thesi me sygkekrimeno arithmo\n");
        printf("5 gia emfanisi tis listas kratimenwn thesewn kata arithmo thesis\n");
        printf("0 gia eksodo apo to menou epilogwn\n");
        scanf(" %d", &choice);

        if (choice==1){
            kenesTheseis();
        }
        else if (choice==2){
            int kratisi;
            printf("Gia poia thesi epithimeite na ginei kratisi?\n");
            scanf(" %d", &kratisi);
            if (kratisi<1 || kratisi>theseis){
                printf("To lewforeio de diathetei ti thesi %d\n", kratisi);
            }
            else {
                kratisiThesis(&(bus[kratisi-1]));   //O deiktis tis sinartisis tha deixnei ti thesi tou lewforeiou
            }                                       //pou exei epilegei kai tha epistrefei tis nees times me anafora
        }
        else if (choice==3){
            char elegxosKratisis;
            printf("Epilekste 'o' gia anazitisi me on/mo h 't' gia anazitisi me tilefwno\n");
            scanf(" %c", &elegxosKratisis);
            if (elegxosKratisis=='o'){
                printf("Eisagete to onomatepwnymo tou epivati pou anazitate\n");
                scanf(" %s %s", tempLastName, tempName);
                strcat(tempLastName, " ");
                strcat(tempLastName, tempName);
                anazitisiMeOnoma(&tempLastName);
            }
            else if (elegxosKratisis=='t'){
                printf("Eisagete to tilefwno tou epivati pou anazitate\n");
                scanf(" %s", tempTel);
                anazitisiMeTilefwno(&tempTel);
            }
            else
                printf("Mi egkyri epilogi\n\n");
        }
        else if (choice==4){
            int akyrwsi;
            printf("Gia poia thesi epithimeite na ginei akyrwsi?\n");
            scanf(" %d", &akyrwsi);
            if (akyrwsi<1 && akyrwsi >theseis){
                printf("To lewforeio de diathetei ti thesi %d\n", akyrwsi);
            }
            else{
                akyrwsiThesis(&(bus[akyrwsi-1]));
            }
        }
        else if (choice==5){
            kratimenesTheseis();
        }
        else if (choice<0 || choice>5){
            printf("Parakalw epilekste metaksy tou 0 kai tou 5");
        }

    } while(choice!=0);
    writefile();

    return 0;
}

void readFile(){

    FILE *fpointer;
    fpointer = fopen("bus.txt", "r");

    if (fpointer==NULL){
        printf("To arheio bus.txt de mporese na anagnostei\n");
        exit(1);
    }
    fscanf(fpointer, "%s %d", pinakida, &theseis);
    for (i=0; i<theseis; i++){
        strcpy(bus[i].fullname, "\0");
        bus[i].seatNo = i+1;
        for (j=0; j<10; j++){
            bus[i].tel[j] = 0;
        }
    }

    while (!feof(fpointer)){
        fscanf(fpointer, " %s %s %d %s\n", tempLastName, tempName, &tempSeatNo, tempTel);
        strcat(tempLastName, " ");      //prosthetei keno meta to epitheto
        strcat(tempLastName, tempName); //prosthetei onoma meta to epitheto_
        strcpy(bus[tempSeatNo-1].fullname, tempLastName);   //antigrafei tin proswrini metavliti sti metavliti tou struct
        for (j=0; j<10; j++){
            bus[tempSeatNo-1].tel[j] = tempTel[j] - ASCII_ZERO;
        }
    }
    fclose(fpointer);

    return;
}

void writefile(){

    FILE *fpointer;
    fpointer = fopen("bus.txt", "w");

    if (fpointer==NULL){
        printf("To arheio bus.txt de mporese na anagnostei\n");
        exit(1);
    }

    fprintf(fpointer, "%s %d\n", pinakida, theseis);
    for (i=0; i<theseis; i++){
        if (strcmp(bus[i].fullname, "\0")!=0){
            fprintf(fpointer, "%s %d ", bus[i].fullname, bus[i].seatNo);
            for (j=0; j<10; j++){
                fprintf(fpointer, "%hu", bus[i].tel[j]);
            }
            fprintf(fpointer, "\n");
        }
    }

    fclose(fpointer);

    return;
}

void kenesTheseis(){
    sumkenes=0;
    for (i=0; i<theseis; i++){
        if (strcmp(bus[i].fullname, "\0")==0){
            sumkenes += 1;
        }
    }
    if (sumkenes == 0){
        printf("To lewforeio einai plires!\n");
    }
    else {
        printf("Sto lewforeio yparxoun synolika %d kenes theseis\n", sumkenes);
        printf("Oi kenes theseis taksinomimenes kata auksousa seira einai oi eksis:\n");
        for (i=0; i<theseis; i++){
            if (strcmp(bus[i].fullname, "\0")==0){
                printf("thesi %d\n", bus[i].seatNo);
            }
        }
        printf("\n\n");
    }
    return;
}

void kratisiThesis(passenger *p){      //deiktis gia thesi lewforeiou bus[kratisi-1]

    if (strcmp((*p).fullname, "\0")!=0){
        printf("I thesi %d pou epileksate einai idi kratimeni\n", (*p).seatNo);
    }
    else {
        printf("I thesi einai eleftheri. Parakalw eisagete to onomatepwnimo tou epivati\n");
        scanf(" %s %s", tempLastName, tempName);
        printf("Eisagete to tilefwno tou epivati\n");
        scanf(" %s", tempTel);
        strcat(tempLastName, " ");
        strcat(tempLastName, tempName);
        printf("Eiste vevaioi oti thelete na kratithei i thesi %d gia epivati me on/mo %s\n", (*p).seatNo, tempLastName);
        printf("kai til %s? Epilekste y/n\n", tempTel);
        scanf(" %c", &epivevaiwsi);

        if (epivevaiwsi=='y'){
            strcpy((*p).fullname, tempLastName);
            for (j=0; j<10; j++){
                (*p).tel[j] = tempTel[j] - ASCII_ZERO;
            }
            printf("I kratisi tis thesis me arithmo %d gia ton epivati %s ", (*p).seatNo, (*p).fullname);
            printf("me tilefwno %s oloklirwthike!\n\n", tempTel);
        }
        else if (epivevaiwsi=='n'){
            printf("I diadikasia kratisis thesis termatistike\n\n");
        }
        else
            printf("mi egkyri epilogi!!");
    }
    return;
}

void anazitisiMeOnoma(char *tempLastName){
    int found = 0;  //an de vrethei epivatis me idio onomatepwnymo i found menei miden kai typwnetai to apotelesma
    for (i=0; i<theseis; i++){
        if (strcmp(bus[i].fullname, tempLastName)==0){
            printf("O epivatis me on/mo %s vrisketai sti thesi %d\n", tempLastName, bus[i].seatNo);
            found += 1;  // gia kathe epivati me idio on/mo afksanei to found paratirwntas diploeggrafes i epivati me idio on/mo
        }
    }
    if (found > 1){
        printf("Vrethikan synolika %d epivates me to onomatepwnymo pou anazitate!!\n", found);
    }
    if (found ==0){
        printf("De vrethike kratimeni thesi gia to on/mo %s\n", tempLastName);
    }
    return;
}

void anazitisiMeTilefwno(char *tempTel){
    int found = 0;
    for (i=0; i<theseis; i++){
        if ((bus[i].tel[0]==tempTel[0]-ASCII_ZERO)&&(bus[i].tel[1]==tempTel[1]-ASCII_ZERO)&&(bus[i].tel[2]==tempTel[2]-ASCII_ZERO)
            &&(bus[i].tel[3]==tempTel[3]-ASCII_ZERO)&&(bus[i].tel[4]==tempTel[4]-ASCII_ZERO)&&(bus[i].tel[5]==tempTel[5]-ASCII_ZERO)
            &&(bus[i].tel[6]==tempTel[6]-ASCII_ZERO)&&(bus[i].tel[7]==tempTel[7]-ASCII_ZERO)&&(bus[i].tel[8]==tempTel[8]-ASCII_ZERO)
            &&(bus[i].tel[9]==tempTel[9]-ASCII_ZERO)){

            if (strcmp(bus[i].fullname, "\0")!= 0){
                printf("O epivatis me til %s vrisketai sti thesi %u kai onomazetai %s\n", tempTel, bus[i].seatNo, bus[i].fullname);
                found +=1;
            }
            if (strcmp(bus[i].fullname, "\0")==0){
                printf("To tilefwno %s einai kataxwrimeno sti thesi %d omws i thesi einai keni\n", tempTel, bus[i].seatNo);
                found +=1;
            }
        }
    }
    if (found > 1){
        printf("To tilefwno pou anazitate vrethike einai kataxwrimeno 2 fores\n");
    }
    if (found == 0){
        printf("Den yparxei kratimeni thesi pou na antistoixei sto tilefwno pou zitisate\n\n");
    }
    return;
}

void akyrwsiThesis(passenger *p){
    char epivevaiwsi;

    if(strcmp((*p).fullname, "\0")==0){
            printf("I thesi %d pou epileksate einai idi eleftheri\n\n", (*p).seatNo);
    }
    else {
        printf("I thesi einai kratimeni ston epivati %s me til ", (*p).fullname);
        for (j=0; j<10; j++){
            printf("%hu", (*p).tel[j]);
        }
        printf("\nEiste vevaioi oti thelete na akyrwthei i thesi %d gia epivati me on/mo %s kai til ", (*p).seatNo, (*p).fullname);
        for (j=0; j<10; j++){
            printf("%hu", (*p).tel[j]);
        }
        printf(" ?\nEpilekste y/n\n");

        scanf(" %c", &epivevaiwsi);
        if (epivevaiwsi=='y'){
            tempSeatNo = (*p).seatNo;
            strcpy(tempLastName, (*p).fullname);

            strcpy((*p).fullname, "\0");
            for (j=0; j<10; j++){
                (*p).tel[j] = 0;
            }
            printf("I akyrwsi tis thesis me arithmo %d gia ton epivati %s oloklirwthike!!\n\n", (*p).seatNo, (*p).fullname);
        }
        else if (epivevaiwsi=='n'){
            printf("I diadikasia akyrwsis thesis termatistike!\n\n");
        }
        else{
            printf("mi egkyri epilogi!!\n\n");
        }
    }
    return;
}

void kratimenesTheseis(){
    sumkratimenes=0;
    for (i=0; i<theseis; i++){
        if (strcmp(bus[i].fullname, "\0")!=0){
            sumkratimenes += 1;
        }
    }
    if (sumkratimenes == 0){
        printf("Den yparxoun kratimenes theseis sto lewforeio\n");
    }
    else {
        printf("Sto lewforeio yparxoun synolika %d kratimenes theseis\n", sumkratimenes);
        printf("Oi kratimenes theseis taksinomimenes kata auksousa seira einai oi eksis:\n");
        for (i=0; i<theseis; i++){
            if (strcmp(bus[i].fullname, "\0")!=0){
                printf("Thesi: %d ", bus[i].seatNo);
                printf("On/mo: %s Tilefwno: ", bus[i].fullname);
                for (j=0; j<10; j++){
                    printf("%hu", bus[i].tel[j]);
                }
                printf("\n");
            }
        }
    }
    return;
}
