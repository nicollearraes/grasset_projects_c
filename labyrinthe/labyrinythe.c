// ************************************************************************** //
//                                                                            //
// Nom : labyrinthe.c                                                         //
//                                                                            //
// Auteur : Nicolle                                                           //
//                                                                            //
// Date : 30 novembre 2018.                                                   //
//                                                                            //
// Exercice de retour sur trace: déplacer une souris dans une labyrinthe.     //
//                                                                            //
// ************************************************************************** //

#include <stdio.h>
#include <stdlib.h>

#define TAILLE 8
#define DESSIN_MUR "███"
#define DESSIN_SOURIS " 🐭"
#define DESSIN_VIDE "   "
#define DESSIN_FROMAGE " 🧀"
#define DESSIN_MUR2 "██"


//*********************************************************
// int libre(int labyrinthe[TAILLE][TAILLE], int x, int y)
// Détermine s'il y a un mur dans la case (x,y) du labyrinthe
//
// INPUT :
//    labyrinthe : Une matrice dont la case i,j est 0
//      s'il est vide et 1 s'il y a un mur.
//    x, y : les coordonnées de la souris.
//
// OUTPUT : 
//    0 si la case x,y est libre, 1 sinon.
//*********************************************************
int libre(int labyrinthe[TAILLE][TAILLE], int x, int y)
{
  for (int i = 0; i < TAILLE; i++)
  {
    if (labyrinthe[x][i] || labyrinthe[i][y])
      return 0;
    for (int j = 0; j < TAILLE; j++)
      if (labyrinthe[i][j] && ((i + j == x + y) || (i - j == x - y)))
	     return 0;
  }
  return 1;
}

//*********************************************************
// void printLabyrinthe(int labyrinthe[TAILLE][TAILLE])
// Imprime le labyrinthe à la console.
//
// INPUT :
//    labyrinthe : Une matrice dont la case i,j est 0
//      s'il est vide et 1 s'il y a un mur, la taille pour
//		le fromage et 2 pour la souris.
//*********************************************************
void printLabyrinthe(int labyrinthe[TAILLE][TAILLE])
{
	printf("%s%s%s%s%s%s%s%s%s%s \n", DESSIN_MUR, DESSIN_MUR, DESSIN_MUR, DESSIN_MUR, DESSIN_MUR, DESSIN_MUR, DESSIN_MUR, DESSIN_MUR, DESSIN_MUR2, DESSIN_MUR2);
	for (int i = 0; i < TAILLE; i++)
	{
		printf("%s", DESSIN_MUR2 );
		for (int j = 0; j < TAILLE; j++)
		{
			if (i == TAILLE - 1 && j == TAILLE - 1)  // i == taille - 1 && j == taille - 1   labyrinthe[TAILLE - 1][TAILLE - 1] == TAILLE
				printf("%s", DESSIN_FROMAGE);
			else if (labyrinthe[i][j] == 2)
				printf("%s", DESSIN_SOURIS);
			else if (labyrinthe[i][j] == 0)
				printf("%s", DESSIN_VIDE);
			else if (labyrinthe[i][j] == 1)
				printf("%s", DESSIN_MUR);
		}
		printf("%s", DESSIN_MUR2 );
		printf("\n");
	}
	printf("%s%s%s%s%s%s%s%s%s%s \n", DESSIN_MUR, DESSIN_MUR, DESSIN_MUR, DESSIN_MUR, DESSIN_MUR, DESSIN_MUR, DESSIN_MUR, DESSIN_MUR, DESSIN_MUR2, DESSIN_MUR2);
}

//*********************************************************
// int chemin(int echiquier[TAILLE][TAILLE], int x, int y)
// Détermine le chemin que la souris va faire pour se déplacer
// dans le labyrinthe.
//
// INPUT :
//    labyrinthe : Une matrice dont la case i,j est 0
//      s'il est vide et 1 s'il y a un mur.
//    x, y : les coordonnées de la souris.
//
// OUTPUT : 
//    1 s'il y a un mur
//    0 si le chemin est libre
//    2 pour montrer le chemin de la souris
//*********************************************************
int chemin(int labyrinthe[TAILLE][TAILLE], int x, int y)
{

	//0 = libre
	//1 = mur
	//2 = souris

	printLabyrinthe(labyrinthe);
	labyrinthe[x][y] = 2;
	if (x == TAILLE - 1 && y == TAILLE - 1)
	{
		//printLabyrinthe(labyrinthe);
		return 1;
	}

	//----------------------------------------------------//
	
	//à droite
	if (y + 1 < TAILLE && labyrinthe[x][y + 1] == 0)   // 0 = pas de mur, pas de souris
		if (chemin(labyrinthe, x, y + 1) == 1)         // 1 = il existe un chemin 
			return 1;

	//----------------------------------------------------//

	//à gauche
	if (y - 1 >= 0 && labyrinthe[x][y - 1] == 0)  
		if (chemin(labyrinthe, x, y - 1) == 1)
			return 1;

	//----------------------------------------------------//

	//à haut
	if (x + 1 < TAILLE && labyrinthe[x + 1][y] == 0)  
		if (chemin(labyrinthe, x + 1, y) == 1)
			return 1;

	//----------------------------------------------------//

	//au bas
	if (x - 1 >= 0 && labyrinthe[x - 1][y] == 0)  
		if (chemin(labyrinthe, x - 1, y) == 1)
			return 1;

	//autres coordonées des voisines
	labyrinthe[x][y] = 0;
		return 0;

}

  
//*********************************************************
// Pilote pour le problème de la souris dans de labyrinthe.
//*********************************************************
int main()
{
  int labyrinthe[][TAILLE] = {{0, 0, 1, 0, 0, 0, 0, 0},
                          	  {0, 1, 1, 0, 1, 1, 1, 0},
                          	  {0, 0, 0, 0, 1, 0, 0, 0},
                          	  {0, 1, 1, 0, 1, 0, 1, 0},
                          	  {1, 1, 1, 0, 1, 0, 1, 1},
                          	  {0, 0, 0, 0, 1, 0, 1, 0},
                          	  {1, 1, 1, 0, 1, 0, 1, 0},
                          	  {1, 0, 0, 0, 1, 0, 0, 0}};

  printf("\n");
  chemin(labyrinthe, 0, 0);
  //printLabyrinthe(labyrinthe);
  printf("\n"); 
}
