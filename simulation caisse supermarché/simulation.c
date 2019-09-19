// ************************************************************************** //
// 																			  //
// Nom : queue.c 													  	   	  //
//  																		  //
// Auteur : Nicolle 														  //
//  																		  //
// Date : 31 octobre 2018 													  //
// 																			  //
// Implémenter une structure de données Queue qui suit le principe "premier   //
// arrivé, premier servi". 													  //
//																			  //
// Contient les fonctions pour la simulation et le main.					  //
//  																		  //
// ************************************************************************** //

#include "queue.h"
#include "simulation.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

double randExpo(double lambda)
{
    double u = rand() / (RAND_MAX + 1.0);
    return (-log(1 - u) / lambda) + 1;
}

int randomiserClient()
{
	const int MIN = 1;
    if ((rand() % PROB_CLIENT_MAX + PROB_CLIENT_MIN) == 1)
    	return 1;
    else 
    	return 0;
}

Statistiques initialiserStatistiques (Statistiques statistiques)
{
	statistiques.nombreClientsEntres = 0;
	statistiques.nombreDArticlesVendus = 0;
	statistiques.tempsDAttenteMoyen = 0;
	statistiques.tempsDAttenteMax = 0;
	statistiques.nombreDArticlesMax = 0;
	statistiques.nombreDArticlesMin = MOYEN_DARTICLES_PAR_CLIENT;
	return statistiques; 
}

void imprimerStatiques(Statistiques statistiques, int instant)
{
	printf("\n");
	printf("+-----------------------------------------+\n");
	printf("| Nombre de clients entrés  : %.4d        |\n", statistiques.nombreClientsEntres);
	printf("| Nombre d’articles vendus  : %.4d        |\n", statistiques.nombreDArticlesVendus);
	if (statistiques.nombreClientsEntres != 0) {
		printf("| Temps d’attente moyen     : %.4d cycles |\n", statistiques.tempsDAttenteMoyen / statistiques.nombreClientsEntres);
	}
	printf("| Temps d’attente maximum   : %.4d cycles |\n", statistiques.tempsDAttenteMax);
	printf("| Nombre d’articles maximum : %.4d        |\n", statistiques.nombreDArticlesMax);
	printf("| Nombre d’articles minimum : %.4d        |\n", statistiques.nombreDArticlesMin);
	if (statistiques.nombreClientsEntres != 0) {
		printf("| Nombre d’articles moyen   : %.4d        |\n", statistiques.nombreDArticlesVendus / statistiques.nombreClientsEntres);
	}
	printf("| Nombre de cycles          : %.4d        |\n", instant - 1);
	printf("+-----------------------------------------+\n");
}

void initialiserCaisses(Queue* queue)
{
	for (int i = 0; i < NOMBRE_CAISSE; i++)
	{
		queue[i].premier = NULL;
		queue[i].dernier = NULL;
	}
}

int encoreClientDansMarche(Queue* queue)
{
	for (int i = 0; i < NOMBRE_CAISSE; i++)
	{
		if (queue[i].premier != NULL)
			return 1;
	}
	return 0;
}

int queuePlusPetite(Queue* queue)
{
	int compteurQueueCaisses = 0;
	int mineureQueue = longueurQueue(queue[0]);
	int caissePlusPetit = 0;


	for (int i = 0; i < NOMBRE_CAISSE; i++)
	{
		compteurQueueCaisses = longueurQueue(queue[i]);
		if (compteurQueueCaisses < mineureQueue)
		{
			mineureQueue = compteurQueueCaisses;
			caissePlusPetit = i;
		}
	}
	return caissePlusPetit;
}

void ajouterClientQueue(Queue* queue, Statistiques* statistiques, int instant)
{
	if (randomiserClient() && instant < NOMBRE_DE_CYCLES)
	{
		Client* nouveau = creerClient(instant, randExpo(1.0/9));
		statistiques->nombreDArticlesVendus += nouveau->nbArticles;

		offrirClient(&queue[queuePlusPetite(queue)], nouveau);

		if (statistiques->nombreDArticlesMax < nouveau->nbArticles)
			statistiques->nombreDArticlesMax = nouveau->nbArticles;

		if (statistiques->nombreDArticlesMin > nouveau->nbArticles)
			statistiques->nombreDArticlesMin = nouveau->nbArticles;

		statistiques->nombreClientsEntres++;
	}
}

void gererCaisses(Queue* queue, Statistiques* statistiques, int instant)
{	
	for (int i = 0; i < NOMBRE_CAISSE; i++)
	{
		Client* client = coupDOeilTete(queue[i]);
		if (client != NULL)
		{
			client->nbArticles--;
			if (client->nbArticles == 0)
			{
				if(instant - client->instantArrivee > statistiques->tempsDAttenteMax)
				{
					statistiques->tempsDAttenteMax = instant - client->instantArrivee;
				}
				statistiques->tempsDAttenteMoyen += instant - client->instantArrivee;
				obtenirTete(&queue[i]);
				free(client);
			}
		}
		printf("Caisse %d: ", i + 1);   //incrementer la caisse (+1) pour que la premier caisse ne soit pas 0.
		imprimerQueue(queue[i]);
		printf("\n");
	}
}

// ************************************************************************** //

int main()
{
	srand(time(NULL));

	Queue caisses[NOMBRE_CAISSE];

	int instant = 1;
	int clientsAAttendre = 0;
	int articlesVendus = 0;
	Statistiques statistiques;
	statistiques = initialiserStatistiques(statistiques);

	initialiserCaisses(caisses);
	
	for (int i = 0; (i < NOMBRE_DE_CYCLES) || (encoreClientDansMarche(caisses) == 1); i++)
	{
		ajouterClientQueue(caisses, &statistiques, instant);
		gererCaisses(caisses, &statistiques, instant);
		printf("\n");
		usleep(SLEEP_TIME);
		instant++;
	}
		
	imprimerStatiques(statistiques, instant);	
}
