// ************************************************************************** //
//                                                                            //
// Nom du fichier: boogle.c                                                   //
//                                                                            //
// Date: 26 novembre 2018                                                     //
//                                                                            //
// Équipe: Adriano Galindo, Ana Urias et Nicolle Falbo                        //
//                                                                            //
// Desciption: contient les fonctions liées au jeu de Boggle et le main pour  //
// le démarrer.                                                               //
//                                                                            //
// ************************************************************************** //

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include "boogle.h"
#include "dictionnaire.h"


// ************************************************************************** //
//          CONSTANTE POUR LES 16 DÉS DU JEU DE BOOGLE EN FRANÇAIS            //
// ************************************************************************** //
const char DES[R * C][NB_FACES] =
{{'E', 'T', 'U', 'K', 'N', 'O'},  // 0
 {'E', 'V', 'G', 'T', 'I', 'N'},  // 1
 {'D', 'E', 'C', 'A', 'M', 'P'},  // 2
 {'I', 'E', 'L', 'R', 'U', 'W'},  // 3
 {'E', 'H', 'I', 'F', 'S', 'E'},  // 4
 {'R', 'E', 'C', 'A', 'L', 'S'},  // 5
 {'E', 'N', 'T', 'D', 'O', 'S'},  // 6
 {'O', 'F', 'X', 'R', 'I', 'A'},  // 7
 {'N', 'A', 'V', 'E', 'D', 'Z'},  // 8
 {'E', 'I', 'O', 'A', 'T', 'A'},  // 9
 {'G', 'L', 'E', 'N', 'Y', 'U'},  // 10
 {'B', 'M', 'A', 'Q', 'J', 'O'},  // 11
 {'T', 'L', 'I', 'B', 'R', 'A'},  // 12
 {'S', 'P', 'U', 'L', 'T', 'E'},  // 13
 {'A', 'I', 'M', 'S', 'O', 'R'},  // 14
 {'E', 'N', 'H', 'R', 'I', 'S'}}; // 15


void shuffleDes(int nombreDesSortie[NB_DES])
{
    for (int i = 0; i < NB_DES; i++)
        nombreDesSortie[i] = i;
    for(int i = NB_DES - 1; i >= 0; i--)
    {
        int j = rand()%(i + 1);
        int temp = nombreDesSortie[j];
        nombreDesSortie[j] = nombreDesSortie[i];
        nombreDesSortie[i] = temp;
    }
}


void remplirGrille(char grille[R][C], int nombreDesSortie[NB_DES])
{
    shuffleDes(nombreDesSortie);
    int compt = 0;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            grille[i][j] = DES[nombreDesSortie[compt]][rand() % NB_FACES];
            compt++;
        }
}


void imprimerGrille(char grille[R][C])
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            printf("%c ", grille[i][j]);
        printf("\n");
    }
    printf("\n");
}


void initialiserNonVisitee(char grilleVisitee[R][C])
{
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            grilleVisitee[i][j] = NON_VISITE;
}


int formeMot(char grille[R][C], char* motAChercher, char grilleVisitee[R][C], int x, int y, int compt)
{


    if (motAChercher[compt] == '\n' || motAChercher[compt] == '\0')
        return VRAI;

    if (grille[x][y] != motAChercher[compt])
    	return FAUX;

    grilleVisitee[x][y] = VISITE;
    compt++;
    if (y + 1 < C && grilleVisitee[x][y + 1] == NON_VISITE && formeMot(grille, motAChercher, grilleVisitee, x, y + 1, compt))
        return VRAI;
    if (x + 1 < R && y + 1 < C  && grilleVisitee[x + 1][y + 1] == NON_VISITE && formeMot(grille, motAChercher, grilleVisitee, x + 1, y + 1, compt))
        return VRAI;
    if (x + 1 < R && grilleVisitee[x + 1][y] == NON_VISITE && formeMot(grille, motAChercher, grilleVisitee, x + 1, y, compt))
        return VRAI;
    if (x + 1 < R && y - 1 >= 0 && grilleVisitee[x + 1][y - 1] == NON_VISITE && formeMot(grille, motAChercher, grilleVisitee, x + 1, y - 1, compt))
        return VRAI;
    if (y - 1 >= 0 && grilleVisitee[x][y - 1] == NON_VISITE && formeMot(grille, motAChercher, grilleVisitee, x, y - 1, compt))
        return VRAI;
    if (x - 1 >= 0 && y - 1 >= 0 && grilleVisitee[x - 1][y - 1] == NON_VISITE && formeMot(grille, motAChercher, grilleVisitee, x - 1, y - 1, compt))
        return VRAI;
    if (x - 1 >= 0 && grilleVisitee[x - 1][y] == NON_VISITE && formeMot(grille, motAChercher, grilleVisitee, x - 1, y, compt))
        return VRAI;
    if (x - 1 >= 0 && y + 1 < C && grilleVisitee[x - 1][y + 1] == NON_VISITE && formeMot(grille, motAChercher, grilleVisitee, x - 1, y + 1, compt))
        return VRAI;
    grilleVisitee[x][y] = NON_VISITE;
    return FAUX;
}


int motDansGrille(char grille[R][C], char* motAChercher, char grilleVisitee[R][C], int compt)
{
    initialiserNonVisitee(grilleVisitee);
    for (int i = 0; i < R; i++) 
        for (int j = 0; j < C; j++) 
        {   
            grilleVisitee[i][j] = VISITE;
            if (formeMot(grille, motAChercher, grilleVisitee, i, j, compt))
                return VRAI;
            grilleVisitee[i][j] = NON_VISITE;
        }
    return FAUX;
}


int motEstDejaTapee(char** matriceDeMotTapez, char* motAChercher, int nbMotTapez)
{
	int ligneMotDansLeTableuDeMots = 0;
	while (matriceDeMotTapez[ligneMotDansLeTableuDeMots] != NULL)
    {
        if (ligneMotDansLeTableuDeMots != nbMotTapez && strcmp(matriceDeMotTapez[ligneMotDansLeTableuDeMots], motAChercher) == 0)
        {
            printf("----------Le mot est déjà tapé----------\n");
            return VRAI;
        }
        ligneMotDansLeTableuDeMots++;
    }
    return FAUX;
}


int scoreDuJeu(char** matriceDeMotTapez)
{   
    int s;
    int nombreTotalDePoints = 0;
    int ligneMotDansLeTableuDeMots = 0;
	while (strcmp(matriceDeMotTapez[ligneMotDansLeTableuDeMots], "quit") != 0)
    {
                    printf("%s, ", matriceDeMotTapez[ligneMotDansLeTableuDeMots]);
        s = strlen(matriceDeMotTapez[ligneMotDansLeTableuDeMots]);
        if (s >= 3)
            nombreTotalDePoints += s - 2;
        ligneMotDansLeTableuDeMots++;
    }
    printf("\n");
    return nombreTotalDePoints;
}


void augmenterLeTableuDeMot(char** matriceDeMotTapez, int* nbMotMaximum, int nbMotTapez)
{	
	*nbMotMaximum += BUFF;
    matriceDeMotTapez = (char**)realloc(matriceDeMotTapez, *nbMotMaximum * sizeof(char*));
}


void executeLeJeu(char** matriceDeDictionnaire, char** matriceDeMotTapez, char grille[R][C], char grilleVisitee[R][C], char* motAChercher, int nbMotTapez, int* nbMotMaximum, int* pTailleDictionnaire)
{
   while (strcmp(motAChercher, "quit\0") != 0)
    {
    	printf("S'il vous plaît, tapez un mot en Français et qui n'est pas déjà tapé: ");
        fgets(motAChercher,BUFF,stdin);
        if (nbMotTapez == *nbMotMaximum)
            augmenterLeTableuDeMot(matriceDeMotTapez, nbMotMaximum, nbMotTapez);
        int tailleMot = strlen(motAChercher);
        matriceDeMotTapez[nbMotTapez] = (char*)malloc(tailleMot * sizeof(char));
        motAChercher[tailleMot - 1] = '\0';
        strcpy(matriceDeMotTapez[nbMotTapez], motAChercher);
        if (strcmp(motAChercher, "quit\0") == 0)
	        printf("\n----------Merci d'avoir jouer----------\n\n");
        else if (motDansDictionnaireRechercheBinaryJava(matriceDeMotTapez, matriceDeDictionnaire, motAChercher, nbMotTapez, pTailleDictionnaire))
        {	
        	int compt = 0;
         	if (motDansGrille(grille, motAChercher, grilleVisitee, compt))
	            printf("----------Mot trouvé----------\n");
            else
            {    
                nbMotTapez--;
                printf("----------Mot n'existe pas dans la grille----------\n"); 
            }
            nbMotTapez++;
	    }  
    }
}


void imprimerMotsPossibles(char** matriceDeDictionnaire, char grilleVisitee[R][C], char grille[R][C])
{   
    int ligneMotDansDictionnaire = 0;
    while (matriceDeDictionnaire[ligneMotDansDictionnaire] != NULL)
    {   
        int compt = 0;
       	if (motDansGrille(grille, matriceDeDictionnaire[ligneMotDansDictionnaire], grilleVisitee, compt))
            printf("%s, ", matriceDeDictionnaire[ligneMotDansDictionnaire]);
        ligneMotDansDictionnaire++;
    }
    printf("\n");
}

// ************************************************************************** //

int main()
{   

    char** matriceDeMotTapez = (char**)calloc(NB_MOT_INITIAL, sizeof(char*));
    char** matriceDeDictionnaire = (char**)malloc(NB_MOT_MAX_DICTIONNAIRE * sizeof(char*));
    int tailleDictionnaire = 0;
    int* pTailleDictionnaire = &tailleDictionnaire;

    lireFichier(DICTIONNAIRE, matriceDeDictionnaire, pTailleDictionnaire);

    srand(time(NULL));
    int nombreDesSortie[NB_DES];
    int nbMotTapez = 0;
    int nbMotMaximum = NB_MOT_INITIAL;
    char grille[R][C], grilleVisitee[R][C], motAChercher[BUFF];

    printf("\nLe jeu de Boggle est un jeu de lettres dont le but est de trouver le plus de mots possibles formés par des dés sur un plateau.\n\n");
    printf("Dans la grille en bas, trouvez autant de mots que vous réussissez.\n");
    printf("Pour finir le jeu, tapez le mot 'quit'\n\n");
    remplirGrille(grille, nombreDesSortie);
    imprimerGrille(grille);
    executeLeJeu(matriceDeDictionnaire, matriceDeMotTapez, grille, grilleVisitee, motAChercher, nbMotTapez, &nbMotMaximum, pTailleDictionnaire);
    printf("Les mots possibles sont: ");
    imprimerMotsPossibles(matriceDeDictionnaire, grilleVisitee, grille);
    printf("Le Resultat total du jeu est: %d points\n\n", scoreDuJeu(matriceDeMotTapez));

    for (int i = 0; i < nbMotMaximum; ++i)
        free(matriceDeMotTapez[i]);
    
    for (int i = 0; i < *pTailleDictionnaire; i++)
        free(matriceDeDictionnaire[i]); 
    
    return 0; 
}