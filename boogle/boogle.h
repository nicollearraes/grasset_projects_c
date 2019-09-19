// ************************************************************************** //
//                                                                            //
// Nom du fichier: boogle.h                                                   //
//                                                                            //
// Date: 26 novembre 2018                                                     //
//                                                                            //
// Équipe: Adriano Galindo, Ana Urias et Nicolle Falbo                        //
//                                                                            //
// Desciption: contient les descriptions de fonctions pour le jeu de Boggle.  //
//                                                                            //
// ************************************************************************** //

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define BUFF 30
#define R 4
#define C 4
#define NB_FACES 6
#define NB_DES 16
#define VISITE '1'
#define NON_VISITE '0'
#define FAUX 0
#define VRAI 1
#define DICTIONNAIRE "francais.txt"
#define NB_MOT_MAX_DICTIONNAIRE 324118
#define NB_MOT_INITIAL 100


// ************************************************************************** //
// void shuffleDes                                                            //
//                                                                            //
// Fonction pour randomiser l'ordre des 16 dés du jeu de Boogle.              //
//                                                                            //
// INPUT:                                                                     //
//       un tableau de 16 cases                                               //
//                                                                            //
// OUTPUT:                                                                    //
//        -                                                                   //
//                                                                            //
// Le code de cette fonction est disponible sur:                              //
//                                                                            //
// https://www.quora.com/What-is-a-simple-implementation-of-the-Fisher%E2%80% //
// 93Yates-shuffle-in-C                                                       //
//                                                                            //
// et a été adapté pour le TP.                                                //
//                                                                            //
// ************************************************************************** //
void shuffleDes(int nombreDesSortie[NB_DES]);

// ************************************************************************** //
// void remplirGrille                                                         //
//                                                                            //
// Fonction pour randomiser les faces dés et remplir la grille du jeu de      //
// Boogle avec les 16 dés qui sont déjà aleatoires dans un tableau.           //
//                                                                            // 
//                                                                            //
// INPUT:                                                                     //
//       la grille du jeu de Boogle                                           //
//       le tableau avec les dés aleatoires.                                  //
//                                                                            //
// OUTPUT:                                                                    //
//        -                                                                   //
//                                                                            //
// ************************************************************************** //
void remplirGrille(char grille[R][C], int nombreDesSortie[NB_DES]);

// ************************************************************************** //
// void imprimerGrille                                                        //
//                                                                            //
// Fonction pour imprimer la grille du jeu de Boogle déjà rempli avec les     //
// dés (lettres)                                                              // 
//                                                                            //
// INPUT:                                                                     //
//       la grille du jeu de Boogle                                           //
//                                                                            //
// OUTPUT:                                                                    //
//        -                                                                   //
//                                                                            //
// ************************************************************************** //
void imprimerGrille(char grille[R][C]);

// ************************************************************************** //
// void initialiserNonVisitee                                                 //
//                                                                            //
// Fonction pour initialiser la matrice à visiter comme non visitée.          // 
//                                                                            //
// INPUT:                                                                     //
//       une matrice de même taille que la grille du jeu de Boggle            //
//                                                                            //
// OUTPUT:                                                                    //
//        -                                                                   //
//                                                                            //
// ************************************************************************** //
void initialiserNonVisitee(char grilleVisitee[R][C]);

// ************************************************************************** //
// int formeMot                                                               //
//                                                                            //
// Fonction pour parcourir la grille du jeu de Boogle et essayer de trouver   // 
// des mots en respectant les régles (les lettres doivent être voissines),    //
// sinon on retourne à l'arrière.                                             //
//                                                                            //
// INPUT:                                                                     //
//       la grille du jeu de Boggle                                           //
//       le mot entré par l'utilisateur                                       //
//       la matrice visitée                                                   //
//       la cordonée x de la lettre du mot entrée par l'utilisateur dans la   //
//          grille                                                            //
//       la cordonée y de la lettre du mot entrée par l'utilisateur dans la   //
//          grille                                                            //
//       un compteur compt pour se déplacer dans le mot entré par             //
//          l'utilisateur                                                     //
//                                                                            //
// OUTPUT:                                                                    //
//        VRAI (1) si on est capable de former un mot                         //
//        FAUX (0) si on n'est pas capable de formet un mot                   //
//                                                                            //
// ************************************************************************** //
int formeMot(char grille[R][C], char* motAChercher, char grilleVisitee[R][C], 
              int x, int y, int compt);

// ************************************************************************** //
// int motDansGrille                                                          //
//                                                                            //
// Fonction pour savoir si le mot entré par l'utilisateur est dans la grille  //
// du jeu de Boogle.                                                          //
//                                                                            //
// INPUT:                                                                     //
//       la grille du jeu de Boggle                                           //
//       le mot entré par l'utilisateur                                       //
//       la matrice visitée                                                   //
//       un compteur compt pour se déplacer dans le mot entré par             //
//          l'utilisateur                                                     //
//                                                                            //
// OUTPUT:                                                                    //
//        VRAI (1) si le mot entré par l'utilisateur est dans la grille       //
//        FAUX (0) sinon                                                      //
//                                                                            //
// ************************************************************************** //
int motDansGrille(char grille[R][C], char* motAChercher, 
                    char grilleVisitee[R][C], int compt);

// ************************************************************************** //
// int motEstDejaTapee                                                        //
//                                                                            //
// Fonction pour savoir si le mot entré par l'utilisateur est a été déjà tapé //
// (s'il a déjà écrit ce mot)                                                 //
//                                                                            //
// INPUT:                                                                     //
//       une matrice avec les mots déjà entrés par l'utilisateur              //
//       le mot entré par l'utilisateur                                       //
//       le nombre de mots entrés                                             //
//                                                                            //
// OUTPUT:                                                                    //
//        VRAI (1) si l'utilisateur a déjà entré le mot                       //
//        FAUX (0) sinon                                                      //
//                                                                            //
// ************************************************************************** //
int motEstDejaTapee(char** matriceDeMotTapez, char* motAChercher, int nbMotTapez);

// ************************************************************************** //
// int scoreDuJeu                                                             //
//                                                                            //
// Fonction pour calculer le nombre de points fait par l'utilisateur.         //
//                                                                            //
// INPUT:                                                                     //
//       une matrice avec les mots entrés par l'utilisateur                   //
//                                                                            //
// OUTPUT:                                                                    //
//        le nombre de points que l'utilisateur a fait                        //
//                                                                            //
// ************************************************************************** //
int scoreDuJeu(char** matriceDeMotTapez);

// ************************************************************************** //
// void augmenterLeTableuDeMot                                                //
//                                                                            //
// Fonction pour augmenter le nombre maximum de mots que l'utilisateur peut   //
// rentrer.                                                                   //
//                                                                            //
// INPUT:                                                                     //
//       une matrice avec les mots entrés par l'utilisateur                   //
//       le nombre maximum de mots que l'utilisateur peut rentrer             //
//           (qui peut changer)                                               //
//       le nombre de mots entrés par l'utilisateur                           //
//                                                                            //
// OUTPUT:                                                                    //
//        -                                                                   //
//                                                                            //
// ************************************************************************** //
void augmenterLeTableuDeMot(char** matriceDeMotTapez, int* nbMotMaximum, 
                                int nbMotTapez);

// ************************************************************************** //
// void executeLeJeu                                                          //
//                                                                            //
// Fonction pour exécuter le jeu de Boogle.                                   //
//                                                                            //
// INPUT:                                                                     //
//       une matrice avec les mots qui sont dans le dictionnaire de français  //
//       une matrice avec les mots entrés par l'utilisateur                   //
//       la grille du jeu de Boogle                                           //
//       la matrice visitée                                                   //
//       le mot entré par l'utilisateur                                       //
//       le nombre de mots entrés par l'utilisateur                           //
//       le nombre de mot maximum                                             //
//       le nombre de mots dans le dictionnaire.                              //
//                                                                            //
// OUTPUT:                                                                    //
//        -                                                                   //
//                                                                            //
// ************************************************************************** //
void executeLeJeu(char** matriceDeDictionnaire, char** matriceDeMotTapez, 
                    char grille[R][C], char grilleVisitee[R][C], 
                    char* motAChercher, int nbMotTapez, int* nbMotMaximum, int* pTailleDictionnaire);

// ************************************************************************** //
// void imprimerMotsPossibles                                                 //
//                                                                            //
// Fonction pour montrer tous les mots possibles dans la grille du jeu de     //
// Boogle qui existent dans le dictionnaire.                                  //
//                                                                            //
// INPUT:                                                                     //
//       une matrice qui contient le dictionnaire de Français                 //
//       la matrice visitée                                                   //
//       la grille du jeu de Boogle                                           //
//                                                                            //
// OUTPUT:                                                                    //
//        -                                                                   //
//                                                                            //
// ************************************************************************** //
void imprimerMotsPossibles(char** matriceDeDictionnaire, 
                            char grilleVisitee[R][C], char grille[R][C]);

// ************************************************************************** //
// int main                                                                   //
//                                                                            //
// Fonction pour démarrer l'exécution du jeu de Boogle.                       //
//                                                                            //
// INPUT:                                                                     //
//       -                                                                    //
//                                                                            //
// OUTPUT:                                                                    //
//        retourne 0 si programme fonctionne                                  //
//                                                                            //
// ************************************************************************** //
int main();
