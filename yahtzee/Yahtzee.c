//**********************************************************************************//
// Nom : Yahtzee.c                                                                  //
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
Jet pigerJet(Jet jet, char choix[5]){
	const int MIN = 1;
	const int MAX = 6;
	srand(time(NULL));
	for (int i = 0; i < NB_DES; i++){
        if (choix[i] == '1'){
            jet.des[i]= rand() % MAX + MIN;
        }
	}
    return jet;
}
//**********************************************************************************//
int nbDeFace(Jet jet, int face){
	int sommeFace = 0;
	for (int i = 0; i < NB_DES; i++){
		if (jet.des[i] == face) {
			sommeFace += jet.des[i];
		}
	}
	return sommeFace;
}
//**********************************************************************************//
Jet ordoneDes (Jet jet){
	int ordreTemp;
	for (int i = 0; i < NB_DES; ++i){
    	for (int j = i + 1; j < NB_DES; ++j){
    		if (jet.des[i] > jet.des[j]){
    			ordreTemp = jet.des[i];
    			jet.des[i] = jet.des[j];
    			jet.des[j] = ordreTemp;
    		}
    	}
    }
    return jet;
}
//**********************************************************************************//
int majeureSequence(Jet jet)
{
    jet = ordoneDes(jet);
    int seqPlusGrande = 1;
    int seqProvisoire  = 1;
    int deProvisoire = jet.des[0];
    for (int i = 1; i < NB_DES; i++){
        if (jet.des[i] == deProvisoire){
            seqProvisoire++;
            if (seqProvisoire > seqPlusGrande){
                seqPlusGrande = seqProvisoire;
            }
        } else {
            seqProvisoire = 1;
            deProvisoire = jet.des[i];
        }
    }
    return seqPlusGrande;
}
//**********************************************************************************//
int brelan(Jet jet){
	const int EST_BRELAN = 3;
	if(majeureSequence(jet) >= EST_BRELAN){
		int sommeBrelan = 0;
		for(int i = 0; i < NB_DES; i++){
			sommeBrelan += jet.des[i];
		}
		return sommeBrelan;
	} else {
		return 0;
	}
}
//**********************************************************************************//
int carre(Jet jet){
	const int EST_CARRE = 4;
	if(majeureSequence(jet) >= EST_CARRE){
		int sommeCarre = 0;
		for(int i = 0; i < NB_DES; i++){
			sommeCarre += jet.des[i];
		}
		return sommeCarre;
	} else {
		return 0;
	}
}
//**********************************************************************************//
int mainPleine(Jet jet) {
	jet = ordoneDes(jet);
    const int EST_MAIN_PLAINE = 25;
    if (((jet.des[0] == jet.des[1])  && (jet.des[1] == jet.des[2]) &&
         (jet.des[3] == jet.des[4])  &&
         (jet.des[2] != jet.des[3])) ||
       (((jet.des[2] == jet.des[3])  && (jet.des[3] == jet.des[4]) &&
         (jet.des[0] == jet.des[1])) &&
         (jet.des[1] != jet.des[2]))){
    	return EST_MAIN_PLAINE;
    } else {
        return 0;
    }
}
//**********************************************************************************//
int petiteSuite(Jet jet){   
    const int EST_PETITE_SUITE = 30;
    jet = ordoneDes(jet);
    int compt = 1;
    for (int i = 0; i < NB_DES - 1; ++i){	
        if (jet.des[i] == jet.des[i + 1] - 1){
            compt++;
        } else if (((jet.des[i + 1] - jet.des[i]) == 2) && 
                 (((jet.des[0] + jet.des[1] + jet.des[2] + jet.des[3] + jet.des[4]) == 17) ||
                  ((jet.des[0] + jet.des[1] + jet.des[2] + jet.des[3] + jet.des[4]) == 18))){
        	compt--;
        }      
	}    
    if (compt >= 4){
        return EST_PETITE_SUITE;
    } else {
        return 0;
    }
}
//**********************************************************************************//
int grandeSuite(Jet jet){
    const int EST_GRANDE_SUITE = 40;
    jet = ordoneDes(jet);
    int sommePetiteSuite = 0;
    for (int i = 0; i < 4; i++){
        if (jet.des[i + 1] == jet.des[i] + 1 &&
            jet.des[i] - jet.des[i - 1] != 2){
                sommePetiteSuite++;
        } else if (jet.des[i + 1] != jet.des[i] + 1){
            sommePetiteSuite--;
        }
    }
        if (sommePetiteSuite >= 3){
            return EST_GRANDE_SUITE;
        } else {
            return 0;
        }
}
//**********************************************************************************//
int yahtzee(Jet jet){
    const int EST_YAHTZEE = 50;
    int sommeYahtzee = 1;
    for (int i = 0; i < NB_DES; i++){
        if (jet.des[i] == jet.des[i + 1]){
            sommeYahtzee++;
        }
    }
    if (sommeYahtzee == 5){
        return EST_YAHTZEE;
    } else {
        return 0;
    }
}
//**********************************************************************************//
int chance(Jet jet){
    int sommeChance = 0;
    for (int i = 0; i < NB_DES; i++){
        sommeChance += jet.des[i];
    }
    return sommeChance;
}
//**********************************************************************************//
void diagrammeContexte(Jet jet){
    printf("**********************************************\n");
    printf("*    QUEL POINTAGE VOULEZ-VOUS GARDER?       *\n");
    printf("**********************************************\n");
    printf("*     (1) : %2d       *       (B)relan = %2d   *\n", nbDeFace(jet, FACE_UN), brelan(jet));
    printf("*     (2) : %2d       *        (C)arré = %2d   *\n", nbDeFace(jet, FACE_DEUX), carre(jet));
    printf("*     (3) : %2d       *  (M)ain Pleine = %2d   *\n", nbDeFace(jet, FACE_TROIS), mainPleine(jet));
    printf("*     (4) : %2d       * (P)etite suite = %2d   *\n", nbDeFace(jet, FACE_QUATRE), petiteSuite(jet));
    printf("*     (5) : %2d       * (G)rande suite = %2d   *\n", nbDeFace(jet, FACE_CINQ), grandeSuite(jet));
    printf("*     (6) : %2d       *      (Y)ahtzee = %2d   *\n", nbDeFace(jet, FACE_SIX), yahtzee(jet));
    printf("*                    *       C(h)ance = %2d   *\n", chance(jet));
    printf("**********************************************\n");
}
//**********************************************************************************//
Score choixUtilisateur (Score score, Jet jet){
	printf("->");
	char choix;
	scanf(" %c", &choix);
	switch (choix){
		case '1': score.sommeDesUn = nbDeFace(jet, FACE_UN);
			break;
		case '2': score.sommeDesDeux = nbDeFace(jet, FACE_DEUX);
			break;
		case '3': score.sommeDesTrois = nbDeFace(jet, FACE_TROIS);
			break;
		case '4': score.sommeDesQuatre = nbDeFace(jet, FACE_QUATRE);
			break;
		case '5': score.sommeDesCinq = nbDeFace(jet, FACE_CINQ);
			break;
		case '6': score.sommeDesSix = nbDeFace(jet, FACE_SIX);
			break;
		case 'B':
		case 'b': score.sommeBrelan = brelan(jet);
			break;
		case 'C':
		case 'c': score.sommeCarre = carre(jet);
			break;
		case 'M':
		case 'm': score.sommeMainPlaine = mainPleine(jet);
			break;
		case 'P':
		case 'p': score.sommePetiteSuite = petiteSuite(jet);
			break;
		case 'G':
		case 'g': score.sommeGrandeSuite = grandeSuite(jet);
			break;
		case 'Y':
		case 'y': score.sommeYahtzee = yahtzee(jet);
			break;
		case 'H':
		case 'h': score.sommeChance = chance(jet);
			break;
	}
	return score;
}
//**********************************************************************************//
void feuilleScore(Score score){
    printf("************************************************************************************\n");
    printf("*                              FEUILLE DE SCORE TOUR  %2d/13                        *\n", score.tour);
    printf("************************************************************************************\n\n");
    printf("**********  Partie supérieure **********    **********  Partie inférieure **********\n");
    printf("*                                      *    *                                      *\n");
    printf("*                1 :  %2d               *    *               (B)relan =  %2d         *\n", score.sommeDesUn, score.sommeBrelan);
    printf("*                2 :  %2d               *    *                (C)arré =  %2d         *\n", score.sommeDesDeux, score.sommeCarre);
    printf("*                3 :  %2d               *    *          (M)ain Pleine =  %2d         *\n", score.sommeDesTrois, score.sommeMainPlaine);
    printf("*                4 :  %2d               *    *         (P)etite suite =  %2d         *\n", score.sommeDesQuatre, score.sommePetiteSuite);
    printf("*                5 :  %2d               *    *         (G)rande suite =  %2d         *\n", score.sommeDesCinq, score.sommeGrandeSuite);
    printf("*                6 :  %2d               *    *              (Y)ahtzee =  %2d         *\n", score.sommeDesSix, score.sommeYahtzee);
    printf("*                                      *    *               C(h)ance =  %2d         *\n", score.sommeChance);
    printf("*                                      *    *                                      *\n");
    printf("*     Somme partie supérieure : %3d    *    *     Somme partie inferieure : %3d    *\n", sommeSuperieure(score), sommeInferieure(score));
    printf("****************************************    ****************************************\n\n");
    printf("************************************************************************************\n");
    printf("*                                  Score =  %3d                                    *\n", scoreResultat(score));
    printf("************************************************************************************\n");
}
//**********************************************************************************//
int sommeSuperieure(Score score){
    score.sommeSuperieure =  score.sommeDesUn +
                        score.sommeDesDeux +
                        score.sommeDesTrois +
                        score.sommeDesQuatre +
                        score.sommeDesCinq +
                        score.sommeDesSix;
    return score.sommeSuperieure;
}
//**********************************************************************************//
int sommeInferieure(Score score){
    score.sommeInferieure =  score.sommeBrelan +
                        score.sommeCarre +
                        score.sommeMainPlaine +
                        score.sommePetiteSuite +
                        score.sommeGrandeSuite +
                        score.sommeYahtzee +
                        score.sommeChance;
    return score.sommeInferieure;
}
//**********************************************************************************//
int scoreResultat(Score score){
    const int BONUS = 35;
    const int SCORE_MIN = 63;
    score.scoreTotal = sommeInferieure(score) + sommeSuperieure(score);
    if (score.sommeInferieure >= SCORE_MIN){
        score.sommeInferieure += BONUS;
    }
    return score.scoreTotal;
}
//**********************************************************************************//
Score initialiserFeuilleScore(Score score){
    score.sommeDesUn = 0;
    score.sommeDesDeux = 0;
    score.sommeDesTrois = 0;
    score.sommeDesQuatre = 0;
    score.sommeDesCinq = 0;
    score.sommeDesSix = 0;
    score.sommeBrelan = 0;
    score.sommeCarre = 0;
    score.sommeMainPlaine = 0;
    score.sommePetiteSuite = 0;
    score.sommeGrandeSuite = 0;
    score.sommeYahtzee = 0;
    score.sommeChance = 0;
    score.sommeSuperieure = 0;
    score.sommeInferieure = 0;
    score.tour = 1;
    score.scoreTotal = 0;
    return score;
}
//**********************************************************************************//
void imprimerDes(Jet jet){
    printf("\n+-----+      +-----+      +-----+      +-----+      +-----+ \n");
    for (int i = 0; i < NB_DES; i++){
        switch (jet.des[i]){
            case FACE_UN: printf("|     |      ");
                break;
            case FACE_DEUX:
            case FACE_TROIS: printf("|    O|      ");
                break;
            case FACE_QUATRE:
            case FACE_CINQ: printf("|O   O|      ");
                break;
            case FACE_SIX: printf("|O O O|      ");
                break;
        }
    }
    printf("\n");
    for (int i = 0; i < NB_DES; i++){
       switch (jet.des[i]){
           case FACE_UN:
           case FACE_TROIS:
           case FACE_CINQ: printf("|  O  |      ");
               break;
           case FACE_DEUX:
           case FACE_QUATRE:
           case FACE_SIX: printf("|     |      ");
               break;
       }
    }
    printf("\n");
    for (int i = 0; i < NB_DES; i++){
        switch (jet.des[i]){
            case FACE_UN: printf("|     |      ");
                break;
            case FACE_DEUX:
            case FACE_TROIS: printf("|O    |      ");
                break;
            case FACE_QUATRE:
            case FACE_CINQ: printf("|O   O|      ");
                break;
            case FACE_SIX: printf("|O O O|      ");
                break;
        }
    }
    printf("\n+-----+      +-----+      +-----+      +-----+      +-----+ \n");
    printf("\n");
}
//**********************************************************************************//
void jeux(Jet jet, Score score){
    const int NB_TOURS = 13;   //quantité de tours dans le jeux
    const int LANCER_DES = 3;  //quantité de fois qu'on lance les dés
    char choix[5];       
    for (score.tour = 1; score.tour <= NB_TOURS; score.tour++){
    	for (int j = 0; j < NB_DES; j++){
    		choix[j] = '1';
    	}
        for (int i = 0; i < LANCER_DES; i++){
            jet = pigerJet(jet, choix);
            imprimerDes(jet);
            if (i < 2) {
            	printf("Quels dés voulez-vous jeter à nouveau? (0 pour garder, 1 pour jeter) \n");
    			for (int i = 0; i < NB_DES; i++){
        			scanf(" %c", &choix[i]);
            	}
           	}
    	}
    	diagrammeContexte(jet);
    	score = choixUtilisateur(score, jet);
    	feuilleScore(score);
	}
}

