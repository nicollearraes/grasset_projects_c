1 Le Boggle

  Le jeu de Boggle (Hasbro) est un jeu de lettres dont le but est de trouver le plus de mots possibles formes par des des sur un plateau.
Au debut du jeu, 16 des avec une lettre sur chaque face sont jetes et places sur une grille de 4 rangees par 4 colonnes. Par exemple, une grille de jeu possible est :
    
    IDXT 
    MHEI 
    ERVN 
    TLLU

  Le joueur doit trouver le plus possible de mots qui sont formes par ces des en respectant les conditions suivantes :
• Chaque de ne peut être utilise qu’une seule fois par mot.
• Les des formant le mot doivent se toucher (diagonales inclues). 
• Le mot doit être en francais.

  Dans l’exemple, plus haut, le mot UNITE est forme en parcourant les des dans l’ordre : (3,3), (2,3), (1,3), (0,3), (1,2). Le mot VERT est forme en parcourant les des dans l’ordre : (2,2), (1,2), (2,1), (3,0).

  La partie se termine quand le joueur entre le mot vide.
  À la fin de la partie, tous les mots en francais qui apparaissent dans la grille sont affiches.


2 Les dés

  Les des du jeu de Boggle en francais sont les suivants :

        #define R 4
        #define C 4
        #define NB_FACES 6
        /** Les 16 des officiels du jeu de boggle en francais */
        const char DES[R * C][NB_FACES] =
          3
        {{’E’, ’T’, ’U’, ’K’, ’N’, ’O’}, // 0
         {’E’, ’V’, ’G’, ’T’, ’I’, ’N’}, // 1
         {’D’, ’E’, ’C’, ’A’, ’M’, ’P’}, // 2
         {’I’, ’E’, ’L’, ’R’, ’U’, ’W’}, // 3
         {’E’, ’H’, ’I’, ’F’, ’S’, ’E’}, // 4
         {’R’, ’E’, ’C’, ’A’, ’L’, ’S’}, // 5
         {’E’, ’N’, ’T’, ’D’, ’O’, ’S’}, // 6
         {’O’, ’F’, ’X’, ’R’, ’I’, ’A’}, // 7
         {’N’, ’A’, ’V’, ’E’, ’D’, ’Z’}, // 8
         {’E’, ’I’, ’O’, ’A’, ’T’, ’A’}, // 9
         {’G’, ’L’, ’E’, ’N’, ’Y’, ’U’}, // 10
         {’B’, ’M’, ’A’, ’Q’, ’J’, ’O’}, // 11
         {’T’, ’L’, ’I’, ’B’, ’R’, ’A’}, // 12
         {’S’, ’P’, ’U’, ’L’, ’T’, ’E’}, // 13
         {’A’, ’I’, ’M’, ’S’, ’O’, ’R’}, // 14
         {’E’, ’N’, ’H’, ’R’, ’I’, ’S’}}; // 15
 
3 Le dictionnaire
  Le fichier francais.txt contient tous les mots en francais en ordre alphabetique, incluant les conjugaisons et les accords, en majuscules, sans accents, ni caractères speciaux.
  Le fichier lireFichier.c lit un fichier et imprime son contenu, ligne par ligne, à la console.
  
4 À faire
  Vous devez implementer un jeu de Boggle console en C, incluant la recherche dans le dictionnaire, la generation de la grille de jeu, la recherche d’un mot dans la grille et l’interaction avec l’utilisateur.
  Votre solution incluera trois algorithme :
      1. Un algorithme pour generer une grille de jeu.
      2. Un algorithme pour chercher un mot dans le dictionnaire. 
      3. Un algorithme pour chercher un mot dans la grille de jeu.
  Le pseudo-code du dernier algorithme se trouve à la section 4.1.
Portez une attention particulière sur l’efficacit ́e de vos solutions algorithmiques.
  
4.1 Pseudo-codes
  Voici deux pseudo-codes de haut niveau qui resolvent Boggle.

MotDansGrille - D ́etermine si un mot est dans la grille de jeu
Entrees : grille, mot
Pour chaque case c dans la grille Marquer c comme visite
Si formeMot(grille, mot, c)
Retourner vrai
Marquer c comme non-visite
  Retourner Faux

FormeMot - Determine si un mot est dans la grille à partir d’un de
Entrees : grille, mot, c (une case dans la grille)
  Si le mot est vide
     Retourner vrai
Si le de de la case c n’a pas comme lettre la première lettre de mot
     Retourner faux
  Pour case v voisine de c qui n’a pas encore  ́ete visitee
Marquer v comme visit ́e
motSuivant <- mot sans la première lettre Si formeMot(grille, motSuivant, v)
Retourner vrai
Marquer v comme non-visitée
Retourner Faux
  
  
  
