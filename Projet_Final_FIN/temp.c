#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <time.h>
#include "temp.h"
#define LARGEUR_FENETRE 1220
#define HAUTEUR_FENETRE 850
#define TAILLE_CELLULE 20
#define DELAI_MILLISECONDES 100
#define CYCLE 10000L
#define NB_POMMES 5
#define NB_OBSTACLES 100


void AfficherTemps (int min, int sec){
  char Temps[6];
  snprintf(Temps,6, "%02d:%02d", min,sec);
	
  ChoisirCouleurDessin(CouleurParComposante(105,83,147));
	RemplirRectangle(1230,760,265,80); 
  ChoisirCouleurDessin(CouleurParNom("white"));
  EcrireTexte(1325,800,"Temps",2);
  EcrireTexte (1335,835,Temps,2);
}