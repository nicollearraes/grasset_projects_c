// ******************************************************************************** //
//																					//
// Nom du fichier: plusGrandePuissanceDe10.c 										//				
//  																				//
// Date de création: 14 septembre 2018												//
//																					//
// Auteur: Nicolle Falbo															//
//																					//
// Donner à l'utilisateur la plus grande puissance de 10 qui entre dans le nombre   //
// entier strictement positif donnée par lui.										//
// 																					//
//																					//
// ******************************************************************************** //

#include <stdio.h>
#include <stdlib.h>

int main()
{

	int entree = 0;   	 		//pour montrer dans le printf
	int nombre = 0;	  			//pour faire les calculs
	int i = 0;		  	 		//increment chaque fois que le nombre est divisé par 10 (trouve la puissance)				  
	int base = 10;		 		//la base pour faire les calculs et montrer le resultat
	int e = 1; 					//pour les nombres plus petits que 10
	const int PUISSANCE = 10;  	//pour tous les 10 (nombre magique)

	while (entree <= 0)
	{
		printf("Entrez un nombre entier positif, s'il vous plaît.\n");
		scanf("%d", &entree);
	}

	nombre = entree;

	if (nombre < PUISSANCE)
	{
		base = e;
	}

	while (nombre >= PUISSANCE)
	{
		i++;
		nombre /= PUISSANCE;
		while (base <= nombre)
		{
			base *= PUISSANCE;
		}
	}

	printf("La plus gros puissance de 10 dans %d est 10^%d = %d. \n", entree, i, base);
	
}