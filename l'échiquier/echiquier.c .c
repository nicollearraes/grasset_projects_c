// ******************************************************************************** //
//																					//
// Nom du fichier: echiquier.c 					 									//				
//  																				//
// Date de création: 14 septembre 2018												//
//																					//
// Auteur: Nicolle Falbo															//
//																					//
// Le programme demande à l'utilisateur deux caractères ASCII et un entier, puis    //
// affiche un échiquier de la taille désirée.										//
// 																					//
//																					//
// ******************************************************************************** //

#include <stdio.h>
#include <stdlib.h>

int main()
{

	int entree = 0;			//la taille du carre  
	char char1;				//1er char entrée par l'utilisatuer
	char char2;				//2e char entrée par l'utilisateur
	int lignes = 0;
	int colonnes = 0;


	printf("Entrez un caractère, s'il vous plaît.\n");
	scanf(" %c", &char1);

	printf("Entrez un autre caractère, s'il vous plaît.\n");			//la validation de deux caratères differents est fait en validation.c
	scanf(" %c", &char2);

	while (entree <= 0)
	{
		printf("Entrez un nombre entier positif, s'il vous plaît.\n");
		scanf("%d", &entree);
	}

	for (lignes = 0; lignes < entree; lignes++)
	{
		for (colonnes = 0; colonnes < entree; colonnes++)
		{
			if ((lignes + colonnes) % 2 == 0)   			//si c'est pair, on print char1
			{
				printf("%c ", char1);
			}
			else											//si c'est impair, on print char2
			{
				printf("%c ", char2);
			}
		}
		printf("\n");
	}

}