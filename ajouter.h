#ifndef AJOUTER_H_INCLUDED
#define AJOUTER_H_INCLUDED

bool chercherCateg(int nbCat, Categorie TabCat[20], Categorie c){
    for(int i=0;i<nbCat;i++){
            if(strcmp(TabCat[i].NomCat,c.NomCat) == 0 || TabCat[i].idCat == c.idCat){
                return true;
            }
    }
     return  false;

}

void AjouterCat(int *nbCat,Categorie TabCat[20]){
    if(*nbCat>=20){
        //130 = é
        printf("impossible d'ajouter une categorie, espace satur%c \n",130);
    }else{
        Categorie c;
        InitCat(&c);
        bool existe =chercherCateg(*nbCat,TabCat,c);

        if(existe){
            // 133 =à
            //130 = é
            printf( "La cat%cgorie existe d%cj%c! \n",130,130,133);
            while(existe){
                InitCat(&c);
                existe =chercherCateg(*nbCat,TabCat,c);
            }

        }else{
            TabCat[*nbCat].idCat = c.idCat;
            strcpy(TabCat[*nbCat].NomCat, c.NomCat);
            printf("ajout%c avec succ%cs \n",130,138);
            *nbCat=*nbCat+1;
        }
    }
}

bool chercherTyp(int nbType,int nbCat, Categorie TabCat[20],Type TAbType[20],Type t){
    for(int i=0;i<nbType;i++){
        if(strcmp(TAbType[i].Nomtype,t.Nomtype) == 0 && TAbType[i].idType == t.idType){
            return true;
        }
    }
    return false;
}

void AjouterTyp(int *nbType,int *nbCat, Categorie TabCat[20],Type TAbType[20]){

    if(*nbType >=50){
        //130 = é
        printf("impossible d'ajouter un type, espace satur%c \n",130);
    }else{
        printf( "choisissez parmi ces cat%cgories : \n",130);
        for(int i = 0; i<*nbCat;i++){
            printf( "id: %d | nom: %s \n",TabCat[i].idCat, TabCat[i].NomCat);
        }
        Type t;
        InitType(&t);
        bool existe=chercherTyp(*nbType,*nbCat,TabCat,TAbType,t);
        if(existe){
            // 133 =à
            //130 = é
            printf( "Le type existe d%cj%c! \n",130,130,133);
        }else{
            bool existeCat=false;
            for(int j=0;j<*nbCat;j++){
                if(strcmp(TabCat[j].NomCat,t.Cat.NomCat) == 0 && TabCat[j].idCat == t.Cat.idCat){
                existeCat = true;
                break;
                }
            }
            if(existeCat){
                TAbType[*nbType].idType = t.idType;
                strcpy(TAbType[*nbType].Nomtype, t.Nomtype);
                TAbType[*nbType].Cat.idCat =t.Cat.idCat;
                strcpy(TAbType[*nbType].Cat.NomCat, t.Cat.NomCat);
                printf("ajout%c avec succ%cs \n",130,138);

                *nbType=*nbType+1;
            }else{
                printf("La cat%cgorie n'existe pas \n",130);
                while(existe){
                    printf("-----------------------------------\n");
                    printf( "choisissez parmi ces cat%cgories : \n",130);
                    for(int i = 0; i<*nbCat;i++){
                        printf( "id: %d | nom: %s \n",TabCat[i].idCat, TabCat[i].NomCat);
                    }
                    Type t;
                    InitType(&t);
                    existe=chercherTyp(*nbType,*nbCat,TabCat,TAbType,t);
                    }
            }

        }
    }
}

void AjouterPdt(Produit Stock[100][50], Type TabType[20], int TabQte[50], int *nbType){
    Produit p;
    for (int i=0; i<*nbType; i++){
        printf("id type :%d | nomtype : %s |id categorie : %d | nom categorie : %s \n",TabType[i].idType,TabType[i].Nomtype,TabType[i].Cat.idCat,TabType[i].Cat.NomCat);
    }
    InitPdt(&p);
    bool existeType =false;
    // verifier l'existance de type
    int position;
    for(int i=0;i<*nbType;i++){
        if(
           (strcmp(TabType[i].Nomtype,p.type.Nomtype) == 0 )&&
            (TabType[i].idType == p.type.idType)){
            existeType = true;
            position=i;
            break;
        }
    }
    if(existeType ==true){
        bool existeProduit =false;
        //verifier l'existance de produit
        for(int c=0; c<TabQte[position];c++){
            if(
               Stock[position][c].id == p.id &&
                strcmp(Stock[position][c].nom,p.nom)==0 &&
                Stock[position][c].dateexp.AA==p.dateexp.AA &&
                 Stock[position][c].dateexp.jj==p.dateexp.jj &&
                 Stock[position][c].dateexp.MM==p.dateexp.MM ){
                existeProduit=true;
                break;
            }
        }
        if(existeProduit==false){
            int ind=TabQte[position];
            Stock[position][ind]=p;
            TabQte[position]++;
        }else{
            printf("Le produit existe \n");
        }
    }else{
        printf("Veuillez creer le type d'abord !\n");
    }
}

#endif // AJOUTER_H_INCLUDED
