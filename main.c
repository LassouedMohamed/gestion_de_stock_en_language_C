#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include<conio.h>

#include "structure.h"
#include "menu.h"
#include "ajouter.h"
#include "suppression.h"
#include "affichage.h"
#include "vendreStat.h"

int main()
{
    int nbCat=0,nbType=0;
    Type TabType[20];
    Categorie TabCat[20];
    Produit Stock[100][50];
    int TabQte[50]={2,11,1,1};
    Categorie c1,c2,c3;
    c1.idCat=1;
    strcpy(c1.NomCat,"conserve");
    c2.idCat=2;
    strcpy(c2.NomCat,"Boisson");
    c3.idCat=3;
    strcpy(c3.NomCat,"Epice");
    TabCat[0]=c1;
    TabCat[1]=c2;
    TabCat[2]=c3;

    Type t1,t2,t3,t4;
    t1.idType=11;
    strcpy(t1.Nomtype,"tomate");
    t1.Cat=c1;

    t2.idType=12;
    strcpy(t2.Nomtype,"jus");
    t2.Cat=c2;

    t3.idType=10;
    strcpy(t3.Nomtype,"mais");
    t3.Cat=c1;

    t4.idType=45;
    strcpy(t4.Nomtype,"curcuma");
    t4.Cat=c3;
    nbCat=3;


    TabType[0]=t1;
    TabType[1]=t2;
    TabType[2]=t3;
    TabType[3]=t4;
    nbType=4;


    Produit p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16;

    p1.id=50;
    strcpy(p1.nom,"pdt1");
    p1.type=t1;
    p1.dateexp.jj=12;
    p1.dateexp.MM=12;
    p1.dateexp.AA=2021;

    p5.id=48;
    strcpy(p5.nom,"pdt5");
    p5.type=t1;
    p5.dateexp.jj=13;
    p5.dateexp.MM=12;
    p5.dateexp.AA=2020;

    p2.id=48;
    strcpy(p2.nom,"pdt2");
    p2.type=t2;
    p2.dateexp.jj=14;
    p2.dateexp.MM=11;
    p2.dateexp.AA=2022;

    p6.id=30;
    strcpy(p6.nom,"pdt6");
    p6.type=t2;
    p6.dateexp.jj=10;
    p6.dateexp.MM=11;
    p6.dateexp.AA=2021;

    p7.id=60;
    strcpy(p7.nom,"pdt7");
    p7.type=t2;
    p7.dateexp.jj=12;
    p7.dateexp.MM=12;
    p7.dateexp.AA=2021;

    p3.id=27;
    strcpy(p3.nom,"pdt3");
    p3.type=t3;
    p3.dateexp.jj=12;
    p3.dateexp.MM=12;
    p3.dateexp.AA=2021;

    p4.id=11;
    strcpy(p4.nom,"pdt4");
    p4.type=t4;
    p4.dateexp.jj=25;
    p4.dateexp.MM=10;
    p4.dateexp.AA=2021;


    p15.id=24;
    strcpy(p15.nom,"pdt15");
    p15.type=t2;
    p15.dateexp.jj=13;
    p15.dateexp.MM=12;
    p15.dateexp.AA=2021;

    p14.id=99;
    strcpy(p14.nom,"pdt14");
    p14.type=t2;
    p14.dateexp.jj=30;
    p14.dateexp.MM=12;
    p14.dateexp.AA=2021;

    p13.id=19;
    strcpy(p13.nom,"pdt13");
    p13.type=t2;
    p13.dateexp.jj=11;
    p13.dateexp.MM=12;
    p13.dateexp.AA=2021;

    p8.id=600;
    strcpy(p8.nom,"pdt8");
    p8.type=t2;
    p8.dateexp.jj=12;
    p8.dateexp.MM=12;
    p8.dateexp.AA=2021;

    p9.id=59;
    strcpy(p9.nom,"pdt9");
    p9.type=t2;
    p9.dateexp.jj=12;
    p9.dateexp.MM=12;
    p9.dateexp.AA=2021;

    p10.id=49;
    strcpy(p10.nom,"pdt10");
    p10.type=t2;
    p10.dateexp.jj=12;
    p10.dateexp.MM=12;
    p10.dateexp.AA=2021;

    p11.id=79;
    strcpy(p11.nom,"pdt11");
    p11.type=t2;
    p11.dateexp.jj=12;
    p11.dateexp.MM=12;
    p11.dateexp.AA=2021;

    p12.id=89;
    strcpy(p11.nom,"pdt12");
    p12.type=t2;
    p12.dateexp.jj=20;
    p12.dateexp.MM=10;
    p12.dateexp.AA=2021;

    p16.id=89;
    strcpy(p11.nom,"pdt16");
    p16.type=t2;
    p16.dateexp.jj=20;
    p16.dateexp.MM=10;
    p16.dateexp.AA=2021;





    Stock[0][0]=p1;
    Stock[0][1]=p5;

    Stock[1][0]=p2;
    Stock[1][1]=p15;
    Stock[1][2]=p7;
    Stock[1][3]=p8;
    Stock[1][4]=p9;
    Stock[1][5]=p10;
    Stock[1][6]=p11;
    Stock[1][7]=p12;
    Stock[1][8]=p14;
    Stock[1][9]=p13;
    Stock[1][10]=p16;

    Stock[2][0]=p3;

    Stock[3][0]=p4;




    afficherMenu(&nbCat, &nbType, Stock, TabType, TabCat, TabQte);


    //afficherStock(nbCat, nbType, Stock, TabType, TabCat, TabQte);
    // SupprimerCat(&nbCat,TabCat,nbType,TabType);
    //SupprimerPdt(TabQte,&nbType);
    //SupprimerTyp(TabType, &nbType, Stock, TabQte, t1);
    //AjouterPdt(Stock, TabType,TabQte,nbType);
    //AjouterCat(&nbCat,TabCat);
    //AjouterCat(&nbCat,TabCat);
    //AjouterCat(&nbCat,TabCat);
    //AjouterTyp(&nbType,nbCat,TabCat,TabType);

/*
    for(int i = 0; i<nbCat;i++){
            printf( "id: %d | nom: %s | position: %d \n",TabCat[i].idCat, TabCat[i].NomCat,i);
        }
*/

    return 0;
}
