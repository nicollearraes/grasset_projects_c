1. La structure de donnees “Queue”

  Vous allez implementer la structure de donnees Queue. Une queue suit le principe “premier arrive, premier servi”.
  La queue sera composee de pointeurs vers des instances de la structure Client (dont les membres sont precises en plus de details à la section 2.3). La queue doit implementer les fonctionnalites offrirClient, coupDOeilTete, obtenirTete, longueurQueue et imprimerQueue.
  
        typedef struct Client Client;
        struct Client{ /* ... */ };
        typedef struct Queue Queue;
        struct Queue{ /* ... */ };
        // Ajoute le client a la fin de queue.
        void offrirClient(Queue* queue, Client* client);
        // Retourne le premier client dans la queue.
        // Si la queue est vide, NULL est retourne.
        Client* coupDOeilTete(Queue queue);
        // Retire et retourne le premier client dans la queue.
        // Si la queue est vide, NULL est retourne.
        Client* obtenirTete(Queue* queue);
        // Retourne le nombre de clients dans la queue.
        int longueurQueue(Queue queue)
        // Imprime chaque client de la queue.
        void imprimerQueue(Queue queue)
  
  Vous êtes libre de choisir l’implementation de la Queue, soit sous forme d’un tableau dynamique, soit sous forme d’une liste chaînee (recommande). Votre code doit permettre les queues arbitrairement longues, utiliser une quantite raisonnable d’espace et de temps, et liberer toute la memoire qu’il reserve.
  Fournissez le pseudo-code pour les fonctions offrirClient, obtenirTete et longueurQueue dans leur en-tête de commentaire d’implementation.


2. La simulation

  Vous allez simuler les caisses dans une epicerie en utilisant vos structures Queue et Client. Une ́epicerie a 4 caisses ayant chacune une file d’attente.
  La simulation dure 200 cycles. À chaque cycle:  
  
  1. Il y a une chance sur 6 qu’un nouveau client entre dans le système. Quand un client entre, il s’ajoute à la file d’attente la plus courte. Les clients ont en moyenne 10 articles dans leur panier. Du code vous est fourni à la section 2.3 pour génerer des paniers au hasard.
  2. Chaque caissier traite un article du client à la première position dans sa file. Si le client à la caisse n’a plus d’articles, ce dernier quitte l’epicerie et le prochain client dans la file passe à la caisse. Si sa file est vide, le caissier ne fait rien.
  3. Le système pause pendant 1000 millisecondes (Utilisez la fonction sleep).

2.1 L’ ́etat des caisses
  À chaque 1 cycle, l’etat des files d’attente et des caisses est affiche à la console. Vous devez imprimer le contenu de toutes les files d’attente.

      ÉTAT DES CAISSES AU CYCLE #56
      Caisse 1 : [{cycle #1, 1 articles}, {cycle #21, 51 articles}, {cycle #55, 3 articles}]
      Caisse 2 : [{cycle #12, 42}]
      Caisse 3 : []
      Caisse 4 : [{cycle #18, 9 articles}, {cycle #31, 13 articles}]

  N’hesitez pas à modifier la valeur des paramètres de la simulation (le nombre de caisses [4], le nombre de cycles [200], le taux d’arrivee des nouveaux clients [6], le nombre d’articles moyen par panier [10], le temps de pause par cycle [1000] et le taux d’impression de l’etat des caisses [1]).

2.2 Le rapport
  À la fin de la simulation, un rapport est affiche, contenant, au minimum, les informations suivantes :

      STATISTIQUES :
      Nombredeclientsentres :2000 
      Nombre d’articles vendus : 21487 
      Temps d’attente moyen : 36 cycles 
      Temps d’attente maximum : 214 cycles 
      Nombre d’articles maximum : 82
      Nombre d’articles minimum : 1
      Nombre d’articles moyen : 10

2.3 Les paniers des clients
  Les informations suivantes doivent être conservees par client : le numero du cycle auquel il est arrive et le nombre d’articles dans son panier. Le comportement des clients est simple : une fois qu’ils sont ajoutes à une file, ils ne quittent pas tant qu’ils ne sont pas servis. Ils ne changent pas de file et ne perdent pas patience.
  Le nombre d’articles dans le panier d’un client suit une distribution exponentielle. La fonction double randExpo(double lambda) retourne un naturel au hasard, selon la distribution exponentielle d’esperance 1/lambda :
  
      #include <math.h>
      #include <stdlib.h>
      double randExpo(double lambda)
      {
        double u = rand() / (RAND_MAX + 1.0);
        return -log(1 - u) / lambda;
      }
 
  Sur certains syst`emes d’exploitation, vous devrez utiliser l’option lm pour compiler.
      gcc *.c -lm
  
  
  
  
