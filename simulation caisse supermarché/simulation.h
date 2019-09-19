// ************************************************************************** //
// 																			  //
// Nom : simulation.h												  	   	  //
//  																		  //
// Auteur : Nicolle 														  //
//  																		  //
// Date : 31 octobre 2018 													  //
// 																			  //
// ************************************************************************** //

#pragma once

#define NOMBRE_CAISSE 4
#define MOYEN_DARTICLES_PAR_CLIENT 11
#define PROB_CLIENT_MAX 3
#define PROB_CLIENT_MIN 1
#define NOMBRE_DE_CYCLES 200
#define SLEEP_TIME 1000


// ************************************************************************** //
//                        Structure: Statistiques                             //
// ************************************************************************** //
typedef struct Statistiques Statistiques;
struct Statistiques{
	int nombreClientsEntres;
	int nombreDArticlesVendus;
	int tempsDAttenteMoyen;
	int tempsDAttenteMax;
	int nombreDArticlesMax;
	int nombreDArticlesMin;
}; 

// ************************************************************************** //
// randExpo                                                                   //
//                                                                            //
// Retourne un nombre naturel au hasard, selon la distribution exponentielle  //
// d'espérance 1/lambda.			                                          //
//                                                                            //
//                                                                            //
// INPUT:                                                                     //
//      lambda.					                                              //
//                                                                            //
// OUTPUT:                                                                    //
//       un nombre de type double tirée au hasard.      				      //
//                                                                            //
// ************************************************************************** //
double randExpo(double lambda);

// ************************************************************************** //
// randomiserClient                                                           //
//                                                                            //
// Fonction pour tirér un nombre entre PROB_CLIENT_MIN et PROB_CLIENT_MAX au  //
// hasard. Si le nombre tiré est égal a 1, on ajoute un nouveau client à la   //
// fin de la queue.															  //
//                                                                            //
//                                                                            //
// INPUT:                                                                     //
//      -					                                              	  //
//                                                                            //
// OUTPUT:                                                                    //
//       retourne 1 si on ajoute un nouveau client à la fin de la queue, 0    //
//        sinon. 															  //
//                                                                            //
// ************************************************************************** //
int randomiserClient();

// ************************************************************************** //
// initialiserStatistiques                                                    //
//                                                                            //
// Fonction pour initialiser les statistiques à zero, sauf la variable	  	  //
// statistiques.nombreDArticlesMin qui est initialisée à la globale 		  //
// MOYEN_DARTICLES_PAR_CLIENT. 											      //
//                                                                            //
//                                                                            //
// INPUT:                                                                     //
//      les variables dans la structure statistique. 						  //
//                                                                            //
// OUTPUT:                                                                    //
//       les variables dans la structure statistique initialisés à zero.	  //
//                                                                            //
// ************************************************************************** //
Statistiques initialiserStatistiques (Statistiques statistiques);

// ************************************************************************** //
// imprimerStatistiques                                                    	  //
//                                                                            //
// Fonction pour imprimer les statistiques.			  		  	  			  //
//                                                                            //
//                                                                            //
// INPUT:                                                                     //
//      les variables dans la structure statistique. 						  //
//                                                                            //
// OUTPUT:                                                                    //
//       -																	  //
//                                                                            //
// ************************************************************************** //
void imprimerStatiques(Statistiques statistiques, int instant);

// ************************************************************************** //
// initialiserCaisses                                                    	  //
//                                                                            //
// Fonction pour initialiser les caisses (aucun clients dans les queues).	  //
//                                                                            //
//                                                                            //
// INPUT:                                                                     //
//      les variables dans la structure queue. 								  //
//                                                                            //
// OUTPUT:                                                                    //
//       -																	  //
//                                                                            //
// ************************************************************************** //
void initialiserCaisses(Queue* queue);

// ************************************************************************** //
// encoreClientDansMarche                                                 	  //
//                                                                            //
// Fonction pour savoir si il y encore des clients dans le marché et les 	  //
// attendre même si le marché est fermé. Retourne 0 si le marché est vide et  //
// 1 si il y a encore de clients. 											  // 
//                                                                            //
//                                                                            //
// INPUT:                                                                     //
//      les variables dans la structure queue. 								  //
//                                                                            //
// OUTPUT:                                                                    //
//       retourne 1 si il y a encore des clients et 0 si les queus sont 	  //
//		  vides.															  //
//                                                                            //
// ************************************************************************** //
int encoreClientDansMarche(Queue* queue);

// ************************************************************************** //
// queuePlusPetite		                                                 	  //
//                                                                            //
// Fonction pour trouver la queue le plus petite.							  //
//                                                                            //
//                                                                            //
// INPUT:                                                                     //
//      les variables dans la structure queue. 								  //
//                                                                            //
// OUTPUT:                                                                    //
//       le caisse avec la queue la plus petite.							  //
//                                                                            //
// ************************************************************************** //
int queuePlusPetite(Queue* queue);

// ************************************************************************** //
// imprimerCaisses                                                 	  		  //
//                                                                            //
// Fonction pour retirer les articles du panier du client, retirer le client  //
// de la queue si le panier est vide et imprimer les queues des caisses dans  //
// le format suviant: 	  													  //
// caisse 1: {instant arrivée, nombre d'articles}, {i, nbArticles}, ...		  //
// caisse 2: {instant arrivée, nombre d'articles}, {i, nbArticles}, ...		  //
// caisse 3: {instant arrivée, nombre d'articles}, {i, nbArticles}, ...		  //
// caisse 4: {instant arrivée, nombre d'articles}, {i, nbArticles}, ...		  //
//                                                                            //
// La fonction appele las fonctions coupDOeilTete, obtenirTete, imprimerQueue //
// et free pour liberer le client.
//                                                                            //
//                                                                            //
// INPUT:                                                                     //
//      les variables dans la structure queue. 								  //
//		les variables dans la structure statistiques.						  //
//		l'instant où le client est arrivé.									  //
//                                                                            //
// OUTPUT:                                                                    //
//       -																	  //
//                                                                            //
// ************************************************************************** //
void gererCaisses(Queue* queue, Statistiques* statistiques, int instant);

// ************************************************************************** //
// ajouterClientQueue	                                          	  		  //
//                                                                            //
// Fonction pour créér et ajouter un client à la queue le plus petite si se   //
// nombre de cycles est plus petit que la globale donnée et randomiserClient  //
// retourne 1.															   	  //
//                                                                            //
//                                                                            //
// INPUT:                                                                     //
//      les variables dans la structure queue. 								  //
//		les variables dans la structure statistiques.						  //
//		le instant que le client est arrivé.								  //
//                                                                            //
// OUTPUT:                                                                    //
//       -																	  //
//                                                                            //
// ************************************************************************** //
void ajouterClientQueue(Queue* queue, Statistiques* statistiques, int instant);

// ************************************************************************** //
// int main()			                                          	  		  //
//                                                                            //
// Fonction pour démarrer la simulation, si le nombre de cycles est plus 	  //
// petit que la globale donnée (réferent aux cycles) ou si il y a encore de   //
// clients dans le marché, le main ajoute des clients dans les queues et gere //
// les caisses. À la fin, il appele la fonction pour imprimer les        	  //
// statistiques. 															  //
//                                                                            //
//                                                                            //
// INPUT:                                                                     //
//      -									 								  //
//                                                                            //
// OUTPUT:                                                                    //
//       -																	  //
//                                                                            //
// ************************************************************************** //
int main();