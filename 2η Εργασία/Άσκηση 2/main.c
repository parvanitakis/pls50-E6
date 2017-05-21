#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_ZERO 48

char pinakida[7];
int theseis;    //arithmos thesewn lewforeiou pou diavazei apo arxeio
int i;          //thesi leoforeiou
int k;          //gia bubblesort mazi me to i
int m;          //gia antikatastasi tilefwnou sto bubblesort
int j;          //thesi pinaka onomatos
int z;          //thesi pinaka tilefwnou
int sumkenes;
int sumkratimenes;
int choice;

char tempLastName[40] = "";
char tempName[40] = "";
unsigned int tempSeatNo;
char tempTel[11];
char epivevaiwsi;
unsigned short swapTel[10];

typedef struct passenger{  //domi passenger me 3 metavlites
    char fullname[40];
    unsigned short tel[10];
    unsigned int seatNo;
} passenger;

passenger *bus;

struct node{            //Apla syndedemeni lista
    passenger data;
    struct node *next;
}*head=NULL;

void readFile();
void kenesTheseis();
void kratisiThesis();
void anazitisiMeOnoma();
void anazitisiMeTilefwno();
void akyrwsiThesis();
void sort_by_seatNo();
void sort_by_name();
void writefile();
void createList();
void deleteList();

int main()
{
    readFile();
    printf("To lewforeio exei pinakida %s kai diathetei %d theseis\n\n", pinakida, theseis);

    do {
        printf("\nEpilekste ena apo ta parakatw: Epilekste\n");
        printf("1 gia emfanisi tou sinolou kenwn thesewn kai ton arithmwn me afksousa seira\n");
        printf("2 gia kratisi thesis me sigkekrimeno arithmo gia epivati tis epilogis sas\n");
        printf("3 gia na anazitisete me tilefwno i onom/mo epivati an mia thesi einai kratimeni\n");
        printf("4 gia na akirwsete mia kratimeni thesi me sygkekrimeno arithmo\n");
        printf("5 gia emfanisi tis listas kratimenwn thesewn\n");
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
            if (akyrwsi<1 || akyrwsi >theseis){
                printf("To lewforeio de diathetei ti thesi %d\n", akyrwsi);
            }
            else{
                akyrwsiThesis(&(bus[akyrwsi-1]));
            }
        }
        else if (choice==5){
            char epilogi;
            sumkratimenes = 0;
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
                printf("Parakalw epilekste ti seira emfanisis twn kratimenwn thesewn. Epilekste:\n");
                printf("t gia emfanisi kata arithmo thesis i\no gia emfanisi kata onomatepwnymo\n");
                scanf(" %c", &epilogi);

                if (epilogi=='t'){             //taksinomisi kata tilefwno

                    printf("Oi kratimenes theseis taksinomimenes kata arithmo thesis einai oi eksis:\n");
                    sort_by_seatNo();
                    for (i=0; i<theseis; i++){
                        if (strcmp(bus[i].fullname, "\0")!=0){
                            printf("On/mo: %s Thesi: %d Tilefwno: ", bus[i].fullname, bus[i].seatNo);
                            for (z=0; z<10; z++){
                                printf("%hu", bus[i].tel[z]);
                            }
                            printf("\n");
                        }
                    }
                    sort_by_name();
                }
                else if (epilogi=='o'){
                    sort_by_name();//metaferontai oi kratimenes theseis stin arxi tis listas
                    printf("Oi kratimenes theseis taksinomimenes kata onomatepwnymo einai oi eksis:\n");
                    for (i=0; i<theseis; i++){
                        if (strcmp(bus[i].fullname, "\0")!=0){
                            printf("On/mo: %s Thesi: %u Tilefwno: ", bus[i].fullname, bus[i].seatNo);
                            for (z=0; z<10; z++){
                                printf("%hu", bus[i].tel[z]);
                            }
                            printf("\n");
                        }
                    }
                }
                else {
                    printf("Mi ekgyri epilogi!!\n\n");
                }
            }
        }
        else if (choice==0){
            struct node *current = 0;
            createList(0, bus, current);
            writefile();
            deleteList(head);
        }

        else if (choice<0 || choice>5){
            printf("Parakalw epilekste metaksy tou 0 kai tou 5");
        }

    } while(choice!=0);

    return 0;
}

void readFile(){

    FILE *fpointer;
    fpointer = fopen("bus.txt", "r");

    if (fpointer==NULL){
        printf("To arxeio de mporese na anagnwstei\n");
        exit(1);
    }
    fscanf(fpointer," %s %d", pinakida, &theseis);

    bus = (passenger *)malloc(theseis * sizeof(struct passenger));  //desmefsi mnimis
    if (bus == NULL){                              //elegxos an yparxei diathesimi mnimi
        printf("Den yparxei diathesimi mnimi\n");
        exit(1);
    }

    for (i=0; i<theseis; i++){          //arxikopoiisi pinaka
        strcpy(bus[i].fullname, "\0");
        bus[i].seatNo = i+1;
        for (z=0; z<10; z++){
            bus[i].tel[z] = 0;
        }
    }
    while(!feof(fpointer)){
        fscanf(fpointer,"%s %s %d %s", tempLastName, tempName, &tempSeatNo, tempTel);
        strcpy(bus[tempSeatNo-1].fullname, tempLastName);
        strcat(bus[tempSeatNo-1].fullname, " ");
        strcat(bus[tempSeatNo-1].fullname, tempName);
        for (z=0; z<10; z++){
            bus[tempSeatNo-1].tel[z] = tempTel[z] - ASCII_ZERO; //gia metatropi apo char se int
        }
    }
    fclose(fpointer);

    return;
}

void createList(int i, passenger bus[i], struct node *current){
    sort_by_name();

    struct node *newNode;

    if (bus[i].fullname[0] != '\0'){
        newNode = (struct node *)malloc(sizeof(struct node)); //desmefsi mnimis gia dimiourgia struct
        if (newNode == NULL){
            printf("Den yparxei diathesimi mnimi\n");
            exit(1);
        }
        passenger a;    //metavliti typou passenger
        a = bus[i];
        passenger *p;   //deiktis se passenger
        p = &a;             //arxikopoiisi deikti. Deixnei stin timi tou a pou exei apothikevmeni ti thesi tou lewforeiou

        newNode->data = *p;        //sta dedomena tou komvou apothikevetai i timi pou deixei o deiktis p
        newNode->next = NULL;       //o neos komvos de deixnei pouthena afou einai eisagwgi sto telos

        if(head==NULL){     //dimiourgia prwtou komvou -- to head deixnei ston prwto
            head = newNode;
            current = newNode;
        }
        else{               // eisagwgi sto telos meta ti dimiourgia prwtou komvou
            current->next = newNode;
            current = newNode;
        }
        i++;        //afksanei to i(thesi lewforeiou) kata ena kai
        createList(i, bus, current);    //kalei ton eauto tis me to neo i
    }
    else{
        return; //an bus[i].fullname einai keno, termatizei i anadromi
    }
}

void writefile(){

    free(bus);
    FILE *fpointer;
    fpointer = fopen("bus.txt", "w");

    if (fpointer==NULL){
        printf("To arheio bus.txt de mporese na anagnostei\n");
        exit(1);
    }
    fprintf(fpointer, "%s %d\n", pinakida, theseis);

    struct node *newNode;

    newNode = head;            //O deiktis newNode deixnei stin arxi tis listas
    while(newNode!=NULL){     //Sarwsi listas
        int x;
        for(x = 0; newNode->data.fullname[x]; x += 1){
            fprintf(fpointer, "%c", newNode->data.fullname[x]);
        }
        fprintf(fpointer, " ");
        fprintf(fpointer, "%d", newNode->data.seatNo);
        fprintf(fpointer, " ");

        for(j=0; j<10; j++){
            fprintf(fpointer, "%hu", newNode->data.tel[j]);
        }
        fprintf(fpointer, "\n");

        newNode=newNode->next;
    }

    fclose(fpointer);
    printf("I eggrafi sto arxeio bus.txt oloklirwthike!\n");

    return;
}

void deleteList(struct node *head){

    struct node* current = head;
    struct node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
    printf("Apodesmefsi mnimis\n");
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
            printf("O epivatis me on/mo %s vrisketai sti thesi %d kai exei tilefwno ", tempLastName, bus[i].seatNo);
            for (m=0; m<10; m++){
                printf("%u", bus[i].tel[m]);
            }
            printf("\n");
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

void sort_by_name(){

    int i; //topiki metavliti gia metrima thesewn
    int k; //topiki metavliti gia bubblesort
    int j; //topiki metavliti gia metrima grammatwn onomatos
    int z; //topiki metavliti gia metrima psifiwn tilefwnoy

    for (i=1; i<theseis; i++) {         //epistrofi se taksinomisi kata onomatepwnymo
        for (k=0; k<=theseis-1-i; k++){
            if ((bus[k].fullname[0] == '\0')&&(bus[k+1].fullname[0] != '\0')){
                strcpy(bus[k].fullname, bus[k+1].fullname);
                strcpy(bus[k+1].fullname, "\0");
                tempSeatNo = bus[k+1].seatNo;
                bus[k+1].seatNo = bus[k].seatNo;
                bus[k].seatNo = tempSeatNo;
                for (z=0; z<10; z++){
                    bus[k].tel[z] = bus[k+1].tel[z];
                }
                for (z=0; z<10; z++){
                    bus[k+1].tel[z] = 0;
                }
            }
            else if ((bus[k].fullname[0] == '\0')&&(bus[k+1].fullname[0] == '\0')){
                if (bus[k].seatNo > bus[k+1].seatNo){
                    tempSeatNo = bus[k+1].seatNo;
                    bus[k+1].seatNo = bus[k].seatNo;
                    bus[k].seatNo = tempSeatNo;
                }
            }
            else if ((bus[k].fullname[0] != '\0')&&(bus[k+1].fullname[0] != '\0')) {
                for (j=0; j<40; j++){
                    if (bus[k].fullname[j] > bus[k+1].fullname[j]){
                        strcpy(tempLastName, bus[k+1].fullname);
                        strcpy(bus[k+1].fullname, bus[k].fullname);
                        strcpy(bus[k].fullname, tempLastName);
                        tempSeatNo = bus[k+1].seatNo;
                        bus[k+1].seatNo = bus[k].seatNo;
                        bus[k].seatNo = tempSeatNo;
                        for (z=0; z<10; z++){
                            swapTel[z] = bus[k+1].tel[z];
                        }
                        for (z=0; z<10; z++){
                            bus[k+1].tel[z] = bus[k].tel[z];
                        }
                        for (z=0; z<10; z++){
                            bus[k].tel[z] = swapTel[z];
                        }
                        break;
                    }
                    else if (bus[k].fullname[j] < bus[k+1].fullname[j]){
                        break;
                    }
                }
            }
        }
    }
    return;
}

void sort_by_seatNo(){
int i; //topiki metavliti gia metrima thesewn
    int k; //topiki metavliti gia bubblesort
    int z; //topiki metavliti gia metrima psifiwn tilefwnoy

    for (i=1; i<theseis; i++) {         //epistrofi se taksinomisi kata onomatepwnymo
        for (k=0; k<=theseis-1-i; k++){
            if (bus[k].seatNo > bus[k+1].seatNo){
                strcpy(tempLastName, bus[k+1].fullname);
                strcpy(bus[k+1].fullname, bus[k].fullname);
                strcpy(bus[k].fullname, tempLastName);
                tempSeatNo = bus[k+1].seatNo;
                bus[k+1].seatNo = bus[k].seatNo;
                bus[k].seatNo = tempSeatNo;
                for (z=0; z<10; z++){
                    swapTel[z] = bus[k+1].tel[z];
                }
                for (z=0; z<10; z++){
                    bus[k+1].tel[z] = bus[k].tel[z];
                }
                for (z=0; z<10; z++){
                    bus[k].tel[z] = swapTel[z];
                }
            }
            else {
                continue;
            }
        }
    }
    return;
}

