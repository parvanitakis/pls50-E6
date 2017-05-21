//perimetros trigonometrikon shimaton

#include <stdio.h>
#include <math.h> //gia na ypologisoume ti riza ton tetragonon ton katheton plevron trigonou
#define PI 3.14159  //gia na ypologisoume tin perimetro kyklou

double perimetrosTetragonou (double m){     //sinartisi perimetrou tetragonou
    double ptet;
    ptet = 4.0 * m;
    return ptet;
}

double perimetrosParallilogrammou (double m, double p) {    //sinartisi perimetrou parallilogrammou
    double ppar;
    ppar = 2.0*(m+p);
    return ppar;
}

double perimetrosTrigonou (double m, double p) {
    double ptrig;
    ptrig = m+p+(sqrt(m*m + p*p)); //enallaktika mporoume na hrisimopoiisoume to pow, efoson ehoume eisagei ti math
    return ptrig;
    }

double perimetrosKyklou (double m) {
    double pkyk;
    pkyk = 2.0*PI*m;
    return pkyk;
    }

int main()
{
    int a=0;        //metavliti epilogis trigonometrikou shimatos
    double m, p, ptet, ppar, ptrig, pkyk;

    do {
        printf ("Ypologismos perimetrou trigonometrikou shimatos\n");
        printf ("Epilekste:\n");
        printf ("0 gia eksodo\n");
        printf ("1 gia tetragono\n");
        printf ("2 gia parallilogrammo\n");
        printf ("3 gia orthogonio trigono\n");
        printf ("4 gia kyklo\n");
        scanf ( "%d", &a);

        if (a==1) {
            printf ("eisagete to mikos plevras tou tetragonou\n");
            scanf ( "%lf", &m);

            if (m>0){
                ptet = perimetrosTetragonou (m);
                printf ("H perimetros tou tetragonou einai =%0.2lf\n", ptet);
            }
             else printf ("to mikos prepei na einai megalytero tou midenos\n");
        }

        else if (a==2) {
            printf ("eisagete to mikos kai to platos tou parallilogrammou\n");
            scanf ( "%lf %lf", &m, &p);

            if (m>0 && p>0){
                ppar = perimetrosParallilogrammou (m, p);
                printf ("H perimetros tou parallilogrammou einai =%0.2lf\n", ppar);
            }
            else printf ("to mikos kai to platos prepei na einai megalytera tou midenos\n");
        }

        else if (a==3) {
            printf ("eisagete to mikos ton dyo katheton plevron tou orthogoniou trigonou\n");
            scanf ( "%lf %lf", &m, &p);

            if (m>0 && p>0){
                ptrig = perimetrosTrigonou (m, p);
                printf ("H perimetros tou orthogoniou trigonou einai =%0.2lf\n", ptrig);
            }
            else printf("to mikos prepei na einai megalytero tou midenos\n");
        }

        else if (a==4) {
            printf ("eisagete to mikos tis aktinas tou kyklou\n");
            scanf ( "%lf", &m);

            if (m>0) {
                pkyk = perimetrosKyklou (m);
                printf ("H perimetros tou kyklou einai =%0.2lf\n", pkyk);
            }
            else printf ("To mikos aktinas prepei na einai megalytero tou midenos\n");
        }
        else printf("Parakalo epilekste enan arithmo metaksy toy 0 kai tou 4\n");

    }while (a!=0);

    return 0;
}
