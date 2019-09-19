// **************************************************************************** //
// Nom : parenthesagebonus.c													//
//																				//
// Auteur : Nicolle																//
//																				//
// Date : 3 octobre 2018														//
//																				//
// La fonction reçoit une chaîne de caractères et retourne vrai si elle a des 	//
// parenthéses, crochets et accolades corrects et faux sinon.  					//
//																				//
// Entrées Testées:																//
//																				//
// Input: {[()]} 																//
// Output: L'expression est bien parenthesée.									//
//																				//
// Input: [)])																	//
// Output: L'expression n'est pas bien parenthesée. 							//
//																				//
// Input: {(][)}																//
// Output: L'expression n'est pas bien parenthesée.								//
//																				//
// * Le code n'est pas complet. Malheureusement j'ai pas eu le temps de le 		//
//   terminer 																  * //
//																				//
// **************************************************************************** //

#include <stdio.h>

int estBienParenthesee(char expression[])
{
	int parentheseOuverte = 0;
	int parentheseFermee = 0;
	int crochetOuvert = 0;
	int crochetFerme = 0;
	int accoladeOuverte = 0;
	int accoladeFermee = 0;

	for (int i = 0; expression[i] != '\0'; i++) 
	{		// \0 est la fin du tableau
		if (parentheseOuverte >= parentheseFermee) 		//si parentheseFermee > parentheseOuverte -> )( (plus de parenthese fermee ou parenthese fermee avante parenthese ouverte -> return 0
		{
			if (expression[i] == '(')
				parentheseOuverte++;
			if (expression[i] == ')')
				parentheseFermee++;
		} else 
			return 0;				//l'expression n'est pas bien parenthesée
		if (crochetOuvert >= crochetFerme) 		//si crochetFerme > crochetOuvert -> )( (plus de parenthese fermee ou parenthese fermee avante parenthese ouverte -> return 0
		{
			if (expression[i] == '[')
				crochetOuvert++;
			if (expression[i] == ']')
				crochetFerme++;
		} else 
			return 0;				//l'expression n'est pas bien parenthesée
		if (accoladeOuverte >= accoladeFermee) 		//si accoladeFermee > accoladeOuverte -> )( (plus de parenthese fermee ou parenthese fermee avante parenthese ouverte -> return 0
		{
			if (expression[i] == '{')
				accoladeOuverte++;
			if (expression[i] == '}')
				accoladeFermee++;
		} else 
			return 0;				//l'expression n'est pas bien parenthesée
	}
	if (parentheseOuverte == parentheseFermee && crochetOuvert == crochetFerme && accoladeOuverte == accoladeFermee)
		return 1; 
		//parentheseOuverte == parentheseFermee && crochetOuvert == crochetFerme && accoladeOuverte == accoladeFermee -> l'expression est bien parenthesée
	else
		return 0; 
	
}


int main() {

	char expression[256];
	printf("Entrez une expression avec des parentheses, svp.\n");
	fgets(expression, 256, stdin);

	int exp = estBienParenthesee(expression);

	if (exp == 1) {
		printf("L'expression est bien parenthesée. \n");	
	} else {
		printf("L'expression n'est pas bien parenthesée. \n");
	}
}
