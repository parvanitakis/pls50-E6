#include <stdio.h>

int main()
{
    double x, y, S, M, P, D;
    char ch;

    printf ("Auto to programma kanei prakseis me dyo arithmous\n");
    printf ("kai stroggylopoiei sta dyo dekadika psifia\n");
    printf ("Eisagete arithmo, praksi, arithmo me ena keno metaksi tous\n");
    scanf ( "%lf %c %lf", &x, &ch, &y);

    if (ch=='+'){
        S = x + y;
        printf ("To athroisma einai =%0.2lf\n", S);
    }
    else if (ch=='-') {
        M = x - y;
        printf ("H diafora einai =%0.2lf\n", M);
    }
    else if (ch=='*') {
        P = x * y;
        printf ("To ginomeno einai =%0.2lf\n", P);
    }
    else if (ch=='/') {
        if (y==0){
            printf("O diairetis de mporei na einai 0");
        }
        else {
            D = x / y;
            printf ("To piliko einai =%0.2lf\n", D);
        }
    }

    else
        printf("To symvolo pou epileksate einai lathos");

    return 0;
}
