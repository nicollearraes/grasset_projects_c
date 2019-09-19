// ******************************************************************************** //
//																					//
// Nom du fichier: profilage.c 														//
//  																				//
// Date de création: 14 septembre 2018												//
//																					//
// Auteur: Nicolle Falbo															//
//																					//
// Demander à l'utilisateur son année de naissance puis, après sa réponse, lui 		//
// dit s'il est un bébé, un enfant, un adolescent(e), un adulte, une personne 		//
// âgée, pas encore né, ou déjà mort(e).											//
//																					//
// ******************************************************************************** //

#include <stdio.h>
#include <stdlib.h>

int main()
{

	printf("Entrez votre année de naissance, s'il vous plaît.\n");

	int anneeNaissance = 0;
	scanf("%d", &anneeNaissance);
	
	if (anneeNaissance <= 2018)
	{
		if (anneeNaissance <= 1902)
		{
			printf("Desolé, vous êtes possiblement mort(e)! :| \n");
		}
		else if (anneeNaissance <= 1903 || anneeNaissance <= 1952)
		{
			printf("Vous êtes une personne âgée, profitez de la vie!\n");
		}
		else if (anneeNaissance <= 2000 || anneeNaissance <= 1953)
		{
			printf("Vous êtes un adulte. La vie est difficile!\n");
		}
		else if (anneeNaissance <= 2001 || anneeNaissance <= 2006)
		{
			printf("Vous êtes un adolescent(e)!\n");
		}
		else if (anneeNaissance <= 2007 || anneeNaissance <= 2015)
		{
			printf("Vous êtes un enfant!\n");
		}
		else if (anneeNaissance <= 2016 || anneeNaissance <= 2018)
		{
			printf("Vous êtes un beau/belle bébé!\n");
			//2018 c'est consideré comme un bébé, même si la personne n'est pas encore née!
		}
	}
	else 
	{
		printf("Vous venez du futur! Vous n'êtes pas encore né(e)! :)\n");	
	}

}