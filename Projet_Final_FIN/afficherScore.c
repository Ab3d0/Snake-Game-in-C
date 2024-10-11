#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <time.h>
#define LARGEUR_FENETRE 1220
#define HAUTEUR_FENETRE 850
#define TAILLE_CELLULE 20
#define DELAI_MILLISECONDES 100
#define CYCLE 10000L
#define NB_POMMES 5
#define NB_OBSTACLES 100
#include "afficherScore.h"


void AfficherScore(int score){
    
  char scoreText[8];
  snprintf(scoreText, 8 ,"%07d",score);
  ChoisirCouleurDessin(CouleurParComposante(105,83,147));
  RemplirRectangle(1230,25,265,200);
  ChoisirCouleurDessin(CouleurParNom("white"));
   EcrireTexte(1320,75,"Score" ,2);
   EcrireTexte(1310,150,scoreText,2);
}
