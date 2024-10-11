#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <time.h>
#include "gameover.h"
#include "record.h"
#define LARGEUR_FENETRE 1220
#define HAUTEUR_FENETRE 850
#define TAILLE_CELLULE 20
#define DELAI_MILLISECONDES 100
#define CYCLE 10000L
#define NB_POMMES 5
#define NB_OBSTACLES 100





void AfficherGameover(int min , int sec, int* score)
{
	int GameOver;
     char Temps[6];
 char scoreText[10];

	ChoisirCouleurDessin(CouleurParNom("white"));
	RemplirRectangle(0, 0, 1500, 900);
	GameOver = ChargerSprite("GameOver.png");
	AfficherSprite(GameOver,0,0);
	LibererSprite(GameOver);
    
      snprintf(Temps,6, "%02d:%02d", min,sec);
  ChoisirCouleurDessin(CouleurParNom("white"));
  EcrireTexte(350,460,"Temps",2);
  EcrireTexte (350,500,Temps,2);
  snprintf(scoreText, 10 ,"%07d",*score);
  ChoisirCouleurDessin(CouleurParNom("white"));
   EcrireTexte(350,360,"Score" ,2);
   EcrireTexte(350,400,scoreText,2);
	EcrireTexte(400,575,"Appuyer sur Q pour quitter",2);
	

	enregistrerScore(&score);
	lireTopScore();
 
	while(1){
	if (ToucheEnAttente()){
	int touche= Touche();
	if (touche == XK_q || touche ==XK_Q){
	FermerGraphique();
	exit(EXIT_SUCCESS);
	}
 	}
	}					 
}
