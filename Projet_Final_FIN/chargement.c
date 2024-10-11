#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <time.h>
#include "chargement.h"
#define LARGEUR_FENETRE 1220
#define HAUTEUR_FENETRE 850
#define TAILLE_CELLULE 20
#define DELAI_MILLISECONDES 100
#define CYCLE 10000L
#define NB_POMMES 5
#define NB_OBSTACLES 100

void afficherBarreDeChargement(int progres) {
    int i;
    
    printf("[");
    for ( i = 0; i < progres; ++i) {
        printf("#");
    }
    for ( i = progres; i < 10; ++i) {
        printf(" ");
    }
    printf("] %d%%\r", progres * 10);
    fflush(stdout);
}
void chargerRessources() {
    int i,j;
    for (i = 0; i <= 10; ++i) {
        afficherBarreDeChargement(i);
    
        for ( j = 0; j < 100000000; ++j) {}
    }
  
}