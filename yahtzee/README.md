1 Le Yahtzee

  Vous allez developper un programme qui permet à un·e utilisateur·trice de jouer au Yahtzee. Le Yahtzee est un jeu de hasard où, à chaque tour, le joueur lance cinq des ordinaires et choisit une figure à ajouter à sa feuille de score. La partie se termine après 13 tours.
Un tour se d ́eroule ainsi :
    1. Les cinq des sont lances.
    2. Le joueur selectionne le ou les des qu’il souhaite relancer (il peut choisir d’en relancer aucun).
    3. Les des selectionnes sont relances.
    4. Le joueur selectionne le ou les des qu’il souhaite relancer (il peut choisir d’en relancer aucun)
    5. Les des selectionn ́es sont relances.
  À la fin de chaque tour, le joueur choisit une figure à ajouter à sa feuille de score. L’ordre des dès dans un jet n’a pas d’importance. S’il choisit une figure qu’il a dejà ajoutee, la nouvelle valeur efface l’ancienne. La feuille de score est affichee.
  À la fin du dernier tour, le pointage final est calcule. Le pointage final est la somme des points obtenus pour chaque figure.
  La transcription d’une partie est fournie dans le fichier transcript.txt. Il ne s’agit que d’un exemple, votre programme peut avoir un comportement different, tant que les règles du jeu soient respectees.
  Le code pour tirer un nombre au hasard est fourni dans le fichier piger.c.

1.1 Les figures et leur valeur
  Voici la liste des figures possibles et le pointage accorde si elles sont reussies.

  Des exemples de jets et la valeur des figures réalisées par ceux-ci apparaissent dans la table 1.

1.2. La feuille de score
  La feuille de score est divisee en deux sections : la section superieure et la section inferieure. Si le joueur a obtenu au moins 63 points dans la section superieure, il additionne 35 points en bonus à son score. La table 2 est un exemple de feuille de score finale.


2. La modelisation
  Votre code doit être separes en fichiers cohesifs (au moins un fichier d’en-tête et un fichier de source). Chaque fonction doit avoir une seule tâche et ne doit pas être trop longue.
  Vous devez avoir au moins deux structures, dont Jet qui sert à contenir les faces des cinq des lances.
  Huit fonctions sont obligatoires (vous en aurez beaucoup plus) : une pour les figures de la section superieure et une pour chaque figure de la section inferieure. La tâche de ces fonctions est de recevoir un Jet et de calculer le pointage pour cette figure. Dans le fichier yahtzee.h, vous avez des exemples de signatures documentees qui respectent l’enoncé.
  
3. Les tests
Vous devez fournir deux tests unitaires pour chaque fonction listee dans la section 2. Si l’utilisateur·trice execute le programme avec l’argument TEST, ce sont les tests qui sont executes, sinon le jeu se deroule normalement.
