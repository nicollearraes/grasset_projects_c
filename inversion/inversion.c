// ******************************************************************************** //
//																					//
// Nom du fichier: inversion.c 						 								//				
//  																				//
// Date de création: 14 septembre 2018												//
//																					//
// Auteur: Nicolle Falbo															//
//																					//
// Le programme demande à l'utilisateur un nombre entier, puis il inverse l'ordre 	//
// des chiffres dans le nombre.														//
//																					//
// ******************************************************************************** //

#include <stdio.h>
#include <stdlib.h>

int main()
{

	int entree = 0;					//pour montrer dans le printf	  
	int nombre = 0;					//pour faire les calculs
	int envers = 0;					//l'envers du nombre entrée
	int reste = 0;					//reste de la division pour DIVISEUR
	const int DIVISEUR = 10;		//constante 10 pour éviter les nombres magiques

	while (entree <= 0)
	{
		printf("Entrez un nombre entier positif, s'il vous plaît.\n");
		scanf("%d", &entree);
	}

	nombre = entree;

	do 
	{
		reste = nombre % DIVISEUR;				  //reste de la division du nombre entree pour DIVISEUR
												  //donne le dernier chiffre
		envers = envers * DIVISEUR + reste;  	  //multiplie l'envers (au debut 0) par DIVISEUR, puis ajoute 
										 		  //le reste du nombre divisé par 10
		nombre /= DIVISEUR;						  //on divise des int, alors, divisé par DIVISEUR(10) ira "effacer" le dernier chiffre
												  //comme ça, on peut boucler jusqu'au moment où il n'y aura plus de chhiffres
												  //(les chiffres sont 0 - les chiffres vont être tous après la virgule)
	} while (nombre > 0); 						  //on loop jusqu'au moment que les nombre soient zero
	printf("%d à l'envers est %d.\n", entree, envers);

 }
