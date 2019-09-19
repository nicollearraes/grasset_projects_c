// **************************************************************************** //
// Nom : vraimentMagique.c 														//
//																				//
// Auteur : Nicolle																//
//																				//
// Date : 3 octobre 2018														//
//																				//
// La fonction reçoit une matrice et dit si elle est un carré magique, presque 	//
// magique ou pas magique.														//
//																				//
//																				//
// Entrées Testées:																//
//																				//
// Input: 4																		//
// Input: 4																		//
// Input: 8 8 8 8 	 															//
// 		  8 8 8 8	 															//
//		  8 8 8 8	 															//
//		  8 8 8 8																//
// Output: La matrice donnée est un carré presque magique. 						//
//																				//
// Input: 3 																	//
// Input: 3																		//
// Input: 4 9 2 																//
// 		  3 5 7																	//
//		  8 1 6																	//
// Output: La matrice donnée est un carré vraiment magique. 					//
//																				//
// Input: 2																		//
// Input: 2																		//
// Input: 0 1  																	//
//		  1 0																	//
// Output: La matrice donnée n'est pas magique. 								//
//																				//
// **************************************************************************** //

#include <stdio.h>
#include <stdlib.h>


int diagonalePrincipale (const int R, const int C, int matrice[R][C])
{													
	int sommePrincipale = 0;										// *	
																	//   *
	for (int i = 0; i < R; i++)										//     *
	{																//		 *					
		for (int j = 0; j < C; j++)									// 		   *
		{
			if (i == j)				
			sommePrincipale = sommePrincipale + matrice[i][j];			
		}
	}
	return sommePrincipale;
}


int diagonaleSecondaire (const int R, const int C, int matrice[R][C])
{													
	int sommeSecondaire = 0;											//         *
																		//       *
	int diagonaleMineure[R][C];											//     *
	for (int i = 0; i < R; i++)											//   *
		for (int j = 0; j < C; j++)										// *
			if (i + j == R - 1)
				sommeSecondaire = sommeSecondaire + matrice[i][j];

	return sommeSecondaire;
}


// Calculer et comparer la somme de la diagonale avec la somme de 
// chaque ligne. Retourne 1 si égal, 0 sinon.
int compareLignesEtDiagonale (const int R, const int C, int matrice[R][C], int sommePrincipale)
{

	int sommePrincipal = diagonalePrincipale(R, C, matrice);

	int sommeLigne = 0;
	int j = 0; 				
	int i = 0;				


	for (i = 0; i < R; i++)
	{
		sommeLigne = 0;
		for (j = 0; j < C; j++)
		{
			sommeLigne = sommeLigne + matrice[i][j];
		}
		if (sommeLigne != sommePrincipal)
			return 0;  		// retourne 0 si n'est pas égal
	}

	return 1; 				// retourne 1 si est égal
}


// Calculer et comparer la somme de la diagonale avec la somme de 
// chaque colonne. Retourne 1 si égal, 0 sinon.
int compareColonnesEtDiagonale (const int R, const int C, int matrice[R][C], int sommePrincipale)
{

	int sommePrincipal = diagonalePrincipale(R, C, matrice);

	int sommeColonne = 0;
	int j = 0; 				
	int i = 0;				


	for (i = 0; i < R; i++)
	{
		sommeColonne = 0;
		for (j = 0; j < C; j++)
			sommeColonne = sommeColonne + matrice[j][i];
		if (sommeColonne != sommePrincipal)
			return 0;				// retourne 0 si n'est pas égal
	}		

	return 1; 						// retourne 1 si est égal
}


int estPresqueMagique (const int R, const int C, int matrice[R][C])
{ 
	int sommePrincipale = diagonalePrincipale(R, C, matrice);
	int sommeSecondaire = diagonaleSecondaire(R, C, matrice);
	int sommeLignes = compareLignesEtDiagonale(R, C, matrice, sommePrincipale);
	int sommeColonnes = compareColonnesEtDiagonale(R, C, matrice, sommePrincipale);

	if (sommePrincipale == sommeSecondaire)
	{
		if (sommeLignes == 1)
		{
			if (sommeColonnes == 1)
				return 1;			//retourne 1 si presque magique
			else
				return 0;			//retourne 0 si n'est pas magique
		} 
		else 
			return 0;				//retourne 0 si n'est pas magique
	} 
	else 
		return 0;					//retourne 0 si n'est pas magique
}


int nombresDansMatrice(const int R, const int C, int matrice[R][C])
{
	int taille = R * C;

	//un carré vraiment magique ne peut pas avoir 0 ou des nombres négatifs
	if (matrice[R] <= 0 || matrice[C] <= 0)
		return 0;

 	//les nombres dans la matrice doit être entre 1 et taille
    
    int ordre[taille];
    int ordreTemp;
    int compteur = 0;

    for (int i = 0; i < R; i++)
    	for (int j = 0; j < C; j++)
    	{
    		ordre[compteur] = matrice[i][j];
    		compteur++;
    	}

    for (int i = 0; i < taille; ++i)
    {
    	for (int j = i + 1; j < taille; ++j)
    	{
    		if (ordre[i] > ordre[j])
    		{
    			ordreTemp = ordre[i];
    			ordre[i] = ordre[j];
    			ordre[j] = ordreTemp;
    		}
    	}
    		
    }

    for (int i = 0; i < taille - 1; i++)
    	if (ordre[i] == ordre[i + 1])
    		return 0;
    
    return 1;
}


// **************************************************************************** //
// 									MAIN										//
// **************************************************************************** //

int main() 
{
	
	int R;
	int C;
	

	printf("Entrez nombre de rangées du carré, svp: \n");
	scanf("%d", &R);

	printf("Entrez nombre de colonnes du carré, svp: \n");
	scanf("%d", &C);


	if (R != C)
	{
		printf("Erreur! \n");
		printf("Un carré doit avoir le même nombre de rangées et de colonnes! \n");
		exit(1); 
	}
	
	printf("Entrez les nombres pour le carré, svp.\n");
	printf("Entrez les nombres dans le format a b c \n");
	printf("				  d e f \n");
	printf("				  g h i \n");
	printf("etc. \n");
	int matrice[R][C];
	for (int i = 0; i < R; i++)					
	{
		for (int j = 0; j < C; j++)				
		{
			scanf("%d", &matrice[i][j]);
		}
	}

	
	int estMagique = estPresqueMagique(R, C, matrice);
	int nbDansMatrice = nombresDansMatrice(R, C, matrice);

	//Pour verifier si est vraiment magique, presque magique ou pas magique
	if (estMagique == 1)
	{
		if (nbDansMatrice == 1)
			printf("La matrice donnée est un carré vraiment magique. \n");
		else 
			printf("La matrice donnée est un carré presque magique. \n");
	}
	else
		printf("La matrice donnée n'est pas magique. \n");
	
}