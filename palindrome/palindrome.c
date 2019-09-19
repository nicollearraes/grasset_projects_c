// ************************************************************************** //
// 																			  //
// Nom : palindrome.c 													  	  //
//  																		  //
// Auteur : Nicolle 														  //
//  																		  //
// Date : 16 novembre 2018. 												  //
// 																			  //
// Fonction pour dire se un mot est ou non un palindrome. 					  //
//  																		  //
// ************************************************************************** //
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindrome (char* n, int longueur)
{
	if (longueur <= 1)
		return 1;
	if (n[0] != n[longueur - 1])
		return 0;
	return palindrome (n + 1, longueur - 2);
}


int main()
{
	char mot[255]; 
	int longueur;
	printf("Entrez un mot\n");
	fgets(mot, 255, stdin);
	mot[strlen(mot) - 1] = '\0';
	longueur = strlen(mot);

	printf("\n");
	
	printf("\n");
	if (palindrome(mot, longueur))
		printf("%s est un palyndrome.\n", mot);
	else
		printf("%s n'est pas un palyndrome.\n", mot);
	


}