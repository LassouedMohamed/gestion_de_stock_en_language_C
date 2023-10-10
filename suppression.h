#ifndef SUPPRESSION_H_INCLUDED
#define SUPPRESSION_H_INCLUDED

void SupprimerCat(int *nbCat,Categorie TabCat[20], int *nbType, Type TabType[20]){
    if(*nbCat ==0)
        printf("impossible de supprimer une categorie,table est vide");
    else{

        int position;
        printf( "choisissez parmi ces cat%cgories : \n",130);
        for(int i = 0; i<*nbCat;i++){
            printf( "id: %d | nom: %s | position: %d \n",TabCat[i].idCat, TabCat[i].NomCat,i);
        }
        do{
        printf("choisir position pour supprimer la categorie: ");
        scanf("%d",&position);
        }while(position<0 || position>=*nbCat);

        if(*nbType==0){
            for (int j = position; j < *nbCat; j++)
                TabCat[j] = TabCat[j+1];
            *nbCat=*nbCat-1;
            printf("Suppression avec succes\n");
        }else{
            bool existe =false;
            // le tableau TabType ne contient des types dont la catégorie est C
            for(int l=0;l<*nbType;l++){
                if(strcmp(TabType[l].Cat.NomCat,TabCat[position].NomCat) == 0 && TabType[l].Cat.idCat == TabCat[position].idCat){
                    existe = true;
                    break;
                }
            }
            if(existe)
                printf("le tableau TabType contient des types dont la catégorie est %s et id %d",TabCat[position].NomCat,TabCat[position].idCat);
            else{
                    for (int j = position; j < *nbCat; j++)
                        TabCat[j] = TabCat[j+1];
                *nbCat=*nbCat-1;
                printf("Suppression avec succes\n");
            }
        }
    }
}



bool chercherType(Produit Stock[100][50], int nbType, int TabQte[], Type t){
    for(int i=0;i<nbType;i++){
        for(int j=0;j<TabQte[i];j++){
            if( (Stock[i][j].type.idType == t.idType) && (strcmp(Stock[i][j].type.Nomtype,t.Nomtype)==0)&&(Stock[i][j].type.Cat.idCat== t.Cat.idCat)&&(strcmp(Stock[i][j].type.Cat.NomCat,t.Cat.NomCat)==0))
                return true;
        }
    }
    return false;
}

void SupprimerTyp(Type TabType[20], int *nbType, Produit Stock[100][50], int TabQte[]){
    if(*nbType==0){
        printf("TabType est vide");
    }else{
        int position;
        for(int i=0;i<*nbType;i++){
            printf("id : %d | nom : %s | position : %d \n",TabType[i].idType,TabType[i].Nomtype,i);
        }
        do{
            printf("choisir position pour supprimer la categorie: ");
            scanf("%d",&position);
        }while(position<0 || position>=*nbType);
        bool v = chercherType(Stock,*nbType,TabQte,TabType[position]);
        if(v){
           printf("la matrice Stock ne contient  pas des produits dont le type est %s, la suppression ne peut pas  etre effectue\n",TabType[position].Nomtype);
        }else{
            for (int k = position; k < *nbType; k++)
            TabType[k] = TabType[k+1];
            *nbType=*nbType-1;
            printf("Suppression avec succes\n");
        }
    }
}



bool verifQte(int TabQte[50],int l){
    return TabQte[l]>10;
}

void SupprimerPdt(int TabQte[50], int *nbType, Produit Stock[100][50]){
    bool v=false;
    for(int i=0;i<*nbType;i++){
        if(TabQte[i]>10){
                v= true;
            for(int j=0;j<TabQte[i];j++){
                printf("id : %d | nom : %s | Ligne :%d | Colonne : %d \n",Stock[i][j].id,Stock[i][j].nom, i,j);
            }
        }
    }
    if(v==false){
        printf("Il n'y a pas des produits du Type correspondant ont des quantites superieur a 10\n");
    }else{
        int l,c;
        do{
        printf("entrer Ligne :");
        scanf("%d",&l);
        }while(verifQte(TabQte,l)==false);
        printf("entrer colonne:");
        scanf("%d",&c);
        for(int k=c;k<50;k++)
            Stock[l][k]=Stock[l][k+1];
        *nbType=*nbType-1;
        TabQte[l]--;
        printf("Suppression avec succes\n");
    }
}
#endif // SUPPRESSION_H_INCLUDED
