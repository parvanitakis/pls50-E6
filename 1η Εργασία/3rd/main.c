//Ektyposi diadikis anaparastasis thetikou dekadikou akeraiou

#include <stdio.h>

const int a = 2;        //stathera

int main()
{
    int x = 0; //ther=tikos akeraios
    int y;

    printf("To programma afto metatrepei enan thetiko akeraio dekadiko arithmo\n");
    printf("stin antistrofi dyadiki tou anaparastasi\n");
    printf("eisagete ton thetiko akeraio arithmo\n");
    scanf( "%d", &x);

    while (x<=0) {          //gia na min termatizei to programma
        printf("Prosohi! Prepei na eisagete enan thetiko arithmo\n");
        scanf( "%d", &x);
        }

    printf("O antistrofos dyadikos arithmos einai\n"); //ekso ap to loop gia na typonetai mia fora

        while (x>0){
            y = x%a;
            putchar(y==1 ? '1' : '0');      //enallaktika printf("%d", y);

            x=x/a;  //i diairesi synexizetai mexri to x na einai 0
        }
    return 0;
}


