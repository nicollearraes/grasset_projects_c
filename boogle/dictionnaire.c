// ************************************************************************** //
//                                                                            //
// Nom du fichier: dictionnaire.c                                             //
//                                                                            //
// Date: 26 novembre 2018                                                     //
//                                                                            //
// Équipe: Adriano Galindo, Ana Urias et Nicolle Falbo                        //
//                                                                            //
// Desciption: contient les fonctions liées au dictionnaire pour le jeu de    //
// Boggle.                                                                    //
//                                                                            //
// ************************************************************************** //

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include "dictionnaire.h"
#include "boogle.h"

void lireFichier(char *filename, char** matriceDeDictionnaire, int* pTailleDictionnaire)
{
    FILE *file = fopen(filename, "r");
    int nblines = 0;
  
    if (file == NULL)
    {
        perror("fopen");
        exit(1);
    }

    char mot[BUFF];
    int compt = 0;
    while (fgets(mot, BUFF, file) != NULL) 
    {
        int l = strlen(mot);
        matriceDeDictionnaire[compt] = (char*)malloc(l * sizeof(char));
        mot[l - 1] = '\0';
        matriceDeDictionnaire[compt] = strcpy(matriceDeDictionnaire[compt], mot);
        *pTailleDictionnaire+=1;
        compt++;
    }
    
    fclose(file);
}


int motDansDictionnaireRechercheBinaryJava(char** matriceDeMotTapez, char** matriceDeDictionnaire, char* motAChercher, int nbMotTapez, int* pTailleDictionnaire)
{
    int gauche = 0;
    int droit = *pTailleDictionnaire - 1;
    while (gauche <= droit)
    {
        int index = (droit + gauche) / 2;
        if (strcmp(matriceDeDictionnaire[index], motAChercher) == 0) 
        {
            if (motEstDejaTapee(matriceDeMotTapez, motAChercher, nbMotTapez) == FAUX)
                return VRAI;
            else
                return FAUX;
        }    
        if (strcmp(matriceDeDictionnaire[index], motAChercher) > 0)
            droit = index - 1;
        else
            gauche = index + 1;
    }
    printf("----------Le mot n'est pas dans le dictionnaire----------\n");
    return FAUX;
}
