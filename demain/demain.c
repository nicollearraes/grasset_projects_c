// **************************************************************************** //
// Nom : demain.c																//
//																				//
// Auteur : Nicolle																//
//																				//
// Date : 3 octobre 2018														//
//																				//
// Donner le lendemain d'une date entrée par l'utilisateur.						//
//																				//
//																				//
// Entrées Testées:																//
//																				//
// Input: 31/12/2012	 														//
// Output: Le lendemain de 31/12/2012 est 1/1/2013.								//
//																				//
// Input: 12/13/2014															//
// Output: La date 12/13/2014 n'est pas valide.		 							//
//																				//
// Input: 28/02/2016															//
// Output: Le lendemain de 28/2/2016 est 29/2/2016.								//
//																				//
// **************************************************************************** //

#include <stdio.h>


// **************************************************************************** //
// 						Structure pour la Date 									//
// **************************************************************************** //
typedef struct Date Date;
struct Date{
  int jour;
  int mois;
  int annee;
};


// **************************************************************************** //
// 				Fonction pour vérifier si l'année est bisextille				//
// **************************************************************************** //
int bisextile(int annee)
{ 
	Date date;
	date.annee = annee;
	if ((date.annee % 4) == 0)
	{
		if ((date.annee % 400) == 0)
			return 1;
		else if ((date.annee % 100) != 0)
			return 1;
		else 
			return 0;
	}
	else
		return 0;
}

// **************************************************************************** //
// 			Fonction pour vérifier le nombre de jours dans le mois 				//
// **************************************************************************** //
int nbJoursDansMois(int mois, int annee)
{
	Date date;
	date.annee = annee;
	date.mois = mois;

	int bisextille = bisextile(date.annee);
    
    enum Mois {FEVRIER = 2, AVRIL = 4, JUIN = 6, SEPTEMBRE = 9, NOVEMBRE = 11};
  
    switch (mois)
    {
    	case AVRIL:
    	case JUIN:
    	case SEPTEMBRE:
    	case NOVEMBRE:
    		return 30;
    	case FEVRIER:
    		if (bisextille == 1) 
    			return 29;
    		else
    			return 28;
    	default:
    		return 31;
    }
}


// **************************************************************************** //
// 					Fonction pour vérifier si date est valide 					//
// **************************************************************************** //
int estValide(Date date)
{
	Date validation;
	validation.annee = date.annee;
	validation.mois = date.mois;
	validation.jour = date.jour;

	if ((validation.mois < 1) ||(validation.mois > 12))
	{
		return 0;		//le mois n'est pas valide
	}

	int mois = nbJoursDansMois(validation.mois, validation.annee);
	//valider le nombre de jours et si est bisextile

	if ((validation.jour < 1) || (validation.jour > mois))
		return 0; 			//le jour ne peut pas être < 1, et le nombre de jours ne peut pas passer de le maximum de jours dans chaque mois
	else 
		return 1;
}


// **************************************************************************** //
// 					Fonction pour calculer da date du lendemain 				//
// **************************************************************************** //
Date demain(Date aujourdhui)
{
	int const UN = 1; 			//pour éviter 1 (nombre magique)

	Date demain;
	demain.annee = aujourdhui.annee;
	demain.mois = aujourdhui.mois;
	demain.jour = aujourdhui.jour;

	if (estValide(aujourdhui))
	{
		if (aujourdhui.jour == nbJoursDansMois(aujourdhui.mois, aujourdhui.annee))
		{
			if (aujourdhui.mois == 12)
			{
				aujourdhui.jour = UN;
				aujourdhui.mois = UN;
				aujourdhui.annee += UN;
				return aujourdhui;
			}
			else
			{
				aujourdhui.jour = UN;
				aujourdhui.mois += UN;
				//aujourdhui.annee;
				return aujourdhui;
			}
		}
		else
		{
			aujourdhui.jour += UN;
			//aujourdhui.mois;
			//aujourdhui.annee;
			return aujourdhui;
		}
	}
	else
	{
		return aujourdhui;
	}
}


// **************************************************************************** //
// 									MAIN 										//
// **************************************************************************** //
int main() {
	
	Date date;
	
	printf("Entrez une date (jj/mm/aaaa)\n");
	scanf("%d/%d/%d", &date.jour, &date.mois, &date.annee);
	
	Date lendemain = demain(date);

	if (estValide(lendemain))
		printf("Le lendemain de %d/%d/%d est %d/%d/%d.\n", date.jour, date.mois, date.annee, lendemain.jour, lendemain.mois, lendemain.annee);
	else
		printf("La date %d/%d/%d n'est pas valide.\n", date.jour, date.mois, date.annee);
}

