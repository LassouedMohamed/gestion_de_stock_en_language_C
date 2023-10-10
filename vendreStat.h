#ifndef VENDRESTAT_H_INCLUDED
#define VENDRESTAT_H_INCLUDED

/*

void statMois(){
    FILE* fichier = NULL;

    fichier = fopen("Trace.txt", "r");

    if (fichier != NULL)
    {
         while(!feof(FILE)){


        }
        fclose(fichier);
    }

}

void StatAnnee(){
    FILE* fichier = NULL;

    fichier = fopen("Trace.txt", "r");

    if (fichier != NULL)
    {

        while(!feof(FILE)){


        }
        fclose(fichier);
    }

}
*/
void vendrePDT(){
    FILE* fichier = NULL;

    fichier = fopen("Trace.txt", "a");

    if (fichier != NULL)
    {
        fputc('A', fichier);
        fclose(fichier);
    }else{
        printf("ERREUR");
    }

}





#endif // VENDRESTAT_H_INCLUDED
