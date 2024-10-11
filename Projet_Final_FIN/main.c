#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <time.h>
#include "afficherScore.h"
#include "temp.h"
#include "gameover.h"
#include "jeu.h"
#include "attente.h"
#include "chargement.h"



#define LARGEUR_FENETRE 1220
#define HAUTEUR_FENETRE 850
#define TAILLE_CELLULE 20
#define DELAI_MILLISECONDES 100
#define CYCLE 10000L
#define NB_POMMES 5
#define NB_OBSTACLES 100




int main(void) {
	int Demarrage;
     int score =0;
	int direction = 0 ;
	  int min;
	  int sec;
	  int dernierScore;
      int pause;
	  int jeuLance;
    int old_seconde;
  int seconde_act;
  int Temps[2] = {0,0};
  unsigned long int suivant;
    
    Serpent serpent;
     Position pommes[NB_POMMES];
    Obstacle obstacles[NB_OBSTACLES];
  

    
	InitialiserGraphique();
	chargerRessources();
	CreerFenetre(100, 100, 1500, 900);
	ChoisirCouleurDessin(CouleurParComposante(5,8,12));
	EffacerEcran(CouleurParComposante(5,8,12));
	Demarrage = ChargerSprite("demarrage.png");
	AfficherSprite(Demarrage,0,0);
    LibererSprite(Demarrage);

while (1) {
        if (ToucheEnAttente()) {
            int touche = Touche();
            switch (touche) {
                case XK_Return:
               
                       
                        jeuLance = 1;
                       
                
  suivant = Microsecondes()+CYCLE;
	
	  
	  
	
	ChoisirCouleurDessin(CouleurParComposante(164, 0, 217));
	EffacerEcran(CouleurParComposante(164, 0, 217));
	ChoisirCouleurDessin(CouleurParComposante(0,0,0));
	RemplirRectangle(1230,230,265,525);
	RemplirRectangle(1230,760,265,80);
	ChoisirCouleurDessin(CouleurParNom("white"));
	ChargerSprite("fleche");
	AfficherSprite(1,1245,290);
	EcrireTexte(1315,460,"Fleche",2);
	EcrireTexte(1275,500,"Directionelle",2);
	EcrireTexte(1250,600,"Espace = Pause",2);
	EcrireTexte(1255,700,"Echap = Quitter",2);
	EcrireTexte(1325,800,"Temps",2);	
		
	initialiserS( &serpent);
 	genererP(pommes,&serpent);
  initialiserObstacles(obstacles);
	
	
old_seconde = (suivant/1000000)%10;
 
 while (1){
   	  if(Microsecondes()>suivant){
	    suivant=Microsecondes()+CYCLE;
	    seconde_act = (suivant/1000000)%10;
	    if (seconde_act != old_seconde){
	      old_seconde=seconde_act;
	      if((Temps[1] +1) ==60){
		Temps[0]++;
		Temps[1]=0;
	      }else{
		Temps[1]++;
	      }
	    }
	    AfficherTemps(Temps[0],Temps[1]);
	    	 AfficherScore(score);
	  }
	  
	  dessinerObstacles (obstacles);
	if(collisionAvecObstacles ( &serpent, &obstacles)){
		/*FermerGraphique();*/
		AfficherGameover(Temps[0], Temps[1], &score);
	}
	  
	 
	  dessinerDamier();      
        deplacerS(&serpent, direction);
        gestionCollision(&serpent, pommes, &score, Temps);
        dessinerS(&serpent);
        dessinerP(pommes);
	   dessinerObstacles(obstacles);
        attente(DELAI_MILLISECONDES); 
        if (SourisCliquee()) {
            FermerGraphique();
            exit(EXIT_SUCCESS);
        }
        if (ToucheEnAttente()) {
	  int touche = Touche();
            switch (touche) {
                case XK_Right:
					if (direction != 2){
						
                    direction = 0;
                    break;
					}
					
                case XK_Down:
					if (direction != 3){
                    direction = 1;
                    break;
					}
                case XK_Left:
					if (direction != 0){
                    direction = 2;
                    break;
					}
                case XK_Up:
					if (direction != 1){
                    direction = 3;
                    break;
					}
                case XK_Escape:
                    FermerGraphique();
                    exit(EXIT_SUCCESS);
                 case XK_space :
                    pause = 1;
                
                    while(pause){
                        touche = Touche();
                        if (touche == XK_space){
                          
                            pause = 0;
                        }
                    }
            }
		
        }
}
                    
                    break;
                case XK_Escape:
                 
                    FermerGraphique();
                    exit(EXIT_SUCCESS);
                   
            }
        }
    }
		 
	
	Touche();
    return EXIT_SUCCESS;
} 
