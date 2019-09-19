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
// Contient les fonctions pour le Client et la queue.						  //
//  																		  //
// ************************************************************************** //

#include "queue.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

Client* creerClient(int instant, int nbArticles)
{
	Client* nouveau = (Client*)malloc(sizeof(Client));
	nouveau->instantArrivee = instant;
	nouveau->nbArticles = nbArticles;
	nouveau->suivant = NULL;
	return nouveau;
}

void offrirClient(Queue* queue, Client* client)
{
	if (queue->premier != NULL)
	{
		Client* clientDernier;
		Client* clientTemporaire = queue->premier;
		while (clientTemporaire != NULL)
		{	
			clientDernier = clientTemporaire;
			clientTemporaire = clientDernier->suivant;
		}
		clientDernier->suivant = client;
	}
	else
		queue->premier = client;
}

Client* coupDOeilTete(Queue queue)
{
	if (queue.premier != NULL)
		return queue.premier;
	else
		return NULL;
}

Client* obtenirTete(Queue* queue)
{
	if (queue->premier != NULL)
	{	
		Client* premierClient = queue->premier;
		queue->premier = queue->premier->suivant;
		return premierClient;
	}
	else
		return NULL;
}

int longueurQueue(Queue queue)
{
	Client* c = queue.premier;
	int longueur = 0;
	while (c != NULL)
	{	
		c = c->suivant;
		longueur++;
	}
	return longueur;
}

void imprimerQueue(Queue queue)
{
	Client* c = queue.premier;
	while (c != NULL)
	{	
		printf("{%d, %d}", c->instantArrivee, c->nbArticles);
		c = c->suivant;
	}
}