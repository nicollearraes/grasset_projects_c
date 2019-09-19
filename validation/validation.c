// ******************************************************************************** //
//																					//
// Nom du fichier: validation.c 					 								//				
//  																				//
// Date de création: 14 septembre 2018												//
//																					//
// Auteur: Nicolle Falbo															//
//																					//
// Le programme demande à l'utilisateur deux caractères ASCII et un entier, puis    //
// affiche un échiquier de la taille désirée.										//
// Valide si les caractères entrées par l'utilisateur sont différents.				//
// Valide si les symboles choisis par l'utilisateur sont des caractères 			//
// d'impression (entre 32 et 127 - inclusivement - dans la table ASCII)				//
// Valide si le nombre entier entrée est entre 1 et 16 inclusivement.				//
//																					//
// ******************************************************************************** //

#include <stdio.h>
#include <stdlib.h>

int main()
{

	int entree = 0;				//la taille du carre  
	char char1 = 0;				//1er char entrée par l'utilisatuer
	char char2 = 0;				//2e char entrée par l'utilisateur
	int lignes = 0;
	int colonnes = 0;


	do
	{
		printf("Entrez un caractère, s'il vous plaît. \n");
		scanf(" %c", &char1);
	} while ((char1 < 32) || (char1 > 127));
	
	do 
	{
		printf("Entrez un autre caractère, s'il vous plaît. \n");
		scanf(" %c", &char2);
	} while ((char1 == char2) || ((char2 < 32) || (char2 > 127)));	

	while (entree < 1 || entree > 16)
	{
		printf("Entrez un nombre entier positif entre 1 et 16, s'il vous plaît.\n");
		scanf("%d", &entree);
	}

	for (lignes = 0; lignes < entree; lignes++)
	{
		for (colonnes = 0; colonnes < entree; colonnes++)
		{
			if ((lignes + colonnes) % 2 == 0)
			{
				printf("%c ", char1);
			}
			else
			{
				printf("%c ", char2);
			}
		}
		printf("\n");
	}

 }