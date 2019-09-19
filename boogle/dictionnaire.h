// ************************************************************************** //
//                                                                            //
// Nom du fichier: dictionnaire.h                                             //
//                                                                            //
// Date: 26 novembre 2018                                                     //
//                                                                            //
// Équipe: Adriano Galindo, Ana Urias et Nicolle Falbo                        //
//                                                                            //
// Desciption: contient les descriptions de fonctions liées au dictionnaire   //
// pour le jeu de Boggle.     											      //
//                                                                            //
// ************************************************************************** //

#pragma once

#define BUFF 30
#define VISITE '1'
#define NON_VISITE '0'
#define FAUX 0
#define VRAI 1
#define DICTIONNAIRE "francais.txt"
#define NB_MOT_MAX_DICTIONNAIRE 324118


// ************************************************************************** //
// void lireFichier                                                           //
//                                                                            //
// Fonction pour lire de dictionnaire de Français et le mettre dans une       //
// matrice.																	  //
//                                                                            //
// INPUT:                                                                     //
//       le fichier du dictionnaire de Français                               //
//	     une matrice pour mettre les mots du dictionnaire                     //
//       le nombre de mots dans le dictionnaire.         				      //
//                                                                            //
// OUTPUT:                                                                    //
//        -                                                                   //
//                                                                            //
// ************************************************************************** //
void lireFichier(char *filename, char** matriceDeDictionnaire, int* pTailleDictionnaire);

// ************************************************************************** //
// int motDansDictionnaireRechercheBinaryJava                                 //
//                                                                            //
// Fonction pour savoir si le mot tapé pour l'utilisateur est dans la         //
// matrice qui contient le dictionnaire de Français.						  //
//                                                                            //
// INPUT:                                                                     //
//       le fichier du dictionnaire de Français                               //
//	     une matrice pour mettre les mots du dictionnaire 				      //
//       le nombre de mots dans le dictionnaire.         				      //
//                                                                            //
// OUTPUT:                                                                    //
//        VRAI (1) si le mot est dans le dictionnaire/la matrice              //
//        FAUX (0) sinon													  //
//                                                                            //
// ************************************************************************** //
int motDansDictionnaireRechercheBinaryJava(char** matriceDeMotTapez, 
											char** matriceDeDictionnaire, 
											char* motAChercher, int nbMotTapez, int* pTailleDictionnaire);
