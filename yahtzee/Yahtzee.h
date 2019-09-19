//**********************************************************************************//
// Nom : Yahtzee.c                                                                  //
//                                                                                  //
// Auteur : Marcel & Nicolle                                                        //
//                                                                                  //
// Date : 12 octobre 2018                                                           //
//                                                                                  //
//**********************************************************************************//

#pragma once
#define NB_DES 5

//**********************************************************************************//
//                            Structure: enum des dés                               //
//**********************************************************************************//
typedef enum FaceDes FaceDes;
enum FaceDes {FACE_UN = 1, FACE_DEUX, FACE_TROIS, FACE_QUATRE, FACE_CINQ, FACE_SIX};

//**********************************************************************************//
//                            enum jeter ou garder dés                              //
//**********************************************************************************//
enum JeterOuGarderDes {GARDER, JETER};

//**********************************************************************************//
//                               Structure: Jet                                     //
//**********************************************************************************//
typedef struct Jet Jet;
struct Jet{
    int des[NB_DES];
};

//**********************************************************************************//
//                       Structure: Diagramme de Contexte                           //
//**********************************************************************************//
typedef struct Score Score;
struct Score{
    int sommeDesUn;
    int sommeDesDeux;
    int sommeDesTrois;
    int sommeDesQuatre;
    int sommeDesCinq;
    int sommeDesSix;
    int sommeBrelan;
    int sommeCarre;
    int sommeMainPlaine;
    int sommePetiteSuite;
    int sommeGrandeSuite;
    int sommeYahtzee;
    int sommeChance;
    int sommeSuperieure;
    int sommeInferieure;
    int tour;
    int scoreTotal;
};

//**********************************************************************************//
// pigerJet                                                                         //
//                                                                                  //
// Fonction qui gère 5 nombres au hasard. À faire une fois avant tous les           //
// jets.                                                                            //
//                                                                                  //
//                                                                                  //
// INPUT:                                                                           //
//      Tableau d'éntiers avec 5 cases.                                             //
//                                                                                  //
// OUTPUT:                                                                          //
//      Tableau avec des nombres tirés au hasard pour un Jet.                       //
//                                                                                  //
//**********************************************************************************//
Jet pigerJet(Jet jet, char choix[5]);

//**********************************************************************************//
// nbDeFace                                                                         //
//                                                                                  //
// Calcule le pointage pour la figure "face".                                       //
//                                                                                  //
//                                                                                  //
// INPUT :                                                                          //
//     jet : cinq dés.                                                              //
//     face : la face a comptabiliser.                                              //
//                                                                                  //
// OUTPUT :                                                                         //
//     Le pointage pour face dans jet. Le pointage est le produit de face et du     //
//     nombre de des dans jets qui valent face.                                     //
//                                                                                  //
//**********************************************************************************//
int nbDeFace(Jet jet, int face);

//**********************************************************************************//
// ordoneDes                                                                        //
//                                                                                  //
// Mettre les dés d'un jet en order croissant.                                      //
//                                                                                  //
//                                                                                  //
// INPUT :                                                                          //
//         jet : cinq dés.                                                          //
//                                                                                  //
// OUTPUT :                                                                         //
//         jet : cinq dés.                                                          //
//                                                                                  //
//**********************************************************************************//
Jet ordoneDes (Jet jet);

//**********************************************************************************//
// majeureSequence                                                                  //
//                                                                                  //
// Trouve la majeure sequence des dés dans un jet.                                  //
//                                                                                  //
//                                                                                  //
// INPUT :                                                                          //
//         jet : cinq dés.                                                          //
//                                                                                  //
// OUTPUT :                                                                         //
//         la majeure sequence.                                                     //
//                                                                                  //
//**********************************************************************************//
int majeureSequence(Jet jet);

//**********************************************************************************//
// brelan                                                                           //
//                                                                                  //
// Calcule le pointage pour la figure "brelan".                                     //
//                                                                                  //
//                                                                                  //
// INPUT :                                                                          //
//         jet : cinq dés.                                                          //
//                                                                                  //
// OUTPUT :                                                                         //
//         Le pointage pour brelan dans jet. Un brelan est trois faces identiques,  //
//         il vaut la somme de dés.                                                 //
//                                                                                  //
//**********************************************************************************//
int brelan(Jet jet);

//**********************************************************************************//
// carre                                                                            //
//                                                                                  //
// Calcule le pointage pour la figure "carre".                                      //
//                                                                                  //
//                                                                                  //
// INPUT :                                                                          //
//         jet : cinq dés.                                                          //
//                                                                                  //
// OUTPUT :                                                                         //
//         Le pointage pour carré dans jet. Un carré est trois faces identiques,    //
//         il vaut la somme de dés.                                                 //
//                                                                                  //
//**********************************************************************************//
int carre(Jet jet);

//**********************************************************************************//
// mainPleine                                                                       //
//                                                                                  //
// Calcule le pointage pour la figure "main pleine".                                //
//                                                                                  //
//                                                                                  //
// INPUT :                                                                          //
//         jet : cinq dés.                                                          //
//                                                                                  //
// OUTPUT :                                                                         //
//         Le pointage pour main pleine dans jet. Un maine plaine est trois faces   //
//         identiques et deux faces identiques. Elle vaut 25 points.                //
//                                                                                  //
//**********************************************************************************//
int mainPleine(Jet jet);

//**********************************************************************************//
// petiteSuite                                                                      //
//                                                                                  //
// Calcule le pointage pour la figure "petite suite"                                //
//                                                                                  //
//                                                                                  //
// INPUT :                                                                          //
//         jet : cinq dés.                                                          //
//                                                                                  //
// OUTPUT :                                                                         //
//        Le pointage pour petite suite dans jet. Une petite suite vaut 30          //
//        points. Il y a trois petites suites possibles : 1,2,3,4 ou 2,3,4,5 ou     //
//        3,4,5,6. L’ordre des dés n’a pas d’importance.                            //
//                                                                                  //
//**********************************************************************************//
int petiteSuite(Jet jet);

//**********************************************************************************//
// grandeSuite                                                                      //
//                                                                                  //
// Calcule le pointage pour la figure "grande suite".                               //
//                                                                                  //
//                                                                                  //
// INPUT :                                                                          //
//         jet : cinq dés.                                                          //
//                                                                                  //
// OUTPUT :                                                                         //
//        le pointage pour grande suite dans jet. Une grande suite vaut 40          //
//        points. Il y a deux grandes suites possibles : 1,2,3,4,5 ou               //
//        2,3,4,5,6. L’ordre des dés n’a pas d’importance.                          //
//                                                                                  //
//**********************************************************************************//
int grandeSuite(Jet jet);

//**********************************************************************************//
// yahtzee                                                                          //
//                                                                                  //
// Calcule le pointage pour la figure "yahtzee".                                    //
//                                                                                  //
//                                                                                  //
// INPUT :                                                                          //
//         jet : cinq dés.                                                          //
//                                                                                  //
// OUTPUT :                                                                         //
//        Le pointage pour yahtzee dans jet. Un yahtzee est cinq des identiques.    //
//        Il vaut 50 points.                                                        //
//                                                                                  //
//**********************************************************************************//
int yahtzee(Jet jet);

//**********************************************************************************//
// chance                                                                           //
//                                                                                  //
// Calcule la pointage pour la figure "chance".                                     //
//                                                                                  //
//                                                                                  //
// INPUT :                                                                          //
//         jet : cinq dés.                                                          //
//                                                                                  //
// OUTPUT :                                                                         //
//        Le pointage pour chance dans jet. Une chance est la somme des dés.        //
//                                                                                  //
//**********************************************************************************//
int chance(Jet jet);

//**********************************************************************************//
// diagrammeContexte                                                                //
//                                                                                  //
// Il montre le résultat obtenu des 5 dés pour que l'utilisateur puisse choisir     //
// ce qu'il veut garder.                                                            //
//                                                                                  //
//                                                                                  //
// INPUT :                                                                          //
//         jet: cinq dés.                                                           //
//                                                                                  //
// OUTPUT :                                                                         //
//        Le diagramme de contexte.                                                 //
//                                                                                  //
//**********************************************************************************//
void diagrammeContexte(Jet jet);

//**********************************************************************************//
// choixUtilisateur		                                                            //
//                                                                                  //
// Garde le choix de l'utilisateur.                                                 //
//                                                                                  //
//                                                                                  //
// INPUT :                                                                          //
//         score : les items de la structure score.                                 //
// 		   jet: cinq dés.                                                           //
//                                                                                  //
// OUTPUT :                                                                         //
//        Le score de l'utilisateur.                                                //
//                                                                                  //
//**********************************************************************************//
Score choixUtilisateur (Score score, Jet jet);

//**********************************************************************************//
// feuilleScore                                                                     //
//                                                                                  //
// Il montre le résultat obtenu par tour et total.                                  //
//                                                                                  //
//                                                                                  //
// INPUT :                                                                          //
//         score : les items de la structure score.                                 //
//                                                                                  //
// OUTPUT :                                                                         //
//        La feuille de score.                                                      //
//                                                                                  //
//**********************************************************************************//
void feuilleScore(Score score);

//**********************************************************************************//
// feuilleScore                                                                     //
//                                                                                  //
// Il montre le résultat obtenu par tour et total.                                  //
//                                                                                  //
//                                                                                  //
// INPUT :                                                                          //
//         score : les items de la structure score.                                 //
//                                                                                  //
// OUTPUT :                                                                         //
//        La feuille de score.                                                      //
//                                                                                  //
//**********************************************************************************//
int sommeSuperieure(Score score);

//**********************************************************************************//
// feuilleScore                                                                     //
//                                                                                  //
// Il montre le résultat obtenu par tour et total.                                  //
//                                                                                  //
//                                                                                  //
// INPUT :                                                                          //
//         score : les items de la structure score.                                 //
//                                                                                  //
// OUTPUT :                                                                         //
//        La feuille de score.                                                      //
//                                                                                  //
//**********************************************************************************//
int sommeInferieure(Score score);

//**********************************************************************************//
// scoreResultat        		                                                        //
//                                                                                  //
// Il montre le résultat obtenu par tour et total.                                  //
//                                                                                  //
//                                                                                  //
// INPUT :                                                                          //
//         score : les items de la structure score.                                 //
//                                                                                  //
// OUTPUT :                                                                         //
//        La feuille de score.                                                      //
//                                                                                  //
//**********************************************************************************//
int scoreResultat(Score score);

//**********************************************************************************//
// initialiserFeuilleScore                                                          //
//                                                                                  //
// Pour reinitialiser la feuille de score au début de chaque partie.                //
//                                                                                  //
//                                                                                  //
// INPUT :                                                                          //
//         score : les items de la structure score qui vont être reinitialisés.     //
//                                                                                  //
// OUTPUT :                                                                         //
//        La feuille de score initialisée à zero.                                   //
//                                                                                  //
//**********************************************************************************//
Score initialiserFeuilleScore(Score score);

//**********************************************************************************//
// imprimerDes                                                                      //
//                                                                                  //
// Pour imprimer les faces des dés dans un jet.                                     //
//                                                                                  //
//                                                                                  //
// INPUT :                                                                          //
//         jet : cinq dés.                                                          //
//                                                                                  //
// OUTPUT :                                                                         //
//        L'impression des faces des dés.                                           //
//                                                                                  //
//**********************************************************************************//
void imprimerDes(Jet jet);

//**********************************************************************************//
// jeux		                                                                        //
//                                                                                  //
// Fonction pour jouer le Yahtzee.			                                        //
//                                                                                  //
//                                                                                  //
// INPUT :                                                                          //
//         jet : cinq dés.                                                          //
//                                                                                  //
// OUTPUT :                                                                         //
//        L'impression des faces des dés.                                           //
//                                                                                  //
//**********************************************************************************//
void jeux(Jet jet, Score score);
