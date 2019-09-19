// ******************************************************************************** //
//																					//
// Nom du fichier: chiffreDansUnNombre.c 											//				
//  																				//
// Date de création: 14 septembre 2018												//
//																					//
// Auteur: Nicolle Falbo															//
//																					//
// Le programme fait la liste des chiffres qui forment un nombre entier strictement //
// positif donnée par l'usageur, seprarés par "," et "et".							//
// 																					//
//																					//
// ******************************************************************************** //

#include <stdio.h>
#include <stdlib.h>

int main()
{

	int entree = 0;					//pour montrer dans le printf	  
	int nombre = 0;					//pour faire les calculs
	int base = 10;					 
	int i = 0;						//increment chaque fois que le nombre est divisé par 10 (trouve la puissance)
	int huit = 8;					//en utilisant le caractere 8 ASCII, il va effacer la 
									//dernière virgule
	char effacer = huit;			//sélectionne le caractère 8 de la table ASCII (backspace)
	int chiffre = 0;   			    //pour chaque chiffre dans le nombre
	int x = 0;						//le resultat de 10 à le exposant trouvé
	const int PUISSANCE = 10;

	while (entree <= 0)
	{
		printf("Entrez un nombre entier positif, s'il vous plaît. \n");
		scanf("%d", &entree);
	}

	nombre = entree;

	while (nombre >= PUISSANCE)		   //trouve la plus grande puissance de dix dans le nombre donnée par l'utilisateur
	{
		i++;
		nombre /= PUISSANCE;
		while (base <= nombre)
		{
			base *= PUISSANCE;
			x = base;			  //x = la plus grande puissance de dix dans le nombre donnée
		}
		
	}

	printf("Les chiffres qui forment %d sont ", entree);

	if ((entree > 0) && (entree < 10)) 		//si le nombre a un seul caractère
	{
		printf("%d. \n", entree);
	}
	else								    //sinon,
	{
		while (i > 0)
		{
			i--;
			chiffre = entree / x;			//chiffre = nombre donnée par l'utilisateur divisé par la plus grande puissance de dix
			printf("%d, ", chiffre);		//on print le résultat
			entree %= x;					//entree = le reste de la division efectuer 2 lignes avant
			x /= PUISSANCE;					//x est divisé par dix (1 exposant de moins) et on repete le boucle
		}
		printf("%c et %d.\n", effacer, chiffre = entree / x );   //le char efface la virgule et on print le dernier chiffre
	}
	
}