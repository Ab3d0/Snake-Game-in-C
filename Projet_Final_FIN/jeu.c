#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <time.h>
#include "jeu.h"
#include "gameover.h"
#define LARGEUR_FENETRE 1220
#define HAUTEUR_FENETRE 850
#define TAILLE_CELLULE 20
#define DELAI_MILLISECONDES 100
#define CYCLE 10000L
#define NB_POMMES 5
#define NB_OBSTACLES 100



void initialiserS( Serpent *serpent) {
    serpent->longueur = 10;
    serpent->corps = (Position *)malloc(sizeof(Position) * serpent->longueur);
    serpent->corps[0].x = 31*20; 
    serpent->corps[0].y = 21*20; 
}
void dessinerS(const Serpent *serpent) {
	int i;
    for (i = 0; i < serpent->longueur; i++) {
        if (i % 2 == 0) {
            ChoisirCouleurDessin(CouleurParComposante(255, 255, 0)); 
        } else {
            ChoisirCouleurDessin(CouleurParComposante(235,176, 20)); 
        }
        RemplirRectangle(serpent->corps[i].x, serpent->corps[i].y, TAILLE_CELLULE, TAILLE_CELLULE);
    }
}
void deplacerS(Serpent *serpent, int direction ) {
  int i;
    for (i = serpent->longueur - 1; i > 0; i--) {
        serpent->corps[i] = serpent->corps[i - 1];
    }
   
    switch (direction) {
        case 0:
            serpent->corps[0].x += TAILLE_CELLULE;
            break;
        case 1:
            serpent->corps[0].y += TAILLE_CELLULE;
            break;
        case 2:
            serpent->corps[0].x -= TAILLE_CELLULE;
            break;
        case 3:
            serpent->corps[0].y -= TAILLE_CELLULE;
            break;
    }
}
void genererP(Position *pommes ,Serpent *serpent ) {
	int i,j;
     int newX,newY;
    int collision = 0;
    for ( i = 0; i < NB_POMMES; i++) {
        do{
        newX = rand() % ((LARGEUR_FENETRE - 20) / TAILLE_CELLULE) * TAILLE_CELLULE + 20;  
        newY = rand() % ((HAUTEUR_FENETRE -  20 ) / TAILLE_CELLULE) * TAILLE_CELLULE + 20; 
     for (j =0; j<serpent->longueur; j++){
         if (serpent->corps[j].x == newX && serpent->corps[j].y == newY){
             collision = 1;
             break;
         }}}while(collision);
        pommes[i].x = newX;
        pommes[i].y = newY;
    
        
    }
}
void dessinerP( Position *pommes) {
	int i;
    ChoisirCouleurDessin(CouleurParComposante(220, 20, 0));
    for ( i = 0; i < NB_POMMES; i++) {
        RemplirRectangle(pommes[i].x, pommes[i].y, TAILLE_CELLULE, TAILLE_CELLULE);
    }
	}
void mangerPomme( Serpent *serpent, Position *pommes , int* score){
  int i;
  for(i=0; i< NB_POMMES ; i++){
    if(serpent->corps[0].x == pommes[i].x && serpent->corps[0].y == pommes[i].y){
    serpent->longueur +=2;
    serpent->corps = realloc(serpent->corps, sizeof(Position) *serpent->longueur);
    pommes[i].x = rand ()% ((LARGEUR_FENETRE -20) /TAILLE_CELLULE) *TAILLE_CELLULE+20;
    pommes[i].y = rand() % ((HAUTEUR_FENETRE - 20)/TAILLE_CELLULE) * TAILLE_CELLULE+20;
	*score += 5;
	printf("%d \n", *score);
    }
  }
}

int collisionAvecP(Serpent *serpent, const Position *pommes) {
	int i;
    for ( i = 0; i < NB_POMMES; i++) {
        if ( serpent->corps[0].x == pommes[i].x && serpent->corps[0].y == pommes[i].y) {
            return 1;
        }
    }
    return 0;
}
int collisionAvecS( Serpent *serpent ) {
	int i;
    int scoreActuel,dernierScore,score ;
    char Temps[6];
    
    for ( i = 1; i < serpent->longueur; i++) {
        if (serpent->corps[0].x == serpent->corps[i].x && serpent->corps[0].y == serpent->corps[i].y) {
             return 1;
        }
    }
    return 0;
}
int collisionAvecBordures( Serpent *serpent) {
    return (serpent->corps[0].x < 20 || serpent->corps[0].x >= (LARGEUR_FENETRE) ||
            serpent->corps[0].y < 20 || serpent->corps[0].y >= (HAUTEUR_FENETRE - 20));
}
void gestionCollision( Serpent *serpent, Position *pommes,int* score , int time[2]) {
	
	
  
    if (collisionAvecS(serpent) || collisionAvecBordures(serpent)) {
		/*FermerGraphique();*/
       	AfficherGameover(time[0],time[1], score);
    }
    if(collisionAvecP(serpent,pommes)){
      mangerPomme(serpent, pommes , score);
    }
}

void initialiserObstacles(Obstacle *obstacles){
  int i;
  for(i = 0;i<NB_OBSTACLES;i++){
    obstacles[i].x = rand()% ((LARGEUR_FENETRE-20)/TAILLE_CELLULE)*TAILLE_CELLULE+20;
    obstacles[i].y = rand()% ((HAUTEUR_FENETRE-20)/TAILLE_CELLULE) *TAILLE_CELLULE+20 ;
	  
	 
  }
}
void dessinerObstacles( Obstacle *obstacles){
  int i;
  ChoisirCouleurDessin(CouleurParComposante(106,238,253));
		       for(i = 0; i<NB_OBSTACLES; i++){
			 RemplirRectangle(obstacles[i].x, obstacles[i].y,TAILLE_CELLULE,TAILLE_CELLULE);
		       }
}
int collisionAvecObstacles(Serpent *serpent,  Obstacle *obstacles){
  int i;
  for (i = 0; i<NB_OBSTACLES;i++){
    if(serpent->corps[0].x == obstacles[i].x && serpent->corps[0].y == obstacles[i].y){
      return 1;
    }
  }
  return 0;
}	
