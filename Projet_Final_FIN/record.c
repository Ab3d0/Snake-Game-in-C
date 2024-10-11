#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <time.h>
#include "record.h"
#define LARGEUR_FENETRE 1220
#define HAUTEUR_FENETRE 850
#define TAILLE_CELLULE 20
#define DELAI_MILLISECONDES 100
#define CYCLE 10000L
#define NB_POMMES 5
#define NB_OSTACLES 100

void enregistrerScore(int* score){
  FILE* fichier;
  fichier = fopen("score.txt", "a");

if (fichier== NULL){
  fprintf(stderr, "Erreur lors de l'ouverture du fichier score.txt\n ");
  exit(EXIT_FAILURE);

  fprintf(fichier, "%d\n",score);
  fclose(fichier);
 }
}

void lireTopScore(){
  int meilleurScore;
  int score;
  int premierScore = 1;

  FILE * fichier;
  fichier = fopen("score.txt","r" );

  if(fichier ==NULL){
    fprintf(stderr,"Erreur lors de l'ouverture du fichier score.txt\n");
    exit(EXIT_FAILURE);
  }
  while(fscanf(fichier, "%d", &score) ==1){
    if(premierScore || score){
      meilleurScore = score;
      premierScore = 0;
    }
  }
  fclose (fichier);

  ChoisirCouleurDessin(CouleurParNom("while"));
  EcrireTexte(350,260, "Meilleur Score", 2);

  if(premierScore){
    EcrireTexte(800,250,"Aucun Score" ,2);
  }else{
    char scoreText[10];
    snprintf(scoreText,10, "%07d" , meilleurScore);
    EcrireTexte(350,300,scoreText , 2);

  }
}
