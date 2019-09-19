// ************************************************************************** //
// 																			  //
// Nom : queue.h 													  	   	  //
//  																		  //
// Auteur : Nicolle 														  //
//  																		  //
// Date : 31 octobre 2018 													  //
// 																			  //
// ************************************************************************** //

#pragma once


// ************************************************************************** //
//                            Structure: Client                               //
// ************************************************************************** //
typedef struct Client Client;
struct Client{
	int instantArrivee; 	// l’instant où le client arrive (qu'il est ajouté à une queue)
	int nbArticles;			// le nombre d’articles dans le panier du client
	Client* suivant; 		// le cliente suivante | pour ajouter des clients à la liste chaînée	
							
};

// ************************************************************************** //
//                            Structure: Queue                                //
// ************************************************************************** //
typedef struct Queue Queue;
struct Queue{
	Client* premier;
	Client* dernier;
}; 

// ************************************************************************** //
// creerClient	                                                              //
//                                                                            //
// Fonction pour créer des nouveaux clients qui seront ajoutés à la queue.    //
//                                                                            //
//                                                                            //
// INPUT:                                                                     //
//      instant: 	l'instant que le client est arrivé/ajouté à la fin de la  //
//				  	  queue.  												  //
//		nbArticles: le nombre d'articles dans le panier du client. 			  //
//                                                                            //
// OUTPUT:                                                                    //
//       retourne un nouveau client.							          	  //
//                                                                            //
// ************************************************************************** //
Client* creerClient(int instant, int nbArticles);

// ************************************************************************** //
// offrirClient	                                                              //
//                                                                            //
// Fonction pour ajouter des nouveaux clients à la fin de la queue.    		  //
//                                                                            //
//                                                                            //
// INPUT:                                                                     //
//      Queue* queue: 	un pointeur qui pointe vers la queue.				  //
//		Client* client: un pointeur qui pointe vers le client. 				  //
//                                                                            //
// OUTPUT:                                                                    //
//       -														          	  //
//                                                                            //
// ************************************************************************** //
// PSEUDO-CODE 																  //
//                                                                            //
// void offrirClient(Queue* queue, Client* client)          			      //
// {                                                                          //
//   si queue->premier est different de NULL 							      //
//   { 																	 	  //
//     Client* clientDernier												  //
//     Client* clientTemporaire <- queue->premier 							  //
//     tant que clientTemporaire est different de NULL 						  //
//     { 																      //
//       clientDernier <- clientTemporaire 									  //
//       clientTemporaire <- clientDernier->suivant 						  //
//     } 																	  //
//     clientDernier->suivant <- client 									  //
//   }	 																	  //
//   sinon 																	  //
//     queue->premier <- client 											  //
// }                                                                          //
//                                                                            //
// ************************************************************************** //
void offrirClient(Queue* queue, Client* client);

// ************************************************************************** //
// coupDOeilTete                                                              //
//                                                                            //
// Fonction pour montrer le premier client de la queue.			    		  //
//                                                                            //
//                                                                            //
// INPUT:                                                                     //
//      Queue queue: la queue.				 								  //
//                                                                            //
// OUTPUT:                                                                    //
//       le premier client dans la queue.						          	  //
//                                                                            //
// ************************************************************************** //
Client* coupDOeilTete(Queue queue);

// ************************************************************************** //
// obtenirTete                                                                //
//                                                                            //
// Fonction pour retirer et montrer le premier client de la queue.			  //
//                                                                            //
//                                                                            //
// INPUT:                                                                     //
//      Queue* queue: un pointeur que pointe vers la queue.					  //
//                                                                            //
// OUTPUT:                                                                    //
//       retire et retourne le premier client de la queue. Retourne NULL si   //
//		  la queue est vide. 												  //
//                                                                            //
// ************************************************************************** //
// PSEUDO-CODE 																  //
//                                                                            //
// Client* obtenirTete(Queue* queue)				          			      //
// {                                                                          //
//   si queue->premier est different de NULL 							      //
//   { 																	 	  //
//     Client* permierClient <- queue->premier 								  //
//     queue->premier <- queue->premier->suivant 							  //
//     retourne premierClient 												  //
//   } 																     	  //
//   sinon 																	  //
//     retoune NULL 														  //
// }                                                                          //
//                                                                            //
// ************************************************************************** //
Client* obtenirTete(Queue* queue);

// ************************************************************************** //
// longueurQueue                                                              //
//                                                                            //
// Fonction pour dire le nombre de clients dans la queue.			  		  //
//                                                                            //
//                                                                            //
// INPUT:                                                                     //
//      Queue queue: la queue.												  //
//                                                                            //
// OUTPUT:                                                                    //
//       le nombre de clients dans la queue.								  //
//                                                                            //
// ************************************************************************** //
// PSEUDO-CODE 																  //
//                                                                            //
// int longueurQueue(Queue queue)					          			      //
// {                                                                          //
//   Client* c <- queue.premier 										      //
//   entier longueur <- 0 													  //
//   tant que c est different de NULL 										  //
//   { 																	 	  //
//     c <- c->suivant 						 								  //
//     longueur <- longueur + 1 				 							  //
//     retourne premierClient 												  //
//   } 																     	  //
//   retoune longueur 														  //
// }                                                                          //
//                                                                            //
// ************************************************************************** //
int longueurQueue(Queue queue);

// ************************************************************************** //
// imprimerQueue                                                              //
//                                                                            //
// Fonction pour imprimer chaque client de la queue ({l'intant où il est  	  //
// arrivé, le nombre d'articles dans son panier}).							  //
//                                                                            //
//                                                                            //
// INPUT:                                                                     //
//      Queue queue: la queue.												  //
//                                                                            //
// OUTPUT:                                                                    //
//       -																	  //
//                                                                            //
// ************************************************************************** //
void imprimerQueue(Queue queue);