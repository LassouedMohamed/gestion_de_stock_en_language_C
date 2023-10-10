#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void resetColor() {
  printf("\033[0m");
}

void afficherMenu(int *nbCat, int *nbType, Produit Stock[100][50], Type TabType[], Categorie TabCat[], int TabQte[])
{
    int choixafficherMenu;
    do{
    printf("**********************************************************\n");
    printf("**********\t\tBIENVENU\t\t**********\n");
    printf("**********************************************************\n");
    printf("* veuillez choisir une option : \t\t\t *\n");
    printf("* 0-quittez le programme \t\t\t\t *\n");
    printf("* 1-Gestion de stock \t\t\t\t\t *\n");
    printf("* 2-Vente et Statistiques \t\t\t\t *\n");
    do{
    printf("* >>tapez votre choix : \t\t\t\t *");
    scanf("%d",&choixafficherMenu);
    }while(choixafficherMenu<0||choixafficherMenu>2);
    if (choixafficherMenu==1){
        afficherMenuGestionStock(nbCat, nbType, Stock, TabType, TabCat, TabQte);
    }
    if (choixafficherMenu==2){
        afficherMenuVenteStat(nbCat, nbType, Stock, TabType, TabCat, TabQte);
    }

    }while(choixafficherMenu !=0);
    system("CLS");
    printf("\033[0;31m");
    printf("LE PROGRAMME EST FERME");
    resetColor();
}


void afficherMenuGestionStock(int nbCat, int nbType, Produit Stock[100][50], Type TabType[], Categorie TabCat[], int TabQte[]){
    int choixafficherMenuGestionStock;
    do{
    printf("**********************************************************\n");
    printf("**********\t\tBIENVENU\t\t**********\n");
    printf("**********************************************************\n");
    printf("* veuillez choisir une option : \t\t\t *\n");
    printf("* 0-Menu Principal \t\t\t\t\t *\n");
    printf("* 1 Gestion de Categories \t\t\t\t\t *\n");
    printf("* 2 Gestion des types \t\t\t\t\t *\n");
    printf("* 3 Gestion des produits \t\t\t\t *\n");
    printf("* 4 Affichage du stock \t\t\t\t *\n");

    do{
    printf("* >>tapez votre choix : \t\t\t\t *");
    scanf("%d",&choixafficherMenuGestionStock);
    }while(choixafficherMenuGestionStock<0||choixafficherMenuGestionStock>4);
    if (choixafficherMenuGestionStock==0)
    {
        afficherMenu(nbCat, nbType, Stock, TabType, TabCat, TabQte);
    }
    if (choixafficherMenuGestionStock==1){
        afficherMenuGestionCat(nbCat, nbType, Stock, TabType, TabCat, TabQte);
    }
    if(choixafficherMenuGestionStock==2){
        afficherMenuGestionType(nbCat, nbType, Stock, TabType, TabCat, TabQte);
    }
    if(choixafficherMenuGestionStock==3){
        afficherMenuGestionProduit(nbCat, nbType, Stock, TabType, TabCat, TabQte);
    }
    if(choixafficherMenuGestionStock==4){
        afficherStock(nbCat, nbType, Stock, TabType, TabCat, TabQte);
    }


    }while(choixafficherMenuGestionStock !=0);
}



void afficherMenuGestionCat(int nbCat, int nbType, Produit Stock[100][50], Type TabType[], Categorie TabCat[], int TabQte[]){
    int choixafficherMenuGestionCat;
    do{
    printf("**********************************************************\n");
    printf("**********\t\tBIENVENU\t\t**********\n");
    printf("**********************************************************\n");
    printf("* veuillez choisir une option : \t\t\t *\n");
    printf("* 0-Menu Principal \t\t\t\t\t *\n");
    printf("* 1 Gestion des Categories \t\t\t\t\t *\n");
    printf("* 2 Suppression d'une Categories \t\t\t *\n");
    do{
    printf("* >>tapez votre choix : \t\t\t\t *");
    scanf("%d",&choixafficherMenuGestionCat);
    }while(choixafficherMenuGestionCat<0 || choixafficherMenuGestionCat>2);
    if (choixafficherMenuGestionCat==0)
    {

        afficherMenu(nbCat, nbType, Stock, TabType, TabCat, TabQte);
    }
    if(choixafficherMenuGestionCat==1){
        AjouterCat(nbCat,TabCat);
    }

    if(choixafficherMenuGestionCat==2){
        SupprimerCat(nbCat, TabCat, nbType, TabType);
    }

    }while(choixafficherMenuGestionCat != 0);
}



void afficherMenuGestionType(int nbCat, int nbType, Produit Stock[100][50], Type TabType[], Categorie TabCat[], int TabQte[]){
    int choixafficherMenuGestionType;

    do{
        printf("**********************************************************\n");
        printf("**********\t\tBIENVENU\t\t**********\n");
        printf("**********************************************************\n");
        printf("* veuillez choisir une option : \t\t\t *\n");
        printf("* 0-Menu Principal \t\t\t\t\t *\n");
        printf("* 1-Gestion de stock \t\t\t\t\t *\n");
        printf("* 2 Gestion des types \t\t\t\t *\n");
        printf("* 1 Ajout d'un nouveau Type \t\t\t\t\t *\n");
        printf("* 2 Suppression d'un Type \t\t\t\t\t *\n");
        do{
            printf("* >>tapez votre choix : \t\t\t\t *");
            scanf("%d",&choixafficherMenuGestionType);
        }while(choixafficherMenuGestionType<0||choixafficherMenuGestionType>2);
        if (choixafficherMenuGestionType==0){
            afficherMenu(nbCat, nbType, Stock, TabType, TabCat, TabQte);
        }
        if (choixafficherMenuGestionType==1){
            AjouterTyp(nbType,nbCat, TabCat,TabType);
        }
        if (choixafficherMenuGestionType==2){
            SupprimerTyp(TabType, nbType, Stock, TabQte);
    }
    }while(choixafficherMenuGestionType !=0);
}



void afficherMenuGestionProduit(int nbCat, int nbType, Produit Stock[100][50], Type TabType[], Categorie TabCat[], int TabQte[]){

    int choixafficherMenuGestionProduit;
    do{
        printf("**********************************************************\n");
        printf("**********\t\tBIENVENU\t\t**********\n");
        printf("**********************************************************\n");
        printf("* veuillez choisir une option : \t\t\t *\n");
        printf("* 0-Menu Principal \t\t\t\t\t *\n");
        printf("* 1 Ajout d'un nouveau Produit \t\t\t\t\t *\n");
        printf("* 2 Suppression dn Produit \t\t\t\t\t *\n");
        do{
            printf("* >>tapez votre choix : \t\t\t\t *");
            scanf("%d",&choixafficherMenuGestionProduit);
        }while(choixafficherMenuGestionProduit<0||choixafficherMenuGestionProduit>2);
        if (choixafficherMenuGestionProduit==0){
            afficherMenu(nbCat, nbType, Stock, TabType, TabCat, TabQte);
        }
        if (choixafficherMenuGestionProduit==1){
            AjouterPdt(Stock, TabType, TabQte, nbType);
        }
        if (choixafficherMenuGestionProduit ==2){
            SupprimerPdt(TabQte,nbType,Stock);
        }

    }while(choixafficherMenuGestionProduit !=0);
}



void afficherMenuVenteStat(int nbCat, int nbType, Produit Stock[100][50], Type TabType[], Categorie TabCat[], int TabQte[]){
    int choixafficherMenuVenteStat;
    do{
        printf("**********************************************************\n");
        printf("**********\t\tBIENVENU\t\t**********\n");
        printf("**********************************************************\n");
        printf("* veuillez choisir une option : \t\t\t *\n");
        printf("* 0 Menu Principal \t\t\t\t\t *\n");
        printf("* 2 Vente et Statistiques \t\t\t\t *\n");
        printf("* 1 Vente de produits \t\t\t\t *\n");
        printf("* 2 Statistique \t\t\t\t *\n");
        do{
            printf("* >>tapez votre choix : \t\t\t\t *");
            scanf("%d",&choixafficherMenuVenteStat);
        }while(choixafficherMenuVenteStat<0||choixafficherMenuVenteStat>2);

        if (choixafficherMenuVenteStat==0){
            afficherMenu(nbCat, nbType, Stock, TabType, TabCat, TabQte);
        }
        if (choixafficherMenuVenteStat==2){
            afficherMenuStat(nbCat, nbType, Stock, TabType, TabCat, TabQte);
        }

    }while(choixafficherMenuVenteStat !=0);
}



void afficherMenuStat(int nbCat, int nbType, Produit Stock[100][50], Type TabType[], Categorie TabCat[], int TabQte[]){
    int choixafficherMenuS;
    do{
        printf("**********************************************************\n");
        printf("**********\t\tBIENVENU\t\t**********\n");
        printf("**********************************************************\n");
        printf("* veuillez choisir une option : \t\t\t *\n");
        printf("* 0 Menu Principal \t\t\t\t\t *\n");
        printf("* 1 Statistique par mois \t\t\t\t\t *\n");
        printf("* 2 Statistique par annees \t\t\t\t\t *\n");
        do{
            printf("* >>tapez votre choix : \t\t\t\t");
            scanf("%d",&choixafficherMenuS);
        }while(choixafficherMenuS<0||choixafficherMenuS>2);

        if(choixafficherMenuS==0){
            afficherMenu(nbCat, nbType, Stock, TabType, TabCat, TabQte);
        }

    }while(choixafficherMenuS !=0);
}



#endif // MENU_H_INCLUDED
