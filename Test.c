//**********************************************************************************//
// Nom : Test.c                                                                     //
//                                                                                  //
// Auteur : Marcel & Nicolle                                                        //
//                                                                                  //
// Date : 12 octobre 2018                                                           //
//                                                                                  //
//**********************************************************************************//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Yahtzee.h"
#include "Test.h"

//**********************************************************************************//
void testBrelan(){
    printf ("\nTest Brelan:\n");
    // cas ordinaire
    Jet jet1 = {3,3,3,6,1};
    // cas ordinaire
    Jet jet2 = {1,1,3,5,4};
    printf("test 1: ");
    if (brelan(jet1) == 0){
        printf ("échec");
    } else {
        printf ("reussit");
    }
    printf("\ntest 2: ");
    if (brelan(jet2) == 0){
        printf ("échec, n'est pas un brelan: {1,1,3,5,4}");
    } else {
        printf ("reussit");
    }
    printf("\n*****************\n");
}
//**********************************************************************************//
void testCarre(){
    printf ("\nTest Carre:\n");
    // cas limite
    Jet jet1 = {3,3,3,3,1};
    // cas limite
    Jet jet2 = {1,2,3,4,6};
    printf("test 1: ");
    if (carre(jet1) == 0){
        printf ("échec");
    } else {
        printf ("reussit");
    }
    printf("\ntest 2: ");
    if (carre(jet2) == 0){
        printf ("échec, n'est pas une carre: {1,2,3,4,6}");
    } else {
        printf ("reussit");
    }
    printf("\n*****************\n");
}
//**********************************************************************************//
void testMainPleine(){
    printf ("\nTest Main Pleine:\n");
    // cas limite
    Jet jet1 = {3,3,3,1,1};
    // cas limite
    Jet jet2 = {1,2,3,4,6};
    printf("test 1: ");
    if (mainPleine(jet1) == 0){
        printf ("échec");
    } else {
        printf ("reussit");
    }
    printf("\ntest 2: ");
    if (mainPleine(jet2) == 0){
        printf ("échec, n'est pas une main pleine: {1,2,3,4,6}");
    } else {
        printf ("reussit");
    }
    printf("\n*****************\n");
}
//**********************************************************************************//
void testPetiteSuite(){
    printf ("\nTest Petite Suite:\n");
    // cas limite
    Jet jet1 = {1,2,3,4,6};
    // cas ordinaire
    Jet jet2 = {2,3,2,1,5};
    printf("test 1: ");
    if (petiteSuite(jet1) == 0){
        printf ("échec");
    } else {
        printf ("reussit");
    }
    printf("\ntest 2: ");
    if (petiteSuite(jet2) == 0){
        printf ("échec, n'est pas une petite suite: {2,3,2,1,5}");
    } else {
        printf ("reussit");
    }
    printf("\n*****************\n");
}
//**********************************************************************************//
void testGrandeSuite(){
    printf ("\nTest Grande Suite:\n");
    // cas limite
    Jet jet1 = {1,2,3,4,5};
    // cas ordinaire
    Jet jet2 = {2,5,3,6,1};
    printf("test 1: ");
    if (grandeSuite(jet1) == 0){
        printf ("échec");
    } else {
        printf ("reussit");
    }
    printf("\ntest 2: ");
    if (grandeSuite(jet2) == 0){
        printf ("échec, n'est pas grand suite: {2,5,3,6,1}.");
    } else {
        printf ("reussit");
    }
    printf("\n*****************\n");
}
//**********************************************************************************//
void testYahtzee(){
    printf ("\nTest Yahtzee:\n");
    // cas limite
    Jet jet1 = {4,4,4,4,4};
    // cas ordinaire
    Jet jet2 = {1,4,2,3,1};
    printf("test 1: ");
    if (yahtzee(jet1) == 0){
        printf ("échec");
    } else {
        printf ("reussit");
    }
    printf("\ntest 2: ");
    if (yahtzee(jet2) == 0){
        printf ("échec, n'est pas un yahtzee: {1,4,2,3,1}.");
    } else {
        printf ("reussit");
    }
    printf("\n*****************\n");
}
//**********************************************************************************//
void testChance(){
    printf ("\nTest Chance:\n");
    // cas ordinaire
    Jet jet1 = {3,4,2,6,1};
    // cas limite
    Jet jet2 = {4,4,4,4,4};
    printf("test 1: ");
    if (chance(jet1) == 0){
        printf ("échec");
    } else {
        printf ("reussit");
    }
    printf("\ntest 2: ");
    if (chance(jet2) == 0){
        printf ("échec");
    } else {
        printf ("reussit");
    }
    printf("\n*****************\n");
}
//**********************************************************************************//
void testerTout(){
    testBrelan();
    testCarre();
    testMainPleine();
    testPetiteSuite();
    testGrandeSuite();
    testYahtzee();
    testChance();
}
