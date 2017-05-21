//systima katagrafis kratimenon theseon leoforeiou
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x; //diavazei epiloges 1-8
    int i; //oi theseis tou leoforeiou
    int a; //gia kratisi-akyrosi thesis
    char pinakida[7]; //apothikeuei tin tin pinakida tou leoforeiou apo to arxeio bus.txt
    int theseis; //apothikeuei ton arithmo theseon ap to arxeio os int
    int bus[53]; //dilosi pinaka me max theseis 53
    int sumkenes; // apothikeuetai to athroisma kenon theseon tou leoforeiou

    FILE *fnew;
    fnew = fopen("bus.txt", "r");   /*anoigma arxeiou bus.txt. An de vrisketai ston idio fakelo me ti main grafoume ti
                                    diefthinsi prin, gia paradeigma "C:/bus.txt", "r"*/
    if (fnew==NULL){        //elegxos an yparxei to arxeio bus.txt kai minima lathous
        printf("To arheio bus.txt de mporese na anagnostei\n");
        exit(1); //To 1 stin parenthesi gia exodo logo lathous.
    }

    fscanf(fnew, "%s %d", pinakida, &theseis);  //anagnosi pinakidas me %s, diabazei xaraktires mexri na synantisei keno.

    if ((theseis-5)%4 != 0 || theseis > 53) {   //elegxos an theseis =4xN+5 i theseis >53 kai minima lathous
        printf("o arithmos ton theseon pou anaferetai sto arheio bus.txt einai lathos\n");
        exit(1);
    }

    for (i=0; i<theseis; i++) {  //arxikopoiisi pinaka theseon leoforeiou pou dinontai apo to arxeio bus.txt
        bus[i] = 0;
    }

    printf("To leoforeio exei pinakida: %s", pinakida);
    printf(" kai diathetei %d theseis\n\n", theseis);

    do {                            //menou epilogon xristi
        printf("Parakalo epilexte ena apo ta parakato:\n");
        printf("1 gia emfanisi tou synolikou plithous kenon theseon kai tou arithmou tous\n");
        printf("2 gia kratisi thesis me sygekrimeno arithmo\n");
        printf("3 gia evresi kai kratisi tis protis kenis thesis pou vrisketai se parathiro\n");
        printf("4 gia akyrosi kratisis thesis me sygkekrimeno arithmo\n");
        printf("5 gia anazitisi an einai kratimeni mia thesi me sygekrimeno arithmo\n");
        printf("6 gia emfanisi listas kratimenon theseon taxinomimenis kata arithmo thesis\n");
        printf("7 gia emfanisi tis pinakidas kai tou diagrammatos tou leoforeiou\n");
        printf("8 gia apothikefsi tis pinakidas kai tou diagrammatos leoforeiou se neo arheio\n");
        printf("0 gia exodo\n");
        scanf("%d", &x);

        if (x==1) {
            printf("Yparxoun oi parakato kenes theseis:\n");
            sumkenes=0;     //arxikopoiisi sumkenes mesa sto if kai prin to loop oste na min apothikevei timi
            for (i=0; i<theseis; i++){  //me ena loop typonei kenes theseis kai synolo. Mporei na ylopoiithei k me dyo loop
                if (bus[i]==0) {        //an theloume prota na typonei synolo kai meta theseis
                    printf("%d, ", i+1);
                    sumkenes+=1;
                }
            }
            printf("\nSto leoforeio yparxoun synolika %d kenes theseis\n\n", sumkenes);
        }

        if (x==2) {     //kratisi thesis apo to xristi
            printf("Epilekste se poia apo tis %d theseis tou leoforeiou epithimeite na ginei kratisi:\n", theseis);
            scanf( "%d", &a);

            if ((a-1)<0 || (a-1)>=theseis){   //elegxos an i thesi pou dilothike einai sta oria pou exoun dothei
                printf("To leoforeio de diathetei ton arithmo thesis pou epileksate\n\n");
            }
            else if (bus[a-1]==1){  //elegxos an einai kratimeni idi i thesi
                printf("H thesi me arithmo %d einai idi kratimeni\n\n", a);
            }
            else { printf("Egine kratisi gia ti thesi me arithmo %d\n\n", a);
            bus[a-1]=1;     //anathesi timis 1 se thesi, diladi kratisi
            }
        }

        if (x==3) {     //evresi protis kenis thesis se parathiro kai kratisi
            for(i=0; i<theseis; i++){       //loop gia na ksekinaei apo tin proti thesi
                if ((i<theseis-5)&&(i%4==0 || i%4==3)){ //elegxos an den einai galaria kai an einai thesi se parathiro
                    if (bus[i]==0){
                        printf("Kratithike i thesi se parathiro, me arithmo %d\n\n", i+1);
                        bus[i]=1;   //anathesi timis 1 se thesi, diladi kratisi
                        break;      //exodos ap to loop giati allios tha kratisei oles tis eleutheres theseis se parathiro
                    }
                }
                else if((i==theseis-5) || (i==theseis-1)) { //elegxos an einai mia apo tis 2 theseis se parathiro sti galaria
                    if (bus[i]==0){
                        printf("Kratithike i thesi se parathiro me arithmo %d\n\n", i+1);
                        bus[i]=1;   //anathesi timis 1 se thesi, diladi kratisi
                        break;  //exodos ap to loop gia na min kratisei kai tis 2 theseis se parathiro sti galaria
                    }
                }
            }
        }

        if(x==4) {      //epilogi xristi gia akyrosi thesis
            printf("Epilekste gia poia apo tis %d theseis tou leoforeiou epithimeite na ginei akyrosi:\n", theseis);
            scanf( "%d", &a);   /*o xristis epilegei a, to programma elegxei gia a-1 giati oi theseis tou leoforeiou ksekinoun
                                apo 1, eno to programma diavazei apo thesi 0*/
            if ((a-1)<0 || (a-1)>=theseis){     //elegxos an i thesi pou dilothike einai sta oria pou exoun dothei
                printf("To leoforeio de diathetei ton arithmo thesis pou epileksate\n\n");
            }
            else if (bus[a-1]==0){      //elegxos an i thesi mporei na akyrothei i an einai idi eleutheri
                    printf("H thesi me arithmo %d den einai kratimeni\n\n", a);
            }
            else { printf("Egine akyrosi gia ti thesi me arithmo %d\n\n", a);
                bus[a-1]=0; //anathesi timis 1 se thesi, diladi akyrosi
            }
        }

        if (x==5) {     //elegxos an einai kratimeni mia thesi
            printf("Epilekste ton arithmo thesis apo tis %d tou leoforeiou gia na deite an einai kratimeni\n", theseis);
            scanf( "%d", &a);

            if ((a-1)<0 || (a-1)>=theseis){     //elegxos an i thesi pou dilothike einai sta oria pou exoun dothei
                printf("To leoforeio de diathetei ton arithmo thesis pou epileksate\n\n");
            }
            else if (bus[a-1]==1){
                printf("H thesi me arithmo %d einai kratimeni\n\n", a);
            }
            else { printf("H thesi me ton arithmo %d den einai kratimeni\n\n", a);
            }
        }

        if (x==6) {     //epilogi xristi gia emfanisi listas kratimenon theseon
            printf("Oi kratimenes theseis einai oi eksis:\n");

            for(i=0; i<theseis; i++){
                if (bus[i]==1) {
                printf("thesi %d\n", i+1);  //typonei thesi a+1 giati to programma metraei apo to 0
                }
            }
        }

        if (x==7) {     //epilogi xristi gia emfanisi pinakidas kai diagrammatos leoforeiou
            printf("%s\n", pinakida);       //typonei pinakida

            for (i=0; i<theseis-5; i++){    //loop oste gia kathe kratimeni thesi ektos galarias na emfanizetai *
                if (bus[i]==1){             //kai gia kathe eleutheri na emfanizetai _
                    printf("%c", '*');
                }
                else { printf("%c", '_');
                }
                if (i%4==1){                //an einai i deuteri thesi kathe seiras typonei keno
                    printf("%c", ' ');
                }
                else if (i%4==3){           //an einai i tetarti thesi kathe seiras typonei newline
                    printf("%c", '\n');
                }
            }

            for (i=theseis-5; i<theseis; i++){      //loop gia tis theseis sti galaria. * kai _ opos kai sto proigoumeno loop
                if (bus[i]==1){
                    printf("%c", '*');
                }
                else { printf("%c", '_');
                }
                if (i==theseis-1){
                    printf("%c", '\n');         //meta tin teleutaia thesi typonei newline
                }
            }

        }

        if (x==8) {         //epilogi xristi gia apothikeusi pinakidas kai diagrammatos se neo arxeio
            FILE *fapoth;

            fapoth = fopen("layout.txt", "w");      //dimiourgia neou arxeiou me to w, an den yparxei idi
            fprintf(fapoth,"%s\n", &pinakida);      //apothikeusi arithmou pinakidas se neo arxeio

            for (i=0; i<theseis-5; i++){        //akolouthei to idio loop kai oi elegxoi me tin proigoumeni epilogi xristi
                if (bus[i]==1){
                    fprintf(fapoth, "%c", '*');     //moni diafora i xrisi tis fprintf anti tis printf giati to programma
                }                                   //grafei se arxeio kai den typonei kati stin othoni
                else { fprintf(fapoth, "%c", '_');
                }
                if (i%4==1){
                    fprintf(fapoth, "%c", ' ');
                }
                else if (i%4==3){
                    fprintf(fapoth, "%c", '\n');
                }
            }

            for (i=theseis-5; i<theseis; i++){
                if (bus[i]==1){
                    fprintf(fapoth, "%c", '*');
                }
                else { fprintf(fapoth, "%c", '_');
                }
                if (i==theseis-1){
                    fprintf(fapoth, "%c", '\n');
                }
            }
            printf("sto arxeio layout.txt exoun apothikeutei i pinakida kai to diagramma tou leoforeiou\n\n");
            fclose(fapoth);     //kleinei to neo arxeio gia apodesmeusi mnimis
        }

        if(x<0 || x>8){     //elegxos an dinetai sosti epilogi apo xristi kai epistrofi sto menou epilogon
            printf("Parakalo epilexte enan arithmo apo to 0 mehri to 8\n");
        }

    }while (x!=0);      //to programma termatizei mono an o xristis dosei tin timi miden

    fclose(fnew);       //kleinei to arxeio bus.txt gia apodesmeusi mnimis

    return 0;
}
